#pragma once

#include "engine/tcl_main.hpp"
#include "register.hpp"

namespace lf
{

namespace tcl
{

int engine_start( int tcl_argc, char** tcl_argv )
{
  auto instance = TclMain::getInstance();

  instance->set_init_func( registerCmds );

  instance->tcl_main( tcl_argc, tcl_argv );

  return 0;
}

} // namespace tcl

} // namespace lf