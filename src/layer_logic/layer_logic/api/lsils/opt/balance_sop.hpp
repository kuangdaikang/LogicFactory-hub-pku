#include "mockturtle/algorithms/balancing.hpp"
#include "mockturtle/algorithms/balancing/sop_balancing.hpp"
#include "mockturtle/algorithms/balancing/utils.hpp"
#include "mockturtle/utils/cost_functions.hpp"

#include "layer_logic/logic_manager.hpp"

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
template<class Ntk, class Costfn = mockturtle::unit_cost<Ntk>>
void balance_sop( LogicManager& manager )
{
  using NtkBase = typename Ntk::base_type;
  if constexpr ( std::is_same_v<NtkBase, mockturtle::aig_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG );
  }
  else if constexpr ( std::is_same_v<NtkBase, mockturtle::xag_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG );
  }
  else if constexpr ( std::is_same_v<NtkBase, mockturtle::mig_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG );
  }
  else if constexpr ( std::is_same_v<NtkBase, mockturtle::xmg_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG );
  }
  else if constexpr ( std::is_same_v<NtkBase, mockturtle::gtg_network> )
  {
    manager.update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG );
  }
  else
  {
    std::cerr << "Unhandled network type provided." << std::endl;
    assert( false );
  }

  auto ntk = manager.current<Ntk>();
  mockturtle::write_dot<mockturtle::aig_network>( ntk, "b11_comb.gtech.v.aig.dot" );

  Ntk ntk_new = mockturtle::balancing<Ntk, Costfn>( ntk );
  manager.set_current<Ntk>( ntk_new );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
