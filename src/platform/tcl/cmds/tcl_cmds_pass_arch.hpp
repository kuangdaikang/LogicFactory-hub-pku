#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"
#include "tcl/cmds/utils.hpp"

#include "misc/anchor.hpp"

#include "layer_arch/arch_manager.hpp"
#include "layer_arch/api/yosys/pass/hierarchy.hpp"
#include "layer_arch/api/yosys/pass/flatten.hpp"
#include "layer_arch/api/yosys/pass/fsm.hpp"
#include "layer_arch/api/yosys/pass/opt.hpp"
#include "layer_arch/api/yosys/pass/aigmap.hpp"
#include "layer_arch/api/yosys/pass/techmap.hpp"
#include "layer_arch/api/yosys/pass/abc.hpp"

namespace lf
{

namespace tcl
{
class CmdLfArchHierarchy : public TclCmd
{
public:
  explicit CmdLfArchHierarchy( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    std::string domain = "arch";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-check", "yosys", "bool", "" },
        { "-simcheck", "yosys", "bool", "" },
        { "-smtcheck", "yosys", "bool", "" },
        { "-purge_lib", "yosys", "bool", "" },
        { "-libdir", "yosys", "strvec", "" },
        { "-keep_positionals", "yosys", "bool", "" },
        { "-keep_portwidths", "yosys", "bool", "" },
        { "-nodefaults", "yosys", "bool", "" },
        { "-nokeep_prints", "yosys", "bool", "" },
        { "-nokeep_asserts", "yosys", "bool", "" },
        { "-top", "yosys", "string", "" },
        { "-auto-top", "yosys", "bool", "" },
        { "-chparam", "yosys", "strvec", "" } };

    setOptions( this, options );
  }

  ~CmdLfArchHierarchy() override = default;

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

    std::vector<std::string> strOptions = { "-top" };
    std::vector<std::string> boolOptions = { "-check", "-simcheck", "-smtcheck", "-purge_lib", "-keep_positionals", "-keep_portwidths",
                                             "-nodefaults", "-nokeep_prints", "-nokeep_asserts", "-auto-top" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = { "-libdir", "-chparam" };
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_domain = lfAnchorINST->get_anchor_domain();

    std::map<std::string, std::string> chparam;
    for ( size_t i = 0u; i < strvecOptionsValue["-chparam"].size(); i += 2 )
    {
      chparam[strvecOptionsValue["-chparam"][i]] = strvecOptionsValue["-chparam"][i + 1];
    }
    switch ( anchor_domain )
    {
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_ARCH_YOSYS:
      lf::arch::yosys::hierarchy( boolOptionsValue["-check"], boolOptionsValue["-simcheck"], boolOptionsValue["-smtcheck"], boolOptionsValue["-purge_lib"], strvecOptionsValue["-libdir"],
                                  boolOptionsValue["-keep_positionals"], boolOptionsValue["-keep_portwidths"], boolOptionsValue["-nodefaults"], boolOptionsValue["-nokeep_prints"],
                                  boolOptionsValue["-nokeep_asserts"], strOptionsValue["-top"], boolOptionsValue["-auto-top"], chparam );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfArchHierarchy

class CmdLfArchFlatten : public TclCmd
{
public:
  explicit CmdLfArchFlatten( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "arch";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-wb", "yosys", "bool", "" },
        { "-noscopeinfo", "yosys", "bool", "" },
        { "-scopename", "yosys", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfArchFlatten() override = default;

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
    std::vector<std::string> boolOptions = { "-wb", "-noscopeinfo", "-scopename" };
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
      lf::arch::yosys::flatten( boolOptionsValue["-wb"], boolOptionsValue["-noscopeinfo"], boolOptionsValue["-scopename"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfArchFlatten

class CmdLfArchFsm : public TclCmd
{
public:
  explicit CmdLfArchFsm( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "arch";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-expand", "yosys", "bool", "" },
        { "-norecode", "yosys", "bool", "" },
        { "-export", "yosys", "bool", "" },
        { "-nomap", "yosys", "bool", "" },
        { "-fullexpand", "yosys", "bool", "" },
        { "-fm_set_fsm_file", "yosys", "string", "" },
        { "-encfile", "yosys", "string", "" },
        { "-encoding", "yosys", "string", "" } };

    setOptions( this, options );
  }

  ~CmdLfArchFsm() override = default;

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

    std::vector<std::string> strOptions = { "-fm_set_fsm_file", "-encfile", "-encoding" };
    std::vector<std::string> boolOptions = { "-expand", "-norecode", "-export", "-nomap", "-fullexpand" };
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
      lf::arch::yosys::fsm( boolOptionsValue["-expand"], boolOptionsValue["-norecode"], boolOptionsValue["-export"], boolOptionsValue["-nomap"], boolOptionsValue["-fullexpand"],
                            strOptionsValue["-fm_set_fsm_file"], strOptionsValue["-encfile"], strOptionsValue["-encoding"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfArchFsm

class CmdLfArchOpt : public TclCmd
{
public:
  explicit CmdLfArchOpt( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "arch";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-purge", "yosys", "bool", "" },
        { "-mux_undef", "yosys", "bool", "" },
        { "-mux_bool", "yosys", "bool", "" },
        { "-undriven", "yosys", "bool", "" },
        { "-noclkinv", "yosys", "bool", "" },
        { "-fine", "yosys", "bool", "" },
        { "-full", "yosys", "bool", "" },
        { "-keepdc", "yosys", "bool", "" },
        { "-nodffe", "yosys", "bool", "" },
        { "-nosdff", "yosys", "bool", "" },
        { "-sat", "yosys", "bool", "" },
        { "-share_all", "yosys", "bool", "" },
        { "-fast", "yosys", "bool", "" },
        { "-noff", "yosys", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfArchOpt() override = default;

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
    std::vector<std::string> boolOptions = { "-purge", "-mux_undef", "-mux_bool", "-undriven", "-noclkinv",
                                             "-fine", "-full", "-keepdc", "-nodffe", "-nosdff", "-sat",
                                             "-share_all", "-fast", "-noff" };
    std::vector<std::string>
        intOptions = {};
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
      lf::arch::yosys::opt( boolOptionsValue["-purge"], boolOptionsValue["-mux_undef"], boolOptionsValue["-mux_bool"], boolOptionsValue["-undriven"], boolOptionsValue["-noclkinv"],
                            boolOptionsValue["-fine"], boolOptionsValue["-full"], boolOptionsValue["-keepdc"], boolOptionsValue["-nodffe"], boolOptionsValue["-nosdff"], boolOptionsValue["-sat"],
                            boolOptionsValue["-share_all"], boolOptionsValue["-fast"], boolOptionsValue["-noff"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfArchOpt

class CmdLfArchTechmap : public TclCmd
{
public:
  explicit CmdLfArchTechmap( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "arch";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-map", "yosys", "string", "" },
        { "-extern", "yosys", "bool", "" },
        { "-max_iter", "yosys", "bool", "" },
        { "-recursive", "yosys", "bool", "" },
        { "-extern", "yosys", "bool", "" },
        { "-wb", "yosys", "bool", "" },
        { "-assert", "yosys", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfArchTechmap() override = default;

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

    std::vector<std::string> strOptions = { "-map" };
    std::vector<std::string> boolOptions = { "-extern", "-recursive", "-extern", "-wb", "-assert" };
    std::vector<std::string> intOptions = { "-max_iter" };
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
      lf::arch::yosys::techmap( strOptionsValue["-map"],
                                boolOptionsValue["-extern"], intOptionsValue["-max_iter"], boolOptionsValue["-recursive"], boolOptionsValue["-wb"], boolOptionsValue["-assert"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfArchTechmap

class CmdLfArchAigmap : public TclCmd
{
public:
  explicit CmdLfArchAigmap( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "arch";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-nand", "yosys", "bool", "" },
        { "-select", "yosys", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfArchAigmap() override = default;

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
    std::vector<std::string> boolOptions = { "-nand", "-select" };
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
      lf::arch::yosys::aigmap( boolOptionsValue["-nand"], boolOptionsValue["-select"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfArchAigmap

class CmdLfArchAbc : public TclCmd
{
public:
  explicit CmdLfArchAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "arch";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-exe", "yosys", "string", "" },
        { "-script", "yosys", "string", "" },
        { "-liberty", "yosys", "strvec", "" },
        { "-genlib", "yosys", "strvec", "" },
        { "-constr", "yosys", "string", "" },
        { "-dont_use", "yosys", "strvec", "" },
        { "-fast", "yosys", "bool", "" },
        { "-D", "yosys", "double", "" },
        { "-I", "yosys", "int", "" },
        { "-P", "yosys", "int", "" },
        { "-S", "yosys", "int", "" },
        { "-lut", "yosys", "int", "" },
        { "-luts", "yosys", "strvec", "" },
        { "-sop", "yosys", "bool", "" },
        { "-g", "yosys", "strvec", "" },
        { "-dff", "yosys", "bool", "" },
        { "-clk", "yosys", "bool", "" },
        { "-keepff", "yosys", "bool", "" },
        { "-nocleanup", "yosys", "bool", "" },
        { "-showtmp", "yosys", "bool", "" },
        { "-markgroups", "yosys", "bool", "" },
        { "-dress", "yosys", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfArchAbc() override = default;

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

    std::vector<std::string> strOptions = { "-exe", "-script", "-constr" };
    std::vector<std::string> boolOptions = { "-fast", "-sop", "-dff", "-clk", "-keepff", "-nocleanup", "-showtmp", "-markgroups", "-dress" };
    std::vector<std::string> intOptions = { "-I", "-P", "-S", "-lut" };
    std::vector<std::string> doubleOptions = { "-D" };
    std::vector<std::string> strvecOptions = { "-liberty", "-genlib", "-dont_use", "-luts", "-g" };
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_domain = lfAnchorINST->get_anchor_domain();

    switch ( anchor_domain )
    {
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_ARCH_YOSYS:
      lf::arch::yosys::abc( strOptionsValue["-exe"], strOptionsValue["-script"],
                            strvecOptionsValue["-liberty"], strvecOptionsValue["-genlib"], strOptionsValue["-constr"], strvecOptionsValue["-dont_use"],
                            boolOptionsValue["-fast"],
                            doubleOptionsValue["-D"], intOptionsValue["-I"], intOptionsValue["-P"], intOptionsValue["-S"], intOptionsValue["-lut"], strvecOptionsValue["-luts"],
                            boolOptionsValue["-sop"], strvecOptionsValue["-g"], boolOptionsValue["-dff"], boolOptionsValue["-clk"], boolOptionsValue["-keepff"],
                            boolOptionsValue["-nocleanup"], boolOptionsValue["-showtmp"], boolOptionsValue["-markgroups"], boolOptionsValue["-dress"] );
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfArchAbc

class CmdLfArchGtechmap : public TclCmd
{
public:
  explicit CmdLfArchGtechmap( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "";
    this->set_description( description );
    std::string domain = "arch";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {};

    setOptions( this, options );
  }

  ~CmdLfArchGtechmap() override = default;

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

    auto anchor_domain = lfAnchorINST->get_anchor_domain();

    // TODO: add the gtechmap
    std::cerr << "node support now!" << std::endl;
    assert( false );

    switch ( anchor_domain )
    {
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_ARCH_YOSYS:
      // lf::arch::yosys::gtechmap( );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfArchGtechmap
} // namespace tcl
} // namespace lf