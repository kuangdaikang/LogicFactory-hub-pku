#pragma once

#include "operation/iSTA/api/TimingEngine.hh"
#include "layer_netlist/netlist_manager.hpp"

namespace lf
{
namespace netlist
{
namespace ieda
{

struct ProfileSTA
{
  std::vector<double> timings;
};

ProfileSTA run_sta( lf::netlist::NetlistAsicManager& manager )
{
  manager.update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_sta );
  ProfileSTA profile;

  std::string verilog_file = manager.get_config_ieda()->get_verilog_file();
  std::string top_module = manager.get_config_ieda()->get_top_module();
  std::vector<std::string> lib_files = manager.get_config_ieda()->get_lib_files();
  std::vector<std::string> lef_files = manager.get_config_ieda()->get_lef_files();
  std::string tlef_file = manager.get_config_ieda()->get_tlef_file();
  std::string sdc_file = manager.get_config_ieda()->get_sdc_file();
  std::string workspace_sta = manager.get_config_ieda()->get_workspace_sta();

  ista::TimingEngine* ista_manager = ista::TimingEngine::getOrCreateTimingEngine();
  // sta analysis
  ista_manager->set_design_work_space( workspace_sta );
  ista_manager->readLiberty( lib_files );
  ista_manager->readDesign( verilog_file );

  ista_manager->readSdc( sdc_file );

  ista_manager->initRcTree();
  ista_manager->buildGraph();
  ista_manager->updateTiming();

  ista_manager->reportTiming();

  // TODO: get the timing related information

  return profile;
}

} // namespace ieda
} // namespace netlist
} // namespace lf