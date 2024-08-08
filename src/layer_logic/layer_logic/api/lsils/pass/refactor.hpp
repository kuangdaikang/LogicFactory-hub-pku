#pragma once

#include "layer_logic/logic_manager.hpp"
#include "mockturtle/algorithms/node_resynthesis/sop_factoring.hpp"
#include "mockturtle/algorithms/node_resynthesis/akers.hpp"

namespace lf
{

namespace logic
{

namespace lsils
{

/**
 * @brief Logic optimization
 * @example
 *  refactor [options]
 *  options: [P] [zrdpv]
 * @note
 */
void refactor( int Max_pis = -1,
               bool is_zero_cost = false, bool is_reconvergence_cut = false, bool is_dont_cares = false, bool is_progress = false, bool is_verbose = false )
{
  mockturtle::refactoring_params ps;
  if ( Max_pis > 0 )
    ps.max_pis = Max_pis;
  if ( is_zero_cost )
    ps.allow_zero_gain = true;
  if ( is_reconvergence_cut )
    ps.use_reconvergence_cut = true;
  if ( is_dont_cares )
    ps.use_dont_cares = true;
  if ( is_progress )
    ps.progress = true;
  if ( is_verbose )
    ps.verbose = true;

  auto ntktype = lfLntINST->get_ntktype_curr();
  lfLmINST->update_logic( ntktype );
  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();

    mockturtle::sop_factoring<lf::logic::lsils::aig_seq_network> refactoring_fn;
    mockturtle::refactoring( ntk, refactoring_fn, ps );

    lfLmINST->set_current<lf::logic::lsils::aig_seq_network>( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();

    mockturtle::sop_factoring<lf::logic::lsils::xag_seq_network> refactoring_fn;
    mockturtle::refactoring( ntk, refactoring_fn, ps );

    lfLmINST->set_current<lf::logic::lsils::xag_seq_network>( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();

    mockturtle::sop_factoring<lf::logic::lsils::xmg_seq_network> refactoring_fn;
    mockturtle::refactoring( ntk, refactoring_fn, ps );

    lfLmINST->set_current<lf::logic::lsils::xmg_seq_network>( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();

    mockturtle::sop_factoring<lf::logic::lsils::mig_seq_network> refactoring_fn;
    mockturtle::refactoring( ntk, refactoring_fn, ps );

    lfLmINST->set_current<lf::logic::lsils::mig_seq_network>( ntk );
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
