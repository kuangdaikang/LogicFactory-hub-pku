#pragma once

#include "tcl/engine/tcl_cmd.hpp"
#include "tcl/engine/tcl_option.hpp"

#include "layer_arch/arch_manager.hpp"
#include "layer_arch/api/yosys/io/read_aiger.hpp"
#include "layer_arch/api/yosys/io/read_verilog.hpp"
#include "layer_arch/api/yosys/io/read_liberty.hpp"
#include "layer_arch/api/yosys/io/write_verilog.hpp"
#include "layer_arch/api/yosys/pass/hierarchy.hpp"
#include "layer_arch/api/yosys/pass/flattern.hpp"
#include "layer_arch/api/yosys/pass/opt.hpp"
#include "layer_arch/api/yosys/pass/aigmap.hpp"
#include "layer_arch/api/yosys/pass/abc.hpp"

namespace lf
{

namespace tcl
{
class CmdArchInit : public TclCmd
{
public:
  explicit CmdArchInit( const char* cmd_name )
      : TclCmd( cmd_name )
  {
  }

  ~CmdArchInit() override = default;

  unsigned check() override { return 1; }

  unsigned exec() override
  {
    lfAmINST->start();
    printf( "LogicFactory Layer Architecture Init!\n" );
    return 1;
  }

}; // class CmdArchInit

class CmdArchYosysReadAiger : public TclCmd
{
public:
  explicit CmdArchYosysReadAiger( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    auto* file = new TclStringOption( "-file", 1, nullptr );
    auto* module_name = new TclStringOption( "-module_name", 1, nullptr );
    auto* clk_name = new TclStringOption( "-clk_name", 1, nullptr );
    auto* map_file = new TclStringOption( "-map", 1, nullptr );
    auto* wideports = new TclSwitchOption( "-wideports" );
    auto* xaiger = new TclSwitchOption( "-xaiger" );

    addOption( file );
    addOption( module_name );
    addOption( clk_name );
    addOption( map_file );
    addOption( wideports );
    addOption( xaiger );
  }

  ~CmdArchYosysReadAiger() override = default;

  unsigned check() override
  {
    TclOption* option = getOptionOrArg( "-file" ); // the file is essential to read_aiger
    if ( !option )
    {
      std::cerr << "no file is given for read_aiger!" << std::endl;
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
      is_wideports = option_wideports->getSwitchVal();
    if ( option_xaiger->is_set_val() )
      is_xaiger = option_xaiger->getSwitchVal();

    // run the read_aiger
    lf::arch::yosys::read_aiger( file, module_name, clk_name, map_file, is_wideports, is_xaiger );

    std::cout << "Done at reading: " << file << std::endl;
    return 1;
  }

}; // class CmdArchYosysReadAiger

} // namespace tcl
} // namespace lf