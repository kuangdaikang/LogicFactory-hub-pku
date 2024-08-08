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
void read_gtech( const std::string& file )
{
  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );
  mockturtle::read_verilog_params ports;
  lorina::return_code rc;

  auto ntktype = lfLntINST->get_ntktype_curr();
  lfLmINST->update_logic( ntktype );
  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk;
    rc = lorina::read_gtech( file, mockturtle::gtech_reader( ntk, ports ), &diag );
    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk;
    rc = lorina::read_gtech( file, mockturtle::gtech_reader( ntk, ports ), &diag );
    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk;
    rc = lorina::read_gtech( file, mockturtle::gtech_reader( ntk, ports ), &diag );
    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk;
    rc = lorina::read_gtech( file, mockturtle::gtech_reader( ntk, ports ), &diag );
    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG )
  {
    lf::logic::lsils::gtg_seq_network ntk;
    rc = lorina::read_gtech( file, mockturtle::gtech_reader( ntk, ports ), &diag );
    lfLmINST->set_current( ntk );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }

  if ( rc != lorina::return_code::success )
  {
    std::cerr << "parser wrong!" << std::endl;
    assert( false );
  }

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
