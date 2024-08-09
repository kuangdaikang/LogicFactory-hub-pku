#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"
#include "tcl/cmds/utils.hpp"


#include "misc/anchor.hpp"

#include "layer_arch/api/yosys/pass/print_stat.hpp"
#include "layer_logic/api/abc/pass/print_stat.hpp"
#include "layer_logic/api/lsils/pass/print_stat.hpp"

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

class CmdLfStat : public TclCmd
{
public:
  explicit CmdLfStat( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-top", "yosys", "string", "" },
        { "-liberty", "yosys", "string", "" },
        { "-tech", "yosys", "string", "" },
        { "-width", "yosys", "bool", "" },
        { "-json", "yosys", "bool", "" },
        { "-f", "abc", "bool", "" },
        { "-b", "abc", "bool", "" },
        { "-d", "abc", "bool", "" },
        { "-l", "abc", "bool", "" },
        { "-t", "abc", "bool", "" },
        { "-m", "abc", "bool", "" },
        { "-p", "abc", "bool", "" },
        { "-g", "abc", "bool", "" },
        { "-s", "abc", "bool", "" },
        { "-c", "abc", "bool", "" },
        { "-u", "abc", "bool", "" },
        { "-lib", "lsils", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfStat() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {};
    return checkEssentialOptions( this, essential );
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    std::map<std::string, std::string> strOptionsValue;
    std::map<std::string, bool> boolOptionsValue;
    std::map<std::string, int> intOptionsValue;
    std::map<std::string, double> doubleOptionsValue;
    std::map<std::string, std::vector<std::string>> strvecOptionsValue;
    std::map<std::string, std::vector<int>> intvecOptionsValue;
    std::map<std::string, std::vector<double>> doublevecOptionsValue;

    std::vector<std::string> strOptions = { "-top", "-liberty", "-tech" };
    std::vector<std::string> boolOptions = { "-width", "-json", "-f", "-b", "-d", "-l", "-t", "-m", "-p", "-g", "-s", "-c", "-u", "-lib" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_domain = lfAnchorINST->get_anchor_domain();

    switch ( anchor_domain )
    {
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_ARCH_YOSYS:
      lf::arch::yosys::print_stat( strOptionsValue["-top"], strOptionsValue["-liberty"], strOptionsValue["-tech"],
                                   boolOptionsValue["-width"], boolOptionsValue["-json"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::print_stat( boolOptionsValue["-f"], boolOptionsValue["-b"], boolOptionsValue["-d"], boolOptionsValue["-l"],
                                  boolOptionsValue["-t"], boolOptionsValue["-m"], boolOptionsValue["-p"], boolOptionsValue["-g"],
                                  boolOptionsValue["-s"], boolOptionsValue["-c"], boolOptionsValue["-u"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::print_stat( boolOptionsValue["-lib"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfStat

} // namespace tcl

} // namespace lf