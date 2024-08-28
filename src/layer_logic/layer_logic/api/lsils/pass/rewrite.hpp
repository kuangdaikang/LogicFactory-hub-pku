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
void rewrite( bool is_preserve_depth = false, bool is_zero_gain = false, bool is_dont_cares = false, bool is_progress = false, bool is_verbose = false, bool is_very_verbose = false )
{
  printf( "rewrite\n" );
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

  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG );

  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();

    mockturtle::xag_npn_resynthesis<lf::logic::lsils::aig_seq_network> resyn_xag;
    lf::logic::lsils::aig_seq_network ntk_new = mockturtle::cut_rewriting( ntk, resyn_xag, ps );

    lfLmINST->set_current( ntk_new );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();

    mockturtle::xag_npn_resynthesis<lf::logic::lsils::xag_seq_network> resyn_xag;
    lf::logic::lsils::xag_seq_network ntk_new = mockturtle::cut_rewriting( ntk, resyn_xag, ps );

    lfLmINST->set_current( ntk_new );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();

    mockturtle::xmg_npn_resynthesis resyn_xmg;
    lf::logic::lsils::xmg_seq_network ntk_new = mockturtle::cut_rewriting( ntk, resyn_xmg, ps );

    lfLmINST->set_current( ntk_new );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();

    mockturtle::mig_npn_resynthesis resyn_mig;
    lf::logic::lsils::mig_seq_network ntk_new = mockturtle::cut_rewriting( ntk, resyn_mig, ps );

    lfLmINST->set_current( ntk_new );
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
