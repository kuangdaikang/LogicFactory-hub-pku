#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"

#include "layer_arch/arch_manager.hpp"
#include "layer_logic/logic_manager.hpp"
#include "layer_netlist/netlist_manager.hpp"

namespace lf
{

namespace tcl
{
class CmdLfStart : public TclCmd
{
public:
  explicit CmdLfStart( const char* cmd_name )
      : TclCmd( cmd_name )
  {
  }

  ~CmdLfStart() override = default;

  unsigned check() override
  {
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    lfAmINST->start();
    lfLmINST->start();
    lfNamINST->start();

    return 1;
  }

}; // class CmdLfStart

class CmdLfStop : public TclCmd
{
public:
  explicit CmdLfStop( const char* cmd_name )
      : TclCmd( cmd_name )
  {
  }

  ~CmdLfStop() override = default;

  unsigned check() override
  {
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    lfAmINST->stop();
    lfLmINST->stop();
    lfNamINST->stop();

    return 1;
  }

}; // class CmdLfStop

} // namespace tcl

} // namespace lf