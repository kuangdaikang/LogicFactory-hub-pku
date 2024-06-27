#pragma once

#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp

#include <unordered_map>

namespace lf
{

namespace logic
{

/**
 * @class Strash
 * @brief structure hash of the logic network
 *
 * @todo only support AIG now
 *
 * @code{.cpp}
 *      aig_network aig;
 *      ...\\ operations
 *      aig_network aig_strashed = strash(aig);
 */
template<typename Ntk>
Ntk strash( Ntk const& ntk )
{
  Ntk ntk_res;

  using index_t = typename Ntk::index_t;
  using node_t = typename Ntk::node_t;
  using signal_t = typename Ntk::signal_t;

  std::unordered_map<node_t, index_t> nodes_hash;  // used for the structure hash
  std::unordered_map<index_t, index_t> old_to_new; // {id_in_ntk, id_in_ntk_res}

  // create nodes: constant , pis, gates
  ntk.foreach_node_with_index( [&]( auto const& n, auto id ) {
    if ( ntk.is_and( id ) )
    {
      signal_t oc0 = ntk.fanin0_at( id );
      signal_t oc1 = ntk.fanin1_at( id );
      signal_t nc0 = signal_t( old_to_new[ntk.get_index( oc0 )], ntk.is_complemented( oc0 ) ? 1u : 0u );
      signal_t nc1 = signal_t( old_to_new[ntk.get_index( oc1 )], ntk.is_complemented( oc1 ) ? 1u : 0u );

      node_t dummy_n;
      dummy_n.fanins = { nc0, nc1 };
      if ( nodes_hash.find( dummy_n ) != nodes_hash.end() )
      { // structure hash find
        old_to_new[id] = nodes_hash[dummy_n];
      }
      else
      { // structure hash not find, create the new and gates
        signal_t ns_and = ntk_res.create_and( nc0, nc1 );
        old_to_new[id] = ntk_res.get_index( ns_and );
        nodes_hash[dummy_n] = ntk_res.get_index( ns_and ); // insert the new added node
      }
    }
    else if ( ntk.is_ci( id ) )
    {
      old_to_new[id] = ntk_res.get_index( ntk_res.create_pi() );
    }
    else if ( ntk.is_constant( id ) )
    {
      index_t oc0id = ntk.get_index( ntk.get_constant( false ) );
      index_t oc1id = ntk.get_index( ntk.get_constant( true ) );
      if ( oc0id != oc1id )
      {
        index_t nc0id = ntk.get_index( ntk.get_constant( false ) );
        index_t nc1id = ntk.get_index( ntk.get_constant( true ) );
        if ( nc0id != nc1id )
        {
          old_to_new[oc0id] = nc0id;
          old_to_new[oc1id] = nc1id;
        }
        else
        {
          old_to_new[oc0id] = nc0id;
          old_to_new[oc1id] = nc0id;
        }
      }
    }
    else
    {
      assert( false );
    }
  } );

  // create POs
  ntk.foreach_po( [&]( auto const& f ) {
    signal_t nf = signal_t( old_to_new[ntk.get_index( f )], ntk.is_complemented( f ) ? 1u : 0u );
    ntk_res.create_po( nf );
  } );

  // create RIs
  ntk.foreach_ri( [&]( auto const& f ) {
    signal_t nf = signal_t( old_to_new[ntk.get_index( f )], ntk.is_complemented( f ) ? 1u : 0u );
    ntk_res.create_ri( nf );
  } );

  return ntk_res;
}

} // end namespace logic

} // namespace lf