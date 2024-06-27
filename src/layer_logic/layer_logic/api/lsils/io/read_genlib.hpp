#pragma once

#pragma once

#include "layer_logic/logic_manager.hpp"

#include "lorina/genlib.hpp"
#include "mockturtle/io/genlib_reader.hpp"

#include "utility/string.hpp"

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
void read_genlib( LogicManager& manager, std::string file )
{
  if ( !lf::utility::endsWith( file, ".genlib" ) )
  {
    std::cerr << "Unmatched genlib suffix type." << std::endl;
    assert( false );
    return;
  }

  std::ifstream in( file );
  lib_gates gates;
  lorina::read_genlib( in, mockturtle::genlib_reader( gates ) );
  manager.set_current<lib_gates>( gates );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
