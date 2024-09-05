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
void read_cnf( const std::string& file )
{
  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );
  mockturtle::read_verilog_params ports;
  lorina::return_code rc;

  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_OIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AOG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XAG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XOG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XMG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_MIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_GTG );
  if ( ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_OIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AOG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XAG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XOG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XMG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_MIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_GTG )
  {
    std::cerr << "[ERROR] read_cnf: wrong ntk type!" << std::endl;
    return;
  }

  switch ( ntktype )
  {
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AIG:
  {
    lf::logic::lsils::aig_seq_network ntk;
    rc = lorina::read_dimacs( file, mockturtle::dimacs_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_OIG:
  {
    lf::logic::lsils::oig_seq_network ntk;
    rc = lorina::read_dimacs( file, mockturtle::dimacs_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_AOG:
  {
    lf::logic::lsils::aog_seq_network ntk;
    rc = lorina::read_dimacs( file, mockturtle::dimacs_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XAG:
  {
    lf::logic::lsils::xag_seq_network ntk;
    rc = lorina::read_dimacs( file, mockturtle::dimacs_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XOG:
  {
    lf::logic::lsils::xog_seq_network ntk;
    rc = lorina::read_dimacs( file, mockturtle::dimacs_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_XMG:
  {
    lf::logic::lsils::xmg_seq_network ntk;
    rc = lorina::read_dimacs( file, mockturtle::dimacs_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_MIG:
  {
    lf::logic::lsils::mig_seq_network ntk;
    rc = lorina::read_dimacs( file, mockturtle::dimacs_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_PRIMARY:
  {
    lf::logic::lsils::primary_seq_network ntk;
    rc = lorina::read_dimacs( file, mockturtle::dimacs_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
    break;
  }
  case lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_LSILS_LOGIC_GTG:
  {
    lf::logic::lsils::gtg_seq_network ntk;
    rc = lorina::read_dimacs( file, mockturtle::dimacs_reader( ntk ), &diag );
    lfLmINST->set_current( ntk );
    break;
  }
  default:
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
    break;
  }
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
