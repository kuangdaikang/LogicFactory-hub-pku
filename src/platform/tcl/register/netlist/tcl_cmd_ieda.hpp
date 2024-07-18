#pragma once

#include "tcl/engine/tcl_cmd.hpp"

#include "layer_netlist/netlist_manager.hpp"
#include "layer_netlist/api/ieda/init/run_init.hpp"
#include "layer_netlist/api/ieda/floorplan/run_floorplan.hpp"
#include "layer_netlist/api/ieda/placement/run_placement.hpp"
#include "layer_netlist/api/ieda/cts/run_cts.hpp"
#include "layer_netlist/api/ieda/sta/run_sta.hpp"
#include "layer_netlist/api/ieda/routing/run_routing.hpp"

namespace lf
{

namespace tcl
{

class CmdTestAAA : public TclCmd
{
public:
  explicit CmdTestAAA( const char* cmd_name )
      : TclCmd( cmd_name )
  {
  }

  ~CmdTestAAA() override = default;

  unsigned check() override { return 1; }

  unsigned exec() override
  {
    printf( "CmdTestAAA test!\n" );
    return 1;
  }

}; // class CmdTest

class CmdiEDAInit : public TclCmd
{
public:
  explicit CmdiEDAInit( const char* cmd_name )
      : TclCmd( cmd_name )
  {
    auto* config_input_name = new TclStringOption( TCL_iEDA_INPUT_CONFIG, 1, nullptr );
    auto* config_output_name = new TclStringOption( TCL_iEDA_OUTPUT_CONFIG, 1, nullptr );
    addOption( config_input_name );
    addOption( config_output_name );
  }

  ~CmdiEDAInit() override = default;

  unsigned check() override { return 1; }

  unsigned exec() override
  {
    if ( !check() )
    {
      return 0;
    }

    TclOption* option_input = getOptionOrArg( TCL_iEDA_INPUT_CONFIG );
    TclOption* option_output = getOptionOrArg( TCL_iEDA_OUTPUT_CONFIG );

    auto path_input = option_input->getStringVal() != nullptr ? option_input->getStringVal() : "";
    auto path_ouput = option_output->getStringVal() != nullptr ? option_output->getStringVal() : "";

    lfNamINST->init_config( path_input, path_ouput );
    lf::netlist::ieda::run_init();
    return 1;
  }

}; // class CmdiEDAInit

class CmdiEDAFloorplan : public TclCmd
{
public:
  explicit CmdiEDAFloorplan( const char* cmd_name )
      : TclCmd( cmd_name )
  {
  }

  ~CmdiEDAFloorplan() override = default;

  unsigned check() override { return 1; }

  unsigned exec() override
  {
    if ( !check() )
    {
      return 0;
    }
    lf::netlist::ieda::run_floorplan();
    return 1;
  }

}; // class CmdiEDAFloorplan

class CmdiEDAPlacement : public TclCmd
{
public:
  explicit CmdiEDAPlacement( const char* cmd_name )
      : TclCmd( cmd_name )
  {
  }

  ~CmdiEDAPlacement() override = default;

  unsigned check() override { return 1; }

  unsigned exec() override
  {
    if ( !check() )
    {
      return 0;
    }
    lf::netlist::ieda::run_placement();
    return 1;
  }

}; // class CmdiEDAPlacement

class CmdiEDACts : public TclCmd
{
public:
  explicit CmdiEDACts( const char* cmd_name )
      : TclCmd( cmd_name )
  {
  }

  ~CmdiEDACts() override = default;

  unsigned check() override { return 1; }

  unsigned exec() override
  {
    if ( !check() )
    {
      return 0;
    }
    lf::netlist::ieda::run_cts();
    return 1;
  }

}; // class CmdiEDACts

class CmdiEDASta : public TclCmd
{
public:
  explicit CmdiEDASta( const char* cmd_name )
      : TclCmd( cmd_name )
  {
  }

  ~CmdiEDASta() override = default;

  unsigned check() override { return 1; }

  unsigned exec() override
  {
    if ( !check() )
    {
      return 0;
    }
    lf::netlist::ieda::run_sta();
    return 1;
  }

}; // class CmdiEDASta

class CmdiEDARouting : public TclCmd
{
public:
  explicit CmdiEDARouting( const char* cmd_name )
      : TclCmd( cmd_name )
  {
  }

  ~CmdiEDARouting() override = default;

  unsigned check() override { return 1; }

  unsigned exec() override
  {
    if ( !check() )
    {
      return 0;
    }
    lf::netlist::ieda::run_routing();
    return 1;
  }

}; // class CmdiEDARouting

} // namespace tcl

} // namespace lf