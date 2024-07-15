#include "layer_netlist/netlist_manager.hpp"

#include "layer_netlist/api/ieda/init/run_init.hpp"
#include "layer_netlist/api/ieda/sta/run_sta.hpp"
#include "layer_netlist/api/ieda/floorplan/run_floorplan.hpp"
#include "layer_netlist/api/ieda/cts/run_cts.hpp"
#include "layer_netlist/api/ieda/placement/run_placement.hpp"
#include "layer_netlist/api/ieda/routing/run_routing.hpp"

int main( int argc, char** argv )
{
  std::string config_input = std::string( argv[1] );
  std::string config_output = std::string( argv[2] );

  lf::netlist::NetlistAsicManager netlist_manager;
  netlist_manager.start();

  netlist_manager.init_config( config_input, config_output );

  lf::netlist::ieda::run_init( netlist_manager );
  lf::netlist::ieda::run_floorplan( netlist_manager );
  lf::netlist::ieda::run_placement( netlist_manager );
  lf::netlist::ieda::run_sta( netlist_manager );
  lf::netlist::ieda::run_cts( netlist_manager );
  lf::netlist::ieda::run_routing( netlist_manager );

  netlist_manager.stop();

  return 1;
}
