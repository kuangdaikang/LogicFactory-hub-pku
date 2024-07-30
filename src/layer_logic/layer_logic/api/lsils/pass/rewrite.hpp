#pragma once

#include "layer_logic/logic_manager.hpp"

#include "mockturtle/algorithms/cut_rewriting.hpp"
#include "mockturtle/algorithms/node_resynthesis/xag_npn.hpp"
#include "mockturtle/algorithms/node_resynthesis/mig_npn.hpp"
#include "mockturtle/algorithms/node_resynthesis/xmg_npn.hpp"

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
template<typename Ntk = aig_seq_network>
void rewrite( bool is_preserve_depth = false, bool is_zero_gain = false, bool is_dont_cares = false, bool is_progress = false, bool is_verbose = false, bool is_very_verbose = false )
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

  mockturtle::cut_rewriting_params ps;
  ps.cut_enumeration_ps.cut_size = 4;
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
  lf::misc::E_LF_ANCHOR stat = lfAnchorINST->get_anchor_curr();
  Ntk ntk_new;
  switch ( stat )
  {
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG:
    if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
    {
      mockturtle::xag_npn_resynthesis<Ntk> resyn_xag;
      ntk_new = mockturtle::cut_rewriting( ntk, resyn_xag, ps );
      lfLmINST->set_current<Ntk>( ntk_new );
    }
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG:
    if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
    {
      mockturtle::xag_npn_resynthesis<Ntk> resyn_xag;
      ntk_new = mockturtle::cut_rewriting( ntk, resyn_xag, ps );
      lfLmINST->set_current<Ntk>( ntk_new );
    }
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG:
    if constexpr ( std::is_same_v<Ntk, mig_seq_network> )
    {
      mockturtle::mig_npn_resynthesis resyn_mig;
      ntk_new = mockturtle::cut_rewriting( ntk, resyn_mig, ps );
      lfLmINST->set_current<Ntk>( ntk_new );
    }
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG:
    if constexpr ( std::is_same_v<Ntk, xmg_seq_network> )
    {
      mockturtle::xmg_npn_resynthesis resyn_xmg;
      ntk_new = mockturtle::cut_rewriting( ntk, resyn_xmg, ps );
      lfLmINST->set_current<Ntk>( ntk_new );
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
