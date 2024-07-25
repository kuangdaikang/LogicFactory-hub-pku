#pragma once

#include "tcl/cmds/tcl_macro.hpp"
#include "tcl/cmds/tcl_cmds_misc.hpp"
#include "tcl/cmds/tcl_cmds_init.hpp"
#include "tcl/cmds/tcl_cmds_io.hpp"

namespace lf
{

namespace tcl
{

int registerCmds()
{
  // misc
  LF_MACOR_REGISTER_TCL_CMD( CmdLfHelp, "help", "misc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfMan, "man", "misc" );
  // init
  LF_MACOR_REGISTER_TCL_CMD( CmdLfStart, "start", "flow" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfStop, "stop", "flow" );
  // IO
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadAigerYosys, "read_aiger", "arch:yosys" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadVerilogYosys, "read_verilog", "arch:yosys" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadLibertyYosys, "read_liberty", "arch:yosys" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteVerilogYosys, "write_verilog", "arch:yosys" );

  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadAigerAbc, "read_aiger", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBenchAbc, "read_bench", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBlifAbc, "read_blif", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadCnfAbc, "read_cnf", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadFormulaAbc, "read_formula", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadGenlibAbc, "read_genlib", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadLibertyAbc, "read_liberty", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadPlaAbc, "read_pla", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadTruthAbc, "read_truth", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadVerilogAbc, "read_verilog", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteAigerAbc, "write_aiger", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBenchAbc, "write_bench", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBlifAbc, "write_blif", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteCnfAbc, "write_cnf", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteDotAbc, "write_dot", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWritePlaAbc, "write_pla", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteTruthAbc, "write_truth", "logic:abc" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteVerilogAbc, "write_verilog", "logic:abc" );

  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadAigerLsils, "read_aiger", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBenchLsils, "read_bench", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBlifLsils, "read_blif", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadCnfLsils, "read_cnf", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadGtechLsils, "read_gtech", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadGenlibLsils, "read_genlib", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadLibertyLsils, "read_liberty", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadPlaLsils, "read_pla", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteAigerLsils, "write_aiger", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBenchLsils, "write_bench", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBlifLsils, "write_blif", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteCnfLsils, "write_cnf", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteDotLsils, "write_dot", "logic:lsils" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteVerilogLsils, "write_verilog", "logic:lsils" );

  // Pass

  return EXIT_SUCCESS;
}

} // namespace tcl

} // namespace lf