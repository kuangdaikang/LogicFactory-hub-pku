#pragma once

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
// template<class Ntk, class RewritingFn = {}, class NodeCostFn = unit_cost<Ntk>>
void read_liberty( std::string file )
{
  if ( !lf::utility::endsWith( file, ".lib" ) )
  {
    std::cerr << "Unmatched lib suffix type." << std::endl;
    assert( false );
    return;
  }
  std::cerr << "Not support now." << std::endl;
  assert( false );
  return;
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
