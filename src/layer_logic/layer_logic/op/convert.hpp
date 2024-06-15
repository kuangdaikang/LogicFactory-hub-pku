#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp"

#include <unordered_map>

namespace lf
{

namespace logic
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
  static_assert( std::is_same_v<NtkSrcBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkSrcBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkSrcBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkSrcBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkSrcBase, mockturtle::gtg_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, or GTG" );
  static_assert( std::is_same_v<NtkDestBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::gtg_network>,
                 "NtkDest is not an AIG, XAG, MIG, XMG, or GTG" );
  NtkDest ntk_dest;
  using DNode = typename NtkDest::node;
  using DSignal = typename NtkDest::signal;
  using SNode = typename NtkSrc::node;
  using SSignal = typename NtkSrc::signal;

  std::unordered_map<SNode, DNode> old_2_new;

  auto d_zero = ntk_dest.get_constant( false );
  auto d_one = ntk_dest.get_constant( true );

  auto c_zero = ntk_src.get_constant( false );
  auto c_one = ntk_src.get_constant( true );

  // constant
  old_2_new[ntk_src.get_node( c_zero )] = ntk_dest.get_node( d_zero );
  if ( c_zero != c_one )
  {
    old_2_new[ntk_src.get_node( c_one )] = ntk_dest.get_node( d_one );
  }

  // primary inputs
  ntk_src.foreach_pi( [&]( auto const& pi ) {
    old_2_new[pi] = ntk_dest.get_node( ntk_dest.create_pi() );
  } );

  // internal gates
  ntk_src.foreach_gate( [&]( auto const& g ) {
    std::vector<SSignal> children;
    ntk_src.foreach_fanin( g, [&]( auto const& c ) {
      children.push_back( c );
    } );
    auto new_c0 = DSignal( old_2_new[children[0].index], ntk_src.is_complemented( children[0] ) ? 1 : 0 );
    auto new_c1 = DSignal( old_2_new[children[1].index], ntk_src.is_complemented( children[1] ) ? 1 : 0 );

    if ( ntk_src.is_and( g ) )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_and( new_c0, new_c1 ) );
    }
    else if ( ntk_src.is_nand( g ) )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_nand( new_c0, new_c1 ) );
    }
    else if ( ntk_src.is_or( g ) )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_or( new_c0, new_c1 ) );
    }
    else if ( ntk_src.is_nor( g ) )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_nor( new_c0, new_c1 ) );
    }
    else if ( ntk_src.is_xor( g ) )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_xor( new_c0, new_c1 ) );
    }
    else if ( ntk_src.is_xnor( g ) )
    {
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_xnor( new_c0, new_c1 ) );
    }
    else
    {
      assert( false );
    }
  } );

  // primary outputs
  ntk_src.foreach_po( [&]( auto const& po ) {
    auto new_po = DSignal( old_2_new[po.index], ntk_src.is_complemented( po ) ? 1 : 0 );
    ntk_dest.create_po( new_po );
  } );

  // return the dest network
  return ntk_dest;
}

} // end namespace logic

} // end namespace lf