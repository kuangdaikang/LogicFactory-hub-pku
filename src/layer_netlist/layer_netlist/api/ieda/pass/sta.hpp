#pragma once

#include "layer_netlist/netlist_manager.hpp"
#include "layer_netlist/eval/profile_timing.hpp"

#include "misc/anchor.hpp"

namespace lf
{
namespace netlist
{

struct ProfileTiming;

namespace ieda
{

void init_sta( ista::TimingEngine* ista_manager )
{
  std::string verilog_file = lfNmINST->get_config_ieda()->get_verilog_file();
  std::string top_module = lfNmINST->get_config_ieda()->get_top_module();
  std::vector<std::string> lib_files = lfNmINST->get_config_ieda()->get_lib_files();
  std::vector<std::string> lef_files = lfNmINST->get_config_ieda()->get_lef_files();
  std::string tlef_file = lfNmINST->get_config_ieda()->get_tlef_file();
  std::string sdc_file = lfNmINST->get_config_ieda()->get_sdc_file();
  std::string workspace_sta = lfNmINST->get_config_ieda()->get_workspace_sta();

  ista_manager->set_design_work_space( workspace_sta.c_str() );

  ista_manager->readLiberty( lib_files );
  ista_manager->get_ista()->set_top_module_name( "top_module" );
  ista_manager->readDesign( verilog_file.c_str() );
  ista_manager->readSdc( sdc_file.c_str() );
  ista_manager->buildGraph();
  ista_manager->updateTiming();
}

/**
 * @brief
 */
void run_sta( bool is_report_timing = false )
{
  lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_STA );

  ista::TimingEngine* ista_manager = ista::TimingEngine::getOrCreateTimingEngine();

  init_sta( ista_manager );
  if ( is_report_timing )
    ista_manager->reportTiming();

  ProfileTiming* profile = lfNmINST->get_profile_timing();
  profile->set_timing_engine( ista_manager );
}

} // namespace ieda
} // namespace netlist
} // namespace lf