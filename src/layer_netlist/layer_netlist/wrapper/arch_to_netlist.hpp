#pragma once

#include "wrapper_netlist.hpp"
#include "layer_arch/api/yosys/io/write_verilog.hpp"

namespace lf
{

namespace netlist
{

/**
 * @brief Converts a Yosys RTLIL design to iDB
 * @param frame
 */
void arch_to_netlist( const Yosys::RTLIL::Design* frame_yosys )
{
  lf::netlist::ieda::ConfigiEDA* config = lfNmINST->get_config_ieda();
  std::string workspace = config->get_workspace();
  std::string verilog_arch = workspace + "/lf_" + lf::utility::genRandomName( 8 ) + "_arch.v";

  // write the verilog file
  lf::arch::yosys::write_verilog( verilog_arch );

  config->set_verilog_file( verilog_arch );
}

} // namespace netlist

} // namespace lf