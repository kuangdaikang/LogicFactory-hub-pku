#pragma once

#include "tcl/register/tcl_macro.hpp"
#include "tcl_cmds_ieda.hpp"

namespace lf
{

namespace tcl
{

int registerCmdiEDA()
{
  LF_MACOR_REGISTER_TCL_CMD( CmdTestAAA, "ieda_test" );
  LF_MACOR_REGISTER_TCL_CMD( CmdiEDAInit, "ieda_init" );
  LF_MACOR_REGISTER_TCL_CMD( CmdiEDAFloorplan, "ieda_floorplan" );
  LF_MACOR_REGISTER_TCL_CMD( CmdiEDAPlacement, "ieda_placement" );
  LF_MACOR_REGISTER_TCL_CMD( CmdiEDACts, "ieda_cts" );
  LF_MACOR_REGISTER_TCL_CMD( CmdiEDASta, "ieda_sta" );
  LF_MACOR_REGISTER_TCL_CMD( CmdiEDARouting, "ieda_routing" );
  return EXIT_SUCCESS;
}

} // namespace tcl

} // namespace lf