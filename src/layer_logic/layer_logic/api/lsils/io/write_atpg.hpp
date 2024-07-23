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
template<typename Ntk = aig_seq_network>
void write_verilog( Ntk const& ntk, const std::string& file )
{
  using NtkBase = typename Ntk::base_type;

  static_assert( std::is_same_v<NtkBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkBase, mockturtle::gtg_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, or GTG" );

  // set the ports
  assert( !ports.input_names.empty() );
  assert( !ports.output_names.empty() );
  lfLmINST->ports().set_module_name( ports.module_name == std::nullopt ? "" : ports.module_name );
  for ( auto port : ports.input_names )
  {
    assert( port.second == 1u );
    lfLmINST->ports().add_input( port.first );
  }
  for ( auto port : ports.output_names )
  {
    assert( port.second == 1u );
    lfLmINST->ports().add_output( port.first );
  }

  mockturtle::write_verilog_params ps;
  ps.module_name = lfLmINST->ports().get_module_name();
  for ( auto port : lfLmINST->ports().get_inputs() )
  {
    ps.input_names.push_back( std::make_pair( port, 1u ) );
  }
  for ( auto port : lfLmINST->ports().get_outputs() )
  {
    ps.output_names.push_back( std::make_pair( port, 1u ) );
  }

  // write the verilog according to the anchor
  lf::misc::E_LF_ANCHOR stat = lfAnchorINST->get_anchor();
  std::ofstream os( file.c_str(), std::ofstream::out );
  switch ( stat )
  {
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_NETLIST_FPGA:
    mockturtle::write_verilog_with_binding<Ntk>( ntk, os, ps );
    break;
  case lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_NETLIST_ASIC:
    mockturtle::write_verilog_with_binding<Ntk>( ntk, os, ps );
    break;
  default:
    mockturtle::write_verilog<Ntk>( ntk, os, ps );
    break;
  }
  os.close();
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
