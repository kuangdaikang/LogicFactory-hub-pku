#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"
#include "tcl/cmds/utils.hpp"

#include "misc/anchor.hpp"

#include "layer_arch/arch_manager.hpp"
#include "layer_logic/logic_manager.hpp"
#include "layer_logic/wrapper/arch_to_logic.hpp"
#include "layer_logic/aux/convert_node.hpp"
#include "layer_logic/aux/convert_update.hpp"
#include "layer_logic/aux/convert_cover.hpp"

#include "layer_logic/api/abc/pass/strash.hpp"
#include "layer_logic/api/abc/pass/balance.hpp"
#include "layer_logic/api/abc/pass/rewrite.hpp"
#include "layer_logic/api/abc/pass/refactor.hpp"
#include "layer_logic/api/abc/pass/resub.hpp"
#include "layer_logic/api/abc/pass/map_fpga.hpp"
#include "layer_logic/api/abc/pass/map_asic.hpp"

#include "layer_logic/api/lsils/pass/balance.hpp"
#include "layer_logic/api/lsils/pass/rewrite.hpp"
#include "layer_logic/api/lsils/pass/refactor.hpp"
#include "layer_logic/api/lsils/pass/resub.hpp"
#include "layer_logic/api/lsils/pass/map_fpga.hpp"
#include "layer_logic/api/lsils/pass/map_asic.hpp"
#include "layer_logic/api/lsils/pass/strash.hpp"

#include "layer_logic/api/lsnbu/exact_map.hpp"
#include "layer_logic/api/lsnbu/lut_resyn.hpp"
#include "layer_logic/api/lsnbu/mighty.hpp"
#include "layer_logic/api/lsnbu/xag_mprm_multi_mult_opt.hpp"
#include "layer_logic/api/lsnbu/xag_mprm2_area_opt.hpp"
#include "layer_logic/api/lsnbu/xagba.hpp"
#include "layer_logic/api/lsnbu/xagrs.hpp"
#include "layer_logic/api/lsnbu/xagrw.hpp"
#include "layer_logic/api/lsnbu/xmgrs.hpp"
#include "layer_logic/api/lsnbu/xmgrw.hpp"

#include "layer_logic/api/lspku/FastEx/share/exact_synthesis/exact.h"
#include "layer_logic/api/lspku/FastEx/share/incremental/incremental.h"
#include "layer_logic/api/lspku/FastEx/share/netlist/netlist.h"
#include "layer_logic/api/lspku/FastEx/share/power/power.h"
#include "layer_logic/api/lspku/FastEx/share/utility/utility.h"
#include "layer_logic/api/lspku/PowerSyn/share/netlist.h"
#include "layer_logic/api/lspku/PowerSyn/RL/sources/PowerAwareSynthesis/netlist/abc_api.h"
#include "layer_logic/api/lspku/PowerSyn/RL/sources/PowerAwareSynthesis/netlist/netlist.h"
#include "layer_logic/api/lspku/PowerSyn/share/netlist.h"
#include <Python.h>

namespace lf
{

namespace tcl
{
class CmdLfLogicNtktype : public TclCmd
{
public:
  explicit CmdLfLogicNtktype( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-tool", "all", "string", "" },
        { "-stat", "all", "string", "" },
        { "-type", "all", "string", "" } };
    setOptions( this, options );
  }

  ~CmdLfLogicNtktype() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = { "-tool", "-stat", "-type" };
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

    std::vector<std::string> strOptions = { "-tool", "-stat", "-type" };
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    lfLntINST->set_ntktype( strOptionsValue["-tool"], strOptionsValue["-stat"], strOptionsValue["-type"] );

    return 1;
  }
}; // class CmdLfLogicNtktype

class CmdLfArch2Logic : public TclCmd
{
public:
  explicit CmdLfArch2Logic( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfArch2Logic() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );
    // transform arch into logic
    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();
    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_ARCH_YOSYS:
      lf::logic::arch_to_logic( lfAmINST->current<Yosys::RTLIL::Design*>() );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfArch2Logic

class CmdLfLogicConvert : public TclCmd
{
public:
  explicit CmdLfLogicConvert( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-from", "all", "string", "" },
        { "-to", "all", "string", "" },
        { "-n", "all", "bool", "convert by node to node" } };
    setOptions( this, options );
  }

  ~CmdLfLogicConvert() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = { "-from", "-to" };
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

    std::vector<std::string> strOptions = { "-from", "-to" };
    std::vector<std::string> boolOptions = { "-n" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    if ( boolOptionsValue["-n"] )
      lf::logic::convert_node( strOptionsValue["-from"], strOptionsValue["-to"] );
    else
      lf::logic::convert_cover( strOptionsValue["-from"], strOptionsValue["-to"] );
    return 1;
  }
}; // class CmdLfLogicConvert

class CmdLfLogicUpdate : public TclCmd
{
public:
  explicit CmdLfLogicUpdate( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-n", "all", "bool", "convert by node to node" } };
    setOptions( this, options );
  }

  ~CmdLfLogicUpdate() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = { "-n" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    lf::logic::convert_update( boolOptionsValue["-n"] );
    return 1;
  }
}; // class CmdLfLogicUpdate

class CmdLfLogicStrash : public TclCmd
{
public:
  explicit CmdLfLogicStrash( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-a", "abc", "bool", "" },
        { "-c", "abc", "bool", "" },
        { "-r", "abc", "bool", "" },
        { "-i", "abc", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfLogicStrash() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = { "-a", "-c", "-r", "-i" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_ABC:
      lf::logic::abc::strash( boolOptionsValue["-a"], boolOptionsValue["-c"], boolOptionsValue["-r"], boolOptionsValue["-i"] );
      break;
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsils::strash();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicStrash

class CmdLfLogicBalance : public TclCmd
{
public:
  explicit CmdLfLogicBalance( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-l", "abc", "bool", "" },
        { "-d", "abc", "bool", "" },
        { "-s", "abc", "bool", "" },
        { "-x", "abc", "bool", "" },
        { "-v", "abc", "bool", "" },
        { "-m", "lsils", "bool", "minimize level" },
        { "-f", "lsils", "bool", "fast mode" } };
    setOptions( this, options );
  }

  ~CmdLfLogicBalance() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = { "-l", "-d", "-s", "-x", "-v", "-m", "-f" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_ABC:
      lf::logic::abc::balance( boolOptionsValue["-l"], boolOptionsValue["-d"], boolOptionsValue["-s"], boolOptionsValue["-x"], boolOptionsValue["-v"] );
      break;
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsils::balance( boolOptionsValue["-m"], boolOptionsValue["-f"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicBalance

class CmdLfLogicRewrite : public TclCmd
{
public:
  explicit CmdLfLogicRewrite( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-l", "all", "bool", "" },
        { "-z", "all", "bool", "" },
        { "-d", "lsils", "bool", "" },
        { "-p", "lsils", "bool", "" },
        { "-v", "all", "bool", "" },
        { "-w", "all", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfLogicRewrite() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = { "-l", "-z", "-d", "-p", "-v", "-w" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_ABC:
      lf::logic::abc::rewrite( boolOptionsValue["-l"], boolOptionsValue["-z"], boolOptionsValue["-v"], boolOptionsValue["-w"] );
      break;
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsils::rewrite( boolOptionsValue["-l"], boolOptionsValue["-z"], boolOptionsValue["-d"], boolOptionsValue["-p"], boolOptionsValue["-v"], boolOptionsValue["-w"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicRewrite

class CmdLfLogicRefactor : public TclCmd
{
public:
  explicit CmdLfLogicRefactor( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-z", "all", "bool", "" },
        { "-v", "all", "bool", "" },
        { "-N", "all", "int", "max support of the collapsed node." },
        { "-M", "abc", "int", "min number of nodes saved after one step." },
        { "-l", "abc", "bool", "" },
        { "-r", "lsils", "bool", "" },
        { "-d", "lsils", "bool", "" },
        { "-p", "lsils", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfLogicRefactor() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = { "-z", "-v", "-l", "-r", "-d", "-p" };
    std::vector<std::string> intOptions = { "-M", "-N" };
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_ABC:
      lf::logic::abc::refactor( intOptionsValue["-N"], intOptionsValue["-M"], boolOptionsValue["-l"], boolOptionsValue["-z"], boolOptionsValue["-v"] );
      break;
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsils::refactor( intOptionsValue["-N"], boolOptionsValue["-z"], boolOptionsValue["-r"], boolOptionsValue["-d"], boolOptionsValue["-p"], boolOptionsValue["-v"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicRefactor

class CmdLfLogicResub : public TclCmd
{
public:
  explicit CmdLfLogicResub( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-K", "abc", "int", "the max cut size" },
        { "-N", "abc", "int", "max number of nodes to add." },
        { "-M", "abc", "int", "min number of nodes saved after one step." },
        { "-F", "abc", "int", "the number of fanout levels foir ODC computation." },
        { "-l", "all", "bool", "" },
        { "-z", "all", "bool", "" },
        { "-v", "abc", "bool", "" },
        { "-w", "abc", "bool", "" },
        { "-NI", "lsils", "int", "max support of the collapsed node." },
        { "-MD", "lsils", "int", "max divisors" },
        { "-MI", "lsils", "int", "max inserts" },
        { "-FLR", "lsils", "int", "fanout limit of root" },
        { "-FLD", "lsils", "int", "fanout limit divisor" },
        { "-W", "lsils", "int", "window size" },
        { "-d", "lsils", "bool", "" },
        { "-p", "lsils", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfLogicResub() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = { "-l", "-z", "-v", "-w", "-d", "-p" };
    std::vector<std::string> intOptions = { "-K", "-N", "-M", "-F", "-NI", "-MD", "-MI", "-FLR", "-FLD", "-W" };
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_ABC:
      lf::logic::abc::resub( intOptionsValue["-K"], intOptionsValue["-N"], intOptionsValue["-M"], intOptionsValue["-F"],
                             boolOptionsValue["-l"], boolOptionsValue["-z"], boolOptionsValue["-v"], boolOptionsValue["-w"] );
      break;
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsils::resub( intOptionsValue["-NI"], intOptionsValue["-MD"], intOptionsValue["-MI"], intOptionsValue["-FLR"], intOptionsValue["-FLD"], intOptionsValue["-W"],
                               boolOptionsValue["-l"], boolOptionsValue["-d"], boolOptionsValue["-p"], boolOptionsValue["-v"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicResub

class CmdLfLogicMapFPGA : public TclCmd
{
public:
  explicit CmdLfLogicMapFPGA( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        // Integer options with descriptions
        { "-K", "all", "int", "The number of LUT inputs (2 < num < 33)." },
        { "-C", "all", "int", "The max number of priority cuts (0 < num < 2^12)." },
        { "-F", "all", "int", "The number of area flow recovery iterations (num >= 0)." },
        { "-A", "all", "int", "The number of exact area recovery iterations (num >= 0)." },
        { "-G", "abc", "int", "The max AND/OR gate size for mapping (0 = unused)." },
        { "-R", "abc", "int", "The delay relaxation ratio (num >= 0)." },
        { "-N", "abc", "int", "The max size of non-decomposable nodes." },
        { "-T", "abc", "int", "The type of LUT structures." },
        { "-X", "abc", "int", "Delay of AND-gate in LUT library units." },
        { "-Y", "abc", "int", "Area of AND-gate in LUT library units." },
        { "-U", "abc", "int", "Number of LUT inputs for delay-driven LUT decomposition." },
        { "-Z", "abc", "int", "Number of LUT inputs for delay-driven LUT decomposition." },
        // double options with descriptions
        { "-D", "abc", "double", "Sets the delay constraint for the mapping." },
        { "-E", "abc", "double", "Sets epsilon used for tie-breaking." },
        { "-W", "abc", "double", "Sets wire delay between adjacent LUTs." },
        // String options with descriptions
        { "-S", "abc", "string", "String representing the LUT structure." },
        { "-J", "abc", "string", "String representing the LUT structure (new method)." },
        // Boolean switches with descriptions
        { "-q", "abc", "bool", "Toggles preprocessing using several starting points." },
        { "-a", "abc", "bool", "Toggles area-oriented mapping." },
        { "-r", "abc", "bool", "Enables expansion/reduction of the best cuts." },
        { "-l", "abc", "bool", "Optimizes latch paths for delay, other paths for area." },
        { "-e", "abc", "bool", "Uses edge-based cut selection heuristics." },
        { "-p", "abc", "bool", "Uses power-aware cut selection heuristics." },
        { "-m", "abc", "bool", "Enables cut minimization by removing vacuous variables." },
        { "-s", "abc", "bool", "Toggles delay-oriented mapping used with -S <NN>." },
        { "-d", "abc", "bool", "Toggles deriving local AIGs using bi-decomposition." },
        { "-b", "abc", "bool", "Toggles the use of one special feature." },
        { "-g", "abc", "bool", "Toggles delay optimization by SOP balancing." },
        { "-x", "abc", "bool", "Toggles delay optimization by DSD balancing." },
        { "-y", "abc", "bool", "Toggles delay optimization with recorded library." },
        { "-u", "abc", "bool", "Toggles delay optimization with SAT-based library." },
        { "-o", "abc", "bool", "Toggles using buffers to decouple combinational outputs." },
        { "-j", "abc", "bool", "Toggles enabling additional check." },
        { "-i", "abc", "bool", "Toggles using cofactoring variables." },
        { "-k", "abc", "bool", "Toggles matching based on precomputed DSD manager." },
        { "-t", "abc", "bool", "Toggles optimizing average rather than maximum level." },
        { "-n", "abc", "bool", "Toggles computing DSDs of the cut functions." },
        { "-c", "abc", "bool", "Toggles computing truth tables in a new way." },
        { "-v", "all", "bool", "Toggles verbose output." } };
    setOptions( this, options );
  }

  ~CmdLfLogicMapFPGA() override = default;

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

    std::vector<std::string> strOptions = { "-S", "-J" };
    std::vector<std::string> boolOptions = { "-q", "-m", "-s", "-d", "-b", "-g", "-x", "-y", "-u", "-o", "-j", "-i", "-k", "-t", "-n", "-c", "-v" };
    std::vector<std::string> intOptions = { "-K", "-C", "-F", "-A", "-G", "-R", "-N", "-T", "-X", "-Y", "-U", "-Z" };
    std::vector<std::string> doubleOptions = { "-D", "-E", "-W" };
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_ABC:
      lf::logic::abc::map_fpga( intOptionsValue["-K"], intOptionsValue["-C"], intOptionsValue["-F"], intOptionsValue["-A"],
                                intOptionsValue["-G"], intOptionsValue["-R"], intOptionsValue["-N"], intOptionsValue["-T"],
                                intOptionsValue["-X"], intOptionsValue["-Y"],
                                doubleOptionsValue["-D"], doubleOptionsValue["-E"], doubleOptionsValue["-W"],
                                strOptionsValue["-S"], strOptionsValue["-J"],
                                boolOptionsValue["-q"], boolOptionsValue["-a"], boolOptionsValue["-r"], boolOptionsValue["-l"],
                                boolOptionsValue["-e"], boolOptionsValue["-p"], boolOptionsValue["-m"], boolOptionsValue["-s"],
                                boolOptionsValue["-d"], boolOptionsValue["-b"], boolOptionsValue["-g"], boolOptionsValue["-x"],
                                boolOptionsValue["-y"], boolOptionsValue["-u"], boolOptionsValue["-o"], boolOptionsValue["-j"],
                                boolOptionsValue["-i"], boolOptionsValue["-k"], boolOptionsValue["-t"], boolOptionsValue["-n"],
                                boolOptionsValue["-c"], boolOptionsValue["-v"] );
      break;
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsils::map_fpga( intOptionsValue["-K"], intOptionsValue["-C"], intOptionsValue["-F"], intOptionsValue["-A"], boolOptionsValue["-v"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicMapFPGA

class CmdLfLogicMapASIC : public TclCmd
{
public:
  explicit CmdLfLogicMapASIC( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-D", "abc", "double", "Sets the global required times. Default is not used." },
        { "-A", "abc", "double", "\"Area multiplier\" to bias gate selection. Default is 0.00." },
        { "-B", "abc", "double", "\"Delay multiplier\" to bias gate selection. Default is 0.00." },
        { "-F", "abc", "double", "The logarithmic fanout delay parameter. Default is 0.00." },
        { "-S", "abc", "double", "The slew parameter used to generate the library. Default is 0.00." },
        { "-G", "abc", "double", "The gain parameter used to generate the library. Default is 250.00." },
        { "-M", "abc", "int", "Skip gate classes whose size is less than this. Default is 0." },
        { "-a", "abc", "bool", "Toggles area-only mapping. Default is no." },
        { "-r", "abc", "bool", "Toggles area recovery. Default is yes." },
        { "-s", "abc", "bool", "Toggles sweep after mapping. Default is no." },
        { "-p", "abc", "bool", "Optimizes power by minimizing switching. Default is no." },
        { "-f", "abc", "bool", "Do not use large gates to map high-fanout nodes. Default is no." },
        { "-u", "abc", "bool", "Use standard-cell profile. Default is no." },
        { "-o", "abc", "bool", "Toggles using buffers to decouple combinational outputs. Default is no." },
        { "-v", "abc", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfLogicMapASIC() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = { "-a", "-r", "-s", "-p", "-f", "-u", "-o", "-v" };
    std::vector<std::string> intOptions = { "-M" };
    std::vector<std::string> doubleOptions = { "-D", "-A", "-B", "-F", "-S", "-G" };
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_ABC:
      lf::logic::abc::map_asic( doubleOptionsValue["-D"], doubleOptionsValue["-A"], doubleOptionsValue["-B"], doubleOptionsValue["-F"], doubleOptionsValue["-S"], doubleOptionsValue["-G"],
                                intOptionsValue["-M"],
                                boolOptionsValue["-a"], boolOptionsValue["-r"], boolOptionsValue["-s"], boolOptionsValue["-p"], boolOptionsValue["-f"], boolOptionsValue["-u"], boolOptionsValue["-o"],
                                boolOptionsValue["-v"] );
      break;
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsils::map_asic();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicMapASIC

class CmdLfLogicXMGRewrite : public TclCmd
{
public:
  explicit CmdLfLogicXMGRewrite( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicXMGRewrite() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::xmgrw();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicXMGRewrite

class CmdLfLogicXAG1 : public TclCmd
{
public:
  explicit CmdLfLogicXAG1( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicXAG1() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::xag_mprm2_area_opt();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicXAG1

class CmdLfLogicXAG2 : public TclCmd
{
public:
  explicit CmdLfLogicXAG2( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicXAG2() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::xag_mprm_multi_mult_opt();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicXAG2

class CmdLfLogicExactMap : public TclCmd
{
public:
  explicit CmdLfLogicExactMap( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicExactMap() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::exact_map();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicExactMap

class CmdLfLogicLutResyn : public TclCmd
{
public:
  explicit CmdLfLogicLutResyn( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicLutResyn() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::lut_resyn();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicLutResyn

class CmdLfLogicMighty : public TclCmd
{
public:
  explicit CmdLfLogicMighty( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicMighty() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::mighty_rewrite();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicMighty

class CmdLfLogicXAGBalance : public TclCmd
{
public:
  explicit CmdLfLogicXAGBalance( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicXAGBalance() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::xagba();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicXAGBalance

class CmdLfLogicXAGResub : public TclCmd
{
public:
  explicit CmdLfLogicXAGResub( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicXAGResub() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::xagrs();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicXAGResub

class CmdLfLogicXAGRewrite : public TclCmd
{
public:
  explicit CmdLfLogicXAGRewrite( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicXAGRewrite() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::xagrw();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicXAGRewrite

class CmdLfLogicXMGResub : public TclCmd
{
public:
  explicit CmdLfLogicXMGResub( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "logic";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};
    setOptions( this, options );
  }

  ~CmdLfLogicXMGResub() override = default;

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

    std::vector<std::string> strOptions = {};
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_tool_domain = lfAnchorINST->get_anchor_tool_domain();

    switch ( anchor_tool_domain )
    {
    case lf::misc::E_LF_ANCHOR_TOOL::E_LF_ANCHOR_TOOL_LOGIC_LSILS:
      lf::logic::lsnbu::xmgrs();
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfLogicXMGResub


//PKU
class CmdLfLogicRLTestBasic : public TclCmd {
public:
    explicit CmdLfLogicRLTestBasic(const char* cmd_name) : TclCmd(cmd_name) {
        // 命令描述：明确说明使用basic特征模式
        set_description("RL test command with fixed 'basic' feature mode (obs_dim=14)");
        set_domain("logic");

        // 选项定义（移除-feature_mode，固定为basic）
        addOption("-test_list", "Path to test circuit list file", "");
        addOption("-result_log", "Path to result log file", "");
        addOption("-agent_type", "Type of agent (PPO/greedy/random/anneal/abc_resyn)", "PPO");
        addOption("-model", "Path to PPO model file (if agent_type=PPO)", "");
        addOption("-fixed_mode", "Whether to use fixed iteration mode (0/1)", "0");
        addOption("-result_dir", "Directory to save results", "");
        addOption("-test_dir", "Directory containing test circuits", "");
        addOption("-seq_length", "Maximum iterations per circuit", "32");
        addOption("-converge_length", "Convergence threshold", "32");
        addOption("-initial_t", "Initial temperature for annealing", "100.0");
        addOption("-terminate_t", "Termination temperature for annealing", "0.01");
        addOption("-cool_ratio", "Cooling ratio for annealing", "0.2");
        addOption("-trace_dir", "Directory for trace files", "");
        addOption("-trace_file", "Path to trace file", "");
    }

    ~CmdLfLogicRLTestBasic() override {
        if (Py_IsInitialized()) {
            Py_Finalize();
        }
    }

    unsigned check() override {
        // 检查必填参数
        if (getOption("-test_list").empty()) {
            std::cerr << "Missing required option: -test_list" << std::endl;
            return 0;
        }
        // PPO代理必须提供模型路径
        if (getOption("-agent_type") == "PPO" && getOption("-model").empty()) {
            std::cerr << "PPO agent requires -model option" << std::endl;
            return 0;
        }
        return 1;
    }

    unsigned exec() override {
        if (!check()) return 0;

        // 初始化Python
        Py_Initialize();
        if (!Py_IsInitialized()) {
            std::cerr << "Failed to initialize Python" << std::endl;
            return 0;
        }

        // 提取命令参数
        std::string test_list = getOption("-test_list");
        std::string result_log = getOption("-result_log");
        std::string agent_type = getOption("-agent_type");
        std::string model_path = getOption("-model");
        int fixed_mode = std::stoi(getOption("-fixed_mode"));
        std::string result_dir = getOption("-result_dir");
        std::string test_dir = getOption("-test_dir");
        int seq_length = std::stoi(getOption("-seq_length"));
        int converge_length = std::stoi(getOption("-converge_length"));
        double initial_t = std::stod(getOption("-initial_t"));
        double terminate_t = std::stod(getOption("-terminate_t"));
        double cool_ratio = std::stod(getOption("-cool_ratio"));
        std::string trace_dir = getOption("-trace_dir");
        std::string trace_file = getOption("-trace_file");

        // 构建Python代码（固定feature_mode=basic，obs_dim=14）
        std::string python_code = R"(
import gym
from stable_baselines3 import PPO
import copy
import argparse


class Namespace:
    def __init__(self, **kwargs):
        self.__dict__.update(kwargs)


def get_action(agent_type, obs=None, model=None, gym_env=None, temperatures=None, iter_info=None):
    if agent_type == 'PPO':
        assert model is not None and obs is not None
        action, _ = model.predict(obs)
        return action
    elif agent_type == 'random':
        assert gym_env is not None
        return gym_env.action_space.sample()
    elif agent_type == 'anneal':
        assert temperatures is not None and gym_env is not None
        env = copy.deepcopy(gym_env)
        action = env.action_space.sample()
        obs, reward, done, info = env.step(env.action_space.sample())
        env.stop()
        temperatures.current_t *= temperatures.cool_ratio
        if reward > 0 or temperatures.current_t >= temperatures.terminate_t:
            return action
        else:
            return -1
    elif agent_type == 'greedy':
        assert gym_env is not None
        best_reward = float('-inf')
        best_action = -1
        for i in range(gym_env.action_space.n):
            env = copy.deepcopy(gym_env)
            obs, reward, done, info = env.step(i)
            if reward > best_reward:
                best_reward = reward
                best_action = i
            env.stop()
        assert best_action != -1
        return best_action
    elif agent_type == 'abc_resyn':
        assert iter_info is not None
        a = [0, 1, 2, 0, 2, 0, 0, 1, 3, 0, 1, 2, 0, 4, 2, 0]
        return a[(iter_info['current_iters'] + iter_info['current_unchanged_iters']) % 16]
    else:
        raise NotImplementedError


def test_done(fixed_mode, iter_infos):
    iter_infos['total_iters'] += 1
    if fixed_mode:
        iter_infos['current_iters'] += 1
        if iter_infos['current_iters'] < iter_infos['max_iters']:
            return False
        else:
            return True
    else:
        if iter_infos['current_reward'] <= 0:
            iter_infos['current_unchanged_iters'] += 1
        else:
            iter_infos['current_unchanged_iters'] = 0
            iter_infos['current_iters'] += 1
        if iter_infos['current_unchanged_iters'] < iter_infos['converge_length']:
            return False
        else:
            return True


def main(arguments):
    # 固定使用basic特征模式，观测维度=14
    obs_dim = 14
    feature_mode = "basic"
    
    fixed_mode = arguments.fixed_mode
    result_dir = arguments.result_dir
    result_log = arguments.result_log
    model = arguments.model_name
    test_dir = arguments.test_dir
    test_list = arguments.test_list
    seq_length = arguments.seq_length
    converge_length = arguments.converge_length
    temperatures = {'current_t': arguments.initial_t, 'terminate_t': arguments.terminate_t,
                    'cool_ratio': arguments.cool_ratio}

    env = gym.make('gym_genus:genus-v0', 
                   lib_file="/rshome/daikang.kuang/PowerAwareSynthesis/netlist/gsc145nm.lib",
                   feature_mode=feature_mode, 
                   obs_dim=obs_dim)
    model = PPO.load(model, device='cpu') if arguments.agent_type == 'PPO' else None
    
    with open(test_list, 'r') as file:
        for line in file.readlines():
            with open(result_log, 'a') as result:
                env.setup(test_dir + '/' + line)
                result.write(line + "\n")
                obs, info = env.reset(return_info=True)
                info_str = ""
                for _ in info.values():
                    info_str += str(_) + " "
                result.write(info_str)
                result.write('\n')
                iter_infos = {'current_iters': 0, 'converge_length': converge_length, 'max_iters': seq_length,
                              'current_reward': 0, 'current_unchanged_iters': 0, 'total_iters': 0}
                while True:
                    action = get_action(arguments.agent_type, obs=obs, model=model, gym_env=env,
                                        temperatures=temperatures, iter_info=iter_infos)
                    #print(action)
                    if action == -1:
                        continue
                    obs, reward, done, info = env.step(action, arguments.trace_dir, iter_infos['total_iters'])
                    if arguments.trace_file is not None:
                        with open(arguments.trace_file, 'a') as trace:
                            info_str = ""
                            for _ in info.values():
                                info_str += str(_) + " "
                            trace.write(str(iter_infos['total_iters'])+" "+str(iter_infos['current_iters'])+" "+info_str+"\n")
                            trace.close()
                    iter_infos['current_reward'] = reward
                    if test_done(fixed_mode, iter_infos):
                        break
                    print(iter_infos['current_iters'])
                info_str = ""
                for _ in info.values():
                    info_str += str(_) + " "
                result.write(info_str)
                result.write('\n')
                result.write('seq_length: ' + str(iter_infos['current_iters']))
                result.write('\n')
                if result_dir != "":
                    env.write(result_dir + '/' + line)
                env.stop()
                result.close()
        file.close()


# 传递参数并执行
args = Namespace(
    test_list=")";
        python_code += test_list + R"(",
    result_log=")";
        python_code += result_log + R"(",
    agent_type=")";
        python_code += agent_type + R"(",
    model_name=")";
        python_code += model_path + R"(",
    fixed_mode=")";
        python_code += std::to_string(fixed_mode) + R"(",
    result_dir=")";
        python_code += result_dir + R"(",
    test_dir=")";
        python_code += test_dir + R"(",
    seq_length=")";
        python_code += std::to_string(seq_length) + R"(",
    converge_length=")";
        python_code += std::to_string(converge_length) + R"(",
    initial_t=")";
        python_code += std::to_string(initial_t) + R"(",
    terminate_t=")";
        python_code += std::to_string(terminate_t) + R"(",
    cool_ratio=")";
        python_code += std::to_string(cool_ratio) + R"(",
    trace_dir=")";
        python_code += trace_dir + R"(",
    trace_file=")";
        python_code += trace_file + R"("
)

main(args)
)";

        // 执行Python代码
        PyRun_SimpleString(python_code.c_str());

        // 检查Python执行错误
        if (PyErr_Occurred()) {
            PyErr_Print();
            std::cerr << "Python code execution failed (basic feature mode)" << std::endl;
            Py_Finalize();
            return 0;
        }

        Py_Finalize();
        return 1;
    }
};



class CmdLfLogicRLTestGlitch : public TclCmd {
public:
    explicit CmdLfLogicRLTestGlitch(const char* cmd_name) : TclCmd(cmd_name) {
        // 命令描述：明确说明使用glitch特征模式
        set_description("RL test command with fixed 'glitch' feature mode (obs_dim=89)");
        set_domain("logic");

        // 选项定义（移除-feature_mode，固定为glitch）
        addOption("-test_list", "Path to test circuit list file", "");
        addOption("-result_log", "Path to result log file", "");
        addOption("-agent_type", "Type of agent (PPO/greedy/random/anneal/abc_resyn)", "PPO");
        addOption("-model", "Path to PPO model file (if agent_type=PPO)", "");
        addOption("-fixed_mode", "Whether to use fixed iteration mode (0/1)", "0");
        addOption("-result_dir", "Directory to save results", "");
        addOption("-test_dir", "Directory containing test circuits", "");
        addOption("-seq_length", "Maximum iterations per circuit", "32");
        addOption("-converge_length", "Convergence threshold", "32");
        addOption("-initial_t", "Initial temperature for annealing", "100.0");
        addOption("-terminate_t", "Termination temperature for annealing", "0.01");
        addOption("-cool_ratio", "Cooling ratio for annealing", "0.2");
        addOption("-trace_dir", "Directory for trace files", "");
        addOption("-trace_file", "Path to trace file", "");
    }

    ~CmdLfLogicRLTestGlitch() override {
        if (Py_IsInitialized()) {
            Py_Finalize();
        }
    }

    unsigned check() override {
        // 检查必填参数
        if (getOption("-test_list").empty()) {
            std::cerr << "Missing required option: -test_list" << std::endl;
            return 0;
        }
        // PPO代理必须提供模型路径
        if (getOption("-agent_type") == "PPO" && getOption("-model").empty()) {
            std::cerr << "PPO agent requires -model option" << std::endl;
            return 0;
        }
        return 1;
    }

    unsigned exec() override {
        if (!check()) return 0;

        // 初始化Python
        Py_Initialize();
        if (!Py_IsInitialized()) {
            std::cerr << "Failed to initialize Python" << std::endl;
            return 0;
        }

        // 提取命令参数
        std::string test_list = getOption("-test_list");
        std::string result_log = getOption("-result_log");
        std::string agent_type = getOption("-agent_type");
        std::string model_path = getOption("-model");
        int fixed_mode = std::stoi(getOption("-fixed_mode"));
        std::string result_dir = getOption("-result_dir");
        std::string test_dir = getOption("-test_dir");
        int seq_length = std::stoi(getOption("-seq_length"));
        int converge_length = std::stoi(getOption("-converge_length"));
        double initial_t = std::stod(getOption("-initial_t"));
        double terminate_t = std::stod(getOption("-terminate_t"));
        double cool_ratio = std::stod(getOption("-cool_ratio"));
        std::string trace_dir = getOption("-trace_dir");
        std::string trace_file = getOption("-trace_file");

        // 构建Python代码（固定feature_mode=glitch，obs_dim=89）
        std::string python_code = R"(
import gym
from stable_baselines3 import PPO
import copy
import argparse


class Namespace:
    def __init__(self, **kwargs):
        self.__dict__.update(kwargs)


def get_action(agent_type, obs=None, model=None, gym_env=None, temperatures=None, iter_info=None):
    if agent_type == 'PPO':
        assert model is not None and obs is not None
        action, _ = model.predict(obs)
        return action
    elif agent_type == 'random':
        assert gym_env is not None
        return gym_env.action_space.sample()
    elif agent_type == 'anneal':
        assert temperatures is not None and gym_env is not None
        env = copy.deepcopy(gym_env)
        action = env.action_space.sample()
        obs, reward, done, info = env.step(env.action_space.sample())
        env.stop()
        temperatures.current_t *= temperatures.cool_ratio
        if reward > 0 or temperatures.current_t >= temperatures.terminate_t:
            return action
        else:
            return -1
    elif agent_type == 'greedy':
        assert gym_env is not None
        best_reward = float('-inf')
        best_action = -1
        for i in range(gym_env.action_space.n):
            env = copy.deepcopy(gym_env)
            obs, reward, done, info = env.step(i)
            if reward > best_reward:
                best_reward = reward
                best_action = i
            env.stop()
        assert best_action != -1
        return best_action
    elif agent_type == 'abc_resyn':
        assert iter_info is not None
        a = [0, 1, 2, 0, 2, 0, 0, 1, 3, 0, 1, 2, 0, 4, 2, 0]
        return a[(iter_info['current_iters'] + iter_info['current_unchanged_iters']) % 16]
    else:
        raise NotImplementedError


def test_done(fixed_mode, iter_infos):
    iter_infos['total_iters'] += 1
    if fixed_mode:
        iter_infos['current_iters'] += 1
        if iter_infos['current_iters'] < iter_infos['max_iters']:
            return False
        else:
            return True
    else:
        if iter_infos['current_reward'] <= 0:
            iter_infos['current_unchanged_iters'] += 1
        else:
            iter_infos['current_unchanged_iters'] = 0
            iter_infos['current_iters'] += 1
        if iter_infos['current_unchanged_iters'] < iter_infos['converge_length']:
            return False
        else:
            return True


def main(arguments):
    # 固定使用glitch特征模式，观测维度=89
    obs_dim = 89
    feature_mode = "glitch"
    
    fixed_mode = arguments.fixed_mode
    result_dir = arguments.result_dir
    result_log = arguments.result_log
    model = arguments.model_name
    test_dir = arguments.test_dir
    test_list = arguments.test_list
    seq_length = arguments.seq_length
    converge_length = arguments.converge_length
    temperatures = {'current_t': arguments.initial_t, 'terminate_t': arguments.terminate_t,
                    'cool_ratio': arguments.cool_ratio}

    env = gym.make('gym_genus:genus-v0', 
                   lib_file="/rshome/daikang.kuang/PowerAwareSynthesis/netlist/gsc145nm.lib",
                   feature_mode=feature_mode, 
                   obs_dim=obs_dim)
    model = PPO.load(model, device='cpu') if arguments.agent_type == 'PPO' else None
    
    with open(test_list, 'r') as file:
        for line in file.readlines():
            with open(result_log, 'a') as result:
                env.setup(test_dir + '/' + line)
                result.write(line + "\n")
                obs, info = env.reset(return_info=True)
                info_str = ""
                for _ in info.values():
                    info_str += str(_) + " "
                result.write(info_str)
                result.write('\n')
                iter_infos = {'current_iters': 0, 'converge_length': converge_length, 'max_iters': seq_length,
                              'current_reward': 0, 'current_unchanged_iters': 0, 'total_iters': 0}
                while True:
                    action = get_action(arguments.agent_type, obs=obs, model=model, gym_env=env,
                                        temperatures=temperatures, iter_info=iter_infos)
                    #print(action)
                    if action == -1:
                        continue
                    obs, reward, done, info = env.step(action, arguments.trace_dir, iter_infos['total_iters'])
                    if arguments.trace_file is not None:
                        with open(arguments.trace_file, 'a') as trace:
                            info_str = ""
                            for _ in info.values():
                                info_str += str(_) + " "
                            trace.write(str(iter_infos['total_iters'])+" "+str(iter_infos['current_iters'])+" "+info_str+"\n")
                            trace.close()
                    iter_infos['current_reward'] = reward
                    if test_done(fixed_mode, iter_infos):
                        break
                    print(iter_infos['current_iters'])
                info_str = ""
                for _ in info.values():
                    info_str += str(_) + " "
                result.write(info_str)
                result.write('\n')
                result.write('seq_length: ' + str(iter_infos['current_iters']))
                result.write('\n')
                if result_dir != "":
                    env.write(result_dir + '/' + line)
                env.stop()
                result.close()
        file.close()


# 传递参数并执行
args = Namespace(
    test_list=")";
        python_code += test_list + R"(",
    result_log=")";
        python_code += result_log + R"(",
    agent_type=")";
        python_code += agent_type + R"(",
    model_name=")";
        python_code += model_path + R"(",
    fixed_mode=")";
        python_code += std::to_string(fixed_mode) + R"(",
    result_dir=")";
        python_code += result_dir + R"(",
    test_dir=")";
        python_code += test_dir + R"(",
    seq_length=")";
        python_code += std::to_string(seq_length) + R"(",
    converge_length=")";
        python_code += std::to_string(converge_length) + R"(",
    initial_t=")";
        python_code += std::to_string(initial_t) + R"(",
    terminate_t=")";
        python_code += std::to_string(terminate_t) + R"(",
    cool_ratio=")";
        python_code += std::to_string(cool_ratio) + R"(",
    trace_dir=")";
        python_code += trace_dir + R"(",
    trace_file=")";
        python_code += trace_file + R"("
)

main(args)
)";

        // 执行Python代码
        PyRun_SimpleString(python_code.c_str());

        // 检查Python执行错误
        if (PyErr_Occurred()) {
            PyErr_Print();
            std::cerr << "Python code execution failed (glitch feature mode)" << std::endl;
            Py_Finalize();
            return 0;
        }

        Py_Finalize();
        return 1;
    }
};



class CmdLfLogicDITT : public TclCmd
{
public:
  explicit CmdLfLogicDITT(const char* cmd_name)
      : TclCmd(cmd_name)
  {
    // 设置命令描述和域
    std::string description = "Perform exact logic synthesis using DITT (Dynamic Integer Temporal Transformation) method";
    this->set_description(description);
    std::string domain = "logic";
    this->set_domain(domain);

    // 设置命令选项
    std::vector<lfCmdOption> options = {
        { "-functions", "List of boolean functions (hex strings)", "string", "" },
        { "-r", "Number of steps (r value)", "int", "1" },
        { "-sat_output", "Path to save SAT CNF encoding", "string", "ditt_output.cnf" },
        { "-circuit_output", "Path to save decoded circuit", "string", "ditt_circuit.blif" },
        { "-solver", "SAT solver to use (kissat/cadical)", "string", "kissat" },
        { "-non_trivial", "Enable non-trivial constraints", "bool", "0" },
        { "-all_steps", "Enable all-steps constraints", "bool", "0" },
        { "-no_replication", "Enable no-replication constraints", "bool", "0" },
        { "-lex_step", "Enable lexicographical step constraints", "bool", "0" },
        { "-lex_op", "Enable lexicographical op constraints", "bool", "0" },
        { "-ordered_sym", "Enable ordered symmetric constraints", "bool", "0" }
    };
    setOptions(this, options);
  }

  ~CmdLfLogicDITT() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = { "-functions" };
    return checkEssentialOptions(this, essential);
  }

  unsigned exec() override
  {
    if (!check())
      return 0;

    // 提取命令选项值
    std::map<std::string, std::string> strOptionsValue;
    std::map<std::string, bool> boolOptionsValue;
    std::map<std::string, int> intOptionsValue;
    std::map<std::string, double> doubleOptionsValue;
    std::map<std::string, std::vector<std::string>> strvecOptionsValue;
    std::map<std::string, std::vector<int>> intvecOptionsValue;
    std::map<std::string, std::vector<double>> doublevecOptionsValue;

    std::vector<std::string> strOptions = { "-functions", "-sat_output", "-circuit_output", "-solver" };
    std::vector<std::string> boolOptions = { "-non_trivial", "-all_steps", "-no_replication", "-lex_step", "-lex_op", "-ordered_sym" };
    std::vector<std::string> intOptions = { "-r" };
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions(this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue);

    // 分割函数列表字符串
    std::vector<std::string> func_strs = splitString(strOptionsValue["-functions"], ',');

    // 执行DITT逻辑综合
    try {
        // 创建DITT对象
        Technology tech;
        DITT ditt(func_strs, tech, intOptionsValue["-r"],
                  boolOptionsValue["-non_trivial"], boolOptionsValue["-all_steps"],
                  boolOptionsValue["-no_replication"], boolOptionsValue["-lex_step"],
                  boolOptionsValue["-lex_op"], boolOptionsValue["-ordered_sym"]);
        ditt.r = intOptionsValue["-r"];

        // 编码为SAT问题
        Encoding encoding = ditt.encode(true);

        // 保存SAT编码
        if (!strOptionsValue["-sat_output"].empty()) {
            std::ofstream sat_file(strOptionsValue["-sat_output"]);
            if (sat_file.is_open()) {
                encoding.write_dimacs(sat_file);
                sat_file.close();
                std::cout << "SAT encoding saved to: " << strOptionsValue["-sat_output"] << std::endl;
            } else {
                std::cerr << "Failed to open SAT output file: " << strOptionsValue["-sat_output"] << std::endl;
                return 0;
            }
        }

        // 调用SAT求解器
        std::cout << "Running " << strOptionsValue["-solver"] << " for synthesis..." << std::endl;
        auto [success, solution] = synthesis(&ditt, strOptionsValue["-solver"].c_str(), std::cout);
        if (!success) {
            std::cerr << "Synthesis failed (no solution found)" << std::endl;
            return 0;
        }

        // 解码并保存电路
        if (!strOptionsValue["-circuit_output"].empty()) {
            ditt.decode(solution, strOptionsValue["-circuit_output"]);
            std::cout << "Decoded circuit saved to: " << strOptionsValue["-circuit_output"] << std::endl;
        }

        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Exception during synthesis: " << e.what() << std::endl;
        return 0;
    }
  }

private:
    // 辅助函数：字符串分割
    std::vector<std::string> splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
};


class CmdLfLogicMSV : public TclCmd
{
public:
  explicit CmdLfLogicMSV(const char* cmd_name)
      : TclCmd(cmd_name)
  {
    // 设置命令描述和域
    std::string description = "Perform exact logic synthesis using MSV (Multi-Stage Variable) method";
    this->set_description(description);
    std::string domain = "logic";
    this->set_domain(domain);

    // 设置命令选项（与 MSV 类参数对应）
    std::vector<lfCmdOption> options = {
        { "-functions", "List of boolean functions (hex strings, comma-separated)", "string", "" },
        { "-r", "Number of synthesis steps (r value)", "int", "1" },
        { "-sat_output", "Path to save SAT CNF encoding (.cnf)", "string", "msv_output.cnf" },
        { "-circuit_output", "Path to save decoded circuit (.blif)", "string", "msv_circuit.blif" },
        { "-solver", "SAT solver to use (kissat/cadical)", "string", "kissat" },
        // 约束参数
        { "-non_trivial", "Enable non-trivial constraints (0/1)", "bool", "0" },
        { "-all_steps", "Enable all-steps constraints (0/1)", "bool", "0" },
        { "-no_replication", "Enable no-replication constraints (0/1)", "bool", "0" },
        { "-lex_step", "Enable lexicographical step constraints (0/1)", "bool", "0" },
        { "-lex_op", "Enable lexicographical op constraints (0/1)", "bool", "0" },
        { "-ordered_sym", "Enable ordered symmetric constraints (0/1)", "bool", "0" }
    };
    setOptions(this, options);
  }

  ~CmdLfLogicMSV() override = default;

  unsigned check() override
  {
    // 检查必填选项
    std::vector<std::string> essential = { "-functions" };
    return checkEssentialOptions(this, essential);
  }

  unsigned exec() override
  {
    if (!check())
      return 0;

    // 提取选项值到对应映射表
    std::map<std::string, std::string> strOptionsValue;
    std::map<std::string, bool> boolOptionsValue;
    std::map<std::string, int> intOptionsValue;
    std::map<std::string, double> doubleOptionsValue;
    std::map<std::string, std::vector<std::string>> strvecOptionsValue;
    std::map<std::string, std::vector<int>> intvecOptionsValue;
    std::map<std::string, std::vector<double>> doublevecOptionsValue;

    // 定义选项类型分类
    std::vector<std::string> strOptions = { "-functions", "-sat_output", "-circuit_output", "-solver" };
    std::vector<std::string> boolOptions = { "-non_trivial", "-all_steps", "-no_replication", 
                                             "-lex_step", "-lex_op", "-ordered_sym" };
    std::vector<std::string> intOptions = { "-r" };
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    // 提取选项值
    extractOptions(this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue);

    // 分割函数列表（逗号分隔的字符串→向量）
    std::vector<std::string> func_strs = splitString(strOptionsValue["-functions"], ',');

    // 执行 MSV 逻辑综合流程
    try {
        // 创建 MSV 对象
        Technology tech;
        MSV msv(func_strs, tech, intOptionsValue["-r"],
                boolOptionsValue["-non_trivial"], boolOptionsValue["-all_steps"],
                boolOptionsValue["-no_replication"], boolOptionsValue["-lex_step"],
                boolOptionsValue["-lex_op"], boolOptionsValue["-ordered_sym"]);
        msv.r = intOptionsValue["-r"];  // 设置步骤数

        // 编码为 SAT 问题
        Encoding encoding = msv.encode(true);  // 保留变量注释

        // 保存 SAT 编码文件（.cnf）
        if (!strOptionsValue["-sat_output"].empty()) {
            std::ofstream sat_file(strOptionsValue["-sat_output"]);
            if (sat_file.is_open()) {
                encoding.write_dimacs(sat_file);
                sat_file.close();
                std::cout << "SAT encoding saved to: " << strOptionsValue["-sat_output"] << std::endl;
            } else {
                std::cerr << "Failed to open SAT output file: " << strOptionsValue["-sat_output"] << std::endl;
                return 0;
            }
        }

        // 调用 SAT 求解器进行综合
        std::cout << "Running " << strOptionsValue["-solver"] << " for MSV synthesis..." << std::endl;
        auto [success, solution] = synthesis(&msv, strOptionsValue["-solver"].c_str(), std::cout);
        if (!success) {
            std::cerr << "MSV synthesis failed: no solution found" << std::endl;
            return 0;
        }

        // 解码 SAT 解为逻辑电路（.blif）
        if (!strOptionsValue["-circuit_output"].empty()) {
            msv.decode(solution, strOptionsValue["-circuit_output"]);
            std::cout << "Decoded circuit saved to: " << strOptionsValue["-circuit_output"] << std::endl;
        }

        return 1;  // 成功执行
    } catch (const std::exception& e) {
        std::cerr << "MSV synthesis error: " << e.what() << std::endl;
        return 0;
    }
  }

private:
    // 辅助函数：将逗号分隔的字符串分割为向量
    std::vector<std::string> splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            if (!token.empty())  // 忽略空字符串（处理连续逗号的情况）
                tokens.push_back(token);
        }
        return tokens;
    }
};



class CmdLfLogicSSV : public TclCmd
{
public:
  explicit CmdLfLogicSSV(const char* cmd_name)
      : TclCmd(cmd_name)
  {
    // 设置命令描述和域
    std::string description = "Perform exact logic synthesis using SSV (Symmetric Stage Variable) method";
    this->set_description(description);
    std::string domain = "logic";
    this->set_domain(domain);

    // 设置命令选项（与 SSV 类参数对应）
    std::vector<lfCmdOption> options = {
        { "-functions", "List of boolean functions (hex strings, comma-separated)", "string", "" },
        { "-r", "Number of synthesis steps (r value)", "int", "1" },
        { "-sat_output", "Path to save SAT CNF encoding (.cnf)", "string", "ssv_output.cnf" },
        { "-circuit_output", "Path to save decoded circuit (.blif)", "string", "ssv_circuit.blif" },
        { "-solver", "SAT solver to use (kissat/cadical)", "string", "kissat" },
        // 约束参数（与 SSV 类的约束方法对应）
        { "-non_trivial", "Enable non-trivial constraints (0/1)", "bool", "0" },
        { "-all_steps", "Enable all-steps constraints (0/1)", "bool", "0" },
        { "-no_replication", "Enable no-replication constraints (0/1)", "bool", "0" },
        { "-lex_step", "Enable lexicographical step constraints (0/1)", "bool", "0" },
        { "-lex_op", "Enable lexicographical op constraints (0/1)", "bool", "0" },
        { "-ordered_sym", "Enable ordered symmetric constraints (0/1)", "bool", "0" }
    };
    setOptions(this, options);
  }

  ~CmdLfLogicSSV() override = default;

  unsigned check() override
  {
    // 检查必填选项（逻辑函数列表为必需参数）
    std::vector<std::string> essential = { "-functions" };
    return checkEssentialOptions(this, essential);
  }

  unsigned exec() override
  {
    if (!check())
      return 0;

    // 提取选项值到对应映射表
    std::map<std::string, std::string> strOptionsValue;
    std::map<std::string, bool> boolOptionsValue;
    std::map<std::string, int> intOptionsValue;
    std::map<std::string, double> doubleOptionsValue;
    std::map<std::string, std::vector<std::string>> strvecOptionsValue;
    std::map<std::string, std::vector<int>> intvecOptionsValue;
    std::map<std::string, std::vector<double>> doublevecOptionsValue;

    // 定义选项类型分类
    std::vector<std::string> strOptions = { "-functions", "-sat_output", "-circuit_output", "-solver" };
    std::vector<std::string> boolOptions = { "-non_trivial", "-all_steps", "-no_replication", 
                                             "-lex_step", "-lex_op", "-ordered_sym" };
    std::vector<std::string> intOptions = { "-r" };
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    // 提取选项值
    extractOptions(this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue);

    // 分割函数列表（逗号分隔的字符串→向量）
    std::vector<std::string> func_strs = splitString(strOptionsValue["-functions"], ',');

    // 执行 SSV 逻辑综合流程
    try {
        // 创建 SSV 对象
        Technology tech;
        SSV ssv(func_strs, tech, intOptionsValue["-r"],
                boolOptionsValue["-non_trivial"], boolOptionsValue["-all_steps"],
                boolOptionsValue["-no_replication"], boolOptionsValue["-lex_step"],
                boolOptionsValue["-lex_op"], boolOptionsValue["-ordered_sym"]);
        ssv.r = intOptionsValue["-r"];  // 设置步骤数

        // 编码为 SAT 问题
        Encoding encoding = ssv.encode(true);  // 保留变量注释

        // 保存 SAT 编码文件（.cnf）
        if (!strOptionsValue["-sat_output"].empty()) {
            std::ofstream sat_file(strOptionsValue["-sat_output"]);
            if (sat_file.is_open()) {
                encoding.write_dimacs(sat_file);
                sat_file.close();
                std::cout << "SAT encoding saved to: " << strOptionsValue["-sat_output"] << std::endl;
            } else {
                std::cerr << "Failed to open SAT output file: " << strOptionsValue["-sat_output"] << std::endl;
                return 0;
            }
        }

        // 调用 SAT 求解器进行综合
        std::cout << "Running " << strOptionsValue["-solver"] << " for SSV synthesis..." << std::endl;
        auto [success, solution] = synthesis(&ssv, strOptionsValue["-solver"].c_str(), std::cout);
        if (!success) {
            std::cerr << "SSV synthesis failed: no solution found" << std::endl;
            return 0;
        }

        // 解码 SAT 解为逻辑电路（.blif）
        if (!strOptionsValue["-circuit_output"].empty()) {
            ssv.decode(solution, strOptionsValue["-circuit_output"]);
            std::cout << "Decoded circuit saved to: " << strOptionsValue["-circuit_output"] << std::endl;
        }

        return 1;  // 成功执行
    } catch (const std::exception& e) {
        std::cerr << "SSV synthesis error: " << e.what() << std::endl;
        return 0;
    }
  }

private:
    // 辅助函数：将逗号分隔的字符串分割为向量
    std::vector<std::string> splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            if (!token.empty())  // 忽略空字符串（处理连续逗号的情况）
                tokens.push_back(token);
        }
        return tokens;
    }
};


class CmdLfLogicSSVIncremental : public TclCmd
{
public:
  explicit CmdLfLogicSSVIncremental(const char* cmd_name)
      : TclCmd(cmd_name)
  {
    // 设置命令描述和域
    std::string description = "Perform incremental exact logic synthesis using SSV_Incremental method";
    this->set_description(description);
    std::string domain = "logic";
    this->set_domain(domain);

    // 命令选项（与 SSV_Incremental 类参数对应）
    std::vector<lfCmdOption> options = {
        { "-functions", "List of boolean functions (hex strings, comma-separated)", "string", "" },
        { "-r", "Number of synthesis steps (r value)", "int", "1" },
        { "-sub_r", "Number of sub-synthesis steps", "int", "1" },
        { "-sub_n", "Number of inputs for sub-function", "int", "-1" },  // 默认自动计算
        { "-similar_method", "Method to generate similar function (trunc/mute/mute_last/manual/random)", "string", "mute_last" },
        { "-similar_option", "Option string for similar function generation", "string", "" },
        { "-sat_output", "Path to save incremental SAT CNF encoding (.cnf)", "string", "ssv_incr_output.cnf" },
        { "-circuit_output", "Path to save decoded circuit (.blif)", "string", "ssv_incr_circuit.blif" },
        { "-solver", "SAT solver to use (kissat/cadical)", "string", "kissat" },
        { "-num_decomposable", "Number of decomposable variables", "int", "0" },
        { "-random_tt", "Random truth table for synthesis", "string", "" }
    };
    setOptions(this, options);
  }

  ~CmdLfLogicSSVIncremental() override = default;

  unsigned check() override
  {
    // 检查必填选项
    std::vector<std::string> essential = { "-functions", "-similar_method" };
    return checkEssentialOptions(this, essential);
  }

  unsigned exec() override
  {
    if (!check())
      return 0;

    // 提取选项值到对应映射表
    std::map<std::string, std::string> strOptionsValue;
    std::map<std::string, bool> boolOptionsValue;
    std::map<std::string, int> intOptionsValue;
    std::map<std::string, double> doubleOptionsValue;
    std::map<std::string, std::vector<std::string>> strvecOptionsValue;
    std::map<std::string, std::vector<int>> intvecOptionsValue;
    std::map<std::string, std::vector<double>> doublevecOptionsValue;

    // 定义选项类型分类
    std::vector<std::string> strOptions = { "-functions", "-similar_method", "-similar_option", 
                                           "-sat_output", "-circuit_output", "-solver", "-random_tt" };
    std::vector<std::string> boolOptions = {};
    std::vector<std::string> intOptions = { "-r", "-sub_r", "-sub_n", "-num_decomposable" };
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    // 提取选项值
    extractOptions(this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue);

    // 分割函数列表（逗号分隔的字符串→向量）
    std::vector<std::string> func_strs = splitString(strOptionsValue["-functions"], ',');
    std::vector<Boolean> funcs;
    for (const auto& s : func_strs) {
        funcs.emplace_back(Boolean(s));
    }

    // 执行 SSV 增量式逻辑综合流程
    try {
        // 创建 SSV_Incremental 对象
        SSV_Incremental ssv_incr(funcs, intOptionsValue["-sub_r"], intOptionsValue["-sub_n"]);
        ssv_incr.r = intOptionsValue["-r"];  // 设置步骤数

        // 设置相似函数（通过指定方法和选项）
        char* similar_option = const_cast<char*>(strOptionsValue["-similar_option"].c_str());
        ssv_incr.set_similar_function(
            strOptionsValue["-similar_method"],
            similar_option,
            intOptionsValue["-num_decomposable"],
            strOptionsValue["-random_tt"],
            intOptionsValue["-sub_n"]
        );

        // 生成增量式 SAT 编码
        auto [encoding, sub_vars] = ssv_incr.incremental_encode(true);  // 带变量标记

        // 保存 SAT 编码文件（.cnf）
        if (!strOptionsValue["-sat_output"].empty()) {
            std::ofstream sat_file(strOptionsValue["-sat_output"]);
            if (sat_file.is_open()) {
                encoding.write_dimacs(sat_file);
                sat_file.close();
                std::cout << "Incremental SAT encoding saved to: " << strOptionsValue["-sat_output"] << std::endl;
            } else {
                std::cerr << "Failed to open SAT output file: " << strOptionsValue["-sat_output"] << std::endl;
                return 0;
            }
        }

        // 调用 SAT 求解器进行增量式综合
        std::cout << "Running " << strOptionsValue["-solver"] << " for incremental SSV synthesis..." << std::endl;
        auto [success, solution] = incremental_synthesis(&ssv_incr, strOptionsValue["-solver"].c_str(), std::cout);
        if (!success) {
            std::cerr << "Incremental SSV synthesis failed: no solution found" << std::endl;
            return 0;
        }

        // 解码 SAT 解为逻辑电路（.blif）
        if (!strOptionsValue["-circuit_output"].empty()) {
            ssv_incr.decode(solution, strOptionsValue["-circuit_output"]);
            std::cout << "Decoded incremental circuit saved to: " << strOptionsValue["-circuit_output"] << std::endl;
        }

        return 1;  // 成功执行
    } catch (const std::exception& e) {
        std::cerr << "Incremental SSV synthesis error: " << e.what() << std::endl;
        return 0;
    }
  }

private:
    // 辅助函数：将逗号分隔的字符串分割为向量
    std::vector<std::string> splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            if (!token.empty())  // 忽略空字符串（处理连续逗号的情况）
                tokens.push_back(token);
        }
        return tokens;
    }
};


class CmdLfLogicSSVPower : public TclCmd
{
public:
  explicit CmdLfLogicSSVPower(const char* cmd_name)
      : TclCmd(cmd_name)
  {
    // 设置命令描述和域
    std::string description = "Perform power-driven exact logic synthesis using SSV_Power method";
    this->set_description(description);
    std::string domain = "logic";
    this->set_domain(domain);

    // 命令选项（与 SSV_Power 类参数对应）
    std::vector<lfCmdOption> options = {
        { "-functions", "List of boolean functions (hex strings, comma-separated)", "string", "" },
        { "-r", "Number of synthesis steps (r value)", "int", "1" },
        { "-num_classes", "Number of input probability classes", "int", "2" },
        { "-input_probability", "Input probabilities (space-separated list, e.g., \"0.5 0.5 0.5\")", "string", "" },
        { "-average", "Calculate average switching probability", "bool", "true" },
        { "-target_probability", "Target switching probability", "double", "1.0" },
        { "-symmetry", "Symmetry breaking options (N/A/R/C/O/S)", "string", "" },
        { "-solver", "SAT solver to use (z3/kissat/cadical)", "string", "z3" },
        { "-sat_output", "Path to save SAT encoding (.smt2)", "string", "ssv_power_output.smt2" },
        { "-netlist_output", "Path to save power-optimized netlist (.blif)", "string", "ssv_power_netlist.blif" }
    };
    setOptions(this, options);
  }

  ~CmdLfLogicSSVPower() override = default;

  unsigned check() override
  {
    // 检查必填选项
    std::vector<std::string> essential = { "-functions" };
    return checkEssentialOptions(this, essential);
  }

  unsigned exec() override
  {
    if (!check())
      return 0;

    // 提取选项值到对应映射表
    std::map<std::string, std::string> strOptionsValue;
    std::map<std::string, bool> boolOptionsValue;
    std::map<std::string, int> intOptionsValue;
    std::map<std::string, double> doubleOptionsValue;
    std::map<std::string, std::vector<std::string>> strvecOptionsValue;
    std::map<std::string, std::vector<int>> intvecOptionsValue;
    std::map<std::string, std::vector<double>> doublevecOptionsValue;

    // 定义选项类型分类
    std::vector<std::string> strOptions = { "-functions", "-symmetry", "-solver", "-sat_output", "-netlist_output", "-input_probability" };
    std::vector<std::string> boolOptions = { "-average" };
    std::vector<std::string> intOptions = { "-r", "-num_classes" };
    std::vector<std::string> doubleOptions = { "-target_probability" };
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    // 提取选项值
    extractOptions(this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue);

    // 分割函数列表（逗号分隔的字符串→向量）
    std::vector<std::string> func_strs = splitString(strOptionsValue["-functions"], ',');
    std::vector<Boolean> funcs;
    for (const auto& s : func_strs) {
        funcs.emplace_back(Boolean(s));
    }

    // 解析输入概率
    std::vector<double> input_probs;
    if (!strOptionsValue["-input_probability"].empty()) {
        std::vector<std::string> prob_strs = splitString(strOptionsValue["-input_probability"], ' ');
        for (const auto& s : prob_strs) {
            input_probs.push_back(std::stod(s));
        }
    }

    // 执行功耗驱动的 SSV 逻辑综合流程
    try {
        // 创建 SSV_Power 对象
        SSV_Power ssv_power(funcs);
        ssv_power.r = intOptionsValue["-r"];
        ssv_power.num_classes = intOptionsValue["-num_classes"];
        ssv_power.target_switching_probability = doubleOptionsValue["-target_probability"];

        // 设置对称性选项
        if (strOptionsValue["-symmetry"].find('N') != std::string::npos) ssv_power.non_trivial = true;
        if (strOptionsValue["-symmetry"].find('A') != std::string::npos) ssv_power.all_steps = true;
        if (strOptionsValue["-symmetry"].find('R') != std::string::npos) ssv_power.no_replication = true;
        if (strOptionsValue["-symmetry"].find('C') != std::string::npos) ssv_power.lexicographical_step = true;
        if (strOptionsValue["-symmetry"].find('O') != std::string::npos) ssv_power.lexicographical_op = true;
        if (strOptionsValue["-symmetry"].find('S') != std::string::npos) ssv_power.ordered_symmetric = true;

        // 生成功耗优化的 SAT 编码
        auto encoding = ssv_power.encode(true, input_probs, boolOptionsValue["-average"]);

        // 保存 SAT 编码文件（.smt2 格式）
        if (!strOptionsValue["-sat_output"].empty()) {
            std::ofstream sat_file(strOptionsValue["-sat_output"]);
            if (sat_file.is_open()) {
                sat_file << "(set-logic QF_BV)\n";
                sat_file << "(set-option :produce-models true)\n";
                
                // 写入变量声明
                for (const auto& comment : encoding.comments) {
                    sat_file << comment;
                }
                
                // 写入功耗约束
                for (const auto& clause : encoding.clauses_in_real) {
                    sat_file << clause << "\n";
                }
                
                sat_file << "(check-sat)\n";
                sat_file << "(get-model)\n";
                sat_file.close();
                std::cout << "Power-optimized SAT encoding saved to: " << strOptionsValue["-sat_output"] << std::endl;
            } else {
                std::cerr << "Failed to open SAT output file: " << strOptionsValue["-sat_output"] << std::endl;
                return 0;
            }
        }

        // 调用 SAT 求解器进行功耗优化综合
        std::cout << "Running " << strOptionsValue["-solver"] << " for power-driven SSV synthesis..." << std::endl;
        auto [success, solution] = power_synthesis(&ssv_power, strOptionsValue["-solver"].c_str(), std::cout, input_probs);
        if (!success) {
            std::cerr << "Power-driven SSV synthesis failed: no solution found" << std::endl;
            return 0;
        }

        // 计算最终的功耗
        double switching_probability = 0.0;
        for (const auto& entry : solution.first) {
            if (entry.first == "r") {
                switching_probability = entry.second;
                break;
            }
        }
        std::cout << "Final switching probability: " << switching_probability << std::endl;

        // 保存功耗优化的网表
        if (!strOptionsValue["-netlist_output"].empty()) {
            ssv_power.decode(solution.second, strOptionsValue["-netlist_output"]);
            std::cout << "Power-optimized netlist saved to: " << strOptionsValue["-netlist_output"] << std::endl;
        }

        return 1;  // 成功执行
    } catch (const std::exception& e) {
        std::cerr << "Power-driven SSV synthesis error: " << e.what() << std::endl;
        return 0;
    }
  }

private:
    // 辅助函数：将逗号分隔的字符串分割为向量
    std::vector<std::string> splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            if (!token.empty())  // 忽略空字符串（处理连续逗号的情况）
                tokens.push_back(token);
        }
        return tokens;
    }
};


class CmdLfLogicLutRewrite : public TclCmd
{
public:
  explicit CmdLfLogicLutRewrite(const char* cmd_name)
      : TclCmd(cmd_name)
  {
    // 设置命令描述和域
    std::string description = "Perform LUT rewriting on netlist using optimal library";
    this->set_description(description);
    std::string domain = "logic";
    this->set_domain(domain);

    // 命令选项（与LUT重写功能对应）
    std::vector<lfCmdOption> options = {
        { "-input", "Input netlist file (.blif)", "string", "" },
        { "-output", "Output optimized netlist file (.blif)", "string", "" },
        { "-library", "Optimal LUT library file path", "string", "" },
        { "-power", "Enable power-optimized rewriting", "bool", "false" },
        { "-input_prob", "Input signal probabilities (space-separated, e.g., \"0.5 0.5\")", "string", "" }
    };
    setOptions(this, options);
  }

  ~CmdLfLogicLutRewrite() override = default;

  unsigned check() override
  {
    // 检查必填选项
    std::vector<std::string> essential = { "-input", "-output", "-library" };
    return checkEssentialOptions(this, essential);
  }

  unsigned exec() override
  {
    if (!check())
      return 0;

    // 提取选项值到对应映射表
    std::map<std::string, std::string> strOptionsValue;
    std::map<std::string, bool> boolOptionsValue;
    std::map<std::string, int> intOptionsValue;
    std::map<std::string, double> doubleOptionsValue;
    std::map<std::string, std::vector<std::string>> strvecOptionsValue;
    std::map<std::string, std::vector<int>> intvecOptionsValue;
    std::map<std::string, std::vector<double>> doublevecOptionsValue;

    // 定义选项类型分类
    std::vector<std::string> strOptions = { "-input", "-output", "-library", "-input_prob" };
    std::vector<std::string> boolOptions = { "-power" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    // 提取选项值
    extractOptions(this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue);

    // 执行LUT重写流程
    try {
        // 读取输入网表
        NET::Netlist netlist;
        std::cout << "Loading netlist from: " << strOptionsValue["-input"] << std::endl;
        if (!NET::read_blif(strOptionsValue["-input"], netlist)) {
            std::cerr << "Failed to read input netlist: " << strOptionsValue["-input"] << std::endl;
            return 0;
        }

        // 如果启用功耗优化，初始化信号概率
        if (boolOptionsValue["-power"]) {
            std::vector<double> input_probs;
            if (!strOptionsValue["-input_prob"].empty()) {
                // 解析用户提供的输入概率
                std::vector<std::string> prob_strs = splitString(strOptionsValue["-input_prob"], ' ');
                for (const auto& s : prob_strs) {
                    input_probs.push_back(std::stod(s));
                }
            }
            // 初始化信号概率（拓扑排序并计算）
            std::cout << "Initializing signal probabilities for power optimization..." << std::endl;
            initialize_signal_probability(netlist, input_probs);
        }

        // 执行LUT重写（普通版或功耗优化版）
        std::cout << "Performing LUT rewriting using library: " << strOptionsValue["-library"] << std::endl;
        if (boolOptionsValue["-power"]) {
            NET::lut_rewrite_power(netlist, strOptionsValue["-library"]);
        } else {
            NET::lut_rewrite(netlist, strOptionsValue["-library"]);
        }

        // 写入优化后的网表
        std::cout << "Writing optimized netlist to: " << strOptionsValue["-output"] << std::endl;
        if (!NET::write_blif(strOptionsValue["-output"], netlist)) {
            std::cerr << "Failed to write output netlist: " << strOptionsValue["-output"] << std::endl;
            return 0;
        }

        std::cout << "LUT rewriting completed successfully." << std::endl;
        return 1;  // 成功执行
    } catch (const std::exception& e) {
        std::cerr << "LUT rewriting error: " << e.what() << std::endl;
        return 0;
    }
  }

private:
    // 辅助函数：分割字符串
    std::vector<std::string> splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            if (!token.empty())
                tokens.push_back(token);
        }
        return tokens;
    }
};



class CmdLfLogicTechMapping : public TclCmd
{
public:
  explicit CmdLfLogicTechMapping(const char* cmd_name)
      : TclCmd(cmd_name)
  {
    // 设置命令描述和域
    std::string description = "Perform technology mapping using cut enumeration and standard cell library";
    this->set_description(description);
    std::string domain = "logic";
    this->set_domain(domain);

    // 命令选项（与技术映射功能对应）
    std::vector<lfCmdOption> options = {
        { "-input", "Input netlist file (.blif)", "string", "" },
        { "-output", "Output mapped netlist file (.v for Verilog)", "string", "" },
        { "-tech_lib", "Technology library file (.lib in Liberty format)", "string", "" },
        { "-max_cut_size", "Maximum cut size for enumeration (default: 4)", "int", "4" },
        { "-max_stored_cuts", "Maximum stored cuts per node (default: 20)", "int", "20" },
        { "-optimization_target", "Primary optimization target (area/delay/power/glitch, default: area)", "string", "area" },
        { "-enable_iterative", "Enable iterative optimization until convergence (true/false, default: true)", "bool", "true" }
    };
    setOptions(this, options);
  }

  ~CmdLfLogicTechMapping() override = default;

  unsigned check() override
  {
    // 检查必填选项
    std::vector<std::string> essential = { "-input", "-output", "-tech_lib" };
    return checkEssentialOptions(this, essential);
  }

  unsigned exec() override
  {
    if (!check())
      return 0;

    // 提取选项值到对应映射表
    std::map<std::string, std::string> strOptionsValue;
    std::map<std::string, bool> boolOptionsValue;
    std::map<std::string, int> intOptionsValue;
    std::map<std::string, double> doubleOptionsValue;
    std::map<std::string, std::vector<std::string>> strvecOptionsValue;
    std::map<std::string, std::vector<int>> intvecOptionsValue;
    std::map<std::string, std::vector<double>> doublevecOptionsValue;

    // 定义选项类型分类
    std::vector<std::string> strOptions = { "-input", "-output", "-tech_lib", "-optimization_target" };
    std::vector<std::string> boolOptions = { "-enable_iterative" };
    std::vector<std::string> intOptions = { "-max_cut_size", "-max_stored_cuts" };
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    // 提取选项值
    extractOptions(this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue);

    // 执行技术映射流程
    try {
        // 验证优化目标的有效性
        std::vector<std::string> valid_targets = {"area", "delay", "power", "glitch"};
        if (std::find(valid_targets.begin(), valid_targets.end(), strOptionsValue["-optimization_target"]) == valid_targets.end()) {
            std::cerr << "Invalid optimization target: " << strOptionsValue["-optimization_target"] << std::endl;
            std::cerr << "Valid targets: area, delay, power, glitch" << std::endl;
            return 0;
        }

        // 读取技术库（Liberty格式）
        PASyn::Technology technology;
        std::cout << "Loading technology library from: " << strOptionsValue["-tech_lib"] << std::endl;
        if (!PASyn::read_liberty(strOptionsValue["-tech_lib"], technology)) {
            std::cerr << "Failed to read technology library: " << strOptionsValue["-tech_lib"] << std::endl;
            return 0;
        }

        // 读取输入网表（BLIF格式）
        PASyn::Netlist netlist;
        std::cout << "Loading input netlist from: " << strOptionsValue["-input"] << std::endl;
        if (!PASyn::read_blif(strOptionsValue["-input"], netlist)) {
            std::cerr << "Failed to read input netlist: " << strOptionsValue["-input"] << std::endl;
            return 0;
        }

        // 配置技术映射参数（通过修改全局变量或设置器，假设代码支持参数配置）
        std::cout << "Configuring technology mapping parameters..." << std::endl;
        PASyn::set_max_cut_size(intOptionsValue["-max_cut_size"]);                // 设置最大割集大小
        PASyn::set_max_stored_cuts(intOptionsValue["-max_stored_cuts"]);          // 设置最大存储割集数
        PASyn::set_optimization_target(strOptionsValue["-optimization_target"]);  // 设置优化目标
        PASyn::set_iterative_optimization(boolOptionsValue["-enable_iterative"]); // 设置是否迭代优化

        // 执行技术映射核心逻辑
        std::cout << "Performing technology mapping with target: " << strOptionsValue["-optimization_target"] << std::endl;
        PASyn::technology_mapping(netlist, technology);

        // 写入映射后的网表（Verilog格式）
        std::cout << "Writing mapped netlist to: " << strOptionsValue["-output"] << std::endl;
        if (!PASyn::write_verilog(strOptionsValue["-output"], netlist, technology, true)) {
            std::cerr << "Failed to write output netlist: " << strOptionsValue["-output"] << std::endl;
            return 0;
        }

        std::cout << "Technology mapping completed successfully." << std::endl;
        return 1;  // 成功执行
    } catch (const std::exception& e) {
        std::cerr << "Technology mapping error: " << e.what() << std::endl;
        return 0;
    }
}

private:
    // 辅助函数：分割字符串（复用之前的实现）
    std::vector<std::string> splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            if (!token.empty())
                tokens.push_back(token);
        }
        return tokens;
    }
};


class CmdLfLogicCalculatePower : public TclCmd
{
public:
  explicit CmdLfLogicCalculatePower(const char* cmd_name)
      : TclCmd(cmd_name)
  {
    // 设置命令描述和域
    std::string description = "Calculate power consumption (static/dynamic/internal/wire) of a netlist";
    this->set_description(description);
    std::string domain = "logic";
    this->set_domain(domain);

    // 命令选项（与功耗计算功能对应）
    std::vector<lfCmdOption> options = {
        { "-input", "Input netlist file (.blif)", "string", "" },
        { "-tech_lib", "Technology library file (.lib in Liberty format)", "string", "" },
        { "-output", "Output file to save power results (optional, if not set print to console)", "string", "" },
        { "-gym_mode", "Enable gym mode for integration with reinforcement learning (default: false)", "bool", "false" },
        { "-verbose", "Enable verbose output (print detailed power breakdown, default: true)", "bool", "true" }
    };
    setOptions(this, options);
  }

  ~CmdLfLogicCalculatePower() override = default;

  unsigned check() override
  {
    // 检查必填选项
    std::vector<std::string> essential = { "-input", "-tech_lib" };
    return checkEssentialOptions(this, essential);
  }

  unsigned exec() override
  {
    if (!check())
      return 0;

    // 提取选项值到对应映射表
    std::map<std::string, std::string> strOptionsValue;
    std::map<std::string, bool> boolOptionsValue;
    std::map<std::string, int> intOptionsValue;
    std::map<std::string, double> doubleOptionsValue;
    std::map<std::string, std::vector<std::string>> strvecOptionsValue;
    std::map<std::string, std::vector<int>> intvecOptionsValue;
    std::map<std::string, std::vector<double>> doublevecOptionsValue;

    // 定义选项类型分类
    std::vector<std::string> strOptions = { "-input", "-tech_lib", "-output" };
    std::vector<std::string> boolOptions = { "-gym_mode", "-verbose" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    // 提取选项值
    extractOptions(this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue);

    // 执行功耗计算流程
    try {
        // 读取技术库（Liberty格式）并预处理
        PASyn::Technology technology;
        std::cout << "Loading technology library from: " << strOptionsValue["-tech_lib"] << std::endl;
        if (!PASyn::read_liberty(strOptionsValue["-tech_lib"], technology)) {
            std::cerr << "Failed to read technology library: " << strOptionsValue["-tech_lib"] << std::endl;
            return 0;
        }
        // 预处理开关特性（用于快速传播计算）
        PASyn::switch_pre_process(technology);

        // 读取输入网表（BLIF格式）
        PASyn::Netlist netlist;
        std::cout << "Loading input netlist from: " << strOptionsValue["-input"] << std::endl;
        if (!PASyn::read_blif(strOptionsValue["-input"], netlist, &technology)) {
            std::cerr << "Failed to read input netlist: " << strOptionsValue["-input"] << std::endl;
            return 0;
        }

        // 执行功耗计算核心逻辑
        std::cout << "Calculating power consumption..." << std::endl;
        std::vector<double> power_results = PASyn::calculate_power(netlist, technology);

        // 验证结果完整性（预期包含5个值：静态/动态/内部/连线/总功耗）
        if (power_results.size() != 5) {
            std::cerr << "Invalid power calculation results (expected 5 values, got " << power_results.size() << ")" << std::endl;
            return 0;
        }

        // 格式化输出内容
        std::stringstream output_ss;
        if (boolOptionsValue["-verbose"]) {
            output_ss << "Power Consumption Breakdown:" << std::endl;
            output_ss << "  Static Power:    " << power_results[0] << " W" << std::endl;
            output_ss << "  Dynamic Power:   " << power_results[1] << " W" << std::endl;
            output_ss << "  Internal Power:  " << power_results[2] << " W" << std::endl;
            output_ss << "  Wire Power:      " << power_results[3] << " W" << std::endl;
            output_ss << "  Total Power:     " << power_results[4] << " W" << std::endl;
        } else {
            // 简洁模式：仅输出数值（便于脚本解析）
            output_ss << power_results[0] << " " 
                      << power_results[1] << " " 
                      << power_results[2] << " " 
                      << power_results[3] << " " 
                      << power_results[4] << std::endl;
        }

        // 输出到文件或控制台
        if (!strOptionsValue["-output"].empty()) {
            // 保存到文件
            std::ofstream output_file(strOptionsValue["-output"]);
            if (!output_file.is_open()) {
                std::cerr << "Failed to open output file: " << strOptionsValue["-output"] << std::endl;
                return 0;
            }
            output_file << output_ss.str();
            output_file.close();
            std::cout << "Power results saved to: " << strOptionsValue["-output"] << std::endl;
        } else {
            // 打印到控制台
            std::cout << output_ss.str() << std::endl;
        }

        std::cout << "Power calculation completed successfully." << std::endl;
        return 1;  // 成功执行
    } catch (const std::exception& e) {
        std::cerr << "Power calculation error: " << e.what() << std::endl;
        return 0;
    }
}

private:
    // 辅助函数：分割字符串（复用之前的实现）
    std::vector<std::string> splitString(const std::string& str, char delimiter) {
        std::vector<std::string> tokens;
        std::string token;
        std::istringstream tokenStream(str);
        while (std::getline(tokenStream, token, delimiter)) {
            if (!token.empty())
                tokens.push_back(token);
        }
        return tokens;
    }
};



} // namespace tcl
} // namespace lf




