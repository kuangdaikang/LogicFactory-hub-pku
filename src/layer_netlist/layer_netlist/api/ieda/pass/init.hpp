#pragma once
#include "platform/data_manager/idm.h"
#include "layer_netlist/netlist_manager.hpp"

namespace lf
{
namespace netlist
{
namespace ieda
{

/**
 * @brief
 * @note
 *  this command is after config
 */
void run_init()
{
  lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_INIT );

  std::string verilog_file = lfNmINST->get_config_ieda()->get_verilog_file();
  std::string top_module = lfNmINST->get_config_ieda()->get_top_module();
  std::vector<std::string> lib_files = lfNmINST->get_config_ieda()->get_lib_files();
  std::vector<std::string> lef_files = lfNmINST->get_config_ieda()->get_lef_files();
  std::string tlef_file = lfNmINST->get_config_ieda()->get_tlef_file();
  std::string sdc_file = lfNmINST->get_config_ieda()->get_sdc_file();

  std::string workspace = lfNmINST->get_config_ieda()->get_workspace();

  dmInst->get_config().set_verilog_path( verilog_file );
  dmInst->get_config().set_lib_paths( lib_files );
  dmInst->get_config().set_tech_lef_path( tlef_file );
  dmInst->get_config().set_lef_paths( lef_files );
  dmInst->get_config().set_sdc_path( sdc_file );
  dmInst->get_config().set_output_path( workspace );

  // read tech_lef / cell_lef, and tech_lef must before cell_lef
  dmInst->readLef( { tlef_file }, true );
  dmInst->readLef( lef_files, false );

  // read verilog
  dmInst->readVerilog( verilog_file, top_module );

  // sync the unit of layout for dbu = -1 bugs
  dmInst->get_idb_design()->set_units( dmInst->get_idb_layout()->get_units() );
  // dmInst->saveVerilog( workspace + "/init.v" );
  // dmInst->saveDef( workspace + "/init.def" );
}

} // namespace ieda
} // namespace netlist
} // namespace lf