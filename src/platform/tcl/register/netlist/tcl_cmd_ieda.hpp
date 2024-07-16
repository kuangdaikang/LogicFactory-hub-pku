#pragma once

#include "engine/tcl_cmd.hpp"
#include "register/tcl_macro.hpp"

#include "layer_netlist/netlist_manager.hpp"
#include "layer_netlist/api/ieda/init/run_init.hpp"
#include "layer_netlist/api/ieda/floorplan/run_floorplan.hpp"
#include "layer_netlist/api/ieda/placement/run_placement.hpp"
#include "layer_netlist/api/ieda/cts/run_cts.hpp"
#include "layer_netlist/api/ieda/routing/run_routing.hpp"

namespace lf
{

namespace tcl
{

// lf::netlist::NetlistAsicManager

class CmdiEDAInit : public TclCmd
{
public:
  explicit CmdiEDAInit( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // TODO: this is for the args setting
    auto* file_name_option = new TclStringOption( TCL_OUTPUT_PATH, 1, nullptr );
    addOption( file_name_option );
  }

  ~CmdiEDAInit() override = default;

  unsigned check() override { return 1; }

  unsigned exec() override
  {
    if ( !check() )
    {
      return 0;
    }

    TclOption* option = getOptionOrArg( TCL_OUTPUT_PATH );
    auto path = option->getStringVal() != nullptr ? option->getStringVal() : "";

    // TODO: using the netlist manager
    lf::netlist::ieda::run_init();

    return 1;
  }

}; // class CmdiEDAInit

} // namespace tcl

} // namespace lf