#pragma once

#include "platform/data_manager/idm.h"
#include "operation/iCTS/api/CTSAPI.hh"
#include "layer_netlist/netlist_manager.hpp"

namespace lf
{
namespace netlist
{
namespace ieda
{

struct ProfilePlacement
{
  std::vector<double> areas;
};

ProfilePlacement run_floorplan( lf::netlist::NetlistAsicManager& manager )
{
  manager.update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_cts );

  ProfilePlacement profile;

  std::string verilog_file = manager.get_config_ieda()->get_verilog_file();
  std::string top_module = manager.get_config_ieda()->get_top_module();
  std::vector<std::string> lib_files = manager.get_config_ieda()->get_lib_files();
  std::vector<std::string> lef_files = manager.get_config_ieda()->get_lef_files();
  std::string tlef_file = manager.get_config_ieda()->get_tlef_file();
  std::string sdc_file = manager.get_config_ieda()->get_sdc_file();
  std::string workspace = manager.get_config_ieda()->get_workspace_cts();

  // TODO: config the path
  std::string cts_config = "/workspace/LogicFactory/toolkit/iEDA/scripts/design/sky130_gcd/iEDA_config/cts_default_config.json";

  CTSAPIInst.init( cts_config, workspace );
  CTSAPIInst.runCTS();
  dmInst->saveDef( workspace + "/icts.def" );

  // TODO: get the timing related information
  return profile;
}

} // namespace ieda
} // namespace netlist
} // namespace lf