// #include "layer_netlist/wrapper/to_idb_wrapper.hpp"

#include "platform/data_manager/idm.h"

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

  /// logic 2 netlist
  idm::DataManager* idb_manager = idm::DataManager::getInstance();
  // read lef
  idb_manager->get_config().set_lef_paths( lef_service_files );
  idb_manager->readLef( lef_service_files );

  // read verilog
  idb_manager->get_config().set_verilog_path( tmp_verilog );
  bool is_ok = idb_manager->readVerilog( tmp_verilog, "top_module" );

  // save verilog
  idb_manager->get_config().set_output_path( output_folder );
  idb_manager->saveVerilog( "b1_comb.idb.v" );

  logic_manager.stop();
  return 0;
}
