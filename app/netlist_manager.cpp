#include "layer_netlist/netlist_manager.hpp"

#include <string>

int main( int argc, char** argv )
{
  std::string config = std::string( argv[1] );

  lf::netlist::NetlistAsicManager netlist_manager( config );
  netlist_manager.start();

  netlist_manager.stop();

  return 1;
}
