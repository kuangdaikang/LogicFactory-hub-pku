#pragma once

#include "layer_logic/logic_manager.hpp"
#include "pugixml.hpp"
#include "kitty/kitty.hpp"

#include <unordered_map>
#include <bitset>

namespace lf
{

namespace logic
{

std::string uint64_to_hex( babc::word num )
{
  char buffer[17]; // 16 digits for the hexadecimal representation + 1 for the null terminator
  snprintf( buffer, sizeof( buffer ), "%016llx", num );
  std::string hexStr( buffer );
  return "64'\h" + hexStr;
}

std::string expand_hex( std::string hexStr )
{
  std::string res = hexStr;
  while ( res.size() < 16 )
  {
    res += hexStr;
  }
  return "64'\h" + res;
}

static const std::unordered_map<std::string, std::string> NODE_FUNC_MAP = {
    { "PI", "64'hxxxxxxxxxxxxxxxx" },
    { "PO", "64'hxxxxxxxxxxxxxxxx" },
    { "CONST0", "64'h0000000000000000" },   // {0} * 64
    { "CONST1", "64'hffffffffffffffff" },   // {1} * 64
    { "INVERTER", "64'h5555555555555555" }, // {01} * 32
    { "BUFFER", "64'haaaaaaaaaaaaaaaa" },   // {10} * 32
    { "AND2", "64'h8888888888888888" },     // {1000} * 16
    { "NAND2", "64'h7777777777777777" },    // {0111} * 16
    { "OR2", "64'heeeeeeeeeeeeeeee" },      // {1110} * 16
    { "NOR2", "64'h1111111111111111" },     // {0001} * 16
    { "XOR2", "64'h6666666666666666" },     // {0110} * 16
    { "XNOR2", "64'h9999999999999999" } };  // {1001} * 16

/**
 * @brief generate the graphml file for current network.
 *
 * @param ntk the given network
 * @param file file.
 */
template<class Ntk>
void lsils_to_graphml( Ntk const& ntk, const std::string& file )
{
  using Node = typename Ntk::node;
  using Signal = typename Ntk::signal;
  static_assert( std::is_same_v<Ntk, lsils::aig_comb_network> ||
                     std::is_same_v<Ntk, lsils::oig_comb_network> ||
                     std::is_same_v<Ntk, lsils::aog_comb_network> ||
                     std::is_same_v<Ntk, lsils::xag_comb_network> ||
                     std::is_same_v<Ntk, lsils::xog_comb_network> ||
                     std::is_same_v<Ntk, lsils::mig_comb_network> ||
                     std::is_same_v<Ntk, lsils::xmg_comb_network> ||
                     std::is_same_v<Ntk, lsils::primary_comb_network> ||
                     std::is_same_v<Ntk, lsils::gtg_comb_network> ||
                     std::is_same_v<Ntk, lf::logic::lsils::klut_comb_network> ||
                     std::is_same_v<Ntk, lf::logic::lsils::blut_comb_network> ||
                     std::is_same_v<Ntk, lsils::aig_seq_network> ||
                     std::is_same_v<Ntk, lsils::oig_seq_network> ||
                     std::is_same_v<Ntk, lsils::aog_seq_network> ||
                     std::is_same_v<Ntk, lsils::xag_seq_network> ||
                     std::is_same_v<Ntk, lsils::xog_seq_network> ||
                     std::is_same_v<Ntk, lsils::mig_seq_network> ||
                     std::is_same_v<Ntk, lsils::xmg_seq_network> ||
                     std::is_same_v<Ntk, lsils::primary_seq_network> ||
                     std::is_same_v<Ntk, lsils::gtg_seq_network> ||
                     std::is_same_v<Ntk, lf::logic::lsils::klut_seq_network> ||
                     std::is_same_v<Ntk, lf::logic::lsils::blut_seq_network>,
                 "Ntk is not an AIG, OIG, AOG, XAG, XOG, MIG, XMG, Primary, GTG, KLUT or BLUT" );

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

  // node attr: func
  auto keyForNodeFunc = graphmlNode.append_child( "key" );
  keyForNodeFunc.append_attribute( "id" ) = "nodeFunc";
  keyForNodeFunc.append_attribute( "for" ) = "node";
  keyForNodeFunc.append_attribute( "attr.name" ) = "func";
  keyForNodeFunc.append_attribute( "attr.type" ) = "string";

  // id for new add gates
  uint32_t current_index = ntk.size();
  std::unordered_map<Signal, uint32_t> inverter_index_map;

  // constant
  auto constant_id_zero = ntk.node_to_index( ntk.get_node( ntk.get_constant( false ) ) );
  auto constant_id_one = ntk.node_to_index( ntk.get_node( ntk.get_constant( true ) ) );
  auto xmlNode_constant = graphNode.append_child( "node" );
  xmlNode_constant.append_attribute( "id" ) = constant_id_zero;
  auto dataType_constant = xmlNode_constant.append_child( "data" );
  dataType_constant.append_attribute( "key" ) = "nodeType";
  dataType_constant.text().set( "CONST0" );
  auto dataFunc_constant = xmlNode_constant.append_child( "data" );
  dataFunc_constant.append_attribute( "key" ) = "nodeFunc";
  dataFunc_constant.text().set( NODE_FUNC_MAP.at( "CONST0" ).c_str() );

  if ( constant_id_one != constant_id_zero )
  {
    xmlNode_constant = graphNode.append_child( "node" );
    xmlNode_constant.append_attribute( "id" ) = constant_id_one;
    auto dataType_constant = xmlNode_constant.append_child( "data" );
    dataType_constant.append_attribute( "key" ) = "nodeType";
    dataType_constant.text().set( "CONST1" );
    auto dataFunc_constant = xmlNode_constant.append_child( "data" );
    dataFunc_constant.append_attribute( "key" ) = "nodeFunc";
    dataFunc_constant.text().set( NODE_FUNC_MAP.at( "CONST1" ).c_str() );
  }

  // primary inputs
  ntk.foreach_pi( [&]( auto const& pi, uint32_t index ) {
    auto pi_id = ntk.node_to_index( pi );
    auto xmlNode_pi = graphNode.append_child( "node" );
    xmlNode_pi.append_attribute( "id" ) = pi_id;
    auto dataType_pi = xmlNode_pi.append_child( "data" );
    dataType_pi.append_attribute( "key" ) = "nodeType";
    dataType_pi.text().set( "PI" );
    auto dataFunc_pi = xmlNode_pi.append_child( "data" );
    dataFunc_pi.append_attribute( "key" ) = "nodeFunc";
    dataFunc_pi.text().set( NODE_FUNC_MAP.at( "PI" ).c_str() );
  } );

  // internal gates
  ntk.foreach_gate( [&]( auto const& g, uint32_t index ) {
    auto g_id = ntk.node_to_index( g );

    // add inverter before the gate
    std::vector<uint32_t> fanins_id;
    ntk.foreach_fanin( g, [&]( auto const& c, int index ) {
      auto child_id = ntk.node_to_index( ntk.get_node( c ) );
      // add inverter
      if ( ntk.is_complemented( c ) )
      {
        inverter_index_map[c] = ++current_index;
        fanins_id.push_back( inverter_index_map[c] );
        // create the inverter node
        auto xmlNode_gate_inv = graphNode.append_child( "node" );
        xmlNode_gate_inv.append_attribute( "id" ) = current_index;
        auto dataType_gate_inv = xmlNode_gate_inv.append_child( "data" );
        dataType_gate_inv.append_attribute( "key" ) = "nodeType";
        dataType_gate_inv.text().set( "INVERTER" );
        auto dataFunc_gate_inv = xmlNode_gate_inv.append_child( "data" );
        dataFunc_gate_inv.append_attribute( "key" ) = "nodeFunc";
        dataFunc_gate_inv.text().set( NODE_FUNC_MAP.at( "INVERTER" ).c_str() );
      }
      else
      {
        fanins_id.push_back( child_id );
      }
    } );

    auto xmlNode_gate = graphNode.append_child( "node" );
    xmlNode_gate.append_attribute( "id" ) = g_id;
    // get the node type
    auto dataType_gate = xmlNode_gate.append_child( "data" );
    dataType_gate.append_attribute( "key" ) = "nodeType";
    if constexpr ( std::is_same_v<Ntk, lsils::aig_comb_network> ||
                   std::is_same_v<Ntk, lsils::oig_comb_network> ||
                   std::is_same_v<Ntk, lsils::aog_comb_network> ||
                   std::is_same_v<Ntk, lsils::xag_comb_network> ||
                   std::is_same_v<Ntk, lsils::xog_comb_network> ||
                   std::is_same_v<Ntk, lsils::mig_comb_network> ||
                   std::is_same_v<Ntk, lsils::xmg_comb_network> ||
                   std::is_same_v<Ntk, lsils::primary_comb_network> ||
                   std::is_same_v<Ntk, lsils::gtg_comb_network> ||
                   std::is_same_v<Ntk, lsils::aig_seq_network> ||
                   std::is_same_v<Ntk, lsils::oig_seq_network> ||
                   std::is_same_v<Ntk, lsils::aog_seq_network> ||
                   std::is_same_v<Ntk, lsils::xag_seq_network> ||
                   std::is_same_v<Ntk, lsils::xog_seq_network> ||
                   std::is_same_v<Ntk, lsils::mig_seq_network> ||
                   std::is_same_v<Ntk, lsils::xmg_seq_network> ||
                   std::is_same_v<Ntk, lsils::primary_seq_network> ||
                   std::is_same_v<Ntk, lsils::gtg_seq_network> )
    {
      if ( ntk.is_and( g ) )
      {
        dataType_gate.text().set( "AND2" );
      }
      else if ( ntk.is_nand( g ) )
      {
        dataType_gate.text().set( "NAND2" );
      }
      else if ( ntk.is_or( g ) )
      {
        dataType_gate.text().set( "OR2" );
      }
      else if ( ntk.is_nor( g ) )
      {
        dataType_gate.text().set( "NOR2" );
      }
      else if ( ntk.is_xor( g ) )
      {
        dataType_gate.text().set( "XOR2" );
      }
      else if ( ntk.is_xnor( g ) )
      {
        dataType_gate.text().set( "XNOR2" );
      }
      else if ( ntk.is_maj( g ) )
      {
        dataType_gate.text().set( "MAJ3" );
      }
      else if ( ntk.is_xor3( g ) )
      {
        dataType_gate.text().set( "XOR3" );
      }
      else if ( ntk.is_nand3( g ) )
      {
        dataType_gate.text().set( "NAND3" );
      }
      else if ( ntk.is_nor3( g ) )
      {
        dataType_gate.text().set( "NOR3" );
      }
      else if ( ntk.is_mux21( g ) || ntk.is_ite( g ) )
      {
        dataType_gate.text().set( "MUX21" );
      }
      else if ( ntk.is_nmux21( g ) )
      {
        dataType_gate.text().set( "NMUX21" );
      }
      else if ( ntk.is_aoi21( g ) )
      {
        dataType_gate.text().set( "AOI21" );
      }
      else if ( ntk.is_oai21( g ) )
      {
        dataType_gate.text().set( "OAI21" );
      }
      else if ( ntk.is_axi21( g ) )
      {
        dataType_gate.text().set( "AXI21" );
      }
      else if ( ntk.is_xai21( g ) )
      {
        dataType_gate.text().set( "XAI21" );
      }
      else if ( ntk.is_oxi21( g ) )
      {
        dataType_gate.text().set( "OXI21" );
      }
      else if ( ntk.is_xoi21( g ) )
      {
        dataType_gate.text().set( "XOI21" );
      }
      else
      {
        assert( false );
      }
    }
    else if constexpr ( std::is_same_v<Ntk, lf::logic::lsils::klut_seq_network> )
    {
      std::string node_name = "LUT" + std::to_string( ntk.fanin_size( g ) );
      dataType_gate.text().set( node_name.c_str() );
    }
    else if constexpr ( std::is_same_v<Ntk, lf::logic::lsils::blut_seq_network> )
    {
      assert( ntk.has_binding( g ) );
      auto gate = ntk.get_binding( g );
      dataType_gate.text().set( gate.name.c_str() );
    }
    // get the node function
    auto dataFunc_gate = xmlNode_gate.append_child( "data" );
    dataFunc_gate.append_attribute( "key" ) = "nodeFunc";
    auto func = ntk.node_function( g );
    auto hex = expand_hex( kitty::to_hex( func ) );
    dataFunc_gate.text().set( hex.c_str() );

    // edge {children[0]->g, children[1]->g}
    ntk.foreach_fanin( g, [&]( auto const& c, int index_child ) {
      auto child_id = ntk.node_to_index( ntk.get_node( c ) );
      // add inverter
      if ( ntk.is_complemented( c ) )
      {
        // edge1: child_id -> current_index
        auto edge1 = graphNode.append_child( "edge" );
        edge1.append_attribute( "source" ) = child_id;
        edge1.append_attribute( "target" ) = fanins_id[index_child];
        // edge2: current_index -> g_id
        auto edge2 = graphNode.append_child( "edge" );
        edge2.append_attribute( "source" ) = fanins_id[index_child];
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

    // add inverter before the gate
    uint32_t inverter_id = 0;
    if ( ntk.is_complemented( po ) )
    {
      inverter_index_map[po] = ++current_index;
      inverter_id = inverter_index_map[po];

      // create the inverter node
      auto xmlNode_gate_inv = graphNode.append_child( "node" );
      xmlNode_gate_inv.append_attribute( "id" ) = current_index;
      auto dataType_gate_inv = xmlNode_gate_inv.append_child( "data" );
      dataType_gate_inv.append_attribute( "key" ) = "nodeType";
      dataType_gate_inv.text().set( "INVERTER" );
      auto dataFunc_gate_inv = xmlNode_gate_inv.append_child( "data" );
      dataFunc_gate_inv.append_attribute( "key" ) = "nodeFunc";
      dataFunc_gate_inv.text().set( NODE_FUNC_MAP.at( "INVERTER" ).c_str() );
    }

    auto xmlNode_po = graphNode.append_child( "node" );
    xmlNode_po.append_attribute( "id" ) = po_id;
    auto dataType_po = xmlNode_po.append_child( "data" );
    dataType_po.append_attribute( "key" ) = "nodeType";
    dataType_po.text().set( "PO" );
    auto dataFunc_po = xmlNode_po.append_child( "data" );
    dataFunc_po.append_attribute( "key" ) = "nodeFunc";
    dataFunc_po.text().set( NODE_FUNC_MAP.at( "PO" ).c_str() );

    if ( ntk.is_complemented( po ) )
    {
      // edge1: root_id -> inverter_id
      auto edge1 = graphNode.append_child( "edge" );
      edge1.append_attribute( "source" ) = root_id;
      edge1.append_attribute( "target" ) = inverter_id;
      // edge2: inverter_id -> po_id
      auto edge2 = graphNode.append_child( "edge" );
      edge2.append_attribute( "source" ) = inverter_id;
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
 * @brief write the abc network into graphml file
 */
void abc_to_graphml( const babc::Abc_Frame_t* frame, const std::string& file )
{
  babc::Abc_Ntk_t* pNtk = babc::Abc_FrameReadNtk( frame );
  babc::Abc_Ntk_t* pNtkTemp;
  babc::Hop_Obj_t* pFunc;
  babc::Abc_Obj_t *pObj, *pFanin, *pNode0, *pNode1;
  int i, k;
  uint32_t current_index = babc::Abc_NtkObjNum( pNtk );
  std::unordered_map<babc::Abc_Obj_t*, uint32_t> inverter_index_map;
  // id for new add gates

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
  auto keyForNodeFunc = graphmlNode.append_child( "key" );
  keyForNodeFunc.append_attribute( "id" ) = "nodeFunc";
  keyForNodeFunc.append_attribute( "for" ) = "node";
  keyForNodeFunc.append_attribute( "attr.name" ) = "func";
  keyForNodeFunc.append_attribute( "attr.type" ) = "string";

  assert( babc::Abc_NtkIsStrash( pNtk ) || babc::Abc_NtkIsLogic( pNtk ) );

  // start the output stream

  // constant node
  if ( babc::Abc_NtkIsStrash( pNtk ) ) // AIG
  {
    pObj = babc::Abc_AigConst1( pNtk );
    int const_id = babc::Abc_ObjId( pObj );
    auto xmlNode_constant = graphNode.append_child( "node" );
    xmlNode_constant.append_attribute( "id" ) = const_id;
    auto dataType_constant = xmlNode_constant.append_child( "data" );
    dataType_constant.append_attribute( "key" ) = "nodeType";
    dataType_constant.text().set( "CONST0" );
    auto dataFunc_constant = xmlNode_constant.append_child( "data" );
    dataFunc_constant.append_attribute( "key" ) = "nodeFunc";
    dataFunc_constant.text().set( NODE_FUNC_MAP.at( "CONST0" ).c_str() );
  }

  // PIs
  Abc_NtkForEachPi( pNtk, pObj, i )
  {
    int pi_id = babc::Abc_ObjId( pObj );
    auto xmlNode_pi = graphNode.append_child( "node" );
    xmlNode_pi.append_attribute( "id" ) = pi_id;
    auto dataType_pi = xmlNode_pi.append_child( "data" );
    dataType_pi.append_attribute( "key" ) = "nodeType";
    dataType_pi.text().set( "PI" );
    auto dataFunc_pi = xmlNode_pi.append_child( "data" );
    dataFunc_pi.append_attribute( "key" ) = "nodeFunc";
    dataFunc_pi.text().set( NODE_FUNC_MAP.at( "PI" ).c_str() );
  }

  // internal gates / POs
  if ( Abc_NtkIsMappedLogic( pNtk ) ) // ASIC netlist
  {
    /**
     * @note constant is seemed as cell in ASIC netlist
     */
    Abc_NtkForEachNode( pNtk, pObj, i )
    {
      int g_id = babc::Abc_ObjId( pObj );
      babc::Mio_Gate_t* pGate = (babc::Mio_Gate_t*)pObj->pData;
      babc::word func = babc::Mio_GateReadTruth( pGate );
      std::string hex = uint64_to_hex( func );
      std::string gatename = babc::Mio_GateReadName( pGate );
      auto xmlNode_gate = graphNode.append_child( "node" );
      xmlNode_gate.append_attribute( "id" ) = g_id;
      auto dataType_gate = xmlNode_gate.append_child( "data" );
      dataType_gate.append_attribute( "key" ) = "nodeType";
      dataType_gate.text().set( gatename.c_str() );
      auto dataFunc_gate = xmlNode_gate.append_child( "data" );
      dataFunc_gate.append_attribute( "key" ) = "nodeFunc";
      dataFunc_gate.text().set( hex.c_str() );

      Abc_ObjForEachFanin( pObj, pFanin, k )
      {
        int child_id = babc::Abc_ObjId( pFanin );
        auto edge = graphNode.append_child( "edge" );
        edge.append_attribute( "source" ) = child_id;
        edge.append_attribute( "target" ) = g_id;
      }
    }
    Abc_NtkForEachPo( pNtk, pObj, i )
    {
      auto po_id = babc::Abc_ObjId( pObj );
      auto xmlNode_po = graphNode.append_child( "node" );
      xmlNode_po.append_attribute( "id" ) = po_id;
      auto dataType_po = xmlNode_po.append_child( "data" );
      dataType_po.append_attribute( "key" ) = "nodeType";
      dataType_po.text().set( "PO" );
      auto dataFunc_po = xmlNode_po.append_child( "data" );
      dataFunc_po.append_attribute( "key" ) = "nodeFunc";
      dataFunc_po.text().set( NODE_FUNC_MAP.at( "PO" ).c_str() );

      Abc_ObjForEachFanin( pObj, pFanin, k )
      {
        int child_id = babc::Abc_ObjId( pFanin );
        auto edge = graphNode.append_child( "edge" );
        edge.append_attribute( "source" ) = child_id;
        edge.append_attribute( "target" ) = po_id;
      }
    }
  }
  else if ( Abc_NtkIsAigLogic( pNtk ) ) // fpga netlist from AIG
  {
    // get the truth table first
    pNtkTemp = babc::Abc_NtkToNetlist( pNtk ); // 在原始aig后面增加LUT， 所以是： const0， PI， PI, ANDs, LUTs， 对该fpga netlist节点遍历从LUTs开始
    babc::Abc_NtkToSop( pNtkTemp, -1, ABC_INFINITY );
    std::vector<std::string> gates_func;
    gates_func.reserve( babc::Abc_NtkObjNum( pNtkTemp ) );
    Abc_NtkForEachNode( pNtkTemp, pObj, i )
    {
      if ( Abc_ObjFaninNum( pObj ) == 0 )
      {
        continue;
      }
      else
      {
        babc::word func = babc::Abc_SopToTruth( (char*)pObj->pData, Abc_ObjFaninNum( pObj ) );
        auto hex = uint64_to_hex( func );
        gates_func.push_back( hex );
      }
    }
    babc::Abc_NtkDelete( pNtkTemp );
    int count = 0; // for index the truth table
    /**
     * @note constant is seemed as node in FPGA netlist, but need to find its id
     */
    // make sure the constant id, and create the constant node
    int fpga_const0_id = -1;
    int fpga_const1_id = -1;
    Abc_NtkForEachNode( pNtk, pObj, i )
    {
      if ( Abc_ObjFaninNum( pObj ) == 0 )
      {
        if ( Abc_NodeIsConst1( pObj ) )
        {
          fpga_const0_id = babc::Abc_ObjId( babc::Abc_ObjFanout( pObj, 0 ) );
        }
        else
        {
          fpga_const1_id = babc::Abc_ObjId( babc::Abc_ObjFanout( pObj, 0 ) );
        }
      }
    }
    if ( fpga_const0_id >= 0 )
    {
      auto xmlNode_const0 = graphNode.append_child( "node" );
      xmlNode_const0.append_attribute( "id" ) = fpga_const0_id;
      auto dataType_const0 = xmlNode_const0.append_child( "data" );
      dataType_const0.append_attribute( "key" ) = "nodeType";
      dataType_const0.text().set( "CONST0" );
      auto dataFunc_const0 = xmlNode_const0.append_child( "data" );
      dataFunc_const0.append_attribute( "key" ) = "nodeFunc";
      dataFunc_const0.text().set( NODE_FUNC_MAP.at( "CONST0" ).c_str() );
    }
    if ( fpga_const1_id >= 0 )
    {
      auto xmlNode_const1 = graphNode.append_child( "node" );
      xmlNode_const1.append_attribute( "id" ) = fpga_const1_id;
      auto dataType_const1 = xmlNode_const1.append_child( "data" );
      dataType_const1.append_attribute( "key" ) = "nodeType";
      dataType_const1.text().set( "CONST1" );
      auto dataFunc_const1 = xmlNode_const1.append_child( "data" );
      dataFunc_const1.append_attribute( "key" ) = "nodeFunc";
      dataFunc_const1.text().set( NODE_FUNC_MAP.at( "CONST1" ).c_str() );
    }

    // write the gates
    Abc_NtkForEachNode( pNtk, pObj, i )
    {
      int g_id = babc::Abc_ObjId( pObj );
      // constant condition
      if ( Abc_ObjFaninNum( pObj ) == 0 )
      {
        continue;
      }
      else
      {
        std::string hex = gates_func[count++];
        std::string gatename = "LUT" + std::to_string( babc::Abc_ObjFaninNum( pObj ) );
        // standard LUT
        auto xmlNode_gate = graphNode.append_child( "node" );
        xmlNode_gate.append_attribute( "id" ) = g_id;
        auto dataType_gate = xmlNode_gate.append_child( "data" );
        dataType_gate.append_attribute( "key" ) = "nodeType";
        dataType_gate.text().set( gatename.c_str() );
        auto dataFunc_gate = xmlNode_gate.append_child( "data" );
        dataFunc_gate.append_attribute( "key" ) = "nodeFunc";
        dataFunc_gate.text().set( hex.c_str() );

        Abc_ObjForEachFanin( pObj, pFanin, k )
        {
          int child_id = babc::Abc_ObjId( pFanin );
          auto edge = graphNode.append_child( "edge" );
          edge.append_attribute( "source" ) = child_id;
          edge.append_attribute( "target" ) = g_id;
        }
      }
    }
    Abc_NtkForEachPo( pNtk, pObj, i )
    {
      auto po_id = babc::Abc_ObjId( pObj );
      auto xmlNode_po = graphNode.append_child( "node" );
      xmlNode_po.append_attribute( "id" ) = po_id;
      auto dataType_po = xmlNode_po.append_child( "data" );
      dataType_po.append_attribute( "key" ) = "nodeType";
      dataType_po.text().set( "PO" );
      auto dataFunc_po = xmlNode_po.append_child( "data" );
      dataFunc_po.append_attribute( "key" ) = "nodeFunc";
      dataFunc_po.text().set( NODE_FUNC_MAP.at( "PO" ).c_str() );

      Abc_ObjForEachFanin( pObj, pFanin, k )
      {
        int child_id = babc::Abc_ObjId( pFanin );
        auto edge = graphNode.append_child( "edge" );
        edge.append_attribute( "source" ) = child_id;
        edge.append_attribute( "target" ) = po_id;
      }
    }
  }
  else if ( Abc_NtkHasAig( pNtk ) ) // AIG
  {
    Abc_AigForEachAnd( pNtk, pObj, i )
    {
      int g_id = babc::Abc_ObjId( pObj );
      // add inverter before the gate
      std::vector<int> fanins_id;
      Abc_ObjForEachFanin( pObj, pFanin, k )
      {
        int child_id = babc::Abc_ObjId( pFanin );
        if ( babc::Abc_ObjFaninC( pObj, k ) )
        {
          inverter_index_map[pFanin] = ++current_index;
          fanins_id.push_back( inverter_index_map[pFanin] );
          // create the inverter node
          auto xmlNode_gate_inv = graphNode.append_child( "node" );
          xmlNode_gate_inv.append_attribute( "id" ) = current_index;
          auto dataType_gate_inv = xmlNode_gate_inv.append_child( "data" );
          dataType_gate_inv.append_attribute( "key" ) = "nodeType";
          dataType_gate_inv.text().set( "INVERTER" );
          auto dataFunc_gate_inv = xmlNode_gate_inv.append_child( "data" );
          dataFunc_gate_inv.append_attribute( "key" ) = "nodeFunc";
          dataFunc_gate_inv.text().set( NODE_FUNC_MAP.at( "INVERTER" ).c_str() );
        }
        else
        {
          fanins_id.push_back( child_id );
          auto edge = graphNode.append_child( "edge" );
          edge.append_attribute( "source" ) = child_id;
          edge.append_attribute( "target" ) = g_id;
        }
      }

      auto xmlNode_gate = graphNode.append_child( "node" );
      xmlNode_gate.append_attribute( "id" ) = g_id;
      auto dataType_gate = xmlNode_gate.append_child( "data" );
      dataType_gate.append_attribute( "key" ) = "nodeType";
      dataType_gate.text().set( "AND2" );
      auto dataFunc_gate = xmlNode_gate.append_child( "data" );
      dataFunc_gate.append_attribute( "key" ) = "nodeFunc";
      dataFunc_gate.text().set( NODE_FUNC_MAP.at( "AND2" ).c_str() );

      Abc_ObjForEachFanin( pObj, pFanin, k )
      {
        int child_id = babc::Abc_ObjId( pFanin );
        if ( babc::Abc_ObjFaninC( pObj, k ) )
        {
          // edge1: child_id -> fanins_id[k]
          auto edge1 = graphNode.append_child( "edge" );
          edge1.append_attribute( "source" ) = child_id;
          edge1.append_attribute( "target" ) = fanins_id[k];
          // edge2: fanins_id[k] -> g_id
          auto edge2 = graphNode.append_child( "edge" );
          edge2.append_attribute( "source" ) = fanins_id[k];
          edge2.append_attribute( "target" ) = g_id;
        }
        else
        {
          auto edge = graphNode.append_child( "edge" );
          edge.append_attribute( "source" ) = child_id;
          edge.append_attribute( "target" ) = g_id;
        }
      }
    }

    Abc_NtkForEachPo( pNtk, pObj, i )
    {
      auto po_id = babc::Abc_ObjId( pObj );
      // add inverter before the gate
      int inverter_id = 0;
      Abc_ObjForEachFanin( pObj, pFanin, k )
      {
        int child_id = babc::Abc_ObjId( pFanin );
        if ( babc::Abc_ObjFaninC( pObj, k ) )
        {
          inverter_index_map[pFanin] = ++current_index;
          inverter_id = inverter_index_map[pFanin];
          // create the inverter node
          auto xmlNode_gate_inv = graphNode.append_child( "node" );
          xmlNode_gate_inv.append_attribute( "id" ) = current_index;
          auto dataType_gate_inv = xmlNode_gate_inv.append_child( "data" );
          dataType_gate_inv.append_attribute( "key" ) = "nodeType";
          dataType_gate_inv.text().set( "INVERTER" );
          auto dataFunc_gate_inv = xmlNode_gate_inv.append_child( "data" );
          dataFunc_gate_inv.append_attribute( "key" ) = "nodeFunc";
          dataFunc_gate_inv.text().set( NODE_FUNC_MAP.at( "INVERTER" ).c_str() );
        }
      }

      auto xmlNode_po = graphNode.append_child( "node" );
      xmlNode_po.append_attribute( "id" ) = po_id;
      auto dataType_po = xmlNode_po.append_child( "data" );
      dataType_po.append_attribute( "key" ) = "nodeType";
      dataType_po.text().set( "PO" );
      auto dataFunc_po = xmlNode_po.append_child( "data" );
      dataFunc_po.append_attribute( "key" ) = "nodeFunc";
      dataFunc_po.text().set( NODE_FUNC_MAP.at( "PO" ).c_str() );
      Abc_ObjForEachFanin( pObj, pFanin, k )
      {
        int child_id = babc::Abc_ObjId( pFanin );
        if ( babc::Abc_ObjFaninC( pObj, k ) )
        {
          // edge1: child_id -> inverter_id
          auto edge1 = graphNode.append_child( "edge" );
          edge1.append_attribute( "source" ) = child_id;
          edge1.append_attribute( "target" ) = inverter_id;
          // edge2: inverter_id -> g_id
          auto edge2 = graphNode.append_child( "edge" );
          edge2.append_attribute( "source" ) = inverter_id;
          edge2.append_attribute( "target" ) = po_id;
        }
        else
        {
          auto edge = graphNode.append_child( "edge" );
          edge.append_attribute( "source" ) = child_id;
          edge.append_attribute( "target" ) = po_id;
        }
      }
    }
  }
  else
  {
    std::cerr << "unsupported ntk type" << std::endl;
    assert( false );
  }
  doc.save_file( file.c_str() );
}

/**
 * @brief write current design into graphml file
 */
void write_graphml( const std::string& file )
{
  auto ntktype = lfLntINST->get_ntktype_curr();
  if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG ||
       ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG )
  {
    babc::Abc_Frame_t* frame = lfLmINST->current<babc::Abc_Frame_t*>();
    abc_to_graphml( frame, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_FPGA ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_NETLIST_FPGA )
  {
    babc::Abc_Frame_t* frame = lfLmINST->current<babc::Abc_Frame_t*>();
    abc_to_graphml( frame, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_ASIC ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_NETLIST_ASIC )
  {
    babc::Abc_Frame_t* frame = lfLmINST->current<babc::Abc_Frame_t*>();
    abc_to_graphml( frame, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AIG ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_OIG ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_OIG )
  {
    lf::logic::lsils::oig_seq_network ntk = lfLmINST->current<lf::logic::lsils::oig_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AOG ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_AOG )
  {
    lf::logic::lsils::aog_seq_network ntk = lfLmINST->current<lf::logic::lsils::aog_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XAG ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XOG ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XOG )
  {
    lf::logic::lsils::xog_seq_network ntk = lfLmINST->current<lf::logic::lsils::xog_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XMG ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_MIG ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_PRIMARY ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY )
  {
    lf::logic::lsils::primary_seq_network ntk = lfLmINST->current<lf::logic::lsils::primary_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_GTG ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_STRASH_GTG )
  {
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_FPGA ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_NETLIST_FPGA )
  {
    lf::logic::lsils::klut_seq_network ntk = lfLmINST->current<lf::logic::lsils::klut_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else if ( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_ASIC ||
            ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_NETLIST_ASIC )
  {
    lf::logic::lsils::blut_seq_network ntk = lfLmINST->current<lf::logic::lsils::blut_seq_network>();
    lsils_to_graphml( ntk, file );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }
}

} // end namespace logic

} // end namespace lf