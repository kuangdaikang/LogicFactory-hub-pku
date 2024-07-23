#pragma once

#include "layer_logic/logic_manager.hpp"

#include "mockturtle/algorithms/cut_rewriting.hpp"
#include "mockturtle/algorithms/node_resynthesis/xag_npn.hpp"

namespace lf
{

namespace logic
{

namespace lsils
{

/**
 * @brief Logic optimization
 * @example
 *  rewrite [options]
 *  options: [KCM] [mzlcpvw]
 * @note
 */
template<class Ntk>
void rewrite( int K_feasible_cut = -1, int Cut_limit = -1, int Min_cand_cut_size = -1,
              bool is_min_truth = false, bool is_zero_gain, bool is_preserve_depth = false, bool is_dont_cares = false, bool is_progress = false, bool is_verbose = false, bool is_very_verbose = false )
{
  using NtkBase = typename Ntk::base_type;
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

  mockturtle::cut_rewriting_params ps;
  if ( K_feasible_cut > 0 )
    ps.cut_enumeration_ps.cut_size = K_feasible_cut;
  if ( Cut_limit > 0 )
    ps.cut_enumeration_ps.cut_limit = Cut_limit;
  if ( is_min_truth )
    ps.cut_enumeration_ps.minimize_truth_table = is_min_truth;
  if ( Min_cand_cut_size > 0 )
    ps.min_cand_cut_size = Min_cand_cut_size;
  if ( is_zero_gain )
    ps.allow_zero_gain = is_zero_gain;
  if ( is_preserve_depth )
    ps.preserve_depth = is_preserve_depth;
  if ( is_dont_cares )
    ps.use_dont_cares = is_dont_cares;
  if ( is_progress )
    ps.progress = is_progress;
  if ( is_verbose )
    ps.verbose = is_verbose;
  if ( is_very_verbose )
    ps.very_verbose = is_very_verbose;

  auto ntk = lfLmINST->current<Ntk>();

  // according to the anchor
  lf::misc::E_LF_ANCHOR stat = lfAnchorINST->get_anchor();
  switch ( stat )
  {
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG:
    Ntk ntk_new = mockturtle::cut_rewriting<Ntk, mockturtle::xag_npn_resynthesis<Ntk>>( ntk, ps );
    lfLmINST->set_current<Ntk>( ntk_new );
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG:
    Ntk ntk_new = mockturtle::cut_rewriting<Ntk, mockturtle::xag_npn_resynthesis<Ntk>>( ntk, ps );
    lfLmINST->set_current<Ntk>( ntk_new );
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG:
    Ntk ntk_new = mockturtle::cut_rewriting<Ntk, mockturtle::mig_npn_resynthesis>( ntk, ps );
    lfLmINST->set_current<Ntk>( ntk_new );
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG:
    Ntk ntk_new = mockturtle::cut_rewriting<Ntk, mockturtle::xmg_npn_resynthesis>( ntk, ps );
    lfLmINST->set_current<Ntk>( ntk_new );
    break;
  default:
    assert( false );
    break;
  }
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
