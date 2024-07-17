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
ProfilePlacement run_placement()
{
  lfNamINST->update_step( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_place );

  std::string workspace = lfNamINST->get_config_ieda()->get_workspace_pl();
  std::string placement_config_file = lfNamINST->get_config_ieda()->get_config_placement_file();

  std::ifstream file_stream( placement_config_file );
  if ( !file_stream.is_open() )
  {
    std::cerr << "Error opening the configuration file: " << placement_config_file << std::endl;
    assert( false );
  }

  nlohmann::json json_config;
  file_stream >> json_config;
  assert( json_config.contains( "PL" ) );

  json_config.at( "PL" ).at( "pl_dir" ) = workspace;
  file_stream.close();

  std::ofstream file_stream_out( placement_config_file, std::ios::out | std::ios::trunc );
  if ( file_stream_out.is_open() )
  {
    file_stream_out << json_config << std::endl;
    file_stream_out.close();
  }
  else
  {
    std::cerr << "Error saving modified configuration file." << std::endl;
    assert( false );
  }

  init_placement( placement_config_file );

  dmInst->saveDef( workspace + "/ipl.def" );

  return eval_placement();
}

} // namespace ieda
} // namespace netlist
} // namespace lf