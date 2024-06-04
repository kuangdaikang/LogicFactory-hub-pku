#include "mockturtle/networks/aig.hpp"
#include "mockturtle/networks/gtg.hpp"
#include "mockturtle/networks/mig.hpp"
#include "mockturtle/networks/xag.hpp"
#include "mockturtle/networks/xmg.hpp"

#include "pugixml.hpp"

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
  using Node = typename Ntk::node;
  using Signal = typename Ntk::signal;
  static_assert( std::is_same_v<NtkBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkBase, mockturtle::gtg_network>,
                 "ntk is not an ntk, XAG, MIG, XMG, or GTG" );

  uint32_t current_index = ntk.size();

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

  // set the type of node
  auto keyForNodeType = graphmlNode.append_child( "key" );
  keyForNodeType.append_attribute( "id" ) = "nodeType";
  keyForNodeType.append_attribute( "for" ) = "node";
  keyForNodeType.append_attribute( "attr.name" ) = "type";
  keyForNodeType.append_attribute( "attr.type" ) = "string";

  // set the index of node
  auto keyForNodeIndex = graphmlNode.append_child( "key" );
  keyForNodeIndex.append_attribute( "id" ) = "nodeIndex";
  keyForNodeIndex.append_attribute( "for" ) = "node";
  keyForNodeIndex.append_attribute( "attr.name" ) = "index";
  keyForNodeIndex.append_attribute( "attr.type" ) = "int";

  // set the type of node
  auto keyForEdgeWeight = graphmlNode.append_child( "key" );
  keyForEdgeWeight.append_attribute( "id" ) = "edgeType";
  keyForEdgeWeight.append_attribute( "for" ) = "edge";
  keyForEdgeWeight.append_attribute( "attr.name" ) = "type";
  keyForEdgeWeight.append_attribute( "attr.type" ) = "string";

  // constant
  auto constant_id_zero = ntk.node_to_index( ntk.get_node( ntk.get_constant( false ) ) );
  auto constant_id_one = ntk.node_to_index( ntk.get_node( ntk.get_constant( true ) ) );
  auto xmlNode_constant = graphNode.append_child( "node" );
  xmlNode_constant.append_attribute( "id" ) = constant_id_zero;
  auto dataNode_constant = xmlNode_constant.append_child( "data" );
  dataNode_constant.append_attribute( "key" ) = "nodeType";
  dataNode_constant.text().set( "zero" );
  auto dataIndex_constant = xmlNode_constant.append_child( "data" );
  dataIndex_constant.append_attribute( "key" ) = "nodeIndex";
  dataIndex_constant.text().set( 0 );
  if ( constant_id_one != constant_id_zero )
  {
    xmlNode_constant = graphNode.append_child( "node" );
    xmlNode_constant.append_attribute( "id" ) = constant_id_one;
    auto dataNode_constant = xmlNode_constant.append_child( "data" );
    dataNode_constant.append_attribute( "key" ) = "nodeType";
    dataNode_constant.text().set( "one" );
    auto dataIndex_constant = xmlNode_constant.append_child( "data" );
    dataIndex_constant.append_attribute( "key" ) = "nodeIndex";
    dataIndex_constant.text().set( 0 );
  }

  // primary inputs
  ntk.foreach_pi( [&]( auto const& pi, uint32_t index ) {
    auto pi_id = ntk.node_to_index( pi );
    auto xmlNode_pi = graphNode.append_child( "node" );
    xmlNode_pi.append_attribute( "id" ) = pi_id;
    auto dataNode_pi = xmlNode_pi.append_child( "data" );
    dataNode_pi.append_attribute( "key" ) = "nodeType";
    dataNode_pi.text().set( "pi" );
    auto dataIndex_pi = xmlNode_pi.append_child( "data" );
    dataIndex_pi.append_attribute( "key" ) = "nodeIndex";
    dataIndex_pi.text().set( index );
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
      dataNode_gate.text().set( "and" );
    }
    else if ( ntk.is_nand( g ) )
    {
      dataNode_gate.text().set( "nand" );
    }
    else if ( ntk.is_or( g ) )
    {
      dataNode_gate.text().set( "or" );
    }
    else if ( ntk.is_nor( g ) )
    {
      dataNode_gate.text().set( "nor" );
    }
    else if ( ntk.is_xor( g ) )
    {
      dataNode_gate.text().set( "xor" );
    }
    else if ( ntk.is_xnor( g ) )
    {
      dataNode_gate.text().set( "xnor" );
    }
    else if ( ntk.is_lt( g ) )
    {
      dataNode_gate.text().set( "lt" );
    }
    else if ( ntk.is_le( g ) )
    {
      dataNode_gate.text().set( "le" );
    }
    else if ( ntk.is_maj( g ) )
    {
      dataNode_gate.text().set( "maj" );
    }
    else
    {
      assert( false );
    }
    auto dataIndex_gate = xmlNode_gate.append_child( "data" );
    dataIndex_gate.append_attribute( "key" ) = "nodeIndex";
    dataIndex_gate.text().set( index );

    // edge {children[0]->g, children[1]->g}
    ntk.foreach_fanin( g, [&]( auto const& c ) {
      auto child_id = ntk.node_to_index( ntk.get_node( c ) );

      auto edge = graphNode.append_child( "edge" );
      edge.append_attribute( "source" ) = child_id;
      edge.append_attribute( "target" ) = g_id;
      auto dataEdge = edge.append_child( "data" );
      dataEdge.append_attribute( "key" ) = "edgeType";
      if ( ntk.is_complemented( c ) )
      {
        dataEdge.text().set( "not" );
      }
      else
      {
        dataEdge.text().set( "buf" );
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
    dataNode_po.text().set( "po" );
    auto dataIndex_po = xmlNode_po.append_child( "data" );
    dataIndex_po.append_attribute( "key" ) = "nodeIndex";
    dataIndex_po.text().set( index );

    auto edge = graphNode.append_child( "edge" );
    edge.append_attribute( "source" ) = root_id;
    edge.append_attribute( "target" ) = po_id;
    auto dataEdge = edge.append_child( "data" );
    dataEdge.append_attribute( "key" ) = "edgeType";
    if ( ntk.is_complemented( po ) )
    {
      dataEdge.text().set( "not" );
    }
    else
    {
      dataEdge.text().set( "buf" );
    }
  } );
  doc.save_file( file.c_str() );
}

} // end namespace lf