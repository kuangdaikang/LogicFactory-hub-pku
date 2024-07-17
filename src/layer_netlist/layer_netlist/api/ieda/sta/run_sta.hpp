#pragma once

#include "operation/iSTA/api/TimingEngine.hh"
#include "layer_netlist/netlist_manager.hpp"

namespace lf
{
namespace netlist
{
namespace ieda
{

///////////////////////////////////////////////////////////////////////////////////////
//  STA
///////////////////////////////////////////////////////////////////////////////////////

void init_sta( ista::TimingEngine* ista_manager )
{
}

///////////////////////////////////////////////////////////////////////////////////////
//  EVALUATION
///////////////////////////////////////////////////////////////////////////////////////
struct ProfileSTA
{
  // TODO: get the profiles of current design
  std::vector<double> timings;
};

ProfileSTA eval_sta( ista::TimingEngine* ista_manager )
{
  ProfileSTA profile;

  return profile;
}

///////////////////////////////////////////////////////////////////////////////////////
//  FLOW
///////////////////////////////////////////////////////////////////////////////////////
ProfileSTA run_sta( )
{
  lfNamINST->update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_sta );

  std::string verilog_file = lfNamINST->get_config_ieda()->get_verilog_file();
  std::string top_module = lfNamINST->get_config_ieda()->get_top_module();
  std::vector<std::string> lib_files = lfNamINST->get_config_ieda()->get_lib_files();
  std::vector<std::string> lef_files = lfNamINST->get_config_ieda()->get_lef_files();
  std::string tlef_file = lfNamINST->get_config_ieda()->get_tlef_file();
  std::string sdc_file = lfNamINST->get_config_ieda()->get_sdc_file();
  std::string workspace_sta = lfNamINST->get_config_ieda()->get_workspace_sta();

  ista::TimingEngine* ista_manager = ista::TimingEngine::getOrCreateTimingEngine();

  init_sta( ista_manager );

  ista_manager->set_design_work_space( workspace_sta.c_str() );
  ista_manager->readLiberty( lib_files );
  ista_manager->readDesign( verilog_file.c_str() );
  ista_manager->readSdc( sdc_file.c_str() );
  ista_manager->initRcTree();
  ista_manager->buildGraph();
  ista_manager->updateTiming();

  return eval_sta( ista_manager );
}

} // namespace ieda
} // namespace netlist
} // namespace lf