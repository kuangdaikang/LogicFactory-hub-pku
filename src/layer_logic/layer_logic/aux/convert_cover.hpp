#pragma once

#include "layer_logic/logic_manager.hpp"

#include "lorina/genlib.hpp"
#include "mockturtle/io/genlib_reader.hpp"

#include "utility/string.hpp"

#include <cstring>
#include <vector>

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
                     std::is_same_v<NtkSrc, lsils::xag_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::mig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xmg_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::gtg_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::primary_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::aig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xag_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::mig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xmg_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::gtg_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::primary_seq_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, Primary, or GTG" );
  static_assert( std::is_same_v<NtkDest, lsils::aig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xag_comb_network> ||
                     std::is_same_v<NtkDest, lsils::mig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xmg_comb_network> ||
                     std::is_same_v<NtkDest, lsils::gtg_comb_network> ||
                     std::is_same_v<NtkDest, lsils::primary_comb_network> ||
                     std::is_same_v<NtkDest, lsils::aig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xag_seq_network> ||
                     std::is_same_v<NtkDest, lsils::mig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xmg_seq_network> ||
                     std::is_same_v<NtkDest, lsils::gtg_seq_network> ||
                     std::is_same_v<NtkDest, lsils::primary_seq_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, Primary, or GTG" );

  NtkDest ntk_dest;
  using DNode = typename NtkDest::node;
  using DSignal = typename NtkDest::signal;
  using SNode = typename lsils::blut_seq_network::node;
  using SSignal = typename lsils::blut_seq_network::signal;
  std::unordered_map<SNode, DNode> old_2_new;

  // load genlib file
  std::string genlib_buffer = R"(
        GATE   zero   0  O=CONST0;
        GATE   one    0  O=CONST1;
        GATE   buf    1  O=a;                                    PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   not    1  O=!a;                                   PIN * INV 1 999 0.9 0.3 0.9 0.3
    )";
  if constexpr ( std::is_same_v<NtkDest, lsils::aig_seq_network> )
  {
    genlib_buffer += R"(
        GATE   and2   6  O=a*b;                                  PIN * NONINV 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::xag_seq_network> )
  {
    genlib_buffer += R"(
        GATE   and2   6  O=a*b;                                  PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   xor2   6  O=a*!b+!a*b;                            PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::mig_seq_network> )
  {
    genlib_buffer += R"(
        GATE   maj3   12 O=a*b + a*c + b*c;                      PIN * NONINV 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::xmg_seq_network> )
  {
    genlib_buffer += R"(
        GATE   maj3   12 O=a*b + a*c + b*c;                      PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   xor3   16 O=a*!b*!c + !a*b*!c + !a*!b*c + a*b*c;  PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::primary_seq_network> )
  {
    genlib_buffer += R"(
        GATE   and2   6  O=a*b;                                  PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   nand2  6  O=!(a*b);                               PIN * INV 1 999 1.0 0.0 1.0 0.0
        GATE   or2    6  O=a+b;                                  PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   nor2   6  O=!(a+b);                               PIN * INV 1 999 1.0 0.0 1.0 0.0
        GATE   xor2   6  O=a*!b+!a*b;                            PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   xnor2  6  O=a*b+!a*!b;                            PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
    )";
  }
  else if constexpr ( std::is_same_v<NtkDest, lsils::gtg_seq_network> )
  {
    genlib_buffer += R"(
        GATE   and2   6  O=a*b;                                  PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   nand2  6  O=!(a*b);                               PIN * INV 1 999 1.0 0.0 1.0 0.0
        GATE   or2    6  O=a+b;                                  PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   nor2   6  O=!(a+b);                               PIN * INV 1 999 1.0 0.0 1.0 0.0
        GATE   xor2   6  O=a*!b+!a*b;                            PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   xnor2  6  O=a*b+!a*!b;                            PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   maj3   12 O=a*b + a*c + b*c;                      PIN * NONINV 1 999 1.0 0.0 1.0 0.0
        GATE   mux    12 O=a*b + a*!c + b*c;                     PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
        GATE   xor3   16 O=a*!b*!c + !a*b*!c + !a*!b*c + a*b*c;  PIN * UNKNOWN 1 999 1.0 0.0 1.0 0.0
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
  else if constexpr ( std::is_same_v<NtkSrc, lsils::xag_seq_network> )
  {
    netlist_asic = mockturtle::seq_map<lf::logic::lsils::xag_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk_src, techlib, ps );
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
  old_2_new[netlist_asic.get_node( c_zero )] = ntk_dest.get_node( d_zero );
  if ( c_zero != c_one )
  {
    old_2_new[netlist_asic.get_node( c_one )] = ntk_dest.get_node( d_one );
  }
  /// inputs
  netlist_asic.foreach_pi( [&]( auto const& pi ) {
    old_2_new[pi] = ntk_dest.get_node( ntk_dest.create_pi() );
  } );

  netlist_asic.foreach_gate( [&]( auto const& g, uint32_t index ) {
    std::vector<SSignal> children;
    netlist_asic.foreach_fanin( g, [&]( auto const& c ) {
      children.push_back( c );
    } );
    auto new_c0 = DSignal( old_2_new[netlist_asic.get_node( children[0] )], netlist_asic.is_complemented( children[0] ) ? 1 : 0 );
    auto new_c1 = DSignal( old_2_new[netlist_asic.get_node( children[1] )], netlist_asic.is_complemented( children[1] ) ? 1 : 0 );

    assert( netlist_asic.has_binding( g ) );
    auto gate = netlist_asic.get_binding( g );

    if ( gate.name == "not" )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_not( new_c0 ) );
    }
    else if ( gate.name == "buf" )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_buf( new_c0 ) );
    }
    else if ( gate.name == "and2" )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_and( new_c0, new_c1 ) );
    }
    else if ( gate.name == "nand2" )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_nand( new_c0, new_c1 ) );
    }
    else if ( gate.name == "or2" )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_or( new_c0, new_c1 ) );
    }
    else if ( gate.name == "nor2" )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_nor( new_c0, new_c1 ) );
    }
    else if ( gate.name == "xor2" )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_xor( new_c0, new_c1 ) );
    }
    else if ( gate.name == "xnor2" )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_xnor( new_c0, new_c1 ) );
    }
    else if ( gate.name == "maj3" )
    {
      auto new_c2 = DSignal( old_2_new[netlist_asic.get_node( children[2] )], netlist_asic.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_maj( new_c0, new_c1, new_c2 ) );
    }
    else if ( gate.name == "mux" )
    {
      auto new_c2 = DSignal( old_2_new[netlist_asic.get_node( children[2] )], netlist_asic.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_ite( new_c0, new_c1, new_c2 ) );
    }
    else if ( gate.name == "xor3" )
    {
      auto new_c2 = DSignal( old_2_new[netlist_asic.get_node( children[2] )], netlist_asic.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_xor3( new_c0, new_c1, new_c2 ) );
    }
    else
    {
      std::cerr << "Unsupported gate: " << gate.name << std::endl;
      assert( false );
    }
  } );

  /// outputs
  netlist_asic.foreach_po( [&]( auto const& po ) {
    auto new_po = DSignal( old_2_new[netlist_asic.get_node( po )], netlist_asic.is_complemented( po ) ? 1 : 0 );
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
  assert( from == "abc" || from == "aig" || from == "xag" || from == "mig" || from == "xmg" || from == "primary" || from == "gtg" );
  assert( to == "abc" || to == "aig" || to == "xag" || to == "mig" || to == "xmg" || to == "primary" || to == "gtg" );

  if ( from == "abc" || to == "abc" )
  {
    std::cerr << "abc is not supported yet" << std::endl;
    return;
  }
  if ( from == to )
    return;
  if ( from == "aig" )
  {
    lf::logic::lsils::aig_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::aig_seq_network>();
    if ( to == "aig" )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xag" )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "mig" )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xmg" )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "primary" )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::aig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "gtg" )
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
  else if ( from == "xag" )
  {
    lf::logic::lsils::xag_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::xag_seq_network>();
    if ( to == "aig" )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xag" )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "mig" )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xmg" )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "primary" )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::xag_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "gtg" )
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
  else if ( from == "mig" )
  {
    lf::logic::lsils::mig_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::mig_seq_network>();
    if ( to == "aig" )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xag" )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "mig" )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xmg" )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "primary" )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::mig_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "gtg" )
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
  else if ( from == "xmg" )
  {
    lf::logic::lsils::xmg_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();
    if ( to == "aig" )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xag" )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "mig" )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xmg" )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "primary" )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::xmg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "gtg" )
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
  else if ( from == "primary" )
  {
    lf::logic::lsils::primary_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::primary_seq_network>();
    if ( to == "aig" )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xag" )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "mig" )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xmg" )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "primary" )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::primary_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "gtg" )
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
  else if ( from == "gtg" )
  {
    lf::logic::lsils::gtg_seq_network ntk_from = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();
    if ( to == "aig" )
    {
      lf::logic::lsils::aig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::aig_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xag" )
    {
      lf::logic::lsils::xag_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xag_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "mig" )
    {
      lf::logic::lsils::mig_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::mig_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "xmg" )
    {
      lf::logic::lsils::xmg_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::xmg_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "primary" )
    {
      lf::logic::lsils::primary_seq_network ntk_to = lf::logic::convert_cover<lf::logic::lsils::primary_seq_network, lf::logic::lsils::gtg_seq_network>( ntk_from );
      lfLmINST->set_current( ntk_to );
    }
    else if ( to == "gtg" )
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