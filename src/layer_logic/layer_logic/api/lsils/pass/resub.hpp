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

  mockturtle::default_resubstitution<Ntk>( ntk, ps );
  lfLmINST->set_current<Ntk>( ntk );
}

template<typename Ntk = aig_seq_network>
void resub( int NInputMax = -1, int Max_divisors = -1, int Max_inserts = -1, int fanout_limit_Root = -1, int Fanout_limit_divisor = -1, int Window_size = -1,
            bool is_preserve_depth = false, bool is_dont_cares = false, bool is_progress = false, bool is_verbose = false )
{
  using NtkBase = Ntk;
  static_assert( std::is_same_v<NtkBase, aig_seq_network> ||
                     std::is_same_v<NtkBase, xag_seq_network> ||
                     std::is_same_v<NtkBase, mig_seq_network> ||
                     std::is_same_v<NtkBase, xmg_seq_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG" );

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

  // according to the anchor
  lf::misc::E_LF_ANCHOR stat = lfAnchorINST->get_anchor_curr();

  switch ( stat )
  {
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG:
    if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
    {
      mockturtle::aig_resubstitution( ntk, ps );
      lfLmINST->set_current<Ntk>( ntk );
    }
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG:
    if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
    {
      mockturtle::resubstitution_minmc_withDC( ntk, ps );
      lfLmINST->set_current<Ntk>( ntk );
    }
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG:
    if constexpr ( std::is_same_v<Ntk, mig_seq_network> )
    {
      mockturtle::mig_resubstitution( ntk, ps );
      lfLmINST->set_current<Ntk>( ntk );
    }
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG:
    if constexpr ( std::is_same_v<Ntk, xmg_seq_network> )
    {
      mockturtle::xmg_resubstitution( ntk, ps );
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
