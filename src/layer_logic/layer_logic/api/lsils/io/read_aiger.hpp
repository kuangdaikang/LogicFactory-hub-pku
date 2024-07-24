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
void read_aiger( const std::string& file )
{
  using NtkBase = typename Ntk::base_type;
  static_assert( std::is_same_v<NtkBase, mockturtle::aig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xag_network> ||
                     std::is_same_v<NtkBase, mockturtle::mig_network> ||
                     std::is_same_v<NtkBase, mockturtle::xmg_network> ||
                     std::is_same_v<NtkBase, mockturtle::gtg_network>,
                 "NtkSrc is not an AIG, XAG, MIG, XMG, GTG" );

  if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG );
  }
  else if constexpr ( std::is_same_v<Ntk, mig_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xmg_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG );
  }
  else if constexpr ( std::is_same_v<Ntk, gtg_seq_network> )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_GTG );
  }
  else
  {
    std::cerr << "Unhandled network type provided." << std::endl;
    assert( false );
  }

  Ntk ntk;

  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );
  mockturtle::read_verilog_params ports;

  // TODO: add the ports
  lorina::return_code rc = lorina::read_aiger( file, mockturtle::aiger_reader<Ntk>( ntk ), &diag );
  if ( rc != lorina::return_code::success )
  {
    std::cerr << "parser wrong!" << std::endl;
    assert( false );
  }

  // set the ports
  assert( !ports.input_names.empty() );
  assert( !ports.output_names.empty() );
  lfLmINST->ports().set_module_name( ports.module_name.has_value() ? "" : ports.module_name.value() );
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

  lfLmINST->set_current<Ntk>( ntk );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
