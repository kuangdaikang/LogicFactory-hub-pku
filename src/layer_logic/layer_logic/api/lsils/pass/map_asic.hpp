#pragma once

#include "layer_logic/logic_manager.hpp"

namespace lf
{

namespace logic
{

namespace lsils
{

/**
 * @brief Technology Mapping
 * @example
 *  rewrite [options]
 *  options: [KCDA] [v]
 * @note
 */
// template<class Ntk, class RewritingFn = {}, class NodeCostFn = unit_cost<Ntk>>
template<class Ntk = aig_seq_network>
void map_asic( int Cut_limit = -1, double Require_time = -1.0f, int FlowIter = -1, int AreaIter = -1, int PowerIter = -1, int logic_Sharing_cut_limit = -1, int Window_size = -1,
               bool is_min_truth = false, bool is_skip_delay_round = false, bool is_logic_sharing = false, bool is_dont_cares = false, bool is_verbose = false )
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

  mockturtle::map_params ps;
  if ( Cut_limit > 0 )
    ps.cut_enumeration_ps.cut_limit = Cut_limit;
  if ( Require_time > 0.0f )
    ps.required_time = Require_time;
  if ( FlowIter > 0.0f )
    ps.area_flow_rounds = FlowIter;
  if ( AreaIter > 0.0f )
    ps.ela_rounds = AreaIter;
  if ( PowerIter > 0.0f )
    ps.eswp_rounds = PowerIter;
  if ( logic_Sharing_cut_limit > 0.0f )
    ps.logic_sharing_cut_limit = logic_Sharing_cut_limit;
  if ( Window_size > 0.0f )
    ps.window_size = Window_size;

  if ( is_min_truth )
    ps.cut_enumeration_ps.minimize_truth_table = is_min_truth;
  if ( is_skip_delay_round )
    ps.skip_delay_round = is_skip_delay_round;
  if ( is_logic_sharing )
    ps.enable_logic_sharing = is_logic_sharing;
  if ( is_dont_cares )
    ps.use_dont_cares = is_dont_cares;
  if ( is_verbose )
    ps.verbose = true;

  auto ntk = lfLmINST->current<Ntk>();
  auto gates = lfLmINST->current<lib_gates>();

  lib_techlib_np techlib( gates );

  blut_seq_network netlist_asic = mockturtle::seq_map<Ntk, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk, techlib, ps );

  lfLmINST->set_current<blut_seq_network>( netlist_asic );
  lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_NETLIST_ASIC );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
