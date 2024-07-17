#pragma once

#include "platform/data_manager/idm.h"
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
  CTSAPIInst.init( file, workspace );
  CTSAPIInst.runCTS();
}

struct ProfileCts
{
  std::vector<double> areas;
};

ProfileCts eval_cts()
{
  ProfileCts profile;

  return profile;
}

///////////////////////////////////////////////////////////////////////////////////////
//  FLOW
///////////////////////////////////////////////////////////////////////////////////////
ProfileCts run_cts(  )
{
  lfNamINST->update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_cts );

  std::string workspace = lfNamINST->get_config_ieda()->get_workspace_cts();

  std::string config_cts_file = lfNamINST->get_config_ieda()->get_config_cts_file();

  init_cts( config_cts_file, workspace );

  dmInst->saveDef( workspace + "/icts.def" );
  return eval_cts();
}

} // namespace ieda
} // namespace netlist
} // namespace lf