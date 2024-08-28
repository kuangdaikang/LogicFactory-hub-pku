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
void map_asic( int Cut_limit = -1, double Require_time = -1.0f, int FlowIter = -1, int AreaIter = -1, int PowerIter = -1, int logic_Sharing_cut_limit = -1, int Window_size = -1,
               bool is_min_truth = false, bool is_skip_delay_round = false, bool is_logic_sharing = false, bool is_dont_cares = false, bool is_verbose = false )
{
  printf( "map asic\n" );
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

  auto gates = lfLmINST->current<lib_gates>();
  lib_techlib_np techlib( gates );

  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_PRIMARY ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG );

  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();

    blut_seq_network netlist_asic = mockturtle::seq_map<lf::logic::lsils::aig_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk, techlib, ps );

    lfLmINST->set_current<blut_seq_network>( netlist_asic );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();

    blut_seq_network netlist_asic = mockturtle::seq_map<lf::logic::lsils::xag_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk, techlib, ps );

    lfLmINST->set_current<blut_seq_network>( netlist_asic );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();

    blut_seq_network netlist_asic = mockturtle::seq_map<lf::logic::lsils::xmg_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk, techlib, ps );

    lfLmINST->set_current<blut_seq_network>( netlist_asic );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();

    blut_seq_network netlist_asic = mockturtle::seq_map<lf::logic::lsils::mig_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk, techlib, ps );

    lfLmINST->set_current<blut_seq_network>( netlist_asic );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_PRIMARY )
  {
    lf::logic::lsils::primary_seq_network ntk = lfLmINST->current<lf::logic::lsils::primary_seq_network>();

    blut_seq_network netlist_asic = mockturtle::seq_map<lf::logic::lsils::primary_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk, techlib, ps );

    lfLmINST->set_current<blut_seq_network>( netlist_asic );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG )
  {
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();

    blut_seq_network netlist_asic = mockturtle::seq_map<lf::logic::lsils::gtg_seq_network, 6u, mockturtle::cut_enumeration_tech_map_cut, 6u, mockturtle::classification_type::np_configurations>( ntk, techlib, ps );

    lfLmINST->set_current<blut_seq_network>( netlist_asic );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }

  lfLntINST->set_ntktype( lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_ASIC );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
