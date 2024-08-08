#pragma once

#include "wrapper_netlist.hpp"
#include "layer_logic/api/abc/io/write_verilog.hpp"
#include "layer_logic/api/lsils/io/write_verilog.hpp"

namespace lf
{

namespace netlist
{

/**
 * @brief abc_to_idb
 * @param frame
 */
void logic_to_netlist( const lf::logic::lsils::blut_seq_network& blut )
{
  lf::netlist::ieda::ConfigiEDA* config = lfNmINST->get_config_ieda();
  std::string workspace = config->get_workspace();
  std::string verilog_arch = workspace + "/lf_" + lf::utility::genRandomName( 8 ) + "_logic.v";

  // write the verilog file
  lf::logic::lsils::write_verilog( verilog_arch );

  config->set_verilog_file( verilog_arch );
}

/**
 * @brief abc_to_idb
 * @param frame
 */
void logic_to_netlist( const babc::Abc_Frame_t* frame_abc )
{
  lf::netlist::ieda::ConfigiEDA* config = lfNmINST->get_config_ieda();
  std::string workspace = config->get_workspace();
  std::string verilog_arch = workspace + "/lf_" + lf::utility::genRandomName( 8 ) + "_logic.v";

  // write the verilog file
  lf::logic::abc::write_verilog( verilog_arch );

  config->set_verilog_file( verilog_arch );
}

} // namespace netlist

} // namespace lf