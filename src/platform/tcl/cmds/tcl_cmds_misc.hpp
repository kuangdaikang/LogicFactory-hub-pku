#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"

#include "utility/string.hpp"

#include <iomanip>

namespace lf
{

namespace tcl
{
class CmdLfHelp : public TclCmd
{
public:
  explicit CmdLfHelp( const char* cmd_name, const char* anchor_domain )
      : TclCmd( cmd_name, anchor_domain )
  {
  }

  ~CmdLfHelp() override = default;

  unsigned check() override
  {
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    std::vector<std::string> commands_misc;
    std::vector<std::string> commands_flow;
    std::vector<std::string> commands_arch;
    std::vector<std::string> commands_logic;
    std::vector<std::string> commands_netlist;

    for ( auto&& [key, cmd] : TclCmds::_cmds )
    {
      std::string anchor_domain = cmd->get_anchor_domain();
      if ( anchor_domain == "misc" )
        commands_misc.push_back( cmd->get_cmd_name() );
      else if ( anchor_domain == "flow" )
        commands_flow.push_back( cmd->get_cmd_name() );
      else if ( lf::utility::startWith( anchor_domain, "arch:" ) )
        commands_arch.push_back( cmd->get_cmd_name() );
      else if ( lf::utility::startWith( anchor_domain, "logic:" ) )
        commands_logic.push_back( cmd->get_cmd_name() );
      else if ( lf::utility::startWith( anchor_domain, "netlist:" ) )
        commands_netlist.push_back( cmd->get_cmd_name() );
      else
      {
        std::cerr << "Unknown anchor domain: " << anchor_domain << std::endl;
        assert( false );
        return 0;
      }
    }

    auto printCommands = []( const std::string& title, const std::vector<std::string>& commands ) {
      std::cout << title << std::endl;
      int count = 0;
      for ( const auto& cmd : commands )
      {
        std::cout << std::setw( 20 ) << std::left << cmd;
        count++;
        if ( count % 4 == 0 )
        {
          std::cout << std::endl;
        }
      }
      if ( count % 4 != 0 )
      {
        std::cout << std::endl;
      }
    };

    printCommands( "misc commands:", commands_misc );
    printCommands( "flow commands:", commands_flow );
    printCommands( "arch commands:", commands_arch );
    printCommands( "logic commands:", commands_logic );
    printCommands( "netlist commands:", commands_netlist );

    return 1;
  }

}; // class CmdLfHelp

class CmdLfMan : public TclCmd
{
public:
  explicit CmdLfMan( const char* cmd_name, const char* anchor_domain )
      : TclCmd( cmd_name, anchor_domain )
  {
  }

  ~CmdLfMan() override = default;

  unsigned check() override
  {
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    return 1;
  }

}; // class CmdLfMan

} // namespace tcl

} // namespace lf