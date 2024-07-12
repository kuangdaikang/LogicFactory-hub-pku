#include "layer_netlist/netlist_manager.hpp"

#include <string>

int main( int argc, char** argv )
{
  std::string config_input = std::string( argv[1] );
  std::string config_output = std::string( argv[1] );

  lf::netlist::NetlistAsicManager netlist_manager;
  netlist_manager.start();

  netlist_manager.init_config( config_input, config_output );

  netlist_manager.stop();

  return 1;
}
