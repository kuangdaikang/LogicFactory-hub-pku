#pragma once

#include "platform/data_manager/idm.h"
#include "operation/iFP/api/ifp_api.h"
#include "operation/iPDN/api/ipdn_api.h"
#include "layer_netlist/netlist_manager.hpp"

#include "nlohmann/json.hpp"

#include "utility/file.hpp"

#include <assert.h>

namespace lf
{
namespace netlist
{
namespace ieda
{
// Define a struct for die initialization
struct DieConfig
{
  double_t xMin, yMin, xMax, yMax;
};

// Define a struct for core initialization
struct CoreConfig
{
  double_t xMin, yMin, xMax, yMax;
  std::string xUnit, yUnit, site;
};

// Define a struct for track making
struct TrackConfig
{
  std::string layer;
  int32_t xPitch, yPitch;
  int32_t xOffset, yOffset;
};

// Define a struct for pin placement
struct PinPlacement
{
  std::string layer;
  int32_t xSpacing, ySpacing;
};

// Define a struct for tap cell insertion
struct TapCellConfig
{
  double_t density;
  std::string tapCellType, fillCellType;
};

// Define a struct for IO Pin configuration
struct IOPinConfig
{
  std::string pin_name;
  std::string net_name;
  std::string direction;
  int32_t is_power;
};

// Define a struct for global connections
struct GlobalConnectConfig
{
  std::string net_name;
  std::string connectTo;
  int32_t is_power; // Use 1 for power, 0 for ground
};

// Define a struct for the grid configuration
struct GridConfig
{
  std::string primary_power;
  std::string primary_ground;
  std::string layer;
  double_t width;
  double_t offset;
};

// Define a struct for stripe configuration
struct StripeConfig
{
  std::string primary_power;
  std::string primary_ground;
  std::string layer;
  double_t width;
  double_t pitch;
  double_t offset;
};

struct ConfigFloorplan
{
  DieConfig die;
  CoreConfig core;
  std::vector<TrackConfig> tracks;
  PinPlacement pins;
  TapCellConfig tapCells;

  ConfigFloorplan() {}

  void defconfig()
  {
    tracks.clear();
    // Initialize the die area
    die = { 0.0f, 0.0f, 149.96f, 150.128f };

    // Initialize the core area
    core = { 9.996f, 10.08f, 139.964f, 140.048f, "unit", "unit", "unit" };

    // Initialize track configurations
    tracks.push_back( { "li1", 240, 480, 185, 370 } );
    tracks.push_back( { "met1", 185, 370, 185, 370 } );
    tracks.push_back( { "met2", 240, 480, 240, 480 } );
    tracks.push_back( { "met3", 370, 740, 370, 740 } );
    tracks.push_back( { "met4", 480, 960, 480, 960 } );
    tracks.push_back( { "met5", 185, 3330, 185, 3330 } );

    // Initialize pin placement
    pins = { "met4", 2000, 2000 };

    // Initialize tap cells
    tapCells = { 14.0f, "sky130_fd_sc_hs__tap_1", "sky130_fd_sc_hs__fill_1" };
  }
};

struct ConfigPdn
{
  std::vector<IOPinConfig> ioPins;
  std::vector<GlobalConnectConfig> global_connections;
  std::vector<GridConfig> grids;
  std::vector<StripeConfig> stripes;
  std::vector<std::string> connected_layerList;

  // Constructor to add initial configurations
  ConfigPdn() {}

  void defconfig()
  {
    ioPins.clear();
    global_connections.clear();
    grids.clear();
    stripes.clear();
    connected_layerList.clear();

    // Initialize IO Pins
    ioPins.push_back( { "", "VDD", "INOUT", 1 } );
    ioPins.push_back( { "", "VSS", "INOUT", 0 } );

    // Initialize global connections
    global_connections.push_back( { "VDD", "VPWR", 1 } );
    global_connections.push_back( { "VDD", "VPB", 1 } );
    global_connections.push_back( { "VDD", "vdd", 1 } );
    global_connections.push_back( { "VSS", "VGND", 0 } );
    global_connections.push_back( { "VSS", "VNB", 0 } );
    global_connections.push_back( { "VSS", "gnd", 0 } );

    // Initialize grid
    grids.push_back( { "VDD", "VSS", "met1", 0.48f, 0.0f } );

    // Initialize stripes
    stripes.push_back( { "VDD", "VSS", "met4", 1.60f, 27.14f, 13.57 } );
    stripes.push_back( { "VDD", "VSS", "met5", 1.60f, 27.20f, 13.60 } );

    // Initialize layer list
    connected_layerList = { "met1", "met4", "met4", "met5" };
  }
};

///////////////////////////////////////////////////////////////////////////////////////
//  FLOORPLAN
///////////////////////////////////////////////////////////////////////////////////////
void init_floorplan( const std::string& file )
{
  ConfigFloorplan config_fp;
  if ( !lf::utility::endsWith( file, ".json" ) )
  {
    std::cerr << "config is not end with .json!" << std::endl;
    assert( false );
    config_fp.defconfig();
  }

  // parse config_fp with config
  std::ifstream file_stream( file );
  if ( !file_stream.is_open() )
  {
    std::cerr << "Error opening the configuration file: " << file << std::endl;
    assert( false );
  }

  nlohmann::json json_config;
  file_stream >> json_config;

  assert( json_config.contains( "die" ) );
  assert( json_config.contains( "core" ) );
  assert( json_config.contains( "tracks" ) );
  assert( json_config.contains( "pins" ) );
  assert( json_config.contains( "tapCells" ) );

  config_fp.die.xMin = json_config["die"]["xMin"].get<double_t>();
  config_fp.die.yMin = json_config["die"]["yMin"].get<double_t>();
  config_fp.die.xMax = json_config["die"]["xMax"].get<double_t>();
  config_fp.die.yMax = json_config["die"]["yMax"].get<double_t>();

  config_fp.core.xMin = json_config["core"]["xMin"].get<double_t>();
  config_fp.core.yMin = json_config["core"]["yMin"].get<double_t>();
  config_fp.core.xMax = json_config["core"]["xMax"].get<double_t>();
  config_fp.core.yMax = json_config["core"]["yMax"].get<double_t>();
  config_fp.core.xUnit = json_config["core"]["xUnit"].get<std::string>();
  config_fp.core.yUnit = json_config["core"]["yUnit"].get<std::string>();
  config_fp.core.site = json_config["core"]["site"].get<std::string>();

  for ( const auto& track : json_config["tracks"] )
  {
    TrackConfig track_config;
    track_config.layer = track["layer"].get<std::string>();
    track_config.xPitch = track["xPitch"].get<int32_t>();
    track_config.yPitch = track["yPitch"].get<int32_t>();
    track_config.xOffset = track["xOffset"].get<int32_t>();
    track_config.yOffset = track["yOffset"].get<int32_t>();
    config_fp.tracks.push_back( track_config );
  }

  config_fp.pins.layer = json_config["pins"]["layer"].get<std::string>();
  config_fp.pins.xSpacing = json_config["pins"]["xSpacing"].get<int32_t>();
  config_fp.pins.ySpacing = json_config["pins"]["ySpacing"].get<int32_t>();

  config_fp.tapCells.density = json_config["tapCells"]["density"].get<double_t>();
  config_fp.tapCells.tapCellType = json_config["tapCells"]["tapCellType"].get<std::string>();
  config_fp.tapCells.fillCellType = json_config["tapCells"]["fillCellType"].get<std::string>();

  // config the floorplan
  fpApiInst->initDie( config_fp.die.xMin, config_fp.die.yMin, config_fp.die.xMax, config_fp.die.yMax );

  fpApiInst->initCore( config_fp.core.xMin, config_fp.core.yMin, config_fp.core.xMax, config_fp.core.yMax, config_fp.core.xUnit, config_fp.core.yUnit, config_fp.core.site );

  for ( auto track : config_fp.tracks )
  {
    fpApiInst->makeTracks( track.layer, track.xOffset, track.xPitch, track.yOffset, track.yPitch );
  }

  fpApiInst->autoPlacePins( config_fp.pins.layer, config_fp.pins.xSpacing, config_fp.pins.ySpacing );

  fpApiInst->tapCells( config_fp.tapCells.density, config_fp.tapCells.tapCellType, config_fp.tapCells.fillCellType );
}

///////////////////////////////////////////////////////////////////////////////////////
//  PDN
///////////////////////////////////////////////////////////////////////////////////////
void init_pdn( const std::string& file )
{
  ConfigPdn config_pdn;
  if ( !lf::utility::endsWith( file, ".json" ) )
  {
    std::cerr << "config is not end with .json!" << std::endl;
    assert( false );
    config_pdn.defconfig();
  }

  // parse config_pdn with config
  std::ifstream file_stream( file );
  if ( !file_stream.is_open() )
  {
    std::cerr << "Error opening the configuration file: " << file << std::endl;
    assert( false );
  }

  nlohmann::json json_config;
  file_stream >> json_config;

  assert( json_config.contains( "ioPins" ) );
  assert( json_config.contains( "global_connections" ) );
  assert( json_config.contains( "grids" ) );
  assert( json_config.contains( "stripes" ) );
  assert( json_config.contains( "connected_layerList" ) );

  for ( const auto& data : json_config["io_pins"] )
  {
    IOPinConfig config;
    config.pin_name = data["pin_name"].get<std::string>();
    config.net_name = data["net_name"].get<std::string>();
    config.direction = data["direction"].get<std::string>();
    config.is_power = data["is_power"].get<int32_t>();
    config_pdn.ioPins.push_back( config );
  }

  for ( const auto& data : json_config["global_connections"] )
  {
    GlobalConnectConfig config;
    config.net_name = data["net_name"].get<std::string>();
    config.connectTo = data["connect_to"].get<std::string>();
    config.is_power = data["is_power"].get<int32_t>();
    config_pdn.global_connections.push_back( config );
  }

  for ( const auto& data : json_config["grids"] )
  {
    GridConfig config;
    config.primary_power = data["primary_power"].get<std::string>();
    config.primary_ground = data["primary_ground"].get<std::string>();
    config.layer = data["layer"].get<int32_t>();
    config.width = data["width"].get<int32_t>();
    config.offset = data["offset"].get<int32_t>();
    config_pdn.grids.push_back( config );
  }

  config_pdn.connected_layerList = json_config["connected_layerList"].get<std::vector<std::string>>();

  // config the pdn within floorplan
  for ( auto iopin : config_pdn.ioPins )
  {
    pdnApiInst->addIOPin( iopin.pin_name, iopin.pin_name, iopin.direction, iopin.is_power );
  }

  for ( auto glo_connect : config_pdn.global_connections )
  {
    pdnApiInst->globalConnect( glo_connect.net_name, glo_connect.connectTo, glo_connect.is_power );
  }

  for ( auto grid : config_pdn.grids )
  {
    pdnApiInst->createGrid( grid.primary_power, grid.primary_ground, grid.layer, grid.width, grid.offset );
  }

  for ( auto stripe : config_pdn.stripes )
  {
    pdnApiInst->createStripe( stripe.primary_power, stripe.primary_ground, stripe.layer, stripe.width, stripe.width, stripe.offset );
  }

  pdnApiInst->connectLayerList( config_pdn.connected_layerList );

  // set clock net
  dmInst->setNetType( "clk", "CLOCK" );
}

///////////////////////////////////////////////////////////////////////////////////////
//  EVALUATION
///////////////////////////////////////////////////////////////////////////////////////
struct ProfileFloorplan
{
  std::vector<double> areas;
};

ProfileFloorplan eval_floorplan()
{
  ProfileFloorplan profile;

  return profile;
}

///////////////////////////////////////////////////////////////////////////////////////
//  FLOW
///////////////////////////////////////////////////////////////////////////////////////
ProfileFloorplan run_floorplan( lf::netlist::NetlistAsicManager& manager )
{
  manager.update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_fp );

  std::string workspace = manager.get_config_ieda()->get_workspace_fp();
  std::string floorplan_config_file = manager.get_config_ieda()->get_config_floorplan_file();
  std::string pdn_config_file = manager.get_config_ieda()->get_config_pdn_file();

  init_floorplan( floorplan_config_file );
  init_pdn( pdn_config_file );

  // save def
  dmInst->saveDef( workspace + "/ifp.def" );

  return eval_floorplan();
}

} // namespace ieda
} // namespace netlist
} // namespace lf