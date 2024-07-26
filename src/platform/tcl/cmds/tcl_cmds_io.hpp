#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"

#include "misc/anchor.hpp"

#include "layer_arch/api/yosys/io/read_aiger.hpp"
#include "layer_arch/api/yosys/io/read_liberty.hpp"
#include "layer_arch/api/yosys/io/read_verilog.hpp"
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
    std::vector<std::pair<std::string, std::string>> str_common = {
        std::make_pair( "-file", "[type: common]" ) };

    std::vector<std::pair<std::string, std::string>> str_yosys = {
        std::make_pair( "-module_name", "[type: yosys], " ),
        std::make_pair( "-clk_name", "[type: yosys]," ),
        std::make_pair( "-map", "[type: yosys]," ) };
    std::vector<std::pair<std::string, std::string>> str_abc = {};
    std::vector<std::pair<std::string, std::string>> str_lsils = {};

    std::vector<std::pair<std::string, std::string>> switch_yosys = {
        std::make_pair( "-wideports", "[type: yosys]," ),
        std::make_pair( "-xaiger", "[type: yosys]," ) };
    std::vector<std::pair<std::string, std::string>> switch_abc = {
        std::make_pair( "-c", "[type: abc]," ) };
    std::vector<std::pair<std::string, std::string>> switch_lsils = {};

    for ( auto [args, desc] : str_common )
    {
      auto* option = new TclStringOption( args.c_str(), 1, nullptr );
      option->set_description( desc );
      addOption( option );
    }
    for ( auto [args, desc] : str_yosys )
    {
      auto* option = new TclStringOption( args.c_str(), 1, nullptr );
      option->set_description( desc );
      addOption( option );
    }
    for ( auto [args, desc] : str_abc )
    {
      auto* option = new TclStringOption( args.c_str(), 1, nullptr );
      option->set_description( desc );
      addOption( option );
    }
    for ( auto [args, desc] : str_lsils )
    {
      auto* option = new TclStringOption( args.c_str(), 1, nullptr );
      option->set_description( desc );
      addOption( option );
    }

    for ( auto [args, desc] : switch_yosys )
    {
      auto* option = new TclSwitchOption( args.c_str() );
      option->set_description( desc );
      addOption( option );
    }
    for ( auto [args, desc] : switch_abc )
    {
      auto* option = new TclSwitchOption( args.c_str() );
      option->set_description( desc );
      addOption( option );
    }
    for ( auto [args, desc] : switch_lsils )
    {
      auto* option = new TclSwitchOption( args.c_str() );
      option->set_description( desc );
      addOption( option );
    }
  }

  ~CmdLfIoReadAiger() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "", module_name = "", clk_name = "", map_file = "";
    bool is_wideports = false, is_xaiger = false, is_checking = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_module_name = getOptionOrArg( "-module_name" );
    TclOption* option_clk_name = getOptionOrArg( "-clk_name" );
    TclOption* option_map_file = getOptionOrArg( "-map" );
    TclOption* option_wideports = getOptionOrArg( "-wideports" );
    TclOption* option_xaiger = getOptionOrArg( "-xaiger" );
    TclOption* option_checking = getOptionOrArg( "-c" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    else
    {
      std::cerr << "Essential option -file is not set!" << std::endl;
      assert( false );
      return 0;
    }

    if ( option_module_name->is_set_val() )
      module_name = option_module_name->getStringVal();
    if ( option_clk_name->is_set_val() )
      clk_name = option_clk_name->getStringVal();
    if ( option_map_file->is_set_val() )
      map_file = option_map_file->getStringVal();
    if ( option_wideports->is_set_val() )
      is_wideports = true;
    if ( option_xaiger->is_set_val() )
      is_xaiger = true;
    if ( option_checking->is_set_val() )
      is_checking = true;

    auto anchor_domain = lfAnchorINST->get_anchor_domain();

    switch ( anchor_domain )
    {
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_ARCH_YOSYS:
      std::cout << "yosys" << std::endl;
      lf::arch::yosys::read_aiger( file, module_name, clk_name, map_file, is_wideports, is_xaiger );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_ABC:
      std::cout << "abc" << std::endl;
      lf::logic::abc::read_aiger( file, is_checking );
      break;
    case lf::misc::E_LF_ANCHOR_DOMAIN::E_LF_ANCHOR_DOMAIN_LOGIC_LSILS:
      std::cout << "lsils" << std::endl;
      lf::logic::lsils::read_aiger( file );
    default:
      std::cerr << "Unsupported anchor domain, please use anchor to set the anchor!" << std::endl;
      return 0;
    }
    return 1;
  }

}; // class CmdLfIoReadAiger

////////////////////////////////////////////////////////////////////////////
//  read_aiger / yosys
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadAigerYosys : public TclCmd
{
public:
  explicit CmdLfIoReadAigerYosys( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    // TODO: it is better to add descripton for this commands
    std::vector<std::pair<std::string, std::string>> strs = {
        std::make_pair( "-module_name", "" ),
        std::make_pair( "-clk_name", "" ),
        std::make_pair( "-map", "" ) };

    std::vector<std::pair<std::string, std::string>> switches = {
        std::make_pair( "-wideports", "" ),
        std::make_pair( "-xaiger", "" ) };

    for ( auto [args, desc] : strs )
    {
      auto* option = new TclStringOption( args.c_str(), 1, nullptr );
      option->set_description( desc );
      addOption( option );
    }

    for ( auto [args, desc] : switches )
    {
      auto* option = new TclSwitchOption( args.c_str() );
      option->set_description( desc );
      addOption( option );
    }
  }

  ~CmdLfIoReadAigerYosys() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "", module_name = "", clk_name = "", map_file = "";
    bool is_wideports = false, is_xaiger = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_module_name = getOptionOrArg( "-module_name" );
    TclOption* option_clk_name = getOptionOrArg( "-clk_name" );
    TclOption* option_map_file = getOptionOrArg( "-map" );
    TclOption* option_wideports = getOptionOrArg( "-wideports" );
    TclOption* option_xaiger = getOptionOrArg( "-xaiger" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_module_name->is_set_val() )
      module_name = option_module_name->getStringVal();
    if ( option_clk_name->is_set_val() )
      clk_name = option_clk_name->getStringVal();
    if ( option_map_file->is_set_val() )
      map_file = option_map_file->getStringVal();
    if ( option_wideports->is_set_val() )
      is_wideports = true;
    if ( option_xaiger->is_set_val() )
      is_xaiger = true;

    lf::arch::yosys::read_aiger( file, module_name, clk_name, map_file, is_wideports, is_xaiger );

    return 1;
  }

}; // class CmdLfIoReadAigerYosys

////////////////////////////////////////////////////////////////////////////
//  read_liberty / yosys
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadLibertyYosys : public TclCmd
{
public:
  explicit CmdLfIoReadLibertyYosys( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file", "-setattr" };

    std::vector<std::string> switches = {
        "-lib", "-wb", "-nooverwrite", "-overwrite", "-ignore_miss_func", "-ignore_miss_dir", "-ignore_miss_data_latch" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadLibertyYosys() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "", setattr = "";
    bool is_lib = false, is_wb = false, is_nooverwrite = false, is_overwrite = false, is_ignore_miss_func = false, is_ignore_miss_dir = false, is_ignore_miss_data_latch = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_setattr = getOptionOrArg( "-setattr" );
    TclOption* option_lib = getOptionOrArg( "-lib" );
    TclOption* option_wb = getOptionOrArg( "-wb" );
    TclOption* option_nooverwrite = getOptionOrArg( "-nooverwrite" );
    TclOption* option_overwrite = getOptionOrArg( "-overwrite" );
    TclOption* option_ignore_miss_func = getOptionOrArg( "-ignore_miss_func" );
    TclOption* option_ignore_miss_dir = getOptionOrArg( "-ignore_miss_dir" );
    TclOption* option_ignore_miss_data_latch = getOptionOrArg( "-ignore_miss_data_latch" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_setattr->is_set_val() )
      setattr = option_setattr->getStringVal();
    if ( option_lib->is_set_val() )
      is_lib = true;
    if ( option_wb->is_set_val() )
      is_wb = true;
    if ( option_nooverwrite->is_set_val() )
      is_nooverwrite = true;
    if ( option_overwrite->is_set_val() )
      is_overwrite = true;
    if ( option_ignore_miss_func->is_set_val() )
      is_ignore_miss_func = true;
    if ( option_ignore_miss_dir->is_set_val() )
      is_ignore_miss_dir = true;
    if ( option_ignore_miss_data_latch->is_set_val() )
      is_ignore_miss_data_latch = true;

    lf::arch::yosys::read_liberty( file, is_lib, is_wb, is_nooverwrite, is_overwrite, is_ignore_miss_func, is_ignore_miss_dir, is_ignore_miss_data_latch, setattr );

    return 1;
  }
}; // class CmdLfIoReadLibertyYosys

////////////////////////////////////////////////////////////////////////////
//  read_verilog / yosys
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadVerilogYosys : public TclCmd
{
public:
  explicit CmdLfIoReadVerilogYosys( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file", "-setattr", "-Dname", "-Idir" };

    std::vector<std::string> switches = {
        "-sv", "-formal", "-nosynthesis", "-noassert", "-noassume", "-norestrict",
        "-assume-asserts", "-assert-assumes", "-nodisplay", "-debug", "-dump_ast1",
        "-dump_ast2", "-no_dump_ptr", "-dump_vlog1", "-dump_vlog2", "-dump_rtlil",
        "-yydebug", "-nolatches", "-nomem2reg", "-mem2reg", "-nomeminit", "-ppdump",
        "-nopp", "-nodpi", "-noblackbox", "-lib", "-nowb", "-specify", "-noopt",
        "-icells", "-pwires", "-nooverwrite", "-overwrite", "-defer", "-noautowire" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadVerilogYosys() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "", setattr = "", Dname = "", Idir = "";
    bool is_sv = false, is_formal = false, is_nosynthesis = false, is_noassert = false,
         is_noassume = false, is_norestrict = false, is_assume_asserts = false, is_assert_assumes = false,
         is_nodisplay = false, is_debug = false, is_dump_ast1 = false, is_dump_ast2 = false, is_no_dump_ptr = false,
         is_dump_vlog1 = false, is_dump_vlog2 = false, is_dump_rtlil = false, is_yydebug = false, is_nolatches = false,
         is_nomem2reg = false, is_mem2reg = false, is_nomeminit = false, is_ppdump = false, is_nopp = false, is_nodpi = false,
         is_noblackbox = false, is_lib = false, is_nowb = false, is_specify = false, is_noopt = false, is_icells = false,
         is_pwires = false, is_nooverwrite = false, is_overwrite = false, is_defer = false, is_noautowire = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_setattr = getOptionOrArg( "-setattr" );
    TclOption* option_Dname = getOptionOrArg( "-Dname" );
    TclOption* option_Idir = getOptionOrArg( "-Idir" );
    TclOption* option_sv = getOptionOrArg( "-sv" );
    TclOption* option_formal = getOptionOrArg( "-formal" );
    TclOption* option_nosynthesis = getOptionOrArg( "-nosynthesis" );
    TclOption* option_noassert = getOptionOrArg( "-noassert" );
    TclOption* option_noassume = getOptionOrArg( "-noassume" );
    TclOption* option_norestrict = getOptionOrArg( "-norestrict" );
    TclOption* option_assume_asserts = getOptionOrArg( "-assume_asserts" );
    TclOption* option_assert_assumes = getOptionOrArg( "-assert_assumes" );
    TclOption* option_nodisplay = getOptionOrArg( "-nodisplay" );
    TclOption* option_debug = getOptionOrArg( "-debug" );
    TclOption* option_dump_ast1 = getOptionOrArg( "-dump_ast1" );
    TclOption* option_dump_ast2 = getOptionOrArg( "-dump_ast2" );
    TclOption* option_no_dump_ptr = getOptionOrArg( "-no_dump_ptr" );
    TclOption* option_dump_vlog1 = getOptionOrArg( "-dump_vlog1" );
    TclOption* option_dump_vlog2 = getOptionOrArg( "-dump_vlog2" );
    TclOption* option_dump_rtlil = getOptionOrArg( "-dump_rtlil" );
    TclOption* option_yydebug = getOptionOrArg( "-yydebug" );
    TclOption* option_nolatches = getOptionOrArg( "-nolatches" );
    TclOption* option_nomem2reg = getOptionOrArg( "-nomem2reg" );
    TclOption* option_mem2reg = getOptionOrArg( "-mem2reg" );
    TclOption* option_nomeminit = getOptionOrArg( "-nomeminit" );
    TclOption* option_ppdump = getOptionOrArg( "-ppdump" );
    TclOption* option_nopp = getOptionOrArg( "-nopp" );
    TclOption* option_nodpi = getOptionOrArg( "-nodpi" );
    TclOption* option_noblackbox = getOptionOrArg( "-noblackbox" );
    TclOption* option_lib = getOptionOrArg( "-lib" );
    TclOption* option_nowb = getOptionOrArg( "-nowb" );
    TclOption* option_specify = getOptionOrArg( "-specify" );
    TclOption* option_noopt = getOptionOrArg( "-noopt" );
    TclOption* option_icells = getOptionOrArg( "-icells" );
    TclOption* option_pwires = getOptionOrArg( "-pwires" );
    TclOption* option_nooverwrite = getOptionOrArg( "-nooverwrite" );
    TclOption* option_overwrite = getOptionOrArg( "-overwrite" );
    TclOption* option_defer = getOptionOrArg( "-defer" );
    TclOption* option_noautowire = getOptionOrArg( "-noautowire" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_setattr->is_set_val() )
      setattr = option_setattr->getStringVal();
    if ( option_Dname->is_set_val() )
      Dname = option_Dname->getStringVal();
    if ( option_Idir->is_set_val() )
      Idir = option_Idir->getStringVal();
    if ( option_sv->is_set_val() )
      is_sv = true;
    if ( option_formal->is_set_val() )
      is_formal = true;
    if ( option_nosynthesis->is_set_val() )
      is_nosynthesis = true;
    if ( option_noassert->is_set_val() )
      is_noassert = true;
    if ( option_noassume->is_set_val() )
      is_noassume = true;
    if ( option_norestrict->is_set_val() )
      is_norestrict = true;
    if ( option_assume_asserts->is_set_val() )
      is_assume_asserts = true;
    if ( option_assert_assumes->is_set_val() )
      is_assert_assumes = true;
    if ( option_nodisplay->is_set_val() )
      is_nodisplay = true;
    if ( option_debug->is_set_val() )
      is_debug = true;
    if ( option_dump_ast1->is_set_val() )
      is_dump_ast1 = true;
    if ( option_dump_ast2->is_set_val() )
      is_dump_ast2 = true;
    is_no_dump_ptr = true;
    if ( option_dump_vlog1->is_set_val() )
      is_dump_vlog1 = true;
    if ( option_dump_vlog2->is_set_val() )
      is_dump_vlog2 = true;
    if ( option_dump_rtlil->is_set_val() )
      is_dump_rtlil = true;
    if ( option_yydebug->is_set_val() )
      is_yydebug = true;
    if ( option_nolatches->is_set_val() )
      is_nolatches = true;
    if ( option_nomem2reg->is_set_val() )
      is_nomem2reg = true;
    if ( option_mem2reg->is_set_val() )
      is_mem2reg = true;
    if ( option_nomeminit->is_set_val() )
      is_nomeminit = true;
    if ( option_ppdump->is_set_val() )
      is_ppdump = true;
    if ( option_nopp->is_set_val() )
      is_nopp = true;
    if ( option_nodpi->is_set_val() )
      is_nodpi = true;
    if ( option_noblackbox->is_set_val() )
      is_noblackbox = true;
    if ( option_lib->is_set_val() )
      is_lib = true;
    if ( option_nowb->is_set_val() )
      is_nowb = true;
    if ( option_specify->is_set_val() )
      is_specify = true;
    if ( option_noopt->is_set_val() )
      is_noopt = true;
    if ( option_icells->is_set_val() )
      is_icells = true;
    if ( option_pwires->is_set_val() )
      is_pwires = true;
    if ( option_nooverwrite->is_set_val() )
      is_nooverwrite = true;
    if ( option_overwrite->is_set_val() )
      is_overwrite = true;
    if ( option_defer->is_set_val() )
      is_defer = true;
    if ( option_noautowire->is_set_val() )
      is_noautowire = true;

    lf::arch::yosys::read_verilog( file, is_sv, is_formal, is_nosynthesis, is_noassert, is_noassume, is_norestrict,
                                   is_assume_asserts, is_assert_assumes, is_nodisplay, is_debug, is_dump_ast1, is_dump_ast2,
                                   is_no_dump_ptr, is_dump_vlog1, is_dump_vlog2, is_dump_rtlil, is_yydebug, is_nolatches,
                                   is_nomem2reg, is_mem2reg, is_nomeminit, is_ppdump, is_nopp, is_nodpi, is_noblackbox,
                                   is_lib, is_nowb, is_specify, is_noopt, is_icells, is_pwires, is_nooverwrite,
                                   is_overwrite, is_defer, is_noautowire, setattr, Dname, Idir );

    return 1;
  }
}; // class CmdLfIoReadVerilogYosys

////////////////////////////////////////////////////////////////////////////
//  write_verilog / yosys
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteVerilogYosys : public TclCmd
{
public:
  explicit CmdLfIoWriteVerilogYosys( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file", "-renameprefix" };

    std::vector<std::string> switches = {
        "-sv", "-norename", "-noattr", "-attr2comment", "-noexpr",
        "-noparallelcase", "-siminit", "-nodec", "-decimal", "-nohex",
        "-nostr", "-simple-lhs", "-extmem", "-defparam", "-blackboxes",
        "-selected", "-v" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteVerilogYosys() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file, renameprefix;
    bool is_sv = false, is_norename = false, is_noattr = false, is_attr2comment = false,
         is_noexpr = false, is_noparallelcase = false, is_siminit = false, is_nodec = false,
         is_decimal = false, is_nohex = false, is_nostr = false, is_simple_lhs = false,
         is_extmem = false, is_defparam = false, is_blackboxes = false, is_selected = false,
         is_v = false;

    // Retrieve all options values only if they have been set by the user
    if ( getOptionOrArg( "-file" )->is_set_val() )
      file = getOptionOrArg( "-file" )->getStringVal();
    if ( getOptionOrArg( "-renameprefix" )->is_set_val() )
      renameprefix = getOptionOrArg( "-renameprefix" )->getStringVal();
    if ( getOptionOrArg( "-sv" )->is_set_val() )
      is_sv = true;
    if ( getOptionOrArg( "-norename" )->is_set_val() )
      is_norename = true;
    if ( getOptionOrArg( "-noattr" )->is_set_val() )
      is_noattr = true;
    if ( getOptionOrArg( "-attr2comment" )->is_set_val() )
      is_attr2comment = true;
    if ( getOptionOrArg( "-noexpr" )->is_set_val() )
      is_noexpr = true;
    if ( getOptionOrArg( "-noparallelcase" )->is_set_val() )
      is_noparallelcase = true;
    if ( getOptionOrArg( "-siminit" )->is_set_val() )
      is_siminit = true;
    if ( getOptionOrArg( "-nodec" )->is_set_val() )
      is_nodec = true;
    if ( getOptionOrArg( "-decimal" )->is_set_val() )
      is_decimal = true;
    if ( getOptionOrArg( "-nohex" )->is_set_val() )
      is_nohex = true;
    if ( getOptionOrArg( "-nostr" )->is_set_val() )
      is_nostr = true;
    if ( getOptionOrArg( "-simple-lhs" )->is_set_val() )
      is_simple_lhs = true;
    if ( getOptionOrArg( "-extmem" )->is_set_val() )
      is_extmem = true;
    if ( getOptionOrArg( "-defparam" )->is_set_val() )
      is_defparam = true;
    if ( getOptionOrArg( "-blackboxes" )->is_set_val() )
      is_blackboxes = true;
    if ( getOptionOrArg( "-selected" )->is_set_val() )
      is_selected = true;
    if ( getOptionOrArg( "-v" )->is_set_val() )
      is_v = true;

    lf::arch::yosys::write_verilog( file, is_sv, is_norename, renameprefix, is_noattr, is_attr2comment,
                                    is_noexpr, is_noparallelcase, is_siminit, is_nodec, is_decimal,
                                    is_nohex, is_nostr, is_simple_lhs, is_extmem, is_defparam,
                                    is_blackboxes, is_selected, is_v );

    return 1;
  }
}; // class CmdLfIoWriteVerilogYosys

#pragma region IO abc
////////////////////////////////////////////////////////////////////////////
//  read_aiger / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadAigerAbc : public TclCmd
{
public:
  explicit CmdLfIoReadAigerAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-c" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadAigerAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_checking = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_checking = getOptionOrArg( "-c" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_checking->is_set_val() )
      is_checking = true;

    lf::logic::abc::read_aiger( file, is_checking );

    return 1;
  }
}; // class CmdLfIoReadAigerAbc

////////////////////////////////////////////////////////////////////////////
//  read_bench / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadBenchAbc : public TclCmd
{
public:
  explicit CmdLfIoReadBenchAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-c" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadBenchAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_checking = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_checking = getOptionOrArg( "-c" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_checking->is_set_val() )
      is_checking = true;

    lf::logic::abc::read_bench( file, is_checking );

    return 1;
  }
}; // class CmdLfIoReadBenchAbc

////////////////////////////////////////////////////////////////////////////
//  read_blif / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadBlifAbc : public TclCmd
{
public:
  explicit CmdLfIoReadBlifAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-n", "-m", "-a", "-c" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadBlifAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_old_parser = false, is_aig_created = false, is_saving_names = false, is_checking = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_old_parser = getOptionOrArg( "-n" );
    TclOption* option_is_aig_created = getOptionOrArg( "-m" );
    TclOption* option_is_saving_names = getOptionOrArg( "-a" );
    TclOption* option_is_checking = getOptionOrArg( "-c" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_checking->is_set_val() )
      is_checking = true;
    if ( option_is_old_parser->is_set_val() )
      is_old_parser = true;
    if ( option_is_aig_created->is_set_val() )
      is_aig_created = true;
    if ( option_is_saving_names->is_set_val() )
      is_saving_names = true;

    lf::logic::abc::read_blif( file, is_old_parser, is_aig_created, is_saving_names, is_checking );

    return 1;
  }
}; // class CmdLfIoReadBlifAbc

////////////////////////////////////////////////////////////////////////////
//  read_cnf / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadCnfAbc : public TclCmd
{
public:
  explicit CmdLfIoReadCnfAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-m" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadCnfAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_multi_output = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_multi_output = getOptionOrArg( "-m" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_multi_output->is_set_val() )
      is_multi_output = true;

    lf::logic::abc::read_cnf( file, is_multi_output );

    return 1;
  }
}; // class CmdLfIoReadCnfAbc

////////////////////////////////////////////////////////////////////////////
//  read_pla / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadPlaAbc : public TclCmd
{
public:
  explicit CmdLfIoReadPlaAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-z", "-b", "-d", "-x", "-c" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadPlaAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_zeors = false, is_both = false, is_dont_care = false, is_exor_sop = false, is_checking = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_zeros = getOptionOrArg( "-z" );
    TclOption* option_is_both = getOptionOrArg( "-b" );
    TclOption* option_is_dont_care = getOptionOrArg( "-d" );
    TclOption* option_is_exor_sop = getOptionOrArg( "-x" );
    TclOption* option_is_checking = getOptionOrArg( "-c" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_zeros->is_set_val() )
      is_zeors = true;
    if ( option_is_both->is_set_val() )
      is_both = true;
    if ( option_is_dont_care->is_set_val() )
      is_dont_care = true;
    if ( option_is_exor_sop->is_set_val() )
      is_exor_sop = true;
    if ( option_is_checking->is_set_val() )
      is_checking = true;

    lf::logic::abc::read_pla( file, is_zeors, is_both, is_dont_care, is_exor_sop, is_checking );

    return 1;
  }
}; // class CmdLfIoReadPlaAbc

////////////////////////////////////////////////////////////////////////////
//  read_formula / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadFormulaAbc : public TclCmd
{
public:
  explicit CmdLfIoReadFormulaAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadFormulaAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::abc::read_formula( file );

    return 1;
  }
}; // class CmdLfIoReadFormulaAbc

////////////////////////////////////////////////////////////////////////////
//  read_truth / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadTruthAbc : public TclCmd
{
public:
  explicit CmdLfIoReadTruthAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-x", "-f" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadTruthAbc() override = default;

  unsigned check() override
  {
    auto* option_file = getOptionOrArg( "-file" );
    auto* option_is_from_file = getOptionOrArg( "-f" );

    if ( ( option_file && !option_is_from_file ) || ( !option_file && option_is_from_file ) )
    {
      std::cerr << "-file is set with -f" << std::endl;
      assert( false );
      return 0;
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_hex = false, is_from_file = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_hex = getOptionOrArg( "-x" );
    TclOption* option_is_from_file = getOptionOrArg( "-f" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_hex->is_set_val() )
      is_hex = true;
    if ( option_is_from_file->is_set_val() )
      is_from_file = true;

    lf::logic::abc::read_truth( file, is_hex, is_from_file );

    return 1;
  }
}; // class CmdLfIoReadTruthAbc

////////////////////////////////////////////////////////////////////////////
//  read_genlib / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadGenlibAbc : public TclCmd
{
public:
  explicit CmdLfIoReadGenlibAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadGenlibAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::abc::read_genlib( file );

    return 1;
  }
}; // class CmdLfIoReadGenlibAbc

////////////////////////////////////////////////////////////////////////////
//  read_liberty / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadLibertyAbc : public TclCmd
{
public:
  explicit CmdLfIoReadLibertyAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadLibertyAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::abc::read_liberty( file );

    return 1;
  }
}; // class CmdLfIoReadLibertyAbc

////////////////////////////////////////////////////////////////////////////
//  read_verilog / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadVerilogAbc : public TclCmd
{
public:
  explicit CmdLfIoReadVerilogAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-m", "-c", "-b" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadVerilogAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_mapped = false, is_checking = false, is_barrier_buffer = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_mapped = getOptionOrArg( "-m" );
    TclOption* option_is_checking = getOptionOrArg( "-c" );
    TclOption* option_is_barrier_buffer = getOptionOrArg( "-b" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_mapped->is_set_val() )
      is_mapped = true;
    if ( option_is_checking->is_set_val() )
      is_checking = true;
    if ( option_is_barrier_buffer->is_set_val() )
      is_barrier_buffer = true;

    lf::logic::abc::read_verilog( file, is_mapped, is_checking, is_barrier_buffer );

    return 1;
  }
}; // class CmdLfIoReadVerilogAbc

////////////////////////////////////////////////////////////////////////////
//  write_aiger / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteAigerAbc : public TclCmd
{
public:
  explicit CmdLfIoWriteAigerAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-s", "-c", "-u", "-v" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteAigerAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_save_names = false, is_compact = false, is_unique = false, is_verbose = false;
    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_save_names = getOptionOrArg( "-s" );
    TclOption* option_is_compact = getOptionOrArg( "-c" );
    TclOption* option_is_unique = getOptionOrArg( "-u" );
    TclOption* option_is_verbose = getOptionOrArg( "-v" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_save_names->is_set_val() )
      is_save_names = true;
    if ( option_is_compact->is_set_val() )
      is_compact = true;
    if ( option_is_unique->is_set_val() )
      is_unique = true;
    if ( option_is_verbose->is_set_val() )
      is_verbose = true;

    lf::logic::abc::write_aiger( file, is_save_names, is_compact, is_unique, is_verbose );

    return 1;
  }
}; // class CmdLfIoWriteAigerAbc

////////////////////////////////////////////////////////////////////////////
//  write_bench / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteBenchAbc : public TclCmd
{
public:
  explicit CmdLfIoWriteBenchAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-l" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteBenchAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_lut = false;
    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_lut = getOptionOrArg( "-l" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_lut->is_set_val() )
      is_lut = true;

    lf::logic::abc::write_bench( file, is_lut );

    return 1;
  }
}; // class CmdLfIoWriteBenchAbc

////////////////////////////////////////////////////////////////////////////
//  write_blif / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteBlifAbc : public TclCmd
{
public:
  explicit CmdLfIoWriteBlifAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file", "-S" };

    std::vector<std::string> switches = {
        "-j", "a" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteBlifAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "", str_lut = "";
    bool is_special = false, is_hierarchy = false;
    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_lut_str = getOptionOrArg( "-S" );
    TclOption* option_is_special = getOptionOrArg( "-j" );
    TclOption* option_is_hierarchy = getOptionOrArg( "-a" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_lut_str->is_set_val() )
      str_lut = option_lut_str->getStringVal();

    if ( option_is_special->is_set_val() )
      is_special = true;
    if ( option_is_hierarchy->is_set_val() )
      is_hierarchy = true;

    lf::logic::abc::write_blif( file, str_lut, is_special, is_hierarchy );

    return 1;
  }
}; // class CmdLfIoWriteBlifAbc

////////////////////////////////////////////////////////////////////////////
//  write_cnf / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteCnfAbc : public TclCmd
{
public:
  explicit CmdLfIoWriteCnfAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-n", "-f", "-p", "-c", "-v" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteCnfAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_new = false, is_fast = false, is_primes = false, is_adjast = false, is_verbose = false;
    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_new = getOptionOrArg( "-n" );
    TclOption* option_is_fast = getOptionOrArg( "-f" );
    TclOption* option_is_primes = getOptionOrArg( "-p" );
    TclOption* option_is_adjast = getOptionOrArg( "-c" );
    TclOption* option_is_verbose = getOptionOrArg( "-v" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_new->is_set_val() )
      is_new = true;
    if ( option_is_fast->is_set_val() )
      is_fast = true;
    if ( option_is_primes->is_set_val() )
      is_primes = true;
    if ( option_is_adjast->is_set_val() )
      is_adjast = true;
    if ( option_is_verbose->is_set_val() )
      is_verbose = true;

    lf::logic::abc::write_cnf( file, is_new, is_fast, is_primes, is_adjast, is_verbose );

    return 1;
  }
}; // class CmdLfIoWriteCnfAbc

////////////////////////////////////////////////////////////////////////////
//  write_cnf / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteDotAbc : public TclCmd
{
public:
  explicit CmdLfIoWriteDotAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteDotAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::abc::write_dot( file );

    return 1;
  }
}; // class CmdLfIoWriteDotAbc

////////////////////////////////////////////////////////////////////////////
//  write_pla / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWritePlaAbc : public TclCmd
{
public:
  explicit CmdLfIoWritePlaAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> inumbers = {
        "-M" };

    std::vector<std::string> switches = {
        "-m" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto number : inumbers )
    {
      auto* option = new TclIntOption( number.c_str(), 1, -1 );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWritePlaAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    int M = -1;
    bool is_multi_output = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_M = getOptionOrArg( "-M" );
    TclOption* option_is_multi_output = getOptionOrArg( "-m" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_M->is_set_val() )
      M = option_M->getIntVal();
    if ( option_is_multi_output->is_set_val() )
      is_multi_output = true;

    lf::logic::abc::write_pla( file, M, is_multi_output );

    return 1;
  }
}; // class CmdLfIoWritePlaAbc

////////////////////////////////////////////////////////////////////////////
//  write_truth / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteTruthAbc : public TclCmd
{
public:
  explicit CmdLfIoWriteTruthAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {
        "-x", "-r" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteTruthAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    bool is_hex = false, is_reversing = false;
    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_is_hex = getOptionOrArg( "-x" );
    TclOption* option_is_reversing = getOptionOrArg( "-r" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_is_hex->is_set_val() )
      is_hex = true;
    if ( option_is_reversing->is_set_val() )
      is_reversing = true;

    lf::logic::abc::write_truth( file, is_hex, is_reversing );

    return 1;
  }
}; // class CmdLfIoWriteTruthAbc

////////////////////////////////////////////////////////////////////////////
//  write_verilog / abc
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteVerilogAbc : public TclCmd
{
public:
  explicit CmdLfIoWriteVerilogAbc( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> inumbers = {
        "-K" };

    std::vector<std::string> switches = {
        "-f", "-a", "-m" };

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto number : inumbers )
    {
      auto* option = new TclIntOption( number.c_str(), 1, -1 );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteVerilogAbc() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";
    int K = -1;
    bool is_fixed_format = false, is_only_ands = false, is_modules = false;

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );
    TclOption* option_K = getOptionOrArg( "-K" );
    TclOption* option_is_fixed_format = getOptionOrArg( "-f" );
    TclOption* option_is_only_ands = getOptionOrArg( "-a" );
    TclOption* option_is_modules = getOptionOrArg( "-m" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();
    if ( option_K->is_set_val() )
      K = option_K->getIntVal();
    if ( option_is_fixed_format->is_set_val() )
      is_fixed_format = true;
    if ( option_is_only_ands->is_set_val() )
      is_only_ands = true;
    if ( option_is_modules->is_set_val() )
      is_modules = true;

    lf::logic::abc::write_verilog( file, K, is_fixed_format, is_only_ands, is_modules );

    return 1;
  }
}; // class CmdLfIoWriteVerilogAbc

#pragma region IO lsils
////////////////////////////////////////////////////////////////////////////
//  read_aiger / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadAigerLsils : public TclCmd
{
public:
  explicit CmdLfIoReadAigerLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadAigerLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::read_aiger( file );

    return 1;
  }
}; // class CmdLfIoReadAigerLsils

////////////////////////////////////////////////////////////////////////////
//  read_bench / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadBenchLsils : public TclCmd
{
public:
  explicit CmdLfIoReadBenchLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadBenchLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::read_bench( file );

    return 1;
  }
}; // class CmdLfIoReadBenchLsils

////////////////////////////////////////////////////////////////////////////
//  read_blif / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadBlifLsils : public TclCmd
{
public:
  explicit CmdLfIoReadBlifLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadBlifLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::read_blif( file );

    return 1;
  }
}; // class CmdLfIoReadBlifLsils

////////////////////////////////////////////////////////////////////////////
//  read_cnf / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadCnfLsils : public TclCmd
{
public:
  explicit CmdLfIoReadCnfLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadCnfLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::read_cnf( file );

    return 1;
  }
}; // class CmdLfIoReadCnfLsils

////////////////////////////////////////////////////////////////////////////
//  read_genlib / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadGenlibLsils : public TclCmd
{
public:
  explicit CmdLfIoReadGenlibLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadGenlibLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::read_genlib( file );

    return 1;
  }
}; // class CmdLfIoReadGenlibLsils

////////////////////////////////////////////////////////////////////////////
//  read_gtech / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadGtechLsils : public TclCmd
{
public:
  explicit CmdLfIoReadGtechLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadGtechLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::read_gtech( file );

    return 1;
  }
}; // class CmdLfIoReadGtechLsils

////////////////////////////////////////////////////////////////////////////
//  read_liberty / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadLibertyLsils : public TclCmd
{
public:
  explicit CmdLfIoReadLibertyLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadLibertyLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::read_liberty( file );

    return 1;
  }
}; // class CmdLfIoReadLibertyLsils

////////////////////////////////////////////////////////////////////////////
//  read_pla / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoReadPlaLsils : public TclCmd
{
public:
  explicit CmdLfIoReadPlaLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoReadPlaLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::read_pla( file );

    return 1;
  }
}; // class CmdLfIoReadPlaLsils

////////////////////////////////////////////////////////////////////////////
//  write_aiger / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteAigerLsils : public TclCmd
{
public:
  explicit CmdLfIoWriteAigerLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteAigerLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::write_aiger( file );

    return 1;
  }
}; // class CmdLfIoWriteAigerLsils

////////////////////////////////////////////////////////////////////////////
//  write_bench / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteBenchLsils : public TclCmd
{
public:
  explicit CmdLfIoWriteBenchLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteBenchLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::write_bench( file );

    return 1;
  }
}; // class CmdLfIoWriteBenchLsils

////////////////////////////////////////////////////////////////////////////
//  write_blif / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteBlifLsils : public TclCmd
{
public:
  explicit CmdLfIoWriteBlifLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteBlifLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::write_blif( file );

    return 1;
  }
}; // class CmdLfIoWriteBlifLsils

////////////////////////////////////////////////////////////////////////////
//  write_cnf / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteCnfLsils : public TclCmd
{
public:
  explicit CmdLfIoWriteCnfLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteCnfLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::write_cnf( file );

    return 1;
  }
}; // class CmdLfIoWriteCnfLsils

////////////////////////////////////////////////////////////////////////////
//  write_dot / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteDotLsils : public TclCmd
{
public:
  explicit CmdLfIoWriteDotLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteDotLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::write_dot( file );

    return 1;
  }
}; // class CmdLfIoWriteDotLsils

////////////////////////////////////////////////////////////////////////////
//  write_verilog / lsils
////////////////////////////////////////////////////////////////////////////
class CmdLfIoWriteVerilogLsils : public TclCmd
{
public:
  explicit CmdLfIoWriteVerilogLsils( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    std::vector<std::string> strs = {
        "-file" };

    std::vector<std::string> switches = {};

    for ( auto str : strs )
    {
      auto* option = new TclStringOption( str.c_str(), 1, nullptr );
      addOption( option );
    }

    for ( auto flag : switches )
    {
      auto* option = new TclSwitchOption( flag.c_str() );
      addOption( option );
    }
  }

  ~CmdLfIoWriteVerilogLsils() override = default;

  unsigned check() override
  {
    std::vector<std::string> essential = {
        "-file" };
    for ( auto& ess : essential )
    {
      if ( !getOptionOrArg( ess.c_str() ) )
      {
        std::cerr << "Essential option " << ess << " is not set!" << std::endl;
        assert( false );
        return 0;
      }
    }
    return 1;
  }

  unsigned exec() override
  {
    if ( !check() )
      return 0;

    // init the args
    std::string file = "";

    // bind the args with the option
    TclOption* option_file = getOptionOrArg( "-file" );

    if ( option_file->is_set_val() )
      file = option_file->getStringVal();

    lf::logic::lsils::write_verilog( file );

    return 1;
  }
}; // class CmdLfIoWriteVerilogLsils

} // namespace tcl

} // namespace lf
