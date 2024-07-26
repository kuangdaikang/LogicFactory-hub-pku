#pragma once

#include "tcl/engine/tcl_macro.hpp"
#include "tcl/cmds/tcl_cmds_misc.hpp"
#include "tcl/cmds/tcl_cmds_flow.hpp"
#include "tcl/cmds/tcl_cmds_io.hpp"

namespace lf
{

namespace tcl
{

int registerCmds()
{
  //////////////////////////////////////////////////////////
  // misc
  //////////////////////////////////////////////////////////
  LF_MACOR_REGISTER_TCL_CMD( CmdLfHelp, "help" );
  //////////////////////////////////////////////////////////
  // init
  //////////////////////////////////////////////////////////
  LF_MACOR_REGISTER_TCL_CMD( CmdLfStart, "start" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfStop, "stop" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfAnchor, "anchor" );
  //////////////////////////////////////////////////////////
  // IO
  //////////////////////////////////////////////////////////

  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadAiger, "read_aiger" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBlif, "read_blif" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBench, "read_bench" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadCnf, "read_cnf" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadFormula, "read_formula" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadPla, "read_pla" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadTruth, "read_truth" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadGenlib, "read_genlib" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadLiberty, "read_liberty" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadVerilog, "read_verilog" );

  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteAiger, "write_aiger" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBlif, "write_blif" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBench, "write_bench" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteCnf, "write_cnf" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWritePla, "write_pla" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteVerilog, "write_verilog" );
  // LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteDot, "write_dot" );

  //////////////////////////////////////////////////////////
  // arch
  //////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////
  // logic
  //////////////////////////////////////////////////////////

  //////////////////////////////////////////////////////////
  // netlist
  //////////////////////////////////////////////////////////

  return EXIT_SUCCESS;
}

} // namespace tcl

} // namespace lf