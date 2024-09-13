#pragma once

#include "wrapper_netlist.hpp"
#include "layer_logic/api/abc/io/write_verilog.hpp"
#include "layer_logic/api/lsils/io/write_verilog.hpp"

namespace lf
{

namespace netlist
{

/**
 * @brief lsils_to_netlist
 * @param frame
 */
void lsils_to_netlist( std::string file = "" )
{
  lf::netlist::ieda::ConfigiEDA* config = lfNmINST->get_config_ieda();
  if ( !file.empty() )
  {
    config->set_verilog_file( file );
  }
  else
  {
    std::string workspace = config->get_workspace();
    std::string verilog_arch = workspace + "/lf_" + lf::utility::genRandomName( 16 ) + "_logic.v";
    lf::logic::lsils::write_verilog( verilog_arch );
    config->set_verilog_file( verilog_arch );
  }
}

/**
 * @brief abc_to_netlist
 * @param frame
 */
void abc_to_netlist( std::string file = "" )
{
  lf::netlist::ieda::ConfigiEDA* config = lfNmINST->get_config_ieda();
  if ( !file.empty() )
  {
    config->set_verilog_file( file );
  }
  else
  {
    std::string workspace = config->get_workspace();
    std::string verilog_arch = workspace + "/lf_" + lf::utility::genRandomName( 16 ) + "_logic.v";
    lf::logic::abc::write_verilog( verilog_arch );
    config->set_verilog_file( verilog_arch );
  }
}

} // namespace netlist

} // namespace lf