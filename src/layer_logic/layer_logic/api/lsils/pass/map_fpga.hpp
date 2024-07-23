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
template<class Ntk = aig_seq_network>
void map_fpga( int K_feasible_cut = -1, int Cut_limit = -1, int DelayIter = -1, int AreaIter = -1,
               bool is_verbose = false )
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

  mockturtle::mapping_view<Ntk> ntk_mapped{ ntk };

  klut_seq_network netlist_fpga;

  mockturtle::lut_mapping( ntk_mapped, ps );

  mockturtle::collapse_mapped_network<klut_seq_network>( netlist_fpga, ntk_mapped );

  lfLmINST->set_current<klut_seq_network>( netlist_fpga );
  lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_NETLIST_FPGA );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
