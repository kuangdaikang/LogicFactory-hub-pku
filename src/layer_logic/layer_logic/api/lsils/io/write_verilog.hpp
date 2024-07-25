#pragma once

#include "layer_logic/logic_manager.hpp"

namespace lf
{

namespace logic
{

namespace lsils
{

/**
 * @brief
 *
 */
template<typename Ntk = blut_seq_network>
void write_verilog( const std::string& file )
{
  using NtkBase = typename Ntk::base_type;
  static_assert( std::is_same_v<NtkBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkBase, mockturtle::gtg_network> ||
                     std::is_same_v<NtkBase, mockturtle::klut_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, GTG, KLUT" );
  Ntk ntk = lfLmINST->current<Ntk>();

  mockturtle::write_verilog_params ports;
  ports.module_name = lfLmINST->ports().get_module_name();
  for ( auto port : lfLmINST->ports().get_inputs() )
  {
    ports.input_names.push_back( std::make_pair( port, 1u ) );
  }
  for ( auto port : lfLmINST->ports().get_outputs() )
  {
    ports.output_names.push_back( std::make_pair( port, 1u ) );
  }

  std::ofstream os( file.c_str(), std::ofstream::out );
  if constexpr ( std::is_same_v<NtkBase, mockturtle::aig_network> ||
                 std::is_same_v<NtkBase, mockturtle::xag_network> ||
                 std::is_same_v<NtkBase, mockturtle::mig_network> ||
                 std::is_same_v<NtkBase, mockturtle::xmg_network> ||
                 std::is_same_v<NtkBase, mockturtle::gtg_network> )
  {
    mockturtle::write_verilog<Ntk>( ntk, os, ports );
    os.close();
  }
  else if constexpr ( std::is_same_v<NtkBase, mockturtle::klut_network> )
  {
    // write the netlist according to the anchor
    lf::misc::E_LF_ANCHOR stat = lfAnchorINST->get_anchor_curr();
    switch ( stat )
    {
    case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_NETLIST_FPGA:
      mockturtle::write_verilog_with_binding<Ntk>( ntk, os, ports );
      break;
    case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_NETLIST_ASIC:
      mockturtle::write_verilog_with_binding<Ntk>( ntk, os, ports );
      break;
    default:
      std::cerr << "No mapped verilog for this anchor" << std::endl;
      break;
    }
    os.close();
  }
  else
  {
    assert( false );
  }
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
