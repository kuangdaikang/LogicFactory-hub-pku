#pragma once

#include "layer_logic/logic_manager.hpp"
#include "layer_logic/aux/type_map.hpp"

#include "lorina/genlib.hpp"
#include "mockturtle/io/genlib_reader.hpp"

#include "utility/string.hpp"

#include <cstring>
#include <vector>
#include <unordered_map>

namespace lf
{

namespace logic
{
/**
 * @brief network transformation by cover
 */
template<class NtkDest, class NtkSrc>
NtkDest convert_cover( const NtkSrc& ntk_src )
{
  static_assert( std::is_same_v<NtkSrc, lsils::aig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::oig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::aog_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xag_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xog_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::mig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xmg_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::gtg_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::primary_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::aig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::oig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::aog_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xag_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xog_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::mig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xmg_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::gtg_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::primary_seq_network>,
                 "NtkSrc is not an AIG, OIG, AOG, XAG, XOG, MIG, XMG, Primary, or GTG" );
  static_assert( std::is_same_v<NtkDest, lsils::aig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::oig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::aog_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xag_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xog_comb_network> ||
                     std::is_same_v<NtkDest, lsils::mig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xmg_comb_network> ||
                     std::is_same_v<NtkDest, lsils::gtg_comb_network> ||
                     std::is_same_v<NtkDest, lsils::primary_comb_network> ||
                     std::is_same_v<NtkDest, lsils::aig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::oig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::aog_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xag_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xog_seq_network> ||
                     std::is_same_v<NtkDest, lsils::mig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xmg_seq_network> ||
                     std::is_same_v<NtkDest, lsils::gtg_seq_network> ||
                     std::is_same_v<NtkDest, lsils::primary_seq_network>,
                 "NtkDest is not an AIG, OIG, AOG, XAG, XOG, MIG, XMG, Primary, or GTG" );

  NtkDest ntk_dest;
  using DNode = typename NtkDest::node;
  using DSignal = typename NtkDest::signal;
  using SNode = typename lsils::blut_seq_network::node;
  using SSignal = typename lsils::blut_seq_network::signal;
  std::unordered_map<SNode, DSignal> old_2_new;

  // load genlib file
  std::string genlib_buffer = R"(
        GATE   zero   5  O=CONST0;
        GATE   one    5  O=CONST1;
        GATE   buf    4  O=a;                            PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   not    4  O=!a;                           PIN * INV 1 999 1.0 0.0 1.0 0.0
    )";
  if constexpr ( std::is_same_v<NtkDest, lsils::aig_seq_network> )
  {
    genlib_buffer += R"(
        GATE   and2   3  O=a*b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
    )";
  }
  if constexpr ( std::is_same_v<NtkDest, lsils::oig_seq_network> )
  {
    genlib_buffer += R"(
        GATE   or2    3  O=a+b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
    )";
  }
  if constexpr ( std::is_same_v<NtkDest, lsils::aog_seq_network> )
  {
    genlib_buffer += R"(
        GATE   and2   3  O=a*b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   or2    3  O=a+b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::xag_seq_network> )
  {
    genlib_buffer += R"(
        GATE   and2   3  O=a*b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   xor2   3  O=a^b;                          PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::xog_seq_network> )
  {
    genlib_buffer += R"(
        GATE   or2    3  O=a+b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   xor2   3  O=a^b;                          PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::mig_seq_network> )
  {
    genlib_buffer += R"(
        GATE   maj3   2  O=(a*b)+(a*c)+(b*c);            PIN * NONINV 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::xmg_seq_network> )
  {
    genlib_buffer += R"(
        GATE   maj3   2  O=(a*b)+(a*c)+(b*c);            PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   xor3   2  O=a^b^c;                        PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::primary_seq_network> )
  {
    genlib_buffer += R"(
        GATE   and2   3  O=a*b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   nand2  3  O=!(a*b);                       PIN * INV 1 999 1.0 0.0 1.0 0.0
        GATE   or2    3  O=a+b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   nor2   3  O=!(a+b);                       PIN * INV 1 999 1.0 0.0 1.0 0.0
        GATE   xor2   3  O=a^b;                          PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   xnor2  3  O=!(a^b);                       PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::gtg_seq_network> )
  {
    genlib_buffer += R"(
        GATE   and2   3  O=a*b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   nand2  3  O=!(a*b);                       PIN * INV 1 999 1.0 0.0 1.0 0.0
        GATE   or2    3  O=a+b;                          PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   nor2   3  O=!(a+b);                       PIN * INV 1 999 1.0 0.0 1.0 0.0
        GATE   xor2   3  O=a^b;                          PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   xnor2  3  O=!(a^b);                       PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   mux21  2  O=a*b+a*!c+b*c;                 PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   nmux21 2  O=!((a*b)+(a*!c)+(b*c));        PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   nand3  2  O=!(a*b*c);                     PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   nor3   2  O=!(a+b+c);                     PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   aoi21  1  O=!((a*b)+c);                   PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   oai21  1  O=!((a+b)*c);                   PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   axi21  1  O=!((a*b)^c);                   PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   xai21  1  O=!((a^b)*c);                   PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   oxi21  1  O=!((a+b)^c);                   PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   xoi21  1  O=!((a^b)+c);                   PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else
  {
    std::cerr << "Unsupported network type" << std::endl;
    assert( false );
    return ntk_dest;
  }

  std::istringstream iss( genlib_buffer );
  lsils::lib_gates gates;
  lorina::read_genlib( iss, mockturtle::genlib_reader( gates ) );

  // cover by technology mapping
  mockturtle::map_params ps;
  lsils::lib_techlib_np techlib( gates );
  lsils::blut_seq_network netlist_asic;

  if constexpr ( std::is_same_v<NtkSrc, lsils::aig_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::aig_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
  }
  else if constexpr ( std::is_same_v<NtkSrc, lsils::oig_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::oig_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
  }
  else if constexpr ( std::is_same_v<NtkSrc, lsils::aog_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::aog_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
  }
  else if constexpr ( std::is_same_v<NtkSrc, lsils::xag_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::xag_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
  }
  else if constexpr ( std::is_same_v<NtkSrc, lsils::xog_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::xog_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
  }
  else if constexpr ( std::is_same_v<NtkSrc, lsils::mig_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::mig_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
  }
  else if constexpr ( std::is_same_v<NtkSrc, lsils::xmg_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::xmg_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
  }
  else if constexpr ( std::is_same_v<NtkSrc, lsils::primary_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::primary_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
  }
  else if constexpr ( std::is_same_v<NtkSrc, lsils::gtg_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::gtg_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
  }
  else
  {
    std::cerr << "Unsupported network type" << std::endl;
    assert( false );
  }

  // transformation
  /// constant
  auto d_zero = ntk_dest.get_constant( false );
  auto d_one = ntk_dest.get_constant( true );
  auto c_zero = netlist_asic.get_constant( false );
  auto c_one = netlist_asic.get_constant( true );
  old_2_new[netlist_asic.get_node( c_zero )] = d_zero;
  if ( c_zero != c_one )
  {
    old_2_new[netlist_asic.get_node( c_one )] = d_one;
  }
  /// inputs
  netlist_asic.foreach_pi( [&]( auto const& pi ) {
    old_2_new[pi] = ntk_dest.create_pi();
  } );

  netlist_asic.foreach_gate( [&]( auto const& g, uint32_t index ) {
    std::vector<SSignal> children;
    netlist_asic.foreach_fanin( g, [&]( auto const& c ) {
      children.push_back( c );
    } );
    auto new_c0 = old_2_new[netlist_asic.get_node( children[0] )];
    auto new_c1 = old_2_new[netlist_asic.get_node( children[1] )];

    assert( netlist_asic.has_binding( g ) );
    auto gate = netlist_asic.get_binding( g );

    auto gate_iter = GATE_TYPE_MAP.find( gate.name );
    if ( gate_iter == GATE_TYPE_MAP.end() )
    {
      std::cerr << "Unsupported gate type: " << gate.name << std::endl;
      assert( false );
      return;
    }
    switch ( gate_iter->second )
    {
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_NOT:
    {
      auto new_sig = ntk_dest.create_not( new_c0 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_BUF:
    {
      auto new_sig = ntk_dest.create_buf( new_c0 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_AND2:
    {
      auto new_sig = ntk_dest.create_and( new_c0, new_c1 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_NAND2:
    {
      auto new_sig = ntk_dest.create_nand( new_c0, new_c1 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_OR2:
    {
      auto new_sig = ntk_dest.create_or( new_c0, new_c1 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_NOR2:
    {
      auto new_sig = ntk_dest.create_nor( new_c0, new_c1 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_XOR2:
    {
      auto new_sig = ntk_dest.create_xor( new_c0, new_c1 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_XNOR2:
    {
      auto new_sig = ntk_dest.create_xnor( new_c0, new_c1 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_MAJ3:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_maj( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_XOR3:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_xor3( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_NAND3:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_nand3( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_NOR3:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_nor3( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_MUX21:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_mux21( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_NMUX21:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_nmux21( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_AOI21:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_aoi21( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_OAI21:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_oai21( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_AXI21:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_axi21( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_XAI21:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_xai21( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_OXI21:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_oxi21( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    case E_LF_GATE_TYPE::E_LF_GATE_TYPE_XOI21:
    {
      auto new_c2 = old_2_new[netlist_asic.get_node( children[2] )];
      auto new_sig = ntk_dest.create_xoi21( new_c0, new_c1, new_c2 );
      old_2_new[g] = new_sig;
      break;
    }
    default:
    {
      std::cerr << "Unsupported gate: " << gate.name << std::endl;
      assert( false );
      break;
    }
    }
  } );

  /// outputs
  netlist_asic.foreach_po( [&]( auto const& po ) {
    auto new_po = old_2_new[netlist_asic.get_node( po )];
    ntk_dest.create_po( new_po );
  } );

  return ntk_dest;
}

/**
 * @brief convert the current type to another type without change the ntktype
 * @param from
 * @param to
 * @note this function is implemented the cover algorithm
 */
void convert_cover( const std::string& from, const std::string& to )
{
  auto from_iter = CONVERT_TYPE_MAP.find( from );
  auto to_iter = CONVERT_TYPE_MAP.find( to );
  if ( from_iter == CONVERT_TYPE_MAP.end() || from_iter == CONVERT_TYPE_MAP.end() )
  {
    std::cerr << "Invalid type: " << from << " or " << to << std::endl;
    return;
  }

  auto from_type = from_iter->second;
  auto to_type = to_iter->second;
  if ( from_type == to_type )
  {
    std::cerr << "The type is the same, no need to convert" << std::endl;
    return;
  }

  if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_ABC || to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_ABC )
  {
    std::cerr << "abc is not supported yet" << std::endl;
    return;
  }

  if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::aig_seq_network>();
    if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    {
      lf::logic::lsils::oig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::oig_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    {
      lf::logic::lsils::aog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aog_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    {
      lf::logic::lsils::xog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xog_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    {
      lf::logic::lsils::gtg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::gtg_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else
    {
      std::cerr << "Unsupported target: " << to << std::endl;
      assert( false );
    }
  }
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
  {
    lf::logic::lsils::oig_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::oig_seq_network>();
    if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::oig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    {
      lf::logic::lsils::oig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::oig_seq_network, lf::logic::lsils::oig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    {
      lf::logic::lsils::aog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aog_seq_network, lf::logic::lsils::oig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::oig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    {
      lf::logic::lsils::xog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xog_seq_network, lf::logic::lsils::oig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::oig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::oig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::oig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    {
      lf::logic::lsils::gtg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::gtg_seq_network, lf::logic::lsils::oig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else
    {
      std::cerr << "Unsupported target: " << to << std::endl;
      assert( false );
    }
  }
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
  {
    lf::logic::lsils::aog_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::aog_seq_network>();
    if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::aog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    {
      lf::logic::lsils::oig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::oig_seq_network, lf::logic::lsils::aog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    {
      lf::logic::lsils::aog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aog_seq_network, lf::logic::lsils::aog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::aog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    {
      lf::logic::lsils::xog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xog_seq_network, lf::logic::lsils::aog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::aog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::aog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::aog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    {
      lf::logic::lsils::gtg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::gtg_seq_network, lf::logic::lsils::aog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else
    {
      std::cerr << "Unsupported target: " << to << std::endl;
      assert( false );
    }
  }
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::xag_seq_network>();
    if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    {
      lf::logic::lsils::oig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::oig_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    {
      lf::logic::lsils::aog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aog_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    {
      lf::logic::lsils::xog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xog_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    {
      lf::logic::lsils::gtg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::gtg_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else
    {
      std::cerr << "Unsupported target: " << to << std::endl;
      assert( false );
    }
  }
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
  {
    lf::logic::lsils::xog_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::xog_seq_network>();
    if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::xog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    {
      lf::logic::lsils::oig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::oig_seq_network, lf::logic::lsils::xog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    {
      lf::logic::lsils::aog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aog_seq_network, lf::logic::lsils::xog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::xog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    {
      lf::logic::lsils::xog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xog_seq_network, lf::logic::lsils::xog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::xog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::xog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::xog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    {
      lf::logic::lsils::gtg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::gtg_seq_network, lf::logic::lsils::xog_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else
    {
      std::cerr << "Unsupported target: " << to << std::endl;
      assert( false );
    }
  }
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::mig_seq_network>();
    if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    {
      lf::logic::lsils::oig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::oig_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    {
      lf::logic::lsils::aog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aog_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    {
      lf::logic::lsils::xog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xog_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    {
      lf::logic::lsils::gtg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::gtg_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else
    {
      std::cerr << "Unsupported target: " << to << std::endl;
      assert( false );
    }
  }
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();
    if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    {
      lf::logic::lsils::oig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::oig_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    {
      lf::logic::lsils::aog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aog_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    {
      lf::logic::lsils::xog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xog_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    {
      lf::logic::lsils::gtg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::gtg_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else
    {
      std::cerr << "Unsupported target: " << to << std::endl;
      assert( false );
    }
  }
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
  {
    lf::logic::lsils::primary_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::primary_seq_network>();
    if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    {
      lf::logic::lsils::oig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::oig_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    {
      lf::logic::lsils::aog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aog_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    {
      lf::logic::lsils::xog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xog_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    {
      lf::logic::lsils::gtg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::gtg_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else
    {
      std::cerr << "Unsupported target: " << to << std::endl;
      assert( false );
    }
  }
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
  {
    lf::logic::lsils::gtg_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();
    if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    {
      lf::logic::lsils::oig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::oig_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    {
      lf::logic::lsils::aog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aog_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    {
      lf::logic::lsils::xog_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xog_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    {
      lf::logic::lsils::gtg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::gtg_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else
    {
      std::cerr << "Unsupported target: " << to << std::endl;
      assert( false );
    }
  }
  else
  {
    std::cerr << "Unsupported target: " << from << std::endl;
    assert( false );
  }
}
} // namespace logic

} // namespace lf