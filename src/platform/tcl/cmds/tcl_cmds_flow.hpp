#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"
#include "tcl/cmds/utils.hpp"

#include "misc/anchor.hpp"

#include "layer_arch/arch_manager.hpp"
#include "layer_logic/logic_manager.hpp"
#include "layer_netlist/netlist_manager.hpp"

#include "layer_netlist/api/ieda/pass/init.hpp"

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
    // set the description
    std::string description = "";
    this->set_description( description );
    // set the domain
    std::string domain = "flow";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
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
    lfNmINST->start();

    return 1;
  }

}; // class CmdLfStart

class CmdLfStop : public TclCmd
{
public:
  explicit CmdLfStop( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    // set the domain
    std::string domain = "flow";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
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
    lfNmINST->stop();

    return 1;
  }

}; // class CmdLfStop

class CmdLfAnchor : public TclCmd
{
public:
  explicit CmdLfAnchor( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    // set the domain
    std::string domain = "flow";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-layer", "all", "string", "" },
        { "-tool", "all", "string", "" },
        { "-stat", "all", "string", "" } };
    setOptions( this, options );
  }

  ~CmdLfAnchor() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = { "-tool" };
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

    std::vector<std::string> strOptions = { "-layer", "-tool", "-stat" };
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    // process
    lfAmINST->start();
    lfLmINST->start();
    lfNmINST->start();

    std::string tool = strOptionsValue["-tool"];

    if ( tool == "yosys" )
    {
      lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_ARCH_YOSYS_INIT );
    }
    else if ( tool == "abc" )
    {
      lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_INIT );
    }
    else if ( tool == "lsils" )
    {
      lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_INIT );
    }
    else if ( tool == "ieda" )
    {
      lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_INIT );
    }
    else
    {
      std::cerr << "Unknown anchor: " << std::endl;
      return 0;
    }

    return 1;
  }

}; // class CmdLfAnchor

} // namespace tcl

} // namespace lf