#pragma once

#define LF_MACOR_REGISTER_TCL_CMD( type, name )    \
  do                                               \
  {                                                \
    auto cmd_ptr = std::make_unique<type>( name ); \
    TclCmds::addTclCmd( std::move( cmd_ptr ) );    \
  } while ( 0 )

///////////////////////////////////////////////////
// definition for yosys
///////////////////////////////////////////////////

///////////////////////////////////////////////////
// definition for abc
///////////////////////////////////////////////////

///////////////////////////////////////////////////
// definition for lsils
///////////////////////////////////////////////////

///////////////////////////////////////////////////
// definition for iEDA
///////////////////////////////////////////////////
#define TCL_HELP "-help"
#define TCL_JSON_OPTION "-discard"
#define TCL_CONFIG "-config"
#define TCL_PATH "-path"
#define TCL_DIRECTORY "-dir"
#define TCL_NAME "-name"
#define TCL_TYPE "-type"
#define EXCLUDE_CELL_NAMES "-exclude_cell_names"
#define TCL_OUTPUT_PATH "-output"
#define TCL_VERILOG_TOP "-top"
#define TCL_MAX_NUM "-max_num"
#define TCL_WORK_DIR "-work_dir"
#define TCL_STEP "-step"