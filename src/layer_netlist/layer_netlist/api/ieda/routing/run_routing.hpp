#pragma once

#include "platform/data_manager/idm.h"
#include "operation/iRT/interface/RTInterface.hpp"
#include "layer_netlist/netlist_manager.hpp"

#include "nlohmann/json.hpp"

#include "utility/file.hpp"

#include <assert.h>

#include <map>
#include <any>

namespace lf
{
namespace netlist
{
namespace ieda
{

struct ConfigRouting
{
  std::string temp_directory_path;
  std::string bottom_routing_layer;
  std::string top_routing_layer;
  int32_t thread_number;

  ConfigRouting() {}

  void defconfig()
  {
    temp_directory_path = "/tmp/workspace_lf/rt/";
    bottom_routing_layer = "met1";
    top_routing_layer = "met4";
    thread_number = 64;
  }
};

///////////////////////////////////////////////////////////////////////////////////////
//  ROUTING
///////////////////////////////////////////////////////////////////////////////////////
void init_routing( const std::string& file )
{
  ConfigRouting config;
  if ( !lf::utility::endsWith( file, ".json" ) )
  {
    std::cerr << "config is not end with .json!" << std::endl;
    assert( false );
    config.defconfig();
  }

  // parse config routing with config
  std::ifstream file_stream( file );
  if ( !file_stream.is_open() )
  {
    std::cerr << "Error opening the configuration file: " << file << std::endl;
    assert( false );
  }

  nlohmann::json json_config;
  file_stream >> json_config;

  assert( json_config.contains( "temp_directory_path" ) );
  assert( json_config.contains( "bottom_routing_layer" ) );
  assert( json_config.contains( "top_routing_layer" ) );
  assert( json_config.contains( "thread_number" ) );

  config.temp_directory_path = json_config["temp_directory_path"].get<std::string>();
  config.bottom_routing_layer = json_config["bottom_routing_layer"].get<std::string>();
  config.top_routing_layer = json_config["top_routing_layer"].get<std::string>();
  config.thread_number = json_config["thread_number"].get<int32_t>();

  std::map<std::string, std::any> config_map = {
      { "-temp_directory_path", config.temp_directory_path },
      { "-bottom_routing_layer", config.bottom_routing_layer },
      { "-top_routing_layer", config.top_routing_layer },
      { "-thread_number", config.thread_number } };
  RTI.initRT( config_map );
  RTI.runRT();
}

///////////////////////////////////////////////////////////////////////////////////////
//  EVALUATION
///////////////////////////////////////////////////////////////////////////////////////
struct ProfileRouting
{
  std::vector<double> areas;
};

ProfileRouting eval_routing()
{
  ProfileRouting profile;

  return profile;
}
///////////////////////////////////////////////////////////////////////////////////////
//  FLOW
///////////////////////////////////////////////////////////////////////////////////////
ProfileRouting run_routing( lf::netlist::NetlistAsicManager& manager )
{
  manager.update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_route );

  std::string workspace = manager.get_config_ieda()->get_workspace_rt();
  std::string routing_config_file = manager.get_config_ieda()->get_config_routing_file();

  init_routing( routing_config_file );

  dmInst->saveDef( workspace + "/irt.def" );
  dmInst->saveGDSII( workspace + "/irt.gds" );

  return eval_routing();
}

} // namespace ieda
} // namespace netlist
} // namespace lf