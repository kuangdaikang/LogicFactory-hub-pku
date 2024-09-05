#pragma once

#include "layer_logic/logic_manager.hpp"
#include "layer_logic/aux/type_map.hpp"

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
  static_assert( std::is_same_v<NtkSrc, lsils::aig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::oig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::aog_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xag_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xog_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::mig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xmg_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::gtg_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::primary_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::aig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::oig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::aog_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xag_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xog_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::mig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xmg_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::gtg_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::primary_seq_network>,
                 "NtkSrc is not an AIG, OIG, AOG, XAG, XOG, MIG, XMG, Primary, or GTG" );
  static_assert( std::is_same_v<NtkDest, lsils::aig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::oig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::aog_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xag_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xog_comb_network> ||
                     std::is_same_v<NtkDest, lsils::mig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xmg_comb_network> ||
                     std::is_same_v<NtkDest, lsils::gtg_comb_network> ||
                     std::is_same_v<NtkDest, lsils::primary_comb_network> ||
                     std::is_same_v<NtkDest, lsils::aig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::oig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::aog_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xag_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xog_seq_network> ||
                     std::is_same_v<NtkDest, lsils::mig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xmg_seq_network> ||
                     std::is_same_v<NtkDest, lsils::gtg_seq_network> ||
                     std::is_same_v<NtkDest, lsils::primary_seq_network>,
                 "NtkDest is not an AIG, OIG, AOG, XAG, XOG, MIG, XMG, Primary, or GTG" );

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
    else if ( ntk_src.is_maj( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_maj( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_xor3( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_xor3( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_nand3( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_nand3( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_nor3( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_nor3( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_mux21( g ) || ntk_src.is_ite( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_mux21( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_nmux21( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_nmux21( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_aoi21( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_aoi21( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_oai21( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_oai21( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_axi21( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_axi21( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_xai21( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_xai21( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_oxi21( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_oxi21( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_xoi21( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_xoi21( new_c0, new_c1, new_c2 ) );
    }
    else
    {
      std::cerr << "Unsupported gate type! " << std::endl;
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
template<typename NtkSrc>
babc::Abc_Ntk_t* convert_lsils_2_abc( NtkSrc const& ntk_src )
{
  static_assert( std::is_same_v<NtkSrc, lsils::aig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::oig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::aog_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xag_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xog_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::mig_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::xmg_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::gtg_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::primary_comb_network> ||
                     std::is_same_v<NtkSrc, lsils::aig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::oig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::aog_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xag_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xog_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::mig_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::xmg_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::gtg_seq_network> ||
                     std::is_same_v<NtkSrc, lsils::primary_seq_network>,
                 "NtkSrc is not an AIG, OIG, AOG, XAG, XOG, MIG, XMG, Primary, or GTG" );
  using DNode = babc::Abc_Obj_t*;
  using SNode = typename NtkSrc::node;
  using SSignal = typename NtkSrc::signal;

  babc::Vec_Ptr_t* vNodes;
  babc::Abc_Ntk_t* pNtk;
  babc::Abc_Obj_t *pObj, *pNode0, *pNode1, *pNode2, *pConst1;

  std::unordered_map<SNode, DNode> old_2_new;

  pNtk = babc::Abc_NtkAlloc( babc::ABC_NTK_STRASH, babc::ABC_FUNC_AIG, 1 );
  pNtk->pName = babc::Extra_UtilStrsav( "top_module" );
  pNtk->pSpec = babc::Extra_UtilStrsav( "top_spec" );
  pNtk->nConstrs = 0;

  vNodes = babc::Vec_PtrAlloc( 1 + ntk_src.num_pis() + ntk_src.num_gates() );

  // constant
  pConst1 = babc::Abc_AigConst1( pNtk );
  assert( pConst1->Id == 0 );
  babc::Vec_PtrPush( vNodes, babc::Abc_ObjNot( pConst1 ) ); // constant 0

  auto c_zero = ntk_src.get_node( ntk_src.get_constant( false ) );
  auto c_one = ntk_src.get_node( ntk_src.get_constant( true ) );
  old_2_new[c_one] = pConst1;
  if ( c_zero != c_one )
  {
    old_2_new[c_zero] = babc::Abc_ObjNot( pConst1 );
  }

  // primary inputs
  ntk_src.foreach_pi( [&]( auto const& pi ) {
    pObj = babc::Abc_NtkCreatePi( pNtk );
    old_2_new[pi] = pObj;
    babc::Vec_PtrPush( vNodes, pObj );
  } );

  // primary outputs
  ntk_src.foreach_po( [&]( auto const& po, int index ) {
    pObj = babc::Abc_NtkCreatePo( pNtk );
  } );

  // internal gates
  int i = 0;
  ntk_src.foreach_gate( [&]( auto const& g, int index ) {
    std::vector<SSignal> children;
    ntk_src.foreach_fanin( g, [&]( auto const& c ) {
      children.push_back( c );
    } );

    assert( children.size() <= 3 );
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
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      babc::Abc_Obj_t* c1 = babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 );
      babc::Abc_Obj_t* c2 = babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode2 );
      babc::Abc_Obj_t* c3 = babc::Abc_AigAnd( (babc::Abc_Aig_t*)pNtk->pManFunc, c1, c2 );
      old_2_new[g] = babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, c3 );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_xor3( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ), pNode2 );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_nand3( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigAnd( (babc::Abc_Aig_t*)pNtk->pManFunc, babc::Abc_AigAnd( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ), pNode2 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_nor3( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigOr( (babc::Abc_Aig_t*)pNtk->pManFunc, babc::Abc_AigOr( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ), pNode2 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_mux21( g ) || ntk_src.is_ite( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_AigMux( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1, pNode2 );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_nmux21( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigMux( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1, pNode2 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_aoi21( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigOr( (babc::Abc_Aig_t*)pNtk->pManFunc, babc::Abc_AigAnd( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ), pNode2 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_oai21( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigAnd( (babc::Abc_Aig_t*)pNtk->pManFunc, babc::Abc_AigOr( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ), pNode2 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_axi21( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, babc::Abc_AigAnd( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ), pNode2 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_xai21( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigAnd( (babc::Abc_Aig_t*)pNtk->pManFunc, babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ), pNode2 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_oxi21( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, babc::Abc_AigOr( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ), pNode2 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else if ( ntk_src.is_xoi21( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_ObjNot( babc::Abc_AigOr( (babc::Abc_Aig_t*)pNtk->pManFunc, babc::Abc_AigXor( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1 ), pNode2 ) );
      assert( Vec_PtrSize( vNodes ) == index + 1 + ntk_src.num_pis() );
      Vec_PtrPush( vNodes, old_2_new[g] );
    }
    else
    {
      std::cerr << "Unsupported gate type! " << std::endl;
      assert( false );
      return;
    }
  } );

  // add fanin of the output nodes
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
template<typename NtkDest>
NtkDest convert_abc_2_lsils( babc::Abc_Ntk_t* pNtk )
{
  static_assert( std::is_same_v<NtkDest, lsils::aig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::oig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::aog_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xag_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xog_comb_network> ||
                     std::is_same_v<NtkDest, lsils::mig_comb_network> ||
                     std::is_same_v<NtkDest, lsils::xmg_comb_network> ||
                     std::is_same_v<NtkDest, lsils::gtg_comb_network> ||
                     std::is_same_v<NtkDest, lsils::primary_comb_network> ||
                     std::is_same_v<NtkDest, lsils::aig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::oig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::aog_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xag_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xog_seq_network> ||
                     std::is_same_v<NtkDest, lsils::mig_seq_network> ||
                     std::is_same_v<NtkDest, lsils::xmg_seq_network> ||
                     std::is_same_v<NtkDest, lsils::gtg_seq_network> ||
                     std::is_same_v<NtkDest, lsils::primary_seq_network>,
                 "NtkDest is not an AIG, OIG, AOG, XAG, XOG, MIG, XMG, Primary, or GTG" );

  using DNode = typename NtkDest::node;
  using DSignal = typename NtkDest::signal;
  using SNode = babc::Abc_Obj_t*;

  NtkDest ntk_dest;
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

/**
 * @brief convert the current type to another type without change the ntktype
 * @param from
 * @param to
 * @note this function is implemented the node to node trasfomation method
 */
void convert_node( const std::string& from, const std::string& to )
{
  auto from_iter = CONVERT_TYPE_MAP.find( from );
  auto to_iter = CONVERT_TYPE_MAP.find( to );
  if ( to_iter == CONVERT_TYPE_MAP.end() || to_iter == CONVERT_TYPE_MAP.end() )
  {
    std::cerr << "Invalid type: " << from << " or " << to << std::endl;
    return;
  }

  auto from_type = from_iter->second;
  auto to_type = to_iter->second;
  if ( from_type == to_type )
  {
    std::cerr << "The type is the same, no need to convert" << std::endl;
    return;
  }

  lf::misc::E_LF_NTK_TYPE ntktype_from;
  lf::misc::E_LF_NTK_TYPE ntktype_to;

  if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_ABC )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG;
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AIG;
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_OIG;
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AOG;
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XAG;
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XOG;
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_MIG;
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XMG;
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY;
  else if ( from_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    ntktype_from = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_GTG;
  else
  {
    std::cerr << "Error: unknown logic network type: " << from << std::endl;
    assert( false );
    return;
  }

  if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_ABC )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG;
  else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AIG )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AIG;
  else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_OIG )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_OIG;
  else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_AOG )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AOG;
  else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XAG )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XAG;
  else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XOG )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XOG;
  else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_MIG )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_MIG;
  else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_XMG )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XMG;
  else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_PRIMARY )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY;
  else if ( to_type == E_LF_CONVERT_TYPE::E_LF_CONVERT_TYPE_GTG )
    ntktype_to = lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_GTG;
  else
  {
    std::cerr << "Error: unknown logic network type: " << from << std::endl;
    assert( false );
    return;
  }

  // perform the convert procedure
  auto frame_abc_ptr = lfLmINST->current<babc::Abc_Frame_t*>();
  auto frame_lsils_ref = lfLmINST->current<lsils::Lsils_Frame_t>();

  using NtkIR = lsils::gtg_seq_network; // gtech is more general, thus the conversion will not affect the original logic
  NtkIR ntk;
  babc::Abc_Ntk_t* pNtk = babc::Abc_FrameReadNtk( frame_abc_ptr );

  // step1:  previous logic-based data structure -> IR
  switch ( ntktype_from )
  {
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG:
  {
    ntk = lf::logic::convert_abc_2_lsils<NtkIR>( pNtk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AIG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::aig_seq_network>( frame_lsils_ref.curr_aig );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_OIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_OIG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::oig_seq_network>( frame_lsils_ref.curr_oig );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AOG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AOG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::aog_seq_network>( frame_lsils_ref.curr_aog );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XAG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XAG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::xag_seq_network>( frame_lsils_ref.curr_xag );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XOG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XOG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::xog_seq_network>( frame_lsils_ref.curr_xog );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_MIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_MIG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::mig_seq_network>( frame_lsils_ref.curr_mig );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XMG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XMG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::xmg_seq_network>( frame_lsils_ref.curr_xmg );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::primary_seq_network>( frame_lsils_ref.curr_primary );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_GTG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_GTG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::gtg_seq_network>( frame_lsils_ref.curr_gtg );
    break;
  }
  default:
  {
    assert( false );
    break;
  }
  }

  // step2:  IR -> current logic-based data structure
  switch ( ntktype_to )
  {
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG:
  {
    pNtk = lf::logic::convert_lsils_2_abc<NtkIR>( ntk );
    babc::Abc_FrameSetCurrentNetwork( frame_abc_ptr, pNtk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AIG:
  {
    auto ntk_res = lf::logic::convert_lsils_internal<lsils::aig_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( ntk_res );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_OIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_OIG:
  {
    auto ntk_res = lf::logic::convert_lsils_internal<lsils::oig_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( ntk_res );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AOG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AOG:
  {
    auto ntk_res = lf::logic::convert_lsils_internal<lsils::aog_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( ntk_res );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XAG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XAG:
  {
    auto ntk_res = lf::logic::convert_lsils_internal<lsils::xag_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( ntk_res );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XOG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XOG:
  {
    auto ntk_res = lf::logic::convert_lsils_internal<lsils::xog_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( ntk_res );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_MIG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_MIG:
  {
    auto ntk_res = lf::logic::convert_lsils_internal<lsils::mig_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( ntk_res );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XMG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XMG:
  {
    auto ntk_res = lf::logic::convert_lsils_internal<lsils::xmg_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( ntk_res );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY:
  {
    auto ntk_res = lf::logic::convert_lsils_internal<lsils::primary_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( ntk_res );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_GTG:
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_GTG:
  {
    auto ntk_res = lf::logic::convert_lsils_internal<lsils::gtg_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( ntk_res );
    break;
  }
  default:
  {
    assert( false );
    break;
  }
  }
}

} // end namespace logic

} // end namespace lf