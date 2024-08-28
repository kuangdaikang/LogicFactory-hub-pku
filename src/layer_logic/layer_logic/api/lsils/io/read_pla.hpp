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
void read_pla( const std::string& file )
{
  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_AIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XAG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XMG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_MIG ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_PRIMARY ||
          ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_GTG );

  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );
  mockturtle::read_verilog_params ports;
  lorina::return_code rc;

  if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_AIG )
  {
    lf::logic::lsils::aig_seq_network ntk;
    rc = lorina::read_pla( file, mockturtle::pla_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XAG )
  {
    lf::logic::lsils::xag_seq_network ntk;
    rc = lorina::read_pla( file, mockturtle::pla_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XMG )
  {
    lf::logic::lsils::xmg_seq_network ntk;
    rc = lorina::read_pla( file, mockturtle::pla_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_MIG )
  {
    lf::logic::lsils::mig_seq_network ntk;
    rc = lorina::read_pla( file, mockturtle::pla_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_PRIMARY )
  {
    lf::logic::lsils::primary_seq_network ntk;
    rc = lorina::read_pla( file, mockturtle::pla_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
  }
  else if ( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_GTG )
  {
    lf::logic::lsils::gtg_seq_network ntk;
    rc = lorina::read_pla( file, mockturtle::pla_reader( ntk ), &diag );
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
