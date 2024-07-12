#pragma once

#include "platform/data_manager/idm.h"
#include "operation/iFP/api/ifp_api.h"
#include "operation/iPDN/api/ipdn_api.h"
#include "layer_netlist/netlist_manager.hpp"

namespace lf
{
namespace netlist
{
namespace ieda
{

struct ProfileFloorplan
{
  std::vector<double> areas;
};

ProfileFloorplan run_floorplan( lf::netlist::NetlistAsicManager& manager )
{
  manager.update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_fp );
  ProfileFloorplan profile;

  std::string verilog_file = manager.get_config_ieda()->get_verilog_file();
  std::string top_module = manager.get_config_ieda()->get_top_module();
  std::vector<std::string> lib_files = manager.get_config_ieda()->get_lib_files();
  std::vector<std::string> lef_files = manager.get_config_ieda()->get_lef_files();
  std::string tlef_file = manager.get_config_ieda()->get_tlef_file();
  std::string sdc_file = manager.get_config_ieda()->get_sdc_file();
  std::string workspace = manager.get_config_ieda()->get_workspace_fp();

  //////////////////////////////////
  // floorplan
  //////////////////////////////////
  fpApiInst->initDie( 0.0f, 0.0f, 149.96f, 150.128f );
  fpApiInst->initCore( 9.996f, 10.08f, 139.964f, 140.048f, "unit", "unit", "unit" );
  fpApiInst->makeTracks( "li1", 240, 480, 185, 370 );
  fpApiInst->makeTracks( "met1", 185, 370, 185, 370 );
  fpApiInst->makeTracks( "met2", 240, 480, 240, 480 );
  fpApiInst->makeTracks( "met3", 370, 740, 370, 740 );
  fpApiInst->makeTracks( "met4", 480, 960, 480, 960 );
  fpApiInst->makeTracks( "met5", 185, 3330, 185, 3330 );

  // palce IO port
  fpApiInst->autoPlacePins( "met4", 2000, 2000 );

  // tap cell
  // TODO: this is not work for CTS
  fpApiInst->tapCells( 14.0f, "sky130_fd_sc_hs__tap_1", "sky130_fd_sc_hs__fill_1" );

  // PDN
  pdnApiInst->addIOPin( "", "VDD", "INOUT", 1 );
  pdnApiInst->addIOPin( "", "VSS", "INOUT", 0 );

  pdnApiInst->globalConnect( "VDD", "VPWR", 1 );
  pdnApiInst->globalConnect( "VDD", "VPB", 1 );
  pdnApiInst->globalConnect( "VDD", "vdd", 1 );
  pdnApiInst->globalConnect( "VSS", "VGND", 0 );
  pdnApiInst->globalConnect( "VSS", "VNB", 0 );
  pdnApiInst->globalConnect( "VSS", "gnd", 0 );

  pdnApiInst->createGrid( "VDD", "VSS", "met1", 0.48f, 0.0f );

  pdnApiInst->createStripe( "VDD", "VSS", "met4", 1.60f, 27.14f, 13.57 );
  pdnApiInst->createStripe( "VDD", "VSS", "met5", 1.60f, 27.20f, 13.60 );

  std::vector<std::string> layerlist = { "met1", "met4", "met4", "met5" };
  pdnApiInst->connectLayerList( layerlist );

  // set clock net
  dmInst->setNetType( "clk", "CLOCK" );

  // save def
  dmInst->saveDef( workspace + "/ifp.def" );

  // TODO: get the timing related information
  return profile;
}

} // namespace ieda
} // namespace netlist
} // namespace lf