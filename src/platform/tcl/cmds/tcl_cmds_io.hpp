#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"
#include "tcl/cmds/utils.hpp"

#include "misc/anchor.hpp"

#include "layer_arch/api/yosys/io/read_aiger.hpp"
#include "layer_arch/api/yosys/io/read_blif.hpp"
#include "layer_arch/api/yosys/io/read_json.hpp"
#include "layer_arch/api/yosys/io/read_rtlil.hpp"
#include "layer_arch/api/yosys/io/read_liberty.hpp"
#include "layer_arch/api/yosys/io/read_verilog.hpp"
#include "layer_arch/api/yosys/io/write_aiger.hpp"
#include "layer_arch/api/yosys/io/write_blif.hpp"
#include "layer_arch/api/yosys/io/write_btor.hpp"
#include "layer_arch/api/yosys/io/write_edif.hpp"
#include "layer_arch/api/yosys/io/write_firrtl.hpp"
#include "layer_arch/api/yosys/io/write_json.hpp"
#include "layer_arch/api/yosys/io/write_rtlil.hpp"
#include "layer_arch/api/yosys/io/write_spice.hpp"
#include "layer_arch/api/yosys/io/write_verilog.hpp"

#include "layer_logic/api/abc/io/read_aiger.hpp"
#include "layer_logic/api/abc/io/read_bench.hpp"
#include "layer_logic/api/abc/io/read_blif.hpp"
#include "layer_logic/api/abc/io/read_cnf.hpp"
#include "layer_logic/api/abc/io/read_formula.hpp"
#include "layer_logic/api/abc/io/read_genlib.hpp"
#include "layer_logic/api/abc/io/read_liberty.hpp"
#include "layer_logic/api/abc/io/read_pla.hpp"
#include "layer_logic/api/abc/io/read_truth.hpp"
#include "layer_logic/api/abc/io/read_verilog.hpp"

#include "layer_logic/api/abc/io/write_aiger.hpp"
#include "layer_logic/api/abc/io/write_bench.hpp"
#include "layer_logic/api/abc/io/write_blif.hpp"
#include "layer_logic/api/abc/io/write_cnf.hpp"
#include "layer_logic/api/abc/io/write_dot.hpp"
#include "layer_logic/api/abc/io/write_pla.hpp"
#include "layer_logic/api/abc/io/write_truth.hpp"
#include "layer_logic/api/abc/io/write_verilog.hpp"

#include "layer_logic/api/lsils/io/read_aiger.hpp"
#include "layer_logic/api/lsils/io/read_bench.hpp"
#include "layer_logic/api/lsils/io/read_blif.hpp"
#include "layer_logic/api/lsils/io/read_cnf.hpp"
#include "layer_logic/api/lsils/io/read_genlib.hpp"
#include "layer_logic/api/lsils/io/read_gtech.hpp"
#include "layer_logic/api/lsils/io/read_liberty.hpp"
#include "layer_logic/api/lsils/io/read_pla.hpp"

#include "layer_logic/api/lsils/io/write_aiger.hpp"
#include "layer_logic/api/lsils/io/write_bench.hpp"
#include "layer_logic/api/lsils/io/write_blif.hpp"
#include "layer_logic/api/lsils/io/write_cnf.hpp"
#include "layer_logic/api/lsils/io/write_dot.hpp"
#include "layer_logic/api/lsils/io/write_verilog.hpp"
#include "layer_logic/aux/write_graphml.hpp"

namespace lf
{

namespace tcl
{

#pragma region Reader
class CmdLfIoReadAiger : public TclCmd
{
public:
  explicit CmdLfIoReadAiger( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." },
        { "-module_name", "yosys", "string", "" },
        { "-clk_name", "yosys", "string", "" },
        { "-map", "yosys", "string", "" },
        { "-wideports", "yosys", "bool", "" },
        { "-xaiger", "yosys", "bool", "" },
        { "-c", "abc", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoReadAiger() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file", "-module_name", "-clk_name", "-map" };
    std::vector<std::string> boolOptions = { "-wideports", "-xaiger", "-c" };
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
      std::cout << "yosys" << std::endl;
      lf::arch::yosys::read_aiger( strOptionsValue["-file"],
                                   strOptionsValue["-module_name"],
                                   strOptionsValue["-clk_name"],
                                   strOptionsValue["-map"],
                                   boolOptionsValue["-wideports"],
                                   boolOptionsValue["-xaiger"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      std::cout << "abc" << std::endl;
      lf::logic::abc::read_aiger( strOptionsValue["-file"],
                                  boolOptionsValue["-c"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      std::cout << "lsils" << std::endl;
      lf::logic::lsils::read_aiger( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadAiger

class CmdLfIoReadBlif : public TclCmd
{
public:
  explicit CmdLfIoReadBlif( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." },
        { "-sop", "yosys", "bool", "cover with sop, rather than lut!" },
        { "-wideports", "yosys", "bool", "" },
        { "-n", "abc", "bool", "" },
        { "-m", "abc", "bool", "" },
        { "-a", "abc", "bool", "" },
        { "-c", "abc", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfIoReadBlif() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-sop", "-wideports", "-n", "-m", "-a", "-c" };
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
      lf::arch::yosys::read_blif( strOptionsValue["-file"],
                                  boolOptionsValue["-sop"],
                                  boolOptionsValue["-wideports"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::read_blif( strOptionsValue["-file"],
                                 boolOptionsValue["-n"],
                                 boolOptionsValue["-m"],
                                 boolOptionsValue["-a"],
                                 boolOptionsValue["-c"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::read_blif( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadBlif

class CmdLfIoReadVerilog : public TclCmd
{
public:
  explicit CmdLfIoReadVerilog( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." },
        { "-setattr", "yosys", "string", "Set attributes on the design." },
        { "-Dname", "yosys", "string", "Define a macro with an optional value." },
        { "-Idir", "yosys", "string", "Specify an include directory." },
        { "-sv", "yosys", "bool", "Enable SystemVerilog features." },
        { "-formal", "yosys", "bool", "Enable formal verification features." },
        { "-nosynthesis", "yosys", "bool", "Disable synthesis, for analysis tasks only." },
        { "-noassert", "yosys", "bool", "Disable assertions." },
        { "-noassume", "yosys", "bool", "Disable assumptions." },
        { "-norestrict", "yosys", "bool", "Disable restrictions." },
        { "-assume-asserts", "yosys", "bool", "Treat asserts as assumptions." },
        { "-assert-assumes", "yosys", "bool", "Treat assumptions as asserts." },
        { "-nodisplay", "yosys", "bool", "Disable display statements." },
        { "-debug", "yosys", "bool", "Enable debugging features." },
        { "-dump_ast1", "yosys", "bool", "Dump initial AST." },
        { "-dump_ast2", "yosys", "bool", "Dump final AST after elaboration." },
        { "-no_dump_ptr", "yosys", "bool", "Do not dump pointers in AST dump." },
        { "-dump_vlog1", "yosys", "bool", "Dump Verilog output after first stage." },
        { "-dump_vlog2", "yosys", "bool", "Dump Verilog output after final stage." },
        { "-dump_rtlil", "yosys", "bool", "Dump RTLIL output." },
        { "-yydebug", "yosys", "bool", "Enable parser debugging." },
        { "-nolatches", "yosys", "bool", "Prevent generation of latches." },
        { "-nomem2reg", "yosys", "bool", "Disable conversion of memories to registers." },
        { "-mem2reg", "yosys", "bool", "Force conversion of memories to registers." },
        { "-nomeminit", "yosys", "bool", "Disable memory initialization." },
        { "-ppdump", "yosys", "bool", "Dump preprocessed designs." },
        { "-nopp", "yosys", "bool", "Disable preprocessor." },
        { "-nodpi", "yosys", "bool", "Disable DPI feature." },
        { "-noblackbox", "yosys", "bool", "Treat blackbox modules as white boxes." },
        { "-lib", "yosys", "bool", "Enable library features." },
        { "-nowb", "yosys", "bool", "Disable whitebox." },
        { "-specify", "yosys", "bool", "Enable specify blocks." },
        { "-noopt", "yosys", "bool", "Disable optimizations." },
        { "-icells", "yosys", "bool", "Ignore cells in outputs." },
        { "-pwires", "yosys", "bool", "Preserve wires in outputs." },
        { "-nooverwrite", "yosys", "bool", "Prevent overwriting output files." },
        { "-overwrite", "yosys", "bool", "Allow overwriting output files." },
        { "-defer", "yosys", "bool", "Defer execution." },
        { "-noautowire", "yosys", "bool", "Disable automatic wiring." },
        { "-m", "abc", "bool", "" },
        { "-c", "abc", "bool", "" },
        { "-b", "abc", "bool", "" }

    };
    setOptions( this, options );
  }

  ~CmdLfIoReadVerilog() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file", "-setattr", "-Dname", "-Idir" };
    std::vector<std::string> boolOptions = { "-sv", "-formal", "-nosynthesis", "-noassert", "-noassume", "-norestrict",
                                             "-assume-asserts", "-assert-assumes", "-nodisplay", "-debug", "-dump_ast1",
                                             "-dump_ast2", "-no_dump_ptr", "-dump_vlog1", "-dump_vlog2", "-dump_rtlil",
                                             "-yydebug", "-nolatches", "-nomem2reg", "-mem2reg", "-nomeminit", "-ppdump",
                                             "-nopp", "-nodpi", "-noblackbox", "-lib", "-nowb", "-specify", "-noopt",
                                             "-icells", "-pwires", "-nooverwrite", "-overwrite", "-defer", "-noautowire",
                                             "-m", "-c", "-b" };
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
      lf::arch::yosys::read_verilog( strOptionsValue["-file"],
                                     boolOptionsValue["-sv"],
                                     boolOptionsValue["-formal"],
                                     boolOptionsValue["-nosynthesis"],
                                     boolOptionsValue["-noassert"],
                                     boolOptionsValue["-noassume"],
                                     boolOptionsValue["-norestrict"],
                                     boolOptionsValue["-assume-asserts"],
                                     boolOptionsValue["-assert-assumes"],
                                     boolOptionsValue["-nodisplay"],
                                     boolOptionsValue["-debug"],
                                     boolOptionsValue["-dump_ast1"],
                                     boolOptionsValue["-dump_ast2"],
                                     boolOptionsValue["-no_dump_ptr"],
                                     boolOptionsValue["-dump_vlog1"],
                                     boolOptionsValue["-dump_vlog2"],
                                     boolOptionsValue["-dump_rtlil"],
                                     boolOptionsValue["-yydebug"],
                                     boolOptionsValue["-nolatches"],
                                     boolOptionsValue["-nomem2reg"],
                                     boolOptionsValue["-mem2reg"],
                                     boolOptionsValue["-nomeminit"],
                                     boolOptionsValue["-ppdump"],
                                     boolOptionsValue["-nopp"],
                                     boolOptionsValue["-nodpi"],
                                     boolOptionsValue["-noblackbox"],
                                     boolOptionsValue["-lib"],
                                     boolOptionsValue["-nowb"],
                                     boolOptionsValue["-specify"],
                                     boolOptionsValue["-noopt"],
                                     boolOptionsValue["-icells"],
                                     boolOptionsValue["-pwires"],
                                     boolOptionsValue["-nooverwrite"],
                                     boolOptionsValue["-overwrite"],
                                     boolOptionsValue["-defer"],
                                     boolOptionsValue["-noautowire"],
                                     strOptionsValue["-setattr"],
                                     strOptionsValue["-Dname"],
                                     strOptionsValue["-Idir"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::read_verilog( strOptionsValue["-file"],
                                    boolOptionsValue["-m"],
                                    boolOptionsValue["-c"],
                                    boolOptionsValue["-b"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadVerilog

class CmdLfIoReadBench : public TclCmd
{
public:
  explicit CmdLfIoReadBench( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." },
        { "-c", "abc", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfIoReadBench() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-c" };
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::read_bench( strOptionsValue["-file"],
                                  boolOptionsValue["-c"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::read_bench( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadBench

class CmdLfIoReadCnf : public TclCmd
{
public:
  explicit CmdLfIoReadCnf( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." },
        { "-m", "abc", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfIoReadCnf() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-m" };
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::read_cnf( strOptionsValue["-file"],
                                boolOptionsValue["-m"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::read_cnf( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadCnf

class CmdLfIoReadPla : public TclCmd
{
public:
  explicit CmdLfIoReadPla( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." },
        { "-z", "abc", "bool", "" },
        { "-b", "abc", "bool", "" },
        { "-d", "abc", "bool", "" },
        { "-x", "abc", "bool", "" },
        { "-c", "abc", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfIoReadPla() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-z", "-b", "-d", "-x", "-c" };
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::read_pla( strOptionsValue["-file"],
                                boolOptionsValue["-z"],
                                boolOptionsValue["-b"],
                                boolOptionsValue["-d"],
                                boolOptionsValue["-x"],
                                boolOptionsValue["-c"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::read_pla( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadPla

class CmdLfIoReadGtech : public TclCmd
{
public:
  explicit CmdLfIoReadGtech( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." } };
    setOptions( this, options );
  }

  ~CmdLfIoReadGtech() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = {};
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::read_gtech( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadGtech

class CmdLfIoReadFormula : public TclCmd
{
public:
  explicit CmdLfIoReadFormula( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." } };
    setOptions( this, options );
  }

  ~CmdLfIoReadFormula() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = {};
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::read_formula( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadFormula

class CmdLfIoReadJson : public TclCmd
{
public:
  explicit CmdLfIoReadJson( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." } };
    setOptions( this, options );
  }

  ~CmdLfIoReadJson() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = {};
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
      lf::arch::yosys::read_json( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadJson

class CmdLfIoReadRtlil : public TclCmd
{
public:
  explicit CmdLfIoReadRtlil( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." },
        { "-nooverwrite ", "yosys", "bool", "" },
        { "-overwrite ", "yosys", "bool", "" },
        { "-lib ", "yosys", "bool", "" } };
    setOptions( this, options );
  }

  ~CmdLfIoReadRtlil() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-nooverwrite", "-overwrite", "-lib" };
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
      lf::arch::yosys::read_rtlil( strOptionsValue["-file"], boolOptionsValue["-nooverwrite"], boolOptionsValue["-overwrite"], boolOptionsValue["-lib"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadRtlil

class CmdLfIoReadGenlib : public TclCmd
{
public:
  explicit CmdLfIoReadGenlib( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." } };
    setOptions( this, options );
  }

  ~CmdLfIoReadGenlib() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = {};
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::read_genlib( strOptionsValue["-file"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::read_genlib( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadGenlib

class CmdLfIoReadLiberty : public TclCmd
{
public:
  explicit CmdLfIoReadLiberty( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to read." },
        { "-lib", "yosys", "bool", "" },
        { "-wb", "yosys", "bool", "" },
        { "-nooverwrite", "yosys", "bool", "" },
        { "-overwrite", "yosys", "bool", "" },
        { "-ignore_miss_func", "yosys", "bool", "" },
        { "-ignore_miss_dir", "yosys", "bool", "" },
        { "-is_ignore_miss_data_latch", "yosys", "bool", "" },
        { "-setattr", "yosys", "string", "" } };
    setOptions( this, options );
  }

  ~CmdLfIoReadLiberty() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file", "-setattr" };
    std::vector<std::string> boolOptions = { "-lib", "-wb", "-nooverwrite", "-overwrite", "-ignore_miss_func", "-ignore_miss_dir", "-is_ignore_miss_data_latch" };
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
      lf::arch::yosys::read_liberty( strOptionsValue["-file"],
                                     boolOptionsValue["-lib"],
                                     boolOptionsValue["-wb"],
                                     boolOptionsValue["-nooverwrite"],
                                     boolOptionsValue["-overwrite"],
                                     boolOptionsValue["-ignore_miss_func"],
                                     boolOptionsValue["-ignore_miss_dir"],
                                     boolOptionsValue["-is_ignore_miss_data_latch"],
                                     strOptionsValue["-setattr"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::read_liberty( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoReadLiberty

#pragma region Writer
class CmdLfIoWriteAiger : public TclCmd
{
public:
  explicit CmdLfIoWriteAiger( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-ascii", "yosys", "bool", "" },
        { "-zinit", "yosys", "bool", "" },
        { "-miter", "yosys", "bool", "" },
        { "-symbols", "yosys", "bool", "" },
        { "-map", "yosys", "string", "" },
        { "-vmap", "yosys", "string", "" },
        { "-no-startoffset", "yosys", "bool", "" },
        { "-ymap", "yosys", "string", "" },
        { "-I", "yosys", "bool", "" },
        { "-O", "yosys", "bool", "" },
        { "-B", "yosys", "bool", "" },
        { "-L", "yosys", "bool", "" },
        { "-s", "abc", "bool", "" },
        { "-c", "abc", "bool", "" },
        { "-u", "abc", "bool", "" },
        { "-v", "abc", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteAiger() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file", "-map", "-vmap", "-ymap" };
    std::vector<std::string> boolOptions = { "-ascii", "-zinit", "-miter", "-symbols", "-no-startoffset", "-I", "-O", "-B", "-L", "-s", "-c", "-u", "-v" };
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
      std::cout << "yosys" << std::endl;
      lf::arch::yosys::write_aiger( strOptionsValue["-file"],
                                    boolOptionsValue["-ascii"],
                                    boolOptionsValue["-zinit"],
                                    boolOptionsValue["-miter"],
                                    boolOptionsValue["-symbols"],
                                    strOptionsValue["-map"],
                                    strOptionsValue["-vmap"],
                                    boolOptionsValue["-no-startoffset"],
                                    strOptionsValue["-ymap"],
                                    boolOptionsValue["-I"],
                                    boolOptionsValue["-O"],
                                    boolOptionsValue["-B"],
                                    boolOptionsValue["-L"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      std::cout << "abc" << std::endl;
      lf::logic::abc::write_aiger( strOptionsValue["-file"],
                                   boolOptionsValue["-s"],
                                   boolOptionsValue["-c"],
                                   boolOptionsValue["-u"],
                                   boolOptionsValue["-v"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      std::cout << "lsils" << std::endl;
      lf::logic::lsils::write_aiger( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteAiger

class CmdLfIoWriteBench : public TclCmd
{
public:
  explicit CmdLfIoWriteBench( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-l", "abc", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteBench() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-l" };
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      std::cout << "abc" << std::endl;
      lf::logic::abc::write_bench( strOptionsValue["-file"],
                                   boolOptionsValue["-l"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      std::cout << "lsils" << std::endl;
      lf::logic::lsils::write_bench( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteBench

class CmdLfIoWriteBlif : public TclCmd
{
public:
  explicit CmdLfIoWriteBlif( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-top", "yosys", "string", "" },
        { "-buf", "yosys", "strvec", "" },
        { "-unbuf", "yosys", "strvec", "" },
        { "-true", "yosys", "strvec", "" },
        { "-false", "yosys", "strvec", "" },
        { "-undef", "yosys", "strvec", "" },
        { "-noalias", "yosys", "bool", "" },
        { "-icells", "yosys", "bool", "" },
        { "-gates", "yosys", "bool", "" },
        { "-conn", "yosys", "bool", "" },
        { "-attr", "yosys", "bool", "" },
        { "-param", "yosys", "bool", "" },
        { "-cname", "yosys", "bool", "" },
        { "-iname", "yosys", "bool", "" },
        { "-iattr", "yosys", "bool", "" },
        { "-blackbox", "yosys", "bool", "" },
        { "-impltf", "yosys", "bool", "" },
        { "-S", "abc", "string", "" },
        { "-j", "abc", "bool", "" },
        { "-a", "abc", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteBlif() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file", "-top", "-S" };
    std::vector<std::string> boolOptions = { "-noalias", "-icells", "-gates", "-conn", "-attr", "-param", "-cname", "-iname", "-iattr", "-blackbox", "-impltf", "-j", "-a" };
    std::vector<std::string> intOptions = {};
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = { "-buf", "-unbuf", "-true", "-false", "-undef" };
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_domain = lfAnchorINST->get_anchor_domain();

    switch ( anchor_domain )
    {
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_ARCH_YOSYS:
      lf::arch::yosys::write_blif( strOptionsValue["-file"],
                                   strOptionsValue["-top"],
                                   strvecOptionsValue["-buf"],
                                   strvecOptionsValue["-unbuf"],
                                   strvecOptionsValue["-true"],
                                   strvecOptionsValue["-false"],
                                   strvecOptionsValue["-undef"],
                                   boolOptionsValue["-noalias"],
                                   boolOptionsValue["-icells"],
                                   boolOptionsValue["-gates"],
                                   boolOptionsValue["-conn"],
                                   boolOptionsValue["-attr"],
                                   boolOptionsValue["-param"],
                                   boolOptionsValue["-cname"],
                                   boolOptionsValue["-iname"],
                                   boolOptionsValue["-iattr"],
                                   boolOptionsValue["-blackbox"],
                                   boolOptionsValue["-impltf"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::write_blif( strOptionsValue["-file"],
                                  strOptionsValue["-S"],
                                  boolOptionsValue["-j"],
                                  boolOptionsValue["-a"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::write_blif( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteBlif

class CmdLfIoWriteCnf : public TclCmd
{
public:
  explicit CmdLfIoWriteCnf( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-n", "abc", "bool", "" },
        { "-f", "abc", "bool", "" },
        { "-p", "abc", "bool", "" },
        { "-c", "abc", "bool", "" },
        { "-v", "abc", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteCnf() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-n", "-f", "-p", "-c", "-v" };
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::write_cnf( strOptionsValue["-file"],
                                 boolOptionsValue["-n"],
                                 boolOptionsValue["-f"],
                                 boolOptionsValue["-p"],
                                 boolOptionsValue["-c"],
                                 boolOptionsValue["-v"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::write_cnf( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteCnf

class CmdLfIoWriteDot : public TclCmd
{
public:
  explicit CmdLfIoWriteDot( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteDot() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = {};
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::write_dot( strOptionsValue["-file"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::write_dot( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteDot

class CmdLfIoWritePla : public TclCmd
{
public:
  explicit CmdLfIoWritePla( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-M", "abc", "int", "" },
        { "-m", "abc", "bool", "" },
    };

    setOptions( this, options );
  }

  ~CmdLfIoWritePla() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-m" };
    std::vector<std::string> intOptions = { "-M" };
    std::vector<std::string> doubleOptions = {};
    std::vector<std::string> strvecOptions = {};
    std::vector<std::string> intvecOptions = {};
    std::vector<std::string> doublevecOptions = {};

    extractOptions( this, strOptions, boolOptions, intOptions, doubleOptions, strvecOptions, intvecOptions, doublevecOptions,
                    strOptionsValue, boolOptionsValue, intOptionsValue, doubleOptionsValue, strvecOptionsValue, intvecOptionsValue, doublevecOptionsValue );

    auto anchor_domain = lfAnchorINST->get_anchor_domain();

    switch ( anchor_domain )
    {
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::write_pla( strOptionsValue["-file"],
                                 intOptionsValue["-M"],
                                 boolOptionsValue["-m"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWritePla

class CmdLfIoWriteTruth : public TclCmd
{
public:
  explicit CmdLfIoWriteTruth( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-x", "abc", "bool", "" },
        { "-r", "abc", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteTruth() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-x", "-r" };
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
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::write_truth( strOptionsValue["-file"],
                                   boolOptionsValue["-x"],
                                   boolOptionsValue["-r"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteTruth

class CmdLfIoWriteBtor : public TclCmd
{
public:
  explicit CmdLfIoWriteBtor( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-v", "yosys", "bool", "" },
        { "-s", "yosys", "bool", "" },
        { "-c", "yosys", "bool", "" },
        { "-i", "yosys", "bool", "" },
        { "-x", "yosys", "bool", "" },
        { "-ywmap", "yosys", "string", "" },
    };

    setOptions( this, options );
  }

  ~CmdLfIoWriteBtor() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file", "-ywmap" };
    std::vector<std::string> boolOptions = { "-v", "-s", "-c", "-i", "-x" };
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
      lf::arch::yosys::write_btor( strOptionsValue["-file"],
                                   boolOptionsValue["-v"],
                                   boolOptionsValue["-s"],
                                   boolOptionsValue["-c"],
                                   boolOptionsValue["-i"],
                                   boolOptionsValue["-x"],
                                   strOptionsValue["-ywmap"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteBtor

class CmdLfIoWriteEdif : public TclCmd
{
public:
  explicit CmdLfIoWriteEdif( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-top", "yosys", "string", "" },
        { "-nogndvcc", "yosys", "bool", "" },
        { "-gndvccy", "yosys", "bool", "" },
        { "-attrprop", "yosys", "bool", "" },
        { "-keep", "yosys", "bool", "" },
        { "-pvector", "yosys", "string", "" },
        { "-lsbidx", "yosys", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteEdif() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file", "-top", "-pvector" };
    std::vector<std::string> boolOptions = { "-nogndvcc", "-gndvccy", "-attrprop", "-keep", "-lsbidx" };
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
      lf::arch::yosys::write_edif( strOptionsValue["-file"],
                                   strOptionsValue["-top"],
                                   boolOptionsValue["-nogndvcc"],
                                   boolOptionsValue["-gndvccy"],
                                   boolOptionsValue["-attrprop"],
                                   boolOptionsValue["-keep"],
                                   strOptionsValue["-pvector"],
                                   boolOptionsValue["-lsbidx"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteEdif

class CmdLfIoWriteFirrtl : public TclCmd
{
public:
  explicit CmdLfIoWriteFirrtl( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteFirrtl() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = {};
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
      lf::arch::yosys::write_firrtl( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteFirrtl

class CmdLfIoWriteJson : public TclCmd
{
public:
  explicit CmdLfIoWriteJson( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "is_aig", "yosys", "bool", "" },
        { "-compat-int", "yosys", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteJson() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-is_aig", "-compat-int" };
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
      lf::arch::yosys::write_json( strOptionsValue["-file"],
                                   boolOptionsValue["-is_aig"],
                                   boolOptionsValue["-compat-int"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteJson

class CmdLfIoWriteRtlil : public TclCmd
{
public:
  explicit CmdLfIoWriteRtlil( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-selected", "yosys", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteRtlil() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = { "-selected" };
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
      lf::arch::yosys::write_json( strOptionsValue["-file"],
                                   boolOptionsValue["-selected"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteRtlil

class CmdLfIoWriteSpice : public TclCmd
{
public:
  explicit CmdLfIoWriteSpice( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the aiger file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "The file to write." },
        { "-top", "yosys", "string", "" },
        { "-big_endian", "yosys", "bool", "" },
        { "-neg", "yosys", "string", "" },
        { "-pos", "yosys", "string", "" },
        { "-buf", "yosys", "string", "" },
        { "-nc_prefix", "yosys", "string", "" },
        { "-inames", "yosys", "bool", "" } };

    setOptions( this, options );
  }

  ~CmdLfIoWriteSpice() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file", "-top", "-neg", "-pos", "-buf", "-nc_prefix" };
    std::vector<std::string> boolOptions = { "-big_endian", "-inames" };
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
      lf::arch::yosys::write_spice( strOptionsValue["-file"],
                                    strOptionsValue["-top"],
                                    boolOptionsValue["-big_endian"],
                                    strOptionsValue["-neg"],
                                    strOptionsValue["-pos"],
                                    strOptionsValue["-buf"],
                                    strOptionsValue["-nc_prefix"],
                                    boolOptionsValue["-inames"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteSpice

class CmdLfIoWriteVerilog : public TclCmd
{
public:
  explicit CmdLfIoWriteVerilog( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "" },
        { "-renameprefix", "yosys", "string", "" },
        { "-sv", "yosys", "bool", "" },
        { "-norename", "yosys", "bool", "" },
        { "-noattr", "yosys", "bool", "" },
        { "-attr2comment", "yosys", "bool", "" },
        { "-noexpr", "yosys", "bool", "" },
        { "-noparallelcase", "yosys", "bool", "" },
        { "-siminit", "yosys", "bool", "" },
        { "-nodec", "yosys", "bool", "" },
        { "-decimal", "yosys", "bool", "" },
        { "-nohex", "yosys", "bool", "" },
        { "-nostr", "yosys", "bool", "" },
        { "-simple-lhs", "yosys", "bool", "" },
        { "-extmem", "yosys", "bool", "" },
        { "-defparam", "yosys", "bool", "" },
        { "-blackboxes", "yosys", "bool", "" },
        { "-selected", "yosys", "bool", "" },
        { "-v", "yosys", "bool", "" },
        { "-K", "abc", "int", "" },
        { "-f", "abc", "bool", "" },
        { "-a", "abc", "bool", "" },
        { "-m", "abc", "bool", "" }

    };
    setOptions( this, options );
  }

  ~CmdLfIoWriteVerilog() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file", "-renameprefix" };
    std::vector<std::string> boolOptions = { "-sv", "-norename", "-noattr", "-attr2comment", "-noexpr",
                                             "-noparallelcase", "-siminit", "-nodec", "-decimal", "-nohex",
                                             "-nostr", "-simple-lhs", "-extmem", "-defparam", "-blackboxes",
                                             "-selected", "-v",
                                             "-f", "-a", "-m" };
    std::vector<std::string> intOptions = { "-K" };
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
      lf::arch::yosys::write_verilog( strOptionsValue["-file"],
                                      boolOptionsValue["-sv"],
                                      boolOptionsValue["-norename"],
                                      strOptionsValue["-renameprefix"],
                                      boolOptionsValue["-noattr"],
                                      boolOptionsValue["-attr2comment"],
                                      boolOptionsValue["-noexpr"],
                                      boolOptionsValue["-noparallelcase"],
                                      boolOptionsValue["-siminit"],
                                      boolOptionsValue["-nodec"],
                                      boolOptionsValue["-decimal"],
                                      boolOptionsValue["-nohex"],
                                      boolOptionsValue["-nostr"],
                                      boolOptionsValue["-simple-lhs"],
                                      boolOptionsValue["-extmem"],
                                      boolOptionsValue["-defparam"],
                                      boolOptionsValue["-blackboxes"],
                                      boolOptionsValue["-selected"],
                                      boolOptionsValue["-v"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::abc::write_verilog( strOptionsValue["-file"],
                                     intOptionsValue["-K"],
                                     boolOptionsValue["-f"],
                                     boolOptionsValue["-a"],
                                     boolOptionsValue["-m"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::lsils::write_verilog(strOptionsValue["-file"]);
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteVerilog

class CmdLfIoWriteGraphml : public TclCmd
{
public:
  explicit CmdLfIoWriteGraphml( const char* cmd_name ) : TclCmd( cmd_name )
  {
    // set the description
    std::string description = "Read the blif file and store the data in the current design. please note the current anchor when use this command!";
    this->set_description( description );
    // set the domain
    std::string domain = "io";
    this->set_domain( domain );
    // set the options
    std::vector<lfCmdOption> options = {
        { "-file", "all", "string", "" } };
    setOptions( this, options );
  }

  ~CmdLfIoWriteGraphml() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
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

    std::vector<std::string> strOptions = { "-file" };
    std::vector<std::string> boolOptions = {};
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
      std::cerr << "TODO ing!" << std::endl;
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      lf::logic::write_graphml( strOptionsValue["-file"] );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      lf::logic::write_graphml( strOptionsValue["-file"] );
      break;
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }
}; // class CmdLfIoWriteGraphml

} // namespace tcl

} // namespace lf
