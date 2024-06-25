#pragma once

#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp"
#include "mockturtle/io/write_dot.hpp"

#include "misc/util/abc_namespaces.h"
#include "misc/util/abc_global.h"
#include "base/abc/abc.h"
#include "misc/vec/vec.h"

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
NtkDest convert_lsils_internal( NtkSrc const& ntk_src )
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

/**
 * @brief
 */
template<typename Ntk>
babc::Abc_Ntk_t* convert_lsils_2_abc( Ntk const& ntk_src )
{
  using NtkSrcBase = typename Ntk::base_type;
  static_assert( std::is_same_v<NtkSrcBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkSrcBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkSrcBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkSrcBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkSrcBase, mockturtle::gtg_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, or GTG" );
  using DNode = babc::Abc_Obj_t*;
  using SNode = typename Ntk::node;
  using SSignal = typename Ntk::signal;

  babc::Vec_Ptr_t* vNodes;
  babc::Abc_Ntk_t* pNtk;
  babc::Abc_Obj_t *pObj, *pNode0, *pNode1;
  std::unordered_map<SNode, DNode> old_2_new;

  pNtk = babc::Abc_NtkAlloc( babc::ABC_NTK_STRASH, babc::ABC_FUNC_AIG, 1 );
  pNtk->pName = babc::Extra_UtilStrsav( "top_module" );
  pNtk->pSpec = babc::Extra_UtilStrsav( "top_spec" );
  pNtk->nConstrs = 0;

  vNodes = babc::Vec_PtrAlloc( 1 + ntk_src.num_pis() + ntk_src.num_gates() );
  babc::Vec_PtrPush( vNodes, babc::Abc_ObjNot( babc::Abc_AigConst1( pNtk ) ) ); // constant 0

  // constant
  auto c_zero = ntk_src.get_node( ntk_src.get_constant( false ) );
  auto c_one = ntk_src.get_node( ntk_src.get_constant( true ) );
  old_2_new[c_one] = babc::Abc_AigConst1( pNtk );
  if ( c_zero != c_one )
  {
    old_2_new[c_zero] = babc::Abc_ObjNot( babc::Abc_AigConst1( pNtk ) );
  }

  // primary inputs
  ntk_src.foreach_pi( [&]( auto const& pi ) {
    old_2_new[pi] = babc::Abc_NtkCreatePi( pNtk );
    babc::Vec_PtrPush( vNodes, old_2_new[pi] );
  } );

  // internal gates
  int i = 0;
  ntk_src.foreach_gate( [&]( auto const& g, int index ) {
    std::vector<SSignal> children;
    ntk_src.foreach_fanin( g, [&]( auto const& c ) {
      children.push_back( c );
    } );

    assert( children.size() <= 2 );
    pNode0 = babc::Abc_ObjNotCond( old_2_new[children[0].index], ntk_src.is_complemented( children[0] ) ? 1 : 0 );
    pNode1 = babc::Abc_ObjNotCond( old_2_new[children[1].index], ntk_src.is_complemented( children[1] ) ? 1 : 0 );

    if ( ntk_src.is_and( g ) )
    {
      old_2_new[g] = babc::Abc_AigAnd( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_nand( g ) )
    {
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigAnd( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_or( g ) )
    {
      old_2_new[g] = babc::Abc_AigOr( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_nor( g ) )
    {
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigOr( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_xor( g ) )
    {
      old_2_new[g] = babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_xnor( g ) )
    {
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_maj( g ) )
    {
      assert( false );
    }
    else
    {
      assert( false );
    }
  } );

  // primary outputs
  ntk_src.foreach_po( [&]( auto const& po, int index ) {
    pObj = babc::Abc_NtkCreatePo( pNtk );
  } );

  ntk_src.foreach_po( [&]( auto const& po, int index ) {
    auto pDriver = old_2_new[ntk_src.get_node( po )];
    auto pPo = babc::Abc_NtkPo( pNtk, index );
    pNode0 = babc::Abc_ObjNotCond( pDriver, ntk_src.is_complemented( po ) ? 1 : 0 );
    babc::Abc_ObjAddFanin( pPo, pNode0 );
  } );
  return pNtk;
}

/**
 * @brief
 */
template<typename Ntk>
Ntk convert_abc_2_lsils( babc::Abc_Ntk_t* pNtk )
{
  using NtkDestBase = typename Ntk::base_type;
  static_assert( std::is_same_v<NtkDestBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::gtg_network>,
                 "NtkDest is not an AIG, XAG, MIG, XMG, or GTG" );
  using DNode = typename Ntk::node;
  using DSignal = typename Ntk::signal;
  using SNode = babc::Abc_Obj_t*;

  Ntk ntk_dest;
  babc::Abc_Obj_t *pObj, *pNode0, *pNode1;
  std::unordered_map<SNode, DNode> old_2_new;
  int i = 0, c0, c1;

  auto c_zero = babc::Abc_ObjNot( babc::Abc_AigConst1( pNtk ) );
  auto c_one = babc::Abc_AigConst1( pNtk );

  auto d_zero = ntk_dest.get_node( ntk_dest.get_constant( false ) );
  auto d_one = ntk_dest.get_node( ntk_dest.get_constant( true ) );

  // constant
  old_2_new[c_zero] = d_zero;
  old_2_new[c_one] = d_one;

  // primary inputs
  Abc_NtkForEachPi( pNtk, pObj, i )
  {
    old_2_new[pObj] = ntk_dest.get_node( ntk_dest.create_pi() );
  }

  // internal gates
  Abc_AigForEachAnd( pNtk, pObj, i )
  {
    pNode0 = babc::Abc_ObjFanin0( pObj );
    c0 = babc::Abc_ObjFaninC0( pObj );
    pNode1 = babc::Abc_ObjFanin1( pObj );
    c1 = babc::Abc_ObjFaninC1( pObj );
    auto sig = ntk_dest.create_and( DSignal( old_2_new[pNode0], c0 ), DSignal( old_2_new[pNode1], c1 ) );
    old_2_new[pObj] = ntk_dest.get_node( sig );
  }

  // primary outputs
  Abc_NtkForEachPo( pNtk, pObj, i )
  {
    pNode0 = babc::Abc_ObjFanin0( pObj );
    c0 = babc::Abc_ObjFaninC0( pObj );
    ntk_dest.create_po( DSignal( old_2_new[pNode0], c0 ) );
  }

  return ntk_dest;
}

} // end namespace logic

} // end namespace lf