#pragma once

#include "layer_logic/logic_manager.hpp"

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
                     std::is_same_v<NtkSrcBase, mockturtle::primary_network> ||
                     std::is_same_v<NtkSrcBase, mockturtle::gtg_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, PRIMARY, or GTG" );
  static_assert( std::is_same_v<NtkDestBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::primary_network> ||
                     std::is_same_v<NtkDestBase, mockturtle::gtg_network>,
                 "NtkDest is not an AIG, XAG, MIG, XMG, PRIMARY, or GTG" );
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
    else if ( ntk_src.is_ite( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_ite( new_c0, new_c1, new_c2 ) );
    }
    else if ( ntk_src.is_xor3( g ) )
    {
      auto new_c2 = DSignal( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = ntk_dest.get_node( ntk_dest.create_xor3( new_c0, new_c1, new_c2 ) );
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
    else if ( ntk_src.is_ite( g ) )
    {
      pNode2 = babc::Abc_ObjNotCond( old_2_new[children[2].index], ntk_src.is_complemented( children[2] ) ? 1 : 0 );
      old_2_new[g] = babc::Abc_AigMux( (babc::Abc_Aig_t*)pNtk->pManFunc, pNode0, pNode1, pNode2 );
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
    else
    {
      assert( false );
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

/**
 * @brief convert the current type to another type without change the ntktype
 * @param from
 * @param to
 * @note this function is implemented the node to node trasfomation method
 */
void convert_node( const std::string& from, const std::string& to )
{
  assert( from == "abc" || from == "aig" || from == "xag" || from == "mig" || from == "xmg" || from == "primary" || from == "gtg" );
  assert( to == "abc" || to == "aig" || to == "xag" || to == "mig" || to == "xmg" || to == "primary" || to == "gtg" );

  if ( from == to )
    return;

  lf::misc::E_LF_LOGIC_NTK_TYPE ntktype_from;
  lf::misc::E_LF_LOGIC_NTK_TYPE ntktype_to;

  if ( from == "abc" )
    ntktype_from = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_STRASH_AIG;
  else if ( from == "aig" )
    ntktype_from = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG;
  else if ( from == "xag" )
    ntktype_from = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG;
  else if ( from == "mig" )
    ntktype_from = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG;
  else if ( from == "xmg" )
    ntktype_from = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG;
  else if ( from == "primary" )
    ntktype_from = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_PRIMARY;
  else if ( from == "gtg" )
    ntktype_from = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG;
  else
  {
    std::cerr << "Error: unknown logic network type: " << from << std::endl;
    assert( false );
    return;
  }

  if ( to == "abc" )
    ntktype_to = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_STRASH_AIG;
  else if ( to == "aig" )
    ntktype_to = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG;
  else if ( to == "xag" )
    ntktype_to = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG;
  else if ( to == "mig" )
    ntktype_to = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG;
  else if ( to == "xmg" )
    ntktype_to = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG;
  else if ( to == "primary" )
    ntktype_to = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_PRIMARY;
  else if ( to == "gtg" )
    ntktype_to = lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG;
  else
  {
    std::cerr << "Error: unknown logic network type: " << from << std::endl;
    assert( false );
    return;
  }

  if ( ntktype_from == ntktype_to )
    return;
  if ( ntktype_from == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_NONE )
    return;
  if ( ntktype_to == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_ASIC ||
       ntktype_to == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_FPGA ||
       ntktype_to == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_ASIC ||
       ntktype_to == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_FPGA )
    return;

  // perform the convert procedure
  auto frame_abc_ptr = lfLmINST->current<babc::Abc_Frame_t*>();
  auto frame_lsils_ref = lfLmINST->current<lsils::Lsils_Frame_t>();

  using NtkIR = lsils::gtg_seq_network; // gtech is more general, thus the conversion will not affect the original logic
  NtkIR ntk;
  babc::Abc_Ntk_t* pNtk = babc::Abc_FrameReadNtk( frame_abc_ptr );

  // step1:  previous logic-based data structure -> IR
  switch ( ntktype_from )
  {
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_AIG:
  {
    ntk = lf::logic::convert_abc_2_lsils<NtkIR>( pNtk );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_AIG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::aig_seq_network>( frame_lsils_ref.curr_aig );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XAG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::xag_seq_network>( frame_lsils_ref.curr_xag );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_MIG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::mig_seq_network>( frame_lsils_ref.curr_mig );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XMG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::xmg_seq_network>( frame_lsils_ref.curr_xmg );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_PRIMARY:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::primary_seq_network>( frame_lsils_ref.curr_primary );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_GTG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::gtg_seq_network>( frame_lsils_ref.curr_gtg );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_STRASH_AIG:
  {
    ntk = lf::logic::convert_abc_2_lsils<NtkIR>( pNtk );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::aig_seq_network>( frame_lsils_ref.curr_aig );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::xag_seq_network>( frame_lsils_ref.curr_xag );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::mig_seq_network>( frame_lsils_ref.curr_mig );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::xmg_seq_network>( frame_lsils_ref.curr_xmg );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_PRIMARY:
  {
    ntk = lf::logic::convert_lsils_internal<NtkIR, lsils::primary_seq_network>( frame_lsils_ref.curr_primary );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG:
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
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_AIG:
  {
    pNtk = lf::logic::convert_lsils_2_abc<NtkIR>( ntk );
    babc::Abc_FrameSetCurrentNetwork( frame_abc_ptr, pNtk );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_AIG:
  {
    auto aig = lf::logic::convert_lsils_internal<lsils::aig_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( aig );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XAG:
  {
    auto xag = lf::logic::convert_lsils_internal<lsils::xag_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( xag );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_MIG:
  {
    auto mig = lf::logic::convert_lsils_internal<lsils::mig_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( mig );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XMG:
  {
    auto xmg = lf::logic::convert_lsils_internal<lsils::xmg_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( xmg );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_PRIMARY:
  {
    auto primary = lf::logic::convert_lsils_internal<lsils::primary_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( primary );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_GTG:
  {
    auto gtg = lf::logic::convert_lsils_internal<lsils::gtg_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( gtg );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_STRASH_AIG:
  {
    pNtk = lf::logic::convert_lsils_2_abc<NtkIR>( ntk );
    babc::Abc_FrameSetCurrentNetwork( frame_abc_ptr, pNtk );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG:
  {
    auto aig = lf::logic::convert_lsils_internal<lsils::aig_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( aig );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG:
  {
    auto xag = lf::logic::convert_lsils_internal<lsils::xag_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( xag );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG:
  {
    auto mig = lf::logic::convert_lsils_internal<lsils::mig_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( mig );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG:
  {
    auto xmg = lf::logic::convert_lsils_internal<lsils::xmg_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( xmg );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_PRIMARY:
  {
    auto primary = lf::logic::convert_lsils_internal<lsils::primary_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( primary );
    break;
  }
  case lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG:
  {
    auto gtg = lf::logic::convert_lsils_internal<lsils::gtg_seq_network, NtkIR>( ntk );
    lfLmINST->set_current( gtg );
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