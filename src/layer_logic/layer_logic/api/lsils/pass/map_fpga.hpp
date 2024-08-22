#pragma once

#include "layer_logic/logic_manager.hpp"

#include "mockturtle/networks/klut.hpp"
#include "mockturtle/networks/sequential.hpp"

#include "mockturtle/views/mapping_view.hpp"
#include "mockturtle/algorithms/lut_mapping.hpp"
#include "mockturtle/algorithms/collapse_mapped.hpp"

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
void map_fpga( int K_feasible_cut = -1, int Cut_limit = -1, int DelayIter = -1, int AreaIter = -1,
               bool is_verbose = false )
{
  printf("map fpga\n");
  mockturtle::lut_mapping_params ps;
  if ( K_feasible_cut > 0 )
    ps.cut_enumeration_ps.cut_size = K_feasible_cut;
  if ( Cut_limit > 0 )
    ps.cut_enumeration_ps.cut_limit = Cut_limit;
  if ( DelayIter > 0 )
    ps.rounds = DelayIter;
  if ( AreaIter > 0 )
    ps.rounds_ela = AreaIter;
  if ( is_verbose )
    ps.verbose = true;

  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG );
  lfLmINST->update_logic();

  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();

    mockturtle::mapping_view<lf::logic::lsils::aig_seq_network> ntk_mapped{ ntk };
    klut_seq_network netlist_fpga;
    mockturtle::lut_mapping( ntk_mapped, ps );
    mockturtle::collapse_mapped_network<klut_seq_network>( netlist_fpga, ntk_mapped );

    lfLmINST->set_current<klut_seq_network>( netlist_fpga );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();

    mockturtle::mapping_view<lf::logic::lsils::xag_seq_network> ntk_mapped{ ntk };
    klut_seq_network netlist_fpga;
    mockturtle::lut_mapping( ntk_mapped, ps );
    mockturtle::collapse_mapped_network<klut_seq_network>( netlist_fpga, ntk_mapped );

    lfLmINST->set_current<klut_seq_network>( netlist_fpga );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();

    mockturtle::mapping_view<lf::logic::lsils::xmg_seq_network> ntk_mapped{ ntk };
    klut_seq_network netlist_fpga;
    mockturtle::lut_mapping( ntk_mapped, ps );
    mockturtle::collapse_mapped_network<klut_seq_network>( netlist_fpga, ntk_mapped );

    lfLmINST->set_current<klut_seq_network>( netlist_fpga );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();

    mockturtle::mapping_view<lf::logic::lsils::mig_seq_network> ntk_mapped{ ntk };
    klut_seq_network netlist_fpga;
    mockturtle::lut_mapping( ntk_mapped, ps );
    mockturtle::collapse_mapped_network<klut_seq_network>( netlist_fpga, ntk_mapped );

    lfLmINST->set_current<klut_seq_network>( netlist_fpga );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG )
  {
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();

    mockturtle::mapping_view<lf::logic::lsils::gtg_seq_network> ntk_mapped{ ntk };
    klut_seq_network netlist_fpga;
    mockturtle::lut_mapping( ntk_mapped, ps );
    mockturtle::collapse_mapped_network<klut_seq_network>( netlist_fpga, ntk_mapped );

    lfLmINST->set_current<klut_seq_network>( netlist_fpga );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }

  lfLntINST->set_ntktype( lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_FPGA );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
