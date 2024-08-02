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
  explicit CmdLfHelp( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::string description = "";
    this->set_description( description );
    // set the domain
    std::string domain = "misc";
    this->set_domain( domain );
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

    std::vector<std::string> commands_misc = {};
    std::vector<std::string> commands_flow = {};
    std::vector<std::string> commands_io = {};
    std::vector<std::string> commands_arch = {};
    std::vector<std::string> commands_logic = {};
    std::vector<std::string> commands_netlist = {};

    for ( auto& [cmd_name, cmd] : TclCmds::getCmds() )
    {
      if ( cmd->get_domain() == "misc" )
        commands_misc.push_back( cmd_name );
      else if ( cmd->get_domain() == "flow" )

        commands_flow.push_back( cmd_name );
      else if ( cmd->get_domain() == "io" )
        commands_io.push_back( cmd_name );
      else if ( cmd->get_domain() == "arch" )
        commands_arch.push_back( cmd_name );
      else if ( cmd->get_domain() == "logic" )
        commands_logic.push_back( cmd_name );
      else if ( cmd->get_domain() == "netlist" )
        commands_netlist.push_back( cmd_name );
      else
      {
        std::cerr << "unknow domain of the cmd: " << cmd_name << std::endl;
        assert( false );
      }
    }
    std::sort( commands_misc.begin(), commands_misc.end() );
    std::sort( commands_flow.begin(), commands_flow.end() );
    std::sort( commands_io.begin(), commands_io.end() );
    std::sort( commands_arch.begin(), commands_arch.end() );
    std::sort( commands_logic.begin(), commands_logic.end() );
    std::sort( commands_netlist.begin(), commands_netlist.end() );

    auto printCommands = []( const std::string& title, const std::vector<std::string>& commands ) {
      if ( commands.empty() )
        return;

      std::cout << "                               " << title << std::endl;

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
      std::cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - " << std::endl;
    };

    printCommands( "MISC", commands_misc );
    printCommands( "FLOW", commands_flow );
    printCommands( "IOs", commands_io );
    printCommands( "ARCH LAYER", commands_arch );
    printCommands( "LOGIC LAYER", commands_logic );
    printCommands( "NETLIST LAYER", commands_netlist );

    return 1;
  }

}; // class CmdLfHelp

} // namespace tcl

} // namespace lf