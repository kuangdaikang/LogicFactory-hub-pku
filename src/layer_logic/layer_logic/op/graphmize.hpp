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
  ntk.foreach_gate( [&]( auto const& g ) {
    if ( ntk.is_and( g ) )
    {
      // create and node in graphml
    }
    else if ( ntk.is_nand( g ) )
    {
      // create or node in graphml
    }
    else if ( ntk.is_or( g ) )
    {
      // create or node in graphml
    }
    else if ( ntk.is_nor( g ) )
    {
      // create or node in graphml
    }
    else if ( ntk.is_xor( g ) )
    {
      // create or node in graphml
    }
    else if ( ntk.is_xnor( g ) )
    {
      // create or node in graphml
    }
    else if ( ntk.is_maj( g ) )
    {
      // create or node in graphml
    }
    else
    {
      assert( false );
    }
  } );
}

// #include <cstdio>
// #include <cstdlib>
// #include <vector>
// #include <set>
// #include <algorithm>
// #include <iostream>
// #include <fstream>
// #include <pugixml.hpp>

// #include "operations/io/reader.hpp"
// #include "operations/io/detail/write_dot.hpp"
// #include "database/views/depth_view.hpp"

// int main(int argc, char **argv) {
//     /**
//      * @brief usages
//      * ./aig2graphml <path_aig_in> <path_out>
//      */
//     if (argc < 3 || argc > 3) {
//         printf("[Error], please refer to the usage:\n");
//         printf("./circuit2graphml <path_in> <path_out>\n");
//         return -1;
//     }
//     std::string path_in = std::string(argv[1]);  // aig path
//     std::string path_out = std::string(argv[2]); // out path
//     iFPGA::aig_network aig;
//     iFPGA::write_verilog_params ports;
//     iFPGA::Reader reader(path_in, aig, ports);

//     // 用于后续给新增加的inverter作为id
//     uint32_t current_index = aig.size();
//     std::unordered_map<iFPGA::aig_network::signal, uint32_t> inverter_index_map;

//     // 创建一个XML文档
//     pugi::xml_document doc;
//     auto declarationNode = doc.append_child(pugi::node_declaration);
//     declarationNode.append_attribute("version") = "1.0";
//     declarationNode.append_attribute("encoding") = "UTF-8";
//     declarationNode.append_attribute("standalone") = "no";

//     // 创建GraphML根节点
//     auto graphmlNode = doc.append_child("graphml");
//     graphmlNode.append_attribute("xmlns") = "http://graphml.graphdrawing.org/xmlns";
//     graphmlNode.append_attribute("xmlns:xsi") = "http://www.w3.org/2001/XMLSchema-instance";
//     graphmlNode.append_attribute("xsi:schemaLocation") = "http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd";

//     // 创建图节点
//     auto graphNode = graphmlNode.append_child("graph");
//     graphNode.append_attribute("id") = "G";
//     graphNode.append_attribute("edgedefault") = "directed";

//     auto keyForNodeType = graphmlNode.append_child("key");
//     keyForNodeType.append_attribute("id") = "nodeType";
//     keyForNodeType.append_attribute("for") = "node";
//     keyForNodeType.append_attribute("attr.name") = "type";
//     keyForNodeType.append_attribute("attr.type") = "string";

//     auto keyForEdgeWeight = graphmlNode.append_child("key");
//     keyForEdgeWeight.append_attribute("id") = "edgeType";
//     keyForEdgeWeight.append_attribute("for") = "edge";
//     keyForEdgeWeight.append_attribute("attr.name") = "type";
//     keyForEdgeWeight.append_attribute("attr.type") = "string";

//     // constant
//     auto constant_id = aig.node_to_index(aig.get_node(aig.get_constant(false)));
//     auto xmlNode_constant = graphNode.append_child("node");
//     xmlNode_constant.append_attribute("id") = constant_id;
//     auto dataNode_constant = xmlNode_constant.append_child("data");
//     dataNode_constant.append_attribute("key") = "nodeType";
//     dataNode_constant.text().set("constant");

//     // PIs
//     aig.foreach_pi([&](auto const &pi, auto ipi) {
//         auto pi_id = aig.node_to_index(pi);
//         auto xmlNode_pi = graphNode.append_child("node");
//         xmlNode_pi.append_attribute("id") = pi_id;
//         auto dataNode_pi = xmlNode_pi.append_child("data");
//         dataNode_pi.append_attribute("key") = "nodeType";
//         dataNode_pi.text().set("input");
//     });

//     // internal nodes
//     aig.foreach_gate([&](auto const &n) {
//         auto nid = aig.node_to_index(n);

//         auto xmlNode_gate = graphNode.append_child("node");
//         xmlNode_gate.append_attribute("id") = nid;
//         auto dataNode_gate = xmlNode_gate.append_child("data");
//         dataNode_gate.append_attribute("key") = "nodeType";
//         dataNode_gate.text().set("gate");

//         aig.foreach_fanin(n, [&](auto const &c) {
//             auto cid = aig.node_to_index(aig.get_node(c));
//             // add inverter
//             if (aig.is_complemented(c)) {
//                 // 使用mapping的节点编号
//                 inverter_index_map[c] = ++current_index;

//                 // create the inverter node
//                 auto xmlNode_gate_inv = graphNode.append_child("node");
//                 xmlNode_gate_inv.append_attribute("id") = current_index;
//                 auto dataNode_gate = xmlNode_gate_inv.append_child("data");
//                 dataNode_gate.append_attribute("key") = "nodeType";
//                 dataNode_gate.text().set("gate");

//                 // edge1: cid -> current_index
//                 auto edge1 = graphNode.append_child("edge");
//                 edge1.append_attribute("source") = cid;
//                 edge1.append_attribute("target") = current_index;
//                 auto dataEdge1 = edge1.append_child("data");
//                 dataEdge1.append_attribute("key") = "edgeType";
//                 dataEdge1.text().set("buffer");
//                 // edge2: current_index -> nid
//                 auto edge2 = graphNode.append_child("edge");
//                 edge2.append_attribute("source") = current_index;
//                 edge2.append_attribute("target") = nid;
//                 auto dataEdge2 = edge2.append_child("data");
//                 dataEdge2.append_attribute("key") = "edgeType";
//                 dataEdge2.text().set("buffer");
//             } else {
//                 auto edge = graphNode.append_child("edge");
//                 edge.append_attribute("source") = cid;
//                 edge.append_attribute("target") = nid;
//                 auto dataEdge = edge.append_child("data");
//                 dataEdge.append_attribute("key") = "edgeType";
//                 dataEdge.text().set("buffer");
//             }
//         });
//     });

//     // POs
//     aig.foreach_po([&](auto const &po, auto ipo) {
//         auto npo = aig.get_node(po);
//         auto po_id = ++current_index; // PO 也将作为一个独立的点进行处理
//         auto root_id = aig.node_to_index(npo);

//         auto xmlNode_gate = graphNode.append_child("node");
//         xmlNode_gate.append_attribute("id") = po_id;
//         auto dataNode_gate = xmlNode_gate.append_child("data");
//         dataNode_gate.append_attribute("key") = "nodeType";
//         dataNode_gate.text().set("output");

//         // add inverter
//         if (aig.is_complemented(po)) {
//             // 使用mapping的节点编号
//             inverter_index_map[po] = ++current_index;

//             // create the inverter node
//             auto xmlNode_gate_inv = graphNode.append_child("node");
//             xmlNode_gate_inv.append_attribute("id") = current_index;
//             auto dataNode_gate = xmlNode_gate_inv.append_child("data");
//             dataNode_gate.append_attribute("key") = "nodeType";
//             dataNode_gate.text().set("gate");

//             // edge1: cid -> current_index
//             auto edge1 = graphNode.append_child("edge");
//             edge1.append_attribute("source") = root_id;
//             edge1.append_attribute("target") = current_index;
//             auto dataEdge1 = edge1.append_child("data");
//             dataEdge1.append_attribute("key") = "edgeType";
//             dataEdge1.text().set("buffer");
//             // edge2: current_index -> nid
//             auto edge2 = graphNode.append_child("edge");
//             edge2.append_attribute("source") = current_index;
//             edge2.append_attribute("target") = po_id;
//             auto dataEdge2 = edge2.append_child("data");
//             dataEdge2.append_attribute("key") = "edgeType";
//             dataEdge2.text().set("buffer");
//         } else {
//             auto edge = graphNode.append_child("edge");
//             edge.append_attribute("source") = root_id;
//             edge.append_attribute("target") = po_id;
//             auto dataEdge = edge.append_child("data");
//             dataEdge.append_attribute("key") = "edgeType";
//             dataEdge.text().set("buffer");
//         }
//     });

//     doc.save_file(path_out.c_str());

//     // iFPGA::write_dot(aig, path_out + ".dot");

//     // iFPGA::depth_view daig(aig);
//     // std::cout << "Profile:\n";
//     // std::cout << "constant size: " << 1 << std::endl;
//     // std::cout << "input size: " << aig.num_pis() << std::endl;
//     // std::cout << "output size: " << aig.num_pos() << std::endl;
//     // std::cout << "gates origin: " << aig.num_gates() << std::endl;
//     // std::cout << "gates pooling: " << aig.num_gates() << std::endl;
//     // std::cout << "depth origin: " << daig.depth() << std::endl;
//     // std::cout << "depth pooling: " << daig.depth() << std::endl;
//     return 1;
// }

} // end namespace lf