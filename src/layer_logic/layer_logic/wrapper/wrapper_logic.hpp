#pragma once

#include "layer_arch/api/yosys/frame.hpp"
#include "layer_logic/api/abc/frame.hpp"
#include "layer_logic/api/lsils/frame.hpp"

#include "lorina/gtech.hpp"
#include "lorina/detail/call_in_topological_order.hpp"

#include <assert.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>

namespace lf
{

namespace logic
{

using namespace Yosys;
using namespace Yosys::RTLIL;

struct WrapperYosysLogic
{
private:
  using GateFn = lorina::detail::Func<
      std::vector<std::pair<std::string, bool>>,
      std::string,
      std::string>;
  using ModuleInstFn = lorina::detail::Func<
      std::string,
      std::vector<std::string>,
      std::string,
      std::vector<std::pair<std::string, std::string>>>;

  /* Parameter maps */
  using GateParamMap = lorina::detail::ParamPackMap<
      /* Key */
      std::string,
      /* Params */
      std::vector<std::pair<std::string, bool>>,
      std::string,
      std::string>;
  using ModuleInstParamMap = lorina::detail::ParamPackMap<
      /* Key */
      std::string,
      /* Param */
      std::string,
      std::vector<std::string>,
      std::string,
      std::vector<std::pair<std::string, std::string>>>;

  constexpr static const int GATE_FN{ 0 };
  constexpr static const int MODULE_INST_FN{ 1 };

  using ParamMaps = lorina::detail::ParamPackMapN<GateParamMap, ModuleInstParamMap>;
  using PackedFns = lorina::detail::FuncPackN<GateFn, ModuleInstFn>;

public:
  lorina::detail::call_in_topological_order<PackedFns, ParamMaps> on_action; // generate network in the given topological order
  mockturtle::gtech_reader<mockturtle::gtg_network> reader;

  RTLIL::Design* design;
  RTLIL::Module* module;
  CellTypes ct;

  vector<shared_str> dot_escape_store;
  std::map<RTLIL::IdString, int> dot_id2num_store;
  std::map<RTLIL::IdString, int> autonames;
  int single_idx_count;

  struct net_conn
  {
    std::set<std::pair<std::string, int>> in, out;
  };
  std::map<std::string, net_conn> net_conn_map;

  std::set<std::string> one_port_signals;             // this store the const port sigs
  std::set<std::string> zero_port_signals;            // this store the const port sigs
  std::map<std::string, std::string> ci_port_signals; // this store the ci port sigs
  std::map<std::string, std::string> co_port_signals; // this store the co port sigs

  std::vector<std::string> inputs;
  std::vector<std::string> outputs;
  std::vector<std::string> internals;
  std::vector<std::tuple<std::string, std::string, lorina::gtech_reader::latch_init_value>> latches; // {Q, D, value}

  const char* findLabel( std::string member_name )
  {
    return escape( member_name, true );
  }

  const char* escape( std::string id, bool is_name = false )
  {
    if ( id.size() == 0 )
      return "";

    if ( id[0] == '\\' )
      id = id.substr( 1 );

    // TODO: optionally include autoname + print correspondence in case of ambiguity
    size_t max_label_len = false ? 256 : 16384;
    if ( id.size() > max_label_len )
    {
      id = id.substr( 0, max_label_len - 3 ) + "...";
    }

    std::string str;
    for ( char ch : id )
    {
      if ( ch == '\\' )
      {
        // new graphviz have bug with escaping '\'
        str += "&#9586;";
        continue;
      }
      if ( ch == '"' || ch == '<' || ch == '>' )
        str += "\\";
      str += ch;
    }

    dot_escape_store.push_back( str );
    return dot_escape_store.back().c_str();
  }

  int id2num( RTLIL::IdString id )
  {
    if ( dot_id2num_store.count( id ) > 0 )
      return dot_id2num_store[id];
    return dot_id2num_store[id] = dot_id2num_store.size() + 1;
  }

  std::string gen_signode_simple( RTLIL::SigSpec sig, bool range_check = true )
  {
    if ( GetSize( sig ) == 0 )
    {
      return stringf( "v%d", single_idx_count++ );
    }

    if ( sig.is_chunk() )
    {
      const RTLIL::SigChunk& c = sig.as_chunk();
      if ( c.wire != nullptr && design->selected_member( module->name, c.wire->name ) )
      {
        if ( !range_check || c.wire->width == c.width )
          return stringf( "n%d", id2num( c.wire->name ) );
      }
      else
      {
        auto label = findLabel( log_signal( c ) );
        auto node = stringf( "v%d", single_idx_count );
        if ( std::string( label ) == "1'1" )
        {
          one_port_signals.insert( node );

          on_action.declare_known( node );

          reader.on_wires( { node } );
          std::string lhs = node;
          std::vector<std::pair<std::string, bool>> args{};
          on_action.call_deferred<GATE_FN>( /* dependencies */ {}, { lhs },
                                            /* gate-function params */ std::make_tuple( args, lhs, "one" ) );
        }
        else if ( std::string( label ) == "1'0" )
        {
          zero_port_signals.insert( node );

          on_action.declare_known( node );

          reader.on_wires( { node } );
          std::string lhs = node;
          std::vector<std::pair<std::string, bool>> args{};
          on_action.call_deferred<GATE_FN>( /* dependencies */ {}, { lhs },
                                            /* gate-function params */ std::make_tuple( args, lhs, "zero" ) );
        }
        else
        {
          printf( "unknow value!\n" );
        }

        printf( "%s  ->  %s\n", std::string( label ).c_str(), node.c_str() );
        return stringf( "v%d", single_idx_count++ );
      }
    }

    return std::string();
  }

  // Return the pieces of a label joined by a '|' separator
  std::string join_label_pieces( std::vector<std::string> pieces )
  {
    std::string ret = "";
    bool first_piece = true;

    for ( auto& piece : pieces )
    {
      if ( !first_piece )
        ret += "|";
      ret += piece;
      first_piece = false;
    }

    return ret;
  }

  void gen_portbox( std::string port, RTLIL::SigSpec sig, bool driver, std::string* node = nullptr )
  {
    std::string net = gen_signode_simple( sig );
    assert( !net.empty() );

    if ( !port.empty() )
    {
      if ( driver )
        net_conn_map[net].in.insert( { port, GetSize( sig ) } );
      else
        net_conn_map[net].out.insert( { port, GetSize( sig ) } );
    }
    if ( node != nullptr )
      *node = net;
  }

  void handle_module()
  {
    single_idx_count = 0;
    dot_escape_store.clear();
    dot_id2num_store.clear();
    net_conn_map.clear();

    std::map<std::string, std::string> wires_on_demand;

    auto wires = module->selected_wires();
    auto cells = module->selected_cells();

    // process inputs and outputs
    printf( "process input / outputs:\n" );
    for ( auto wire : wires )
    {
      auto root_label = findLabel( wire->name.str() );         // the origianl name of input/output
      auto port_name = stringf( "n%d", id2num( wire->name ) ); // the connected port to the root_label

      reader.on_wires( { root_label } );
      reader.on_wires( { port_name } );

      internals.push_back( port_name );
      if ( wire->name.isPublic() )
      {
        if ( wire->port_input )
        {
          inputs.push_back( root_label );
          reader.on_inputs( { root_label } );
          on_action.declare_known( root_label );

          printf( "input: %s  ->  %s\n", std::string( root_label ).c_str(), port_name.c_str() );

          std::string lhs = port_name;
          std::pair<std::string, bool> op1 = std::make_pair( root_label, false );
          std::vector<std::pair<std::string, bool>> args{ op1 };
          on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs },
                                            /* gate-function params */ std::make_tuple( args, lhs, "buf" ) );
        }
        else if ( wire->port_output )
        {
          outputs.push_back( root_label );
          reader.on_outputs( { root_label } );

          printf( "output: %s  ->  %s\n", port_name.c_str(), std::string( root_label ).c_str() );

          std::string lhs = root_label;
          std::pair<std::string, bool> op1 = std::make_pair( port_name, false );
          std::vector<std::pair<std::string, bool>> args{ op1 };
          on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs },
                                            /* gate-function params */ std::make_tuple( args, lhs, "buf" ) );
        }
      }
      else
      {
        wires_on_demand[port_name] = wire->name.str();
      }
    }

    // create latch_output
    printf( "process latch_outputs:\n" );
    for ( auto cell : module->selected_cells() )
    {
      auto cell_label = stringf( "c%d", id2num( cell->name ) );
      auto cell_type = cell->type.str();
      if ( cell_type == "$_FF_" )
      {
        std::vector<RTLIL::IdString> in_ports, out_ports;
        for ( auto& conn : cell->connections() )
        {
          if ( !ct.cell_output( cell->type, conn.first ) )
          {
            in_ports.push_back( conn.first );
          }
          else
          {
            out_ports.push_back( conn.first );
          }
        }

        for ( auto& p : in_ports )
        {
          auto port_name = stringf( "c%d:p%d", id2num( cell->name ), id2num( p ) );
          printf( "latch_input: %s\n", port_name.c_str() );
          reader.on_wires( { port_name } );
          reader.on_latch_input( { port_name } );
        }

        for ( auto& p : out_ports )
        {
          auto port_name = stringf( "c%d:p%d", id2num( cell->name ), id2num( p ) );
          printf( "latch_output: %s\n", port_name.c_str() );
          reader.on_wires( { port_name } );
          reader.on_latch_output( { port_name } );
          on_action.declare_known( port_name );
        }
      }
    }

    // process internal gates
    printf( "process internal cells:\n" );
    for ( auto cell : cells )
    {
      std::vector<RTLIL::IdString> in_ports, out_ports;
      std::vector<std::string> fanin_ports;
      std::vector<std::string> fanout_ports;

      auto cell_label = stringf( "c%d", id2num( cell->name ) );
      auto cell_type = cell->type.str();

      printf( "cell: %s\n", cell_label.c_str() );
      printf( "type: %s\n", cell_type.c_str() );

      for ( auto& conn : cell->connections() )
      {
        gen_portbox( stringf( "c%d:p%d", id2num( cell->name ), id2num( conn.first ) ), conn.second, ct.cell_output( cell->type, conn.first ) );
        if ( !ct.cell_output( cell->type, conn.first ) )
        {
          in_ports.push_back( conn.first );
        }
        else
        {
          out_ports.push_back( conn.first );
        }
      }

      std::sort( in_ports.begin(), in_ports.end(), RTLIL::sort_by_id_str() );
      std::sort( out_ports.begin(), out_ports.end(), RTLIL::sort_by_id_str() );

      for ( auto& p : in_ports )
      {
        auto port_name = stringf( "c%d:p%d", id2num( cell->name ), id2num( p ) );
        fanin_ports.push_back( port_name );
        reader.on_wires( { port_name } );
        printf( "fanin: %s\n", port_name.c_str() );
      }

      for ( auto& p : out_ports )
      {
        auto port_name = stringf( "c%d:p%d", id2num( cell->name ), id2num( p ) );
        fanout_ports.push_back( port_name );
        reader.on_wires( { port_name } );
        printf( "fanout: %s\n", port_name.c_str() );
      }

      if ( cell_type == "$_NOT_" )
      {
        std::string lhs = fanout_ports[0];
        std::pair<std::string, bool> op1 = std::make_pair( fanin_ports[0], false );
        std::vector<std::pair<std::string, bool>> args{ op1 };
        on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs },
                                          /* gate-function params */ std::make_tuple( args, lhs, "not" ) );
      }
      else if ( cell_type == "$_BUF_" )
      {
        std::string lhs = fanout_ports[0];
        std::pair<std::string, bool> op1 = std::make_pair( fanin_ports[0], false );
        std::vector<std::pair<std::string, bool>> args{ op1 };
        on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs },
                                          /* gate-function params */ std::make_tuple( args, lhs, "buf" ) );
      }
      else if ( cell_type == "$_AND_" )
      {
        std::string lhs = fanout_ports[0];
        std::pair<std::string, bool> op1 = std::make_pair( fanin_ports[0], false );
        std::pair<std::string, bool> op2 = std::make_pair( fanin_ports[1], false );
        std::vector<std::pair<std::string, bool>> args{ op1, op2 };
        on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first, op2.first }, { lhs },
                                          /* gate-function params */ std::make_tuple( args, lhs, "and" ) );
      }
      else if ( cell_type == "$_FF_" )
      {
        std::string lhs = fanout_ports[0];
        std::pair<std::string, bool> op1 = std::make_pair( fanin_ports[0], false );
        std::vector<std::pair<std::string, bool>> args{ op1 };
        on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs },
                                          /* gate-function params */ std::make_tuple( args, lhs, "latch" ) );
      }
      else
      {
        printf( "fuxk unknow!\n" );
      }
    }

    printf( "process connections:\n" );
    for ( auto& conn : module->connections() )
    {
      bool found_lhs_wire = false;
      for ( auto& c : conn.first.chunks() )
      {
        if ( c.wire == nullptr || design->selected_member( module->name, c.wire->name ) )
          found_lhs_wire = true;
      }
      bool found_rhs_wire = false;
      for ( auto& c : conn.second.chunks() )
      {
        if ( c.wire == nullptr || design->selected_member( module->name, c.wire->name ) )
          found_rhs_wire = true;
      }
      if ( !found_lhs_wire || !found_rhs_wire )
        continue;

      std::string left_node, right_node;
      gen_portbox( "", conn.second, false, &right_node );
      gen_portbox( "", conn.first, true, &left_node );

      reader.on_wires( { left_node } );
      reader.on_wires( { right_node } );

      if ( left_node[0] == 'x' && right_node[0] == 'x' )
      {
        std::string lhs = left_node;
        std::pair<std::string, bool> op1 = std::make_pair( right_node, false );
        std::vector<std::pair<std::string, bool>> args{ op1 };
        on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs },
                                          /* gate-function params */ std::make_tuple( args, lhs, "buf" ) );

        printf( "%s  ->  %s\n", left_node.c_str(), right_node.c_str() );
      }
      else
      {
        if ( left_node[0] == 'x' )
        {
          net_conn_map[left_node].in.insert( { right_node, GetSize( conn.first ) } );
        }
        else if ( right_node[0] == 'x' )
        {
          net_conn_map[right_node].out.insert( { left_node, GetSize( conn.first ) } );
        }
        else
        {
          auto node = stringf( "x%d", single_idx_count );
          net_conn_map[left_node].in.insert( { stringf( "x%d", single_idx_count ), GetSize( conn.first ) } );
          net_conn_map[right_node].out.insert( { stringf( "x%d", single_idx_count ), GetSize( conn.first ) } );
          single_idx_count++;

          reader.on_wires( { node } );

          std::string lhs1 = node;
          std::pair<std::string, bool> op1 = std::make_pair( right_node, false );
          std::vector<std::pair<std::string, bool>> args1{ op1 };

          std::string lhs2 = left_node;
          std::pair<std::string, bool> op2 = std::make_pair( node, false );
          std::vector<std::pair<std::string, bool>> args2{ op2 };

          on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs1 },
                                            /* gate-function params */ std::make_tuple( args1, lhs1, "buf" ) );

          on_action.call_deferred<GATE_FN>( /* dependencies */ { op2.first }, { lhs2 },
                                            /* gate-function params */ std::make_tuple( args2, lhs2, "buf" ) );

          printf( "%s  ->  %s\n", node.c_str(), left_node.c_str() );
          printf( "%s  ->  %s\n", right_node.c_str(), node.c_str() );
        }
      }
    }

    for ( auto& it : net_conn_map )
    {
      if ( wires_on_demand.count( it.first ) > 0 )
      {
        if ( it.second.in.size() == 1 && it.second.out.size() > 1 && it.second.in.begin()->first.compare( 0, 1, "p" ) == 0 )
          it.second.out.erase( *it.second.in.begin() );
        if ( it.second.in.size() == 1 && it.second.out.size() == 1 )
        {
          std::string from = it.second.in.begin()->first, to = it.second.out.begin()->first;
          int bits = it.second.in.begin()->second;
          if ( from != to || from.compare( 0, 1, "p" ) != 0 )
          {
            reader.on_wires( { from } );
            reader.on_wires( { to } );
            std::string lhs = to;
            std::pair<std::string, bool> op1 = std::make_pair( from, false );
            std::vector<std::pair<std::string, bool>> args{ op1 };
            on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs },
                                              /* gate-function params */ std::make_tuple( args, lhs, "buf" ) );
            printf( "%s  ->  %s\n", from.c_str(), to.c_str() );
          }
          continue;
        }
      }
      for ( auto& it2 : it.second.in )
      {
        reader.on_wires( { it2.first.c_str() } );
        reader.on_wires( { it.first.c_str() } );
        std::string lhs = it.first.c_str();
        std::pair<std::string, bool> op1 = std::make_pair( it2.first.c_str(), false );
        std::vector<std::pair<std::string, bool>> args{ op1 };
        on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs },
                                          /* gate-function params */ std::make_tuple( args, lhs, "buf" ) );
        printf( "%s  ->  %s\n", it2.first.c_str(), it.first.c_str() );
      }
      for ( auto& it2 : it.second.out )
      {
        reader.on_wires( { it2.first.c_str() } );
        reader.on_wires( { it.first.c_str() } );
        std::string lhs = it2.first.c_str();
        std::pair<std::string, bool> op1 = std::make_pair( it.first.c_str(), false );
        std::vector<std::pair<std::string, bool>> args{ op1 };
        on_action.call_deferred<GATE_FN>( /* dependencies */ { op1.first }, { lhs },
                                          /* gate-function params */ std::make_tuple( args, lhs, "buf" ) );
        printf( "%s  ->  %s\n", it.first.c_str(), it2.first.c_str() );
      }
    }

    printf( "\nprint is over\n" );

    // check the unconnected nodes/ gates
    const auto& deps = on_action.unresolved_dependencies();
    assert( deps.size() == 0u );

    // create the outputs
    reader.on_endmodule();
  }

  WrapperYosysLogic( RTLIL::Design* design, mockturtle::gtg_network& ntk, mockturtle::read_verilog_params& ports )
      : reader( mockturtle::gtech_reader<mockturtle::gtg_network>( ntk, ports ) ), design( design ),
        on_action( PackedFns( GateFn( [&]( const std::vector<std::pair<std::string, bool>>& inputs,
                                           const std::string output,
                                           const std::string type ) {
                                if ( type == "assign" )
                                {
                                  assert( inputs.size() == 1u );
                                  reader.on_assign( output, inputs[0] );
                                }
                                else if ( type == "zero" )
                                {
                                  assert( inputs.size() == 0u );
                                  reader.on_zero( output );
                                }
                                else if ( type == "one" )
                                {
                                  assert( inputs.size() == 0u );
                                  reader.on_one( output );
                                }
                                else if ( type == "not" )
                                {
                                  assert( inputs.size() == 1u );
                                  reader.on_not( output, inputs[0] );
                                }
                                else if ( type == "inv" )
                                {
                                  assert( inputs.size() == 1u );
                                  reader.on_inv( output, inputs[0] );
                                }
                                else if ( type == "buf" )
                                {
                                  assert( inputs.size() == 1u );
                                  reader.on_buf( output, inputs[0] );
                                }
                                else if ( type == "latch" )
                                {
                                  assert( inputs.size() == 1u );
                                  auto init = lorina::gtech_reader::latch_init_value::NONDETERMINISTIC;
                                  reader.on_latch( output, inputs[0], init );
                                }
                                else if ( type == "and" )
                                {
                                  assert( inputs.size() == 2u );
                                  reader.on_and( output, inputs[0], inputs[1] );
                                }
                                else if ( type == "nand" )
                                {
                                  assert( inputs.size() == 2u );
                                  reader.on_nand( output, inputs[0], inputs[1] );
                                }
                                else if ( type == "or" )
                                {
                                  assert( inputs.size() == 2u );
                                  reader.on_or( output, inputs[0], inputs[1] );
                                }
                                else if ( type == "nor" )
                                {
                                  assert( inputs.size() == 2u );
                                  reader.on_nor( output, inputs[0], inputs[1] );
                                }
                                else if ( type == "xor" )
                                {
                                  assert( inputs.size() == 2u );
                                  reader.on_xor( output, inputs[0], inputs[1] );
                                }
                                else if ( type == "xnor" )
                                {
                                  assert( inputs.size() == 2u );
                                  reader.on_xnor( output, inputs[0], inputs[1] );
                                }
                                else
                                {
                                  assert( false && "unknown gate function" );
                                  std::cerr << "unknown gate function" << std::endl;
                                  std::abort();
                                }
                              } ),
                              ModuleInstFn( [&]( const std::string module_name,
                                                 const std::vector<std::string>& params,
                                                 const std::string instance_name,
                                                 const std::vector<std::pair<std::string, std::string>>& pin_to_pin ) {
                                reader.on_module_instantiation( module_name, params, instance_name, pin_to_pin );
                              } ) ) )
  {
    on_action.declare_known( "0" );
    on_action.declare_known( "1" );
    on_action.declare_known( "1'b0" );
    on_action.declare_known( "1'b1" );
    on_action.declare_known( "1'h0" );
    on_action.declare_known( "1'h1" );

    ct.setup_internals();
    ct.setup_internals_mem();
    ct.setup_internals_anyinit();
    ct.setup_stdcells();
    ct.setup_stdcells_mem();
    ct.setup_design( design );

    design->optimize();
    module = design->top_module();

    reader.on_module_header( module->name.str(), {} );

    if ( design->selected_whole_module( module->name ) )
    {
      if ( module->get_blackbox_attribute() )
      {
        log( "Skipping blackbox module %s.\n", log_id( module->name ) );
      }
      else if ( module->cells().size() == 0 && module->connections().empty() && module->processes.empty() )
      {
        log( "Skipping empty module %s.\n", log_id( module->name ) );
      }
    }

    handle_module();
  }
};

void wrapper_yosys_logic( RTLIL::Design* design, mockturtle::gtg_network& ntk, mockturtle::read_verilog_params& ports )
{
  WrapperYosysLogic worker( design, ntk, ports );
}

} // namespace logic

} // namespace lf