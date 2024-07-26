#pragma once

#define LF_MACOR_REGISTER_TCL_CMD( type, cmd_name )    \
  do                                                   \
  {                                                    \
    auto cmd_ptr = std::make_unique<type>( cmd_name ); \
    TclCmds::addTclCmd( std::move( cmd_ptr ) );        \
  } while ( 0 )