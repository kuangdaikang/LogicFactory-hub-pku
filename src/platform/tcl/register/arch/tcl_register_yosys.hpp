#pragma once

#include "tcl/register/tcl_macro.hpp"
#include "tcl_cmds_yosys.hpp"

namespace lf
{

namespace tcl
{

int registerCmdArchYosys()
{
  LF_MACOR_REGISTER_TCL_CMD( CmdArchInit, "arch_init" );
  LF_MACOR_REGISTER_TCL_CMD( CmdArchYosysReadAiger, "arch_read_aiger" );
  return EXIT_SUCCESS;
}

} // namespace tcl

} // namespace lf