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
void balancing( int K_feasible_cut = -1, int Cut_limit = -1, int Fanin_limit = -1,
                bool is_min_truth = false, bool is_only_critical_path = false, bool is_progress = false, bool is_verbose = false )
{
  printf("balance\n");
  mockturtle::balancing_params ps;
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

  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG );

  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();

    mockturtle::sop_rebalancing<lf::logic::lsils::aig_seq_network> rebalance;
    lf::logic::lsils::aig_seq_network ntk_new = mockturtle::balancing<lf::logic::lsils::aig_seq_network>( ntk, rebalance, ps );

    lfLmINST->set_current<lf::logic::lsils::aig_seq_network>( ntk_new );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();

    mockturtle::sop_rebalancing<lf::logic::lsils::xag_seq_network> rebalance;
    lf::logic::lsils::xag_seq_network ntk_new = mockturtle::balancing<lf::logic::lsils::xag_seq_network>( ntk, rebalance, ps );

    lfLmINST->set_current<lf::logic::lsils::xag_seq_network>( ntk_new );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();

    mockturtle::sop_rebalancing<lf::logic::lsils::xmg_seq_network> rebalance;
    lf::logic::lsils::xmg_seq_network ntk_new = mockturtle::balancing<lf::logic::lsils::xmg_seq_network>( ntk, rebalance, ps );

    lfLmINST->set_current<lf::logic::lsils::xmg_seq_network>( ntk_new );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();

    mockturtle::sop_rebalancing<lf::logic::lsils::mig_seq_network> rebalance;
    lf::logic::lsils::mig_seq_network ntk_new = mockturtle::balancing<lf::logic::lsils::mig_seq_network>( ntk, rebalance, ps );

    lfLmINST->set_current<lf::logic::lsils::mig_seq_network>( ntk_new );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG )
  {
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();

    mockturtle::sop_rebalancing<lf::logic::lsils::gtg_seq_network> rebalance;
    lf::logic::lsils::gtg_seq_network ntk_new = mockturtle::balancing<lf::logic::lsils::gtg_seq_network>( ntk, rebalance, ps );

    lfLmINST->set_current<lf::logic::lsils::gtg_seq_network>( ntk_new );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }
}

/**
 * @brief Logic optimization
 * @example
 *  balancing [options]
 *  options: [mf]
 * @note
 */
void balance( bool is_minimize_levels = false, bool is_fast_mode = false )
{
  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG );

  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();

    mockturtle::aig_balance( ntk, { is_minimize_levels, is_fast_mode } );

    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();

    mockturtle::xag_balance( ntk, { is_minimize_levels, is_fast_mode } );

    lfLmINST->set_current( ntk );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
