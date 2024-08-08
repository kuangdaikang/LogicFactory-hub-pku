#pragma once

#include "wrapper_logic.hpp"

namespace lf
{

namespace logic
{

void arch_to_logic( const Yosys::RTLIL::Design* frame_yosys )
{
  lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_GTG );
  lfLntINST->set_ntktype( lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG ); // hard code
  lfLmINST->update_logic( lf::misc::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG );

  mockturtle::read_verilog_params ports;
  lf::logic::lsils::gtg_seq_network ntk;
  wrapper_yosys_logic( frame_yosys, ntk, ports );
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

} // namespace logic

} // namespace lf