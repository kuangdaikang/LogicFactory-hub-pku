#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp

namespace lf
{

/**
 * @brief Convert a network from one type to another.
 *
 * @param ntk_src The network to convert.
 * @return The converted network.
 */
template<class NtkDest, class NtkSrc>
NtkDest convert( NtkSrc const& ntk_src )
{
  using NtkSrcBase = typename NtkSrc::base_type;
  using NtkDestBase = typename NtkDest::base_type;
  static_assert( std::is_same_v<NtkSrcBase, aig_network> ||
                     std::is_same_v<NtkSrcBase, xag_network> ||
                     std::is_same_v<NtkSrcBase, mig_network> ||
                     std::is_same_v<NtkSrcBase, xmg_network> ||
                     std::is_same_v<NtkSrcBase, gtech_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, or GTG" );
  static_assert( std::is_same_v<NtkDestBase, aig_network> ||
                     std::is_same_v<NtkDestBase, xag_network> ||
                     std::is_same_v<NtkDestBase, mig_network> ||
                     std::is_same_v<NtkDestBase, xmg_network> ||
                     std::is_same_v<NtkDestBase, gtech_network>,
                 "NtkDest is not an AIG, XAG, MIG, XMG, or GTG" );
  NtkDest ntk_dest;

  // TODO:
}

} // end namespace lf