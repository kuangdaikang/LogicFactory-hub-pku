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

    std::vector<std::string> commands_misc = {
        "help", "man" };
    std::vector<std::string> commands_flow = {
        "start", "stop", "anchor" };
    std::vector<std::string> commands_io = {
        "read_aiger", "read_blif", "read_bench", "read_pla", "read_cnf", "read_truth", "read_genlib", "read_liberty", "read_verilog",
        "write_aiger", "write_blif", "write_bench", "write_cnf", "write_dot", "write_verilog" };
    std::vector<std::string> commands_arch;
    std::vector<std::string> commands_logic;
    std::vector<std::string> commands_netlist;

    auto printCommands = []( const std::string& title, const std::vector<std::string>& commands ) {
      if ( commands.empty() )
        return;

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

    printCommands( "MISC:", commands_misc );
    printCommands( "FLOW:", commands_flow );
    printCommands( "IOs:", commands_io );
    printCommands( "ARCH:", commands_arch );
    printCommands( "LOGIC:", commands_logic );
    printCommands( "NETLIST:", commands_netlist );

    std::cout << "TODO: Use 'help <command>' for more information about a specific command." << std::endl;

    return 1;
  }

}; // class CmdLfHelp

} // namespace tcl

} // namespace lf