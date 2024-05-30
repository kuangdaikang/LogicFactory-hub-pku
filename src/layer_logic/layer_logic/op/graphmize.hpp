#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp

namespace lf
{

/**
 * @brief generate the graphml file for current network.
 *
 * @param ntk the given network
 * @param file file.
 */
template<class Ntk>
void graphmize( Ntk const& ntk, const std::string& file )
{
  using NtkBase = typename Ntk::base_type;
  static_assert( std::is_same_v<NtkBase, aig_network> ||
                     std::is_same_v<NtkBase, xag_network> ||
                     std::is_same_v<NtkBase, mig_network> ||
                     std::is_same_v<NtkBase, xmg_network> ||
                     std::is_same_v<NtkBase, gtech_network>,
                 "ntk is not an AIG, XAG, MIG, XMG, or GTG" );
  // TODO:
}

} // end namespace lf