#pragma once

#include "layer_logic/logic_manager.hpp"

namespace lf
{

namespace logic
{

namespace lsils
{

/**
 * @brief Logic optimization
 * @example
 *  resubing [options]
 *  options: [PDIRFW] [ldpv]
 * @note
 */
template<typename Ntk = aig_seq_network>
void resubing( int NInputMax = -1, int Max_divisors = -1, int Max_inserts = -1, int fanout_limib_Root = -1, int Fanout_limit_divisor = -1, int Window_size = -1,
               bool is_preserve_depth = false, bool is_dont_cares = false, bool is_progress = false, bool is_verbose = false )
{
  // update the params
  mockturtle::resubstitution_params ps;
  if ( NInputMax > 0 )
    ps.max_pis = NInputMax;
  if ( Max_divisors > 0 )
    ps.max_divisors = Max_divisors;
  if ( Max_inserts > 0 )
    ps.max_inserts = Max_inserts;
  if ( fanout_limib_Root > 0 )
    ps.skip_fanout_limit_for_roots = fanout_limib_Root;
  if ( Fanout_limit_divisor > 0 )
    ps.skip_fanout_limit_for_divisors = Fanout_limit_divisor;
  if ( Window_size > 0 )
    ps.window_size = Window_size;
  if ( is_preserve_depth )
    ps.preserve_depth = true;
  if ( is_dont_cares )
    ps.use_dont_cares = true;
  if ( is_progress )
    ps.progress = true;
  if ( is_verbose )
    ps.verbose = true;

  auto ntktype = lfLntINST->get_nkt_type();
  if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_AIG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG );
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();

    mockturtle::default_resubstitution( ntk, ps );

    lfLmINST->set_current<lf::logic::lsils::aig_seq_network>( ntk );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_XAG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG );
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();

    mockturtle::default_resubstitution( ntk, ps );

    lfLmINST->set_current<lf::logic::lsils::xag_seq_network>( ntk );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_XMG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG );
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();

    mockturtle::default_resubstitution( ntk, ps );

    lfLmINST->set_current<lf::logic::lsils::xmg_seq_network>( ntk );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_MIG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG );
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();

    mockturtle::default_resubstitution( ntk, ps );

    lfLmINST->set_current<lf::logic::lsils::mig_seq_network>( ntk );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_GTG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_GTG );
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();

    mockturtle::default_resubstitution( ntk, ps );

    lfLmINST->set_current<lf::logic::lsils::gtg_seq_network>( ntk );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }
}

template<typename Ntk = aig_seq_network>
void resub( int NInputMax = -1, int Max_divisors = -1, int Max_inserts = -1, int fanout_limit_Root = -1, int Fanout_limit_divisor = -1, int Window_size = -1,
            bool is_preserve_depth = false, bool is_dont_cares = false, bool is_progress = false, bool is_verbose = false )
{
  mockturtle::resubstitution_params ps;
  if ( NInputMax > 0 )
    ps.max_pis = NInputMax;
  if ( Max_divisors > 0 )
    ps.max_divisors = Max_divisors;
  if ( Max_inserts > 0 )
    ps.max_inserts = Max_inserts;
  if ( fanout_limit_Root > 0 )
    ps.skip_fanout_limit_for_roots = fanout_limit_Root;
  if ( Fanout_limit_divisor > 0 )
    ps.skip_fanout_limit_for_divisors = Fanout_limit_divisor;
  if ( Window_size > 0 )
    ps.window_size = Window_size;
  if ( is_preserve_depth )
    ps.preserve_depth = true;
  if ( is_dont_cares )
    ps.use_dont_cares = true;
  if ( is_progress )
    ps.progress = true;
  if ( is_verbose )
    ps.verbose = true;

  auto ntktype = lfLntINST->get_nkt_type();
  if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_AIG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG );
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();

    mockturtle::aig_resubstitution( ntk, ps );
    lfLmINST->set_current( ntk );

    lfLmINST->set_current<lf::logic::lsils::aig_seq_network>( ntk );
  }
  // else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_XAG )
  // {
  //   lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG );
  //   lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();

  //   mockturtle::resubstitution_minmc_withDC( ntk, ps );
  //   lfLmINST->set_current( ntk );

  //   lfLmINST->set_current<lf::logic::lsils::xag_seq_network>( ntk );
  // }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_XMG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG );
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();

    mockturtle::xmg_resubstitution( ntk, ps );
    lfLmINST->set_current( ntk );

    lfLmINST->set_current<lf::logic::lsils::xmg_seq_network>( ntk );
  }
  // else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_MIG )
  // {
  //   lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG );
  //   lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();

  //   mockturtle::mig_resubstitution( ntk, ps );
  //   lfLmINST->set_current( ntk );

  //   lfLmINST->set_current<lf::logic::lsils::mig_seq_network>( ntk );
  // }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
