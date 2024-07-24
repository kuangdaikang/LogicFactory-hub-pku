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
void read_bench( const std::string& file )
{
  using Ntk = cvg_seq_network;
  Ntk ntk;

  lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_CVG );

  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );
  mockturtle::read_verilog_params ports;

  // TODO: add the ports
  lorina::return_code rc = lorina::read_bench( file, mockturtle::bench_reader<Ntk>( ntk ), &diag );
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
