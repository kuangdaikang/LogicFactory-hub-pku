#pragma once

#include "platform/data_manager/idm.h"
#include "layer_netlist/api/ieda/config.hpp"
#include "layer_netlist/eval/profile_timing.hpp"
#include "layer_netlist/eval/profile_placement.hpp"
#include "layer_netlist/eval/profile_routing.hpp"

#include "misc/anchor.hpp"
#include "utility/string.hpp"

#include "nlohmann/json.hpp"

#include <fstream>
#include <assert.h>

#define lfNmINST lf::netlist::NetlistManager::get_instance()

namespace lf
{

namespace netlist
{

/**
 * @class NetlistManager
 * @brief
 *
 * @code
 */
class NetlistManager
{
public:
  static NetlistManager* get_instance()
  {
    if ( instance_ == nullptr )
    {
      instance_ = new NetlistManager;
    }
    return instance_;
  }

  void start()
  {
  }

  void stop()
  {
  }

  lf::netlist::ieda::ConfigiEDA* get_config_ieda()
  {
    if ( config_ieda_ == nullptr )
      config_ieda_ = new lf::netlist::ieda::ConfigiEDA();
    return config_ieda_;
  }

  void set_config_ieda( const std::string& file_config )
  {
    assert( lf::utility::endsWith( file_config, ".json" ) );
    config_ieda_ = new lf::netlist::ieda::ConfigiEDA();
    std::ifstream file_config_stream( file_config );
    nlohmann::json data = nlohmann::json::parse( file_config_stream );

    assert( data.contains( "workspace" ) );
    assert( data.contains( "design" ) );
    assert( data.contains( "top_module" ) );
    assert( data.contains( "liberty" ) );
    assert( data.contains( "clef" ) );
    assert( data.contains( "tlef" ) );
    assert( data.contains( "sdc" ) );
    assert( data.contains( "flow" ) );

    std::string workspace;
    std::string verilog_file;
    std::string top_module;
    std::vector<std::string> lib_files;
    std::vector<std::string> lef_files;
    std::string tlef_file;
    std::string sdc_file;

    std::string config_floorplan_file;
    std::string config_pdn_file;
    std::string config_placement_file;
    std::string config_cts_file;
    std::string config_routing_file;

    data.at( "workspace" ).get_to( workspace );
    data.at( "design" ).get_to( verilog_file );
    data.at( "top_module" ).get_to( top_module );
    data.at( "liberty" ).get_to( lib_files );
    data.at( "clef" ).get_to( lef_files );
    data.at( "tlef" ).get_to( tlef_file );
    data.at( "sdc" ).get_to( sdc_file );
    data.at( "flow" ).at( "floorplan" ).get_to( config_floorplan_file );
    data.at( "flow" ).at( "pdn" ).get_to( config_pdn_file );
    data.at( "flow" ).at( "placement" ).get_to( config_placement_file );
    data.at( "flow" ).at( "cts" ).get_to( config_cts_file );
    data.at( "flow" ).at( "routing" ).get_to( config_routing_file );

    config_ieda_->set_workspace( workspace );
    config_ieda_->set_verilog_file( verilog_file );
    config_ieda_->set_top_module( top_module );
    config_ieda_->set_lib_files( lib_files );
    config_ieda_->set_lef_files( lef_files );
    config_ieda_->set_tlef_file( tlef_file );
    config_ieda_->set_sdc_file( sdc_file );

    config_ieda_->set_config_floorplan_file( config_floorplan_file );
    config_ieda_->set_config_pdn_file( config_pdn_file );
    config_ieda_->set_config_placement_file( config_placement_file );
    config_ieda_->set_config_cts_file( config_cts_file );
    config_ieda_->set_config_routing_file( config_routing_file );
  }

  ProfileTiming* get_profile_timing()
  {
    if ( profile_timing_ == nullptr )
      profile_timing_ = new ProfileTiming;
    return profile_timing_;
  }

  ProfilePlacement* get_profile_place()
  {
    if ( profile_place_ == nullptr )
      profile_place_ = new ProfilePlacement;
    return profile_place_;
  }

  ProfileRouting* get_profile_routing()
  {
    if ( profile_routing_ == nullptr )
      profile_routing_ = new ProfileRouting;
    return profile_routing_;
  }

private:
  NetlistManager() = default;
  ~NetlistManager() = default;
  NetlistManager( const NetlistManager& ) = delete;
  NetlistManager& operator=( const NetlistManager& ) = delete;

private:
  static NetlistManager* instance_;
  lf::netlist::ieda::ConfigiEDA* config_ieda_ = nullptr;
  ProfileTiming* profile_timing_ = nullptr;
  ProfilePlacement* profile_place_ = nullptr;
  ProfileRouting* profile_routing_ = nullptr;
}; // class NelistAsicManager

NetlistManager* NetlistManager::instance_ = nullptr;

} // namespace netlist

} // namespace lf