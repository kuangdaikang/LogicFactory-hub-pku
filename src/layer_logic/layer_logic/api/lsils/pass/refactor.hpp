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
 *  refactor [options]
 *  options: [P] [zrdpv]
 * @note
 */
template<class Ntk>
void refactor( int Max_pis = -1,
               bool is_zero_cost = false, bool is_reconvergence_cut = false, bool is_dont_cares = false, bool is_progress = false, bool is_verbose = false )
{
  using NtkBase = typename Ntk::base_type;
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
  mockturtle::sop_factoring<Ntk> refactoring_fn;
  mockturtle::refactoring_params ps;
  if ( Max_pis > 0 )
    ps.max_pis = Max_pis;
  if ( is_zero_cost )
    ps.allow_zero_gain = true;
  if ( use_reconvergence_cut )
    ps.use_reconvergence_cut = true;
  if ( use_dont_cares )
    ps.use_dont_cares = true;
  if ( is_process )
    ps.progress = true;
  if ( is_verbose )
    ps.verbose = true;

  // refactoring
  mockturtle::refactoring<Ntk, mockturtle::sop_factoring<Ntk>>( ntk, refactoring_fn, ps );
  // update current network
  lfLmINST->set_current<Ntk>( ntk );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
