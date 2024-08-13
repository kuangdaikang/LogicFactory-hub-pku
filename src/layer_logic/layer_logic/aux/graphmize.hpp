#pragma once

#include "layer_logic/logic_manager.hpp"

#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp"

#include "pugixml.hpp"

#include <unordered_map>

namespace lf
{

namespace logic
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
  using Node = typename Ntk::node;
  using Signal = typename Ntk::signal;
  static_assert( std::is_same_v<NtkBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkBase, mockturtle::gtg_network>,
                 "ntk is not an ntk, XAG, MIG, XMG, or GTG" );

  pugi::xml_document doc;
  auto declarationNode = doc.append_child( pugi::node_declaration );
  declarationNode.append_attribute( "version" ) = "1.0";
  declarationNode.append_attribute( "encoding" ) = "UTF-8";
  declarationNode.append_attribute( "standalone" ) = "no";

  auto graphmlNode = doc.append_child( "graphml" );
  graphmlNode.append_attribute( "xmlns" ) = "http://graphml.graphdrawing.org/xmlns";
  graphmlNode.append_attribute( "xmlns:xsi" ) = "http://www.w3.org/2001/XMLSchema-instance";
  graphmlNode.append_attribute( "xsi:schemaLocation" ) = "http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd";

  auto graphNode = graphmlNode.append_child( "graph" );
  graphNode.append_attribute( "id" ) = "G";
  graphNode.append_attribute( "edgedefault" ) = "directed";

  // node attr: type
  auto keyForNodeType = graphmlNode.append_child( "key" );
  keyForNodeType.append_attribute( "id" ) = "nodeType";
  keyForNodeType.append_attribute( "for" ) = "node";
  keyForNodeType.append_attribute( "attr.name" ) = "type";
  keyForNodeType.append_attribute( "attr.type" ) = "string";

  // node attr: name
  auto keyForNodeName = graphmlNode.append_child( "key" );
  keyForNodeName.append_attribute( "id" ) = "nodeName";
  keyForNodeName.append_attribute( "for" ) = "node";
  keyForNodeName.append_attribute( "attr.name" ) = "name";
  keyForNodeName.append_attribute( "attr.type" ) = "string";

  // // edge attr: weight
  // auto keyForEdgeWeight = graphmlNode.append_child( "key" );
  // keyForEdgeWeight.append_attribute( "id" ) = "edgeType";
  // keyForEdgeWeight.append_attribute( "for" ) = "edge";
  // keyForEdgeWeight.append_attribute( "attr.name" ) = "weight";
  // keyForEdgeWeight.append_attribute( "attr.type" ) = "float";

  // id for new add gates
  uint32_t current_index = ntk.size();
  std::unordered_map<Signal, uint32_t> inverter_index_map;

  // constant
  auto constant_id_zero = ntk.node_to_index( ntk.get_node( ntk.get_constant( false ) ) );
  auto constant_id_one = ntk.node_to_index( ntk.get_node( ntk.get_constant( true ) ) );
  auto xmlNode_constant = graphNode.append_child( "node" );
  xmlNode_constant.append_attribute( "id" ) = constant_id_zero;
  auto dataNode_constant = xmlNode_constant.append_child( "data" );
  dataNode_constant.append_attribute( "key" ) = "nodeType";
  dataNode_constant.text().set( "CONST0" );
  auto dataName_constant = xmlNode_constant.append_child( "data" );
  dataName_constant.append_attribute( "key" ) = "nodeName";
  dataName_constant.text().set( 0 );
  if ( constant_id_one != constant_id_zero )
  {
    xmlNode_constant = graphNode.append_child( "node" );
    xmlNode_constant.append_attribute( "id" ) = constant_id_one;
    auto dataNode_constant = xmlNode_constant.append_child( "data" );
    dataNode_constant.append_attribute( "key" ) = "nodeType";
    dataNode_constant.text().set( "CONST1" );
    auto dataName_constant = xmlNode_constant.append_child( "data" );
    dataName_constant.append_attribute( "key" ) = "nodeName";
    dataName_constant.text().set( 0 );
  }

  // primary inputs
  ntk.foreach_pi( [&]( auto const& pi, uint32_t index ) {
    auto pi_id = ntk.node_to_index( pi );
    auto xmlNode_pi = graphNode.append_child( "node" );
    xmlNode_pi.append_attribute( "id" ) = pi_id;
    auto dataNode_pi = xmlNode_pi.append_child( "data" );
    dataNode_pi.append_attribute( "key" ) = "nodeType";
    dataNode_pi.text().set( "PI" );
    auto dataName_pi = xmlNode_pi.append_child( "data" );
    dataName_pi.append_attribute( "key" ) = "nodeName";
    dataName_pi.text().set( pi_id );
  } );

  // internal gates
  ntk.foreach_gate( [&]( auto const& g, uint32_t index ) {
    auto g_id = ntk.node_to_index( g );
    auto xmlNode_gate = graphNode.append_child( "node" );
    xmlNode_gate.append_attribute( "id" ) = g_id;
    auto dataNode_gate = xmlNode_gate.append_child( "data" );
    dataNode_gate.append_attribute( "key" ) = "nodeType";
    if ( ntk.is_and( g ) )
    {
      dataNode_gate.text().set( "AND2" );
    }
    else if ( ntk.is_nand( g ) )
    {
      dataNode_gate.text().set( "NAND2" );
    }
    else if ( ntk.is_or( g ) )
    {
      dataNode_gate.text().set( "OR2" );
    }
    else if ( ntk.is_nor( g ) )
    {
      dataNode_gate.text().set( "NOR2" );
    }
    else if ( ntk.is_xor( g ) )
    {
      dataNode_gate.text().set( "XOR2" );
    }
    else if ( ntk.is_xnor( g ) )
    {
      dataNode_gate.text().set( "XNOR2" );
    }
    else if ( ntk.is_maj( g ) )
    {
      dataNode_gate.text().set( "MAJ3" );
    }
    else if ( ntk.is_xor3( g ) )
    {
      dataNode_gate.text().set( "XOR3" );
    }
    else if ( ntk.is_xor3( g ) )
    {
      dataNode_gate.text().set( "XOR3" );
    }
    else
    {
      assert( false );
    }
    auto dataName_gate = xmlNode_gate.append_child( "data" );
    dataName_gate.append_attribute( "key" ) = "nodeName";
    dataName_gate.text().set( index );

    // edge {children[0]->g, children[1]->g}
    ntk.foreach_fanin( g, [&]( auto const& c ) {
      auto child_id = ntk.node_to_index( ntk.get_node( c ) );
      // add inverter
      if ( ntk.is_complemented( c ) )
      {
        inverter_index_map[c] = ++current_index;

        // create the inverter node
        auto xmlNode_gate_inv = graphNode.append_child( "node" );
        xmlNode_gate_inv.append_attribute( "id" ) = current_index;
        auto dataNode_gate_inv = xmlNode_gate_inv.append_child( "data" );
        dataNode_gate_inv.append_attribute( "key" ) = "nodeType";
        dataNode_gate_inv.text().set( "INVERTER" );
        auto dataName_gate_inv = xmlNode_gate_inv.append_child( "data" );
        dataName_gate_inv.append_attribute( "key" ) = "nodeName";
        dataName_gate_inv.text().set( index );

        // edge1: child_id -> current_index
        auto edge1 = graphNode.append_child( "edge" );
        edge1.append_attribute( "source" ) = child_id;
        edge1.append_attribute( "target" ) = current_index;
        // edge2: current_index -> g_id
        auto edge2 = graphNode.append_child( "edge" );
        edge2.append_attribute( "source" ) = current_index;
        edge2.append_attribute( "target" ) = g_id;
      }
      else
      {
        auto edge = graphNode.append_child( "edge" );
        edge.append_attribute( "source" ) = child_id;
        edge.append_attribute( "target" ) = g_id;
      }
    } );
  } );

  // primary outputs
  ntk.foreach_po( [&]( auto const& po, uint32_t index ) {
    auto npo = ntk.get_node( po );
    auto po_id = ++current_index; // each po is also a node
    auto root_id = ntk.node_to_index( npo );

    auto xmlNode_po = graphNode.append_child( "node" );
    xmlNode_po.append_attribute( "id" ) = po_id;
    auto dataNode_po = xmlNode_po.append_child( "data" );
    dataNode_po.append_attribute( "key" ) = "nodeType";
    dataNode_po.text().set( "PO" );
    auto dataName_po = xmlNode_po.append_child( "data" );
    dataName_po.append_attribute( "key" ) = "nodeName";
    dataName_po.text().set( index );

    if ( ntk.is_complemented( po ) )
    {
      inverter_index_map[po] = ++current_index;

      // create the inverter node
      auto xmlNode_gate_inv = graphNode.append_child( "node" );
      xmlNode_gate_inv.append_attribute( "id" ) = current_index;
      auto dataNode_gate_inv = xmlNode_gate_inv.append_child( "data" );
      dataNode_gate_inv.append_attribute( "key" ) = "nodeType";
      dataNode_gate_inv.text().set( "INVERTER" );
      auto dataName_gate_inv = xmlNode_gate_inv.append_child( "data" );
      dataName_gate_inv.append_attribute( "key" ) = "nodeName";
      dataName_gate_inv.text().set( index );

      // edge1: root_id -> current_index
      auto edge1 = graphNode.append_child( "edge" );
      edge1.append_attribute( "source" ) = root_id;
      edge1.append_attribute( "target" ) = current_index;
      // edge2: current_index -> po_id
      auto edge2 = graphNode.append_child( "edge" );
      edge2.append_attribute( "source" ) = current_index;
      edge2.append_attribute( "target" ) = po_id;
    }
    else
    {
      auto edge = graphNode.append_child( "edge" );
      edge.append_attribute( "source" ) = root_id;
      edge.append_attribute( "target" ) = po_id;
    }
  } );
  doc.save_file( file.c_str() );
}

/**
 * @brief write current design into graphml file
 */
void write_graphml( const std::string& file )
{

  auto ntktype = lfLntINST->get_ntktype_curr();
  lfLmINST->update_logic( ntktype );
  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();
    graphmize( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();
    graphmize( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();
    graphmize( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();
    graphmize( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG )
  {
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();
    graphmize( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_FPGA )
  {
    lf::logic::lsils::klut_seq_network ntk = lfLmINST->current<lf::logic::lsils::klut_seq_network>();
    std::cerr << "TODO ing!\n";
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_NETLIST_ASIC )
  {
    lf::logic::lsils::blut_seq_network ntk = lfLmINST->current<lf::logic::lsils::blut_seq_network>();
    std::cerr << "TODO ing!\n";
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_FPGA )
  {
    babc::Abc_Frame_t* ntk = lfLmINST->current<babc::Abc_Frame_t*>();
    std::cerr << "TODO ing!\n";
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_ASIC )
  {
    babc::Abc_Frame_t* ntk = lfLmINST->current<babc::Abc_Frame_t*>();
    std::cerr << "TODO ing!\n";
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }
}

} // end namespace logic

} // end namespace lf