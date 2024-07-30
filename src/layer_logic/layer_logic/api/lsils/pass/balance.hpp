#pragma once

#include "layer_logic/logic_manager.hpp"

#include "mockturtle/algorithms/balancing.hpp"
#include "mockturtle/algorithms/aig_balancing.hpp"
#include "mockturtle/algorithms/xag_balancing.hpp"
#include "mockturtle/algorithms/balancing/sop_balancing.hpp"
#include "mockturtle/algorithms/balancing/utils.hpp"
#include "mockturtle/utils/cost_functions.hpp"

namespace lf
{

namespace logic
{

namespace lsils
{

/**
 * @brief Logic optimization
 * @example
 *  balancing [options]
 *  options: [KCF] [mcpv]
 * @note
 */
template<typename Ntk = aig_seq_network>
void balancing( int K_feasible_cut = -1, int Cut_limit = -1, int Fanin_limit = -1,
                bool is_min_truth = false, bool is_only_critical_path = false, bool is_progress = false, bool is_verbose = false )
{
  using NtkBase = Ntk;
  static_assert( std::is_same_v<NtkBase, aig_seq_network> ||
                     std::is_same_v<NtkBase, xag_seq_network> ||
                     std::is_same_v<NtkBase, mig_seq_network> ||
                     std::is_same_v<NtkBase, xmg_seq_network> ||
                     std::is_same_v<NtkBase, gtg_seq_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, GTG" );

  if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG );
  }
  else if constexpr ( std::is_same_v<Ntk, mig_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xmg_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG );
  }
  else if constexpr ( std::is_same_v<Ntk, gtg_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_GTG );
  }
  else
  {
    std::cerr << "Unhandled network type provided." << std::endl;
    assert( false );
  }

  auto ntk = lfLmINST->current<Ntk>();

  // update the params
  mockturtle::balancing_params ps;
  mockturtle::sop_rebalancing<Ntk> rebalance;
  if ( K_feasible_cut > 0 )
    ps.cut_enumeration_ps.cut_size = K_feasible_cut;
  if ( Cut_limit > 0 )
    ps.cut_enumeration_ps.cut_limit = Cut_limit;
  if ( Fanin_limit > 0 )
    ps.cut_enumeration_ps.fanin_limit = Fanin_limit;
  if ( is_min_truth )
    ps.cut_enumeration_ps.minimize_truth_table = true;
  if ( is_only_critical_path )
    ps.only_on_critical_path = true;
  if ( is_progress )
    ps.progress = true;
  if ( is_verbose )
    ps.verbose = true;

  // balancing
  Ntk ntk_new = mockturtle::balancing<Ntk>( ntk, rebalance, ps );
  // update current network
  lfLmINST->set_current<Ntk>( ntk_new );
}

/**
 * @brief Logic optimization
 * @example
 *  balancing [options]
 *  options: [mf]
 * @note
 */
template<typename Ntk = aig_seq_network>
void balance( bool is_minimize_levels = false, bool is_fast_mode = false )
{
  using NtkBase = Ntk;
  static_assert( std::is_same_v<NtkBase, aig_seq_network> ||
                     std::is_same_v<NtkBase, xag_seq_network>,
                 "NtkSrc is not an AIG, XAG" );

  if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG );
  }
  else if constexpr ( std::is_same_v<Ntk, mig_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xmg_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG );
  }
  else if constexpr ( std::is_same_v<Ntk, gtg_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_GTG );
  }
  else
  {
    std::cerr << "Unhandled network type provided." << std::endl;
    assert( false );
  }

  auto ntk = lfLmINST->current<Ntk>();

  // according to the anchor
  lf::misc::E_LF_ANCHOR stat = lfAnchorINST->get_anchor_curr();
  switch ( stat )
  {
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG:
    if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
    {
      mockturtle::aig_balance( ntk, { is_minimize_levels, is_fast_mode } );
      lfLmINST->set_current<Ntk>( ntk );
    }
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG:
    if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
    {
      mockturtle::xag_balance( ntk, { is_minimize_levels, is_fast_mode } );
      lfLmINST->set_current<Ntk>( ntk );
    }
    break;
  default:
    assert( false );
    break;
  }
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
