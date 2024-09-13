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
void yosys_to_netlist( std::string file = "" )
{
  lf::netlist::ieda::ConfigiEDA* config = lfNmINST->get_config_ieda();
  if ( !file.empty() )
  {
    config->set_verilog_file( file );
  }
  else
  {
    std::string workspace = config->get_workspace();
    std::string verilog_arch = workspace + "/lf_" + lf::utility::genRandomName( 16 ) + "_arch.v";
    lf::arch::yosys::write_verilog( verilog_arch );
    config->set_verilog_file( verilog_arch );
  }
}

} // namespace netlist

} // namespace lf