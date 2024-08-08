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
  cvg_seq_network ntk; // sequential cover network

  auto ntktype = lfLntINST->get_ntktype_curr();
  lfLmINST->update_logic( ntktype );

  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );
  mockturtle::read_verilog_params ports;

  lorina::return_code rc = lorina::read_bench( file, mockturtle::bench_reader( ntk ), &diag );
  if ( rc != lorina::return_code::success )
  {
    std::cerr << "parser wrong!" << std::endl;
    assert( false );
  }
  lfLmINST->set_current( ntk );

  // set the ports
  lfLmINST->ports().set_module_name( ports.module_name.has_value() ? ports.module_name.value() : "top" );
  if ( !ports.input_names.empty() )
  {
    for ( auto port : ports.input_names )
    {
      assert( port.second == 1u );
      lfLmINST->ports().add_input( port.first );
    }
  }

  if ( !ports.output_names.empty() )
  {
    for ( auto port : ports.output_names )
    {
      assert( port.second == 1u );
      lfLmINST->ports().add_output( port.first );
    }
  }
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
