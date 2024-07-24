#pragma once

#include "tcl/cmds/tcl_macro.hpp"
#include "tcl/cmds/tcl_cmds_init.hpp"
#include "tcl/cmds/tcl_cmds_io.hpp"

namespace lf
{

namespace tcl
{

int registerCmds()
{
  // init
  LF_MACOR_REGISTER_TCL_CMD( CmdLfStart, "start" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfStop, "stop" );
  // IO
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadAigerYosys, "arch:yosys:read_aiger" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadVerilogYosys, "arch:yosys:read_verilog" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadLibertyYosys, "arch:yosys:read_liberty" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteVerilogYosys, "arch:yosys:write_verilog" );

  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadAigerAbc, "logic:abc:read_aiger" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBenchAbc, "logic:abc:read_bench" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBlifAbc, "logic:abc:read_blif" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadCnfAbc, "logic:abc:read_cnf" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadFormulaAbc, "logic:abc:read_formula" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadGenlibAbc, "logic:abc:read_genlib" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadLibertyAbc, "logic:abc:read_liberty" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadPlaAbc, "logic:abc:read_pla" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadTruthAbc, "logic:abc:read_truth" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadVerilogAbc, "logic:abc:read_verilog" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteAigerAbc, "logic:abc:write_aiger" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBenchAbc, "logic:abc:write_bench" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBlifAbc, "logic:abc:write_blif" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteCnfAbc, "logic:abc:write_cnf" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteDotAbc, "logic:abc:write_dot" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWritePlaAbc, "logic:abc:write_pla" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteTruthAbc, "logic:abc:write_truth" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteVerilogAbc, "logic:abc:write_verilog" );

  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadAigerLsils, "logic:lsils:read_aiger" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBenchLsils, "logic:lsils:read_bench" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadBlifLsils, "logic:lsils:read_blif" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadCnfLsils, "logic:lsils:read_cnf" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadGtechLsils, "logic:lsils:read_gtech" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadGenlibLsils, "logic:lsils:read_genlib" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadLibertyLsils, "logic:lsils:read_liberty" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoReadPlaLsils, "logic:lsils:read_pla" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteAigerLsils, "logic:lsils:write_aiger" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBenchLsils, "logic:lsils:write_bench" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteBlifLsils, "logic:lsils:write_blif" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteCnfLsils, "logic:lsils:write_cnf" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteDotLsils, "logic:lsils:write_dot" );
  LF_MACOR_REGISTER_TCL_CMD( CmdLfIoWriteVerilogLsils, "logic:lsils:write_verilog" );

  // Pass

  return EXIT_SUCCESS;
}

} // namespace tcl

} // namespace lf