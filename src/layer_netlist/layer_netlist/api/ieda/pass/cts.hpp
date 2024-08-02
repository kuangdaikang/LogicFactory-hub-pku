#pragma once

#include "platform/data_manager/idm.h"
#include "operation/iSTA/api/TimingEngine.hh"
#include "operation/iCTS/api/CTSAPI.hh"
#include "layer_netlist/netlist_manager.hpp"

namespace lf
{
namespace netlist
{
namespace ieda
{

void init_cts( const std::string& file, const std::string& workspace )
{
  // cts need a clean ista engine
  ista::TimingEngine* ista_manager = ista::TimingEngine::getOrCreateTimingEngine();
  ista_manager->destroyTimingEngine();

  CTSAPIInst.init( file, workspace );
  CTSAPIInst.runCTS();
}

///////////////////////////////////////////////////////////////////////////////////////
//  FLOW
///////////////////////////////////////////////////////////////////////////////////////
void run_cts()
{

  lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_CTS );

  std::string workspace = lfNmINST->get_config_ieda()->get_workspace_cts();

  std::string config_cts_file = lfNmINST->get_config_ieda()->get_config_cts_file();

  init_cts( config_cts_file, workspace );

  dmInst->saveDef( workspace + "/icts.def" );
}

} // namespace ieda
} // namespace netlist
} // namespace lf