#pragma once

#include "platform/data_manager/idm.h"
#include "operation/iRT/interface/RTInterface.hpp"
#include "layer_netlist/netlist_manager.hpp"

#include <map>
#include <any>

namespace lf
{
namespace netlist
{
namespace ieda
{

struct ProfileRouting
{
  std::vector<double> areas;
};

ProfileRouting run_routing( lf::netlist::NetlistAsicManager& manager )
{

  manager.update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_route );

  ProfileRouting profile;

  std::string verilog_file = manager.get_config_ieda()->get_verilog_file();
  std::string top_module = manager.get_config_ieda()->get_top_module();
  std::vector<std::string> lib_files = manager.get_config_ieda()->get_lib_files();
  std::vector<std::string> lef_files = manager.get_config_ieda()->get_lef_files();
  std::string tlef_file = manager.get_config_ieda()->get_tlef_file();
  std::string sdc_file = manager.get_config_ieda()->get_sdc_file();
  std::string workspace = manager.get_config_ieda()->get_workspace_rt();

  std::map<std::string, std::any> config_map = {
      { "-temp_directory_path", std::string( "/workspace/LogicFactory/tmp/" ) },
      { "-bottom_routing_layer", std::string( "met1" ) },
      { "-top_routing_layer", std::string( "met4" ) },
      { "-thread_number", int32_t( 64 ) } };
  RTI.initRT( config_map );
  RTI.runRT();
  dmInst->saveDef( workspace + "/irt.def" );
  dmInst->saveGDSII( workspace + "/irt.gds" );

  // TODO: get the timing related information
  return profile;
}

} // namespace ieda
} // namespace netlist
} // namespace lf