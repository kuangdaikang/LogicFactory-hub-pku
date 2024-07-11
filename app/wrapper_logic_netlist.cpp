
// idb data manager
#include "platform/data_manager/idm.h"

// ista
#include "operation/iSTA/api/TimingEngine.hh"
#include "operation/iSTA/api/TimingIDBAdapter.hh"

// iFP
#include "operation/iFP/api/ifp_api.h"
#include "operation/iPDN/api/ipdn_api.h"

// iPL
#include "operation/iPL/api/PLAPI.hh"

// iRT
#include "operation/iRT/interface/RTInterface.hpp"

#include "layer_logic/logic_manager.hpp"

#include "layer_logic/io/read_aiger.hpp"
#include "layer_logic/io/read_liberty.hpp"

#include "layer_logic/api/abc/map/map_asic.hpp"
#include "layer_logic/api/abc/io/write_verilog.hpp"

#include "utility/file.hpp"
#include "utility/string.hpp"

int main( int argc, char** argv )
{
  std::string aiger = std::string( argv[1] );
  std::string liberty = std::string( argv[2] );
  std::string lef_service_folder = std::string( argv[3] );
  std::string output_folder = std::string( argv[4] );

  // load tlef file first
  std::vector<const char*> lib_files = {
      "/workspace/LogicFactory/techlib/foundry/sky130/lib/sky130_dummy_io.lib",
      "/workspace/LogicFactory/techlib/foundry/sky130/lib/sky130_fd_sc_hs__tt_025C_1v80.lib",
      "/workspace/LogicFactory/techlib/foundry/sky130/lib/sky130_sram_1rw1r_128x256_8_TT_1p8V_25C.lib",
      "/workspace/LogicFactory/techlib/foundry/sky130/lib/sky130_sram_1rw1r_64x256_8_TT_1p8V_25C.lib",
      "/workspace/LogicFactory/techlib/foundry/sky130/lib/sky130_sram_1rw1r_44x64_8_TT_1p8V_25C.lib",
      "/workspace/LogicFactory/techlib/foundry/sky130/lib/sky130_sram_1rw1r_80x64_8_TT_1p8V_25C.lib" };

  const char* sdc_file = "/workspace/LogicFactory/toolkit/iEDA/scripts/foundry/sky130/sdc/default.sdc";

  // load tlef file first
  std::vector<std::string> lef_service_files = {
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_fd_sc_hs.tlef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_fd_sc_hs_merged.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__com_bus_slice_10um.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__com_bus_slice_1um.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__com_bus_slice_20um.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__com_bus_slice_5um.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__connect_vcchib_vccd_and_vswitch_vddio_slice_20um.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__corner_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__disconnect_vccd_slice_5um.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__disconnect_vdda_slice_5um.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__gpiov2_pad_wrapped.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vccd_hvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vccd_lvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vdda_hvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vdda_lvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vddio_hvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vddio_lvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vssa_hvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vssa_lvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vssd_hvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vssd_lvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vssio_hvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_ef_io__vssio_lvc_pad.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_fd_io__top_xres4v2.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130io_fill.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_sram_1rw1r_128x256_8.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_sram_1rw1r_44x64_8.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_sram_1rw1r_64x256_8.lef",
      "/workspace/LogicFactory/techlib/foundry/sky130/lef/sky130_sram_1rw1r_80x64_8.lef" };

  std::string tmp_verilog = "/workspace/LogicFactory/tmp/lf_" + lf::utility::genRandomName( 8 ) + "_abc.v";

  /// logic technology mapping file
  lf::logic::LogicManager logic_manager;
  logic_manager.start();

  lf::logic::read_aiger( logic_manager, aiger );
  lf::logic::read_liberty( logic_manager, liberty );

  logic_manager.update_logic( lf::logic::E_ToolLogicType::E_LOGIC_ABC_AIG ); // convert the aig to ABC frame

  // technology mapping
  lf::logic::abc::map_asic( logic_manager );
  lf::logic::abc::write_verilog( logic_manager, tmp_verilog );

  //////////////////////////////////
  // idb
  //////////////////////////////////
  // read lef
  dmInst->get_config().set_lef_paths( lef_service_files );
  dmInst->readLef( lef_service_files );

  // read verilog
  dmInst->get_config().set_verilog_path( tmp_verilog );
  bool is_ok = dmInst->readVerilog( tmp_verilog, "top_module" );

  // save verilog
  dmInst->get_config().set_output_path( output_folder );
  dmInst->saveVerilog( "/workspace/LogicFactory/tmp/b1_comb.idb.v" );

  //////////////////////////////////
  // sta
  //////////////////////////////////
  const char* sta_workspace = "/workspace/LogicFactory/tmp/";
  // sta analysis
  ista::TimingEngine* ista_manager = ista::TimingEngine::getOrCreateTimingEngine();
  ista_manager->set_design_work_space( sta_workspace );
  ista_manager->readLiberty( lib_files );

  auto ista_adapter = std::make_unique<ista::TimingIDBAdapter>( ista_manager->get_ista() );
  ista_adapter->set_idb( dmInst->get_idb_builder() );
  ista_adapter->convertDBToTimingNetlist();

  ista_manager->set_db_adapter( std::move( ista_adapter ) );
  ista_manager->readSdc( sdc_file );

  ista_manager->initRcTree();
  ista_manager->buildGraph();
  ista_manager->updateTiming();

  ista_manager->reportTiming();

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
  dmInst->saveDef( "/workspace/LogicFactory/tmp/ifp.def" );

  //////////////////////////////////
  // placement
  //////////////////////////////////
  std::string pl_config = "/workspace/LogicFactory/toolkit/iEDA/scripts/design/sky130_gcd/iEDA_config/pl_default_config.json";
  iPLAPIInst.initAPI( pl_config, dmInst->get_idb_builder() );
  iPLAPIInst.initTimingEval();
  iPLAPIInst.runFlow();
  dmInst->saveDef( "/workspace/LogicFactory/tmp/ipl.def" );

  //////////////////////////////////
  // routing
  //////////////////////////////////
  std::map<std::string, std::any> config_map = {
      { "-temp_directory_path", std::string( "/workspace/LogicFactory/tmp/" ) },
      { "-bottom_routing_layer", std::string( "met1" ) },
      { "-top_routing_layer", std::string( "met4" ) },
      { "-thread_number", int32_t( 64 ) } };
  RTI.initRT( config_map );
  RTI.runRT();
  dmInst->saveDef( "/workspace/LogicFactory/tmp/irt.def" );

  logic_manager.stop();
  return 0;
}
