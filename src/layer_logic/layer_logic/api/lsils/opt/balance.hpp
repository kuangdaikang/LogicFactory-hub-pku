#pragma once

#include "layer_logic/logic_manager.hpp"

#include "mockturtle/algorithms/balancing.hpp"
#include "mockturtle/algorithms/balancing/sop_balancing.hpp"
#include "mockturtle/algorithms/balancing/utils.hpp"
#include "mockturtle/utils/cost_functions.hpp"

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
template<class Ntk>
void balance_sop( LogicManager& manager )
{
  if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG );
  }
  else if constexpr ( std::is_same_v<Ntk, mig_seq_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xmg_seq_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG );
  }
  else if constexpr ( std::is_same_v<Ntk, gtg_seq_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG );
  }
  else
  {
    std::cerr << "Unhandled network type provided." << std::endl;
    assert( false );
  }

  auto ntk = manager.current<Ntk>();

  mockturtle::sop_rebalancing<Ntk> rebalance;
  Ntk ntk_new = mockturtle::balancing<Ntk>( ntk, rebalance );
  manager.set_current<Ntk>( ntk_new );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
