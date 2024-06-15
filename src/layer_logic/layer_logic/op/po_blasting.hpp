#pragma once
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/ntk_src.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp

#include <functional>
#include <unordered_map>
#include <vector>

namespace lf
{

namespace logic
{

/**
 * @class po blasting
 * @brief split the given network into single-output sub-network
 *
 * @todo only support AIG now
 *
 * @code{.cpp}
 *      aig_network aig;
 *      ...\\ operations
 *      std::vector<aig_network> sub_aigs = po_blasting(aig);
 */
template<typename Ntk>
std::vector<Ntk> po_blasting( Ntk const& ntk_src )
{
  Ntk ntk_copy( ntk_src );
  std::vector<Ntk> po_ntks;
  using signal_t = Ntk::signal_t;
  using node_t = Ntk::node_t;
  using index_t = Ntk::index_t;

  std::function<void( signal_t const& )> visit_cone_rec = [&]( signal_t const& f ) -> void { // recursive lambda
    node_t n = ntk_copy.get_node( f );
    ntk_copy.set_visited_at( n, true );
    ntk_copy.foreach_fanin( n, [&]( signal_t const& c ) {
      visit_cone_rec( c );
    } );
  };

  ntk_copy.foreach_po_with_index( [&]( auto const& po, auto ipo ) {
    Ntk po_aig;
    ntk_copy.clear_visited();
    std::unordered_map<index_t, index_t> old_2_new;
    visit_cone_rec( po );
    // create pis
    ntk_copy.foreach_pi_with_index( [&]( auto const& pi, uint32_t index ) {
      if ( ntk_copy.visited_at( pi ) )
      {
        auto new_pi = po_aig.create_pi();
        old_2_new[index + ntk_copy.num_constants()] = po_aig.get_index( new_pi );
      }
    } );

    // create gates
    ntk_copy.foreach_gate_with_index( [&]( auto const& n, uint32_t index ) {
      if ( ntk_copy.visited_at( n ) )
      {
        signal_t const& c0 = ntk_copy.fanin0_at( n );
        signal_t const& c1 = ntk_copy.fanin1_at( n );

        signal_t new_c0 = signal_t( old_2_new[ntk_copy.get_index( c0 )], ntk_copy.is_complemented( c0 ) );
        signal_t new_c1 = signal_t( old_2_new[ntk_copy.get_index( c1 )], ntk_copy.is_complemented( c1 ) );
        auto new_gate = po_aig.create_and( new_c0, new_c1 );
        old_2_new[index + ntk_copy.num_constants() + ntk_copy.num_cis()] = po_aig.get_index( new_gate );
      }
    } );

    // create po
    signal_t new_po = signal_t( old_2_new[ntk_copy.get_index( po )], ntk_copy.is_complemented( po ) );
    po_aig.create_po( new_po );
    po_ntks.emplace_back( po_aig );
  } );
  return po_ntks;
}

} // end namespace logic

} // namespace lf