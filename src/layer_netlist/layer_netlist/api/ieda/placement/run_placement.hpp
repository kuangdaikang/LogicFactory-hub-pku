#pragma once

#include "platform/data_manager/idm.h"
#include "operation/iPL/api/PLAPI.hh"
#include "layer_netlist/netlist_manager.hpp"

namespace lf
{
namespace netlist
{
namespace ieda
{

///////////////////////////////////////////////////////////////////////////////////////
//  PLACEMENT
///////////////////////////////////////////////////////////////////////////////////////
void init_placement( const std::string& file )
{
  if ( !lf::utility::endsWith( file, ".json" ) )
  {
    std::cerr << "config is not end with .json!" << std::endl;
    assert( false );
  }

  iPLAPIInst.initAPI( file, dmInst->get_idb_builder() );
  iPLAPIInst.initTimingEval();
  iPLAPIInst.runFlow();
}

///////////////////////////////////////////////////////////////////////////////////////
//  EVALUATION
///////////////////////////////////////////////////////////////////////////////////////
struct ProfilePlacement
{
  std::vector<double> areas;
};

ProfilePlacement eval_placement()
{
  ProfilePlacement profile;

  return profile;
}

///////////////////////////////////////////////////////////////////////////////////////
//  FLOW
///////////////////////////////////////////////////////////////////////////////////////
ProfilePlacement run_placement( lf::netlist::NetlistAsicManager& manager )
{
  manager.update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_place );

  std::string workspace = manager.get_config_ieda()->get_workspace_pl();
  std::string placement_config_file = manager.get_config_ieda()->get_config_placement_file();

  init_placement( placement_config_file );

  dmInst->saveDef( workspace + "/ipl.def" );

  return eval_placement();
}

} // namespace ieda
} // namespace netlist
} // namespace lf