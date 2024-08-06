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
void write_verilog( const std::string& file )
{
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

  auto ntktype = LfLntINST->get_nkt_type();
  if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_AIG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG );
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();
    mockturtle::write_verilog( ntk, os, ports );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_XAG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG );
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();
    mockturtle::write_verilog( ntk, os, ports );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_XMG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG );
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();
    mockturtle::write_verilog( ntk, os, ports );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_MIG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG );
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();
    mockturtle::write_verilog( ntk, os, ports );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_GTG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_GTG );
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();
    mockturtle::write_verilog( ntk, os, ports );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_KLUT )
  {
    std::cerr << "TODO ing!\n";
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_BLUT )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_NETLIST_ASIC );
    lf::logic::lsils::blut_seq_network ntk = lfLmINST->current<lf::logic::lsils::blut_seq_network>();
    mockturtle::write_verilog_with_binding( ntk, os, ports );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }

  os.close();
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
