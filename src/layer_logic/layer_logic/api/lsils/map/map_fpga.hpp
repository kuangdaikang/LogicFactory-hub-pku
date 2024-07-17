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
 * @brief balance current network
 * @param ntk   network
 * @param rebalancing_fn function
 * @param ps    params
 * @param pst   stats
 * @code
 *  mockturtle::aig_network aig;
 *  // ...
 *  mockturtle::aig_network aig_balanced = sop_balance(aig);
 *
 */
// template<class Ntk, class RewritingFn = {}, class NodeCostFn = unit_cost<Ntk>>
template<class Ntk = aig_seq_network>
void map_fpga()
{
  if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG );
  }
  else if constexpr ( std::is_same_v<Ntk, mig_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xmg_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG );
  }
  else if constexpr ( std::is_same_v<Ntk, gtg_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG );
  }
  else
  {
    std::cerr << "Unhandled network type provided." << std::endl;
    assert( false );
  }

  auto ntk = lfLmINST->current<Ntk>();
  mockturtle::mapping_view<Ntk> ntk_mapped{ ntk };

  klut_seq_network netlist_fpga;

  mockturtle::lut_mapping( ntk_mapped );

  mockturtle::collapse_mapped_network<klut_seq_network>( netlist_fpga, ntk_mapped );

  lfLmINST->set_current<klut_seq_network>( netlist_fpga );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
