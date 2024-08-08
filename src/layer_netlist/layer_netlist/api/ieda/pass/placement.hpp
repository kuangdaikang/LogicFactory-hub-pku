#pragma once

#include "platform/data_manager/idm.h"
#include "operation/iPL/api/PLAPI.hh"
#include "layer_netlist/netlist_manager.hpp"
#include "layer_netlist/eval/profile_placement.hpp"

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

  // update the wireless information
  iPLAPIInst.get_reporter()->updateWL();
}

///////////////////////////////////////////////////////////////////////////////////////
//  EVALUATION
///////////////////////////////////////////////////////////////////////////////////////

void eval_placement( ProfilePlacement* profile )
{
  // set the palcement engine
}

///////////////////////////////////////////////////////////////////////////////////////
//  FLOW
///////////////////////////////////////////////////////////////////////////////////////
void run_placement( bool is_report_placement = false )
{
  lfAnchorINST->set_anchor( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_NETLIST_IEDA_PLACEMENT );

  std::string workspace = lfNmINST->get_config_ieda()->get_workspace_pl();
  std::string placement_config_file = lfNmINST->get_config_ieda()->get_config_placement_file();

  // nlohmann::json json_config;
  // std::ifstream file_stream( placement_config_file );
  // if ( !file_stream.is_open() )
  // {
  //   std::cerr << "Error opening the configuration file: " << placement_config_file << std::endl;
  //   assert( false );
  // }
  // file_stream >> json_config;
  // assert( json_config.contains( "PL" ) );

  // json_config.at( "PL" ).at( "pl_dir" ) = workspace;
  // file_stream.close();

  // std::ofstream file_stream_out( placement_config_file, std::ios::out | std::ios::trunc );
  // if ( file_stream_out.is_open() )
  // {
  //   file_stream_out << json_config << std::endl;
  //   file_stream_out.close();
  // }
  // else
  // {
  //   std::cerr << "Error saving modified configuration file." << std::endl;
  //   assert( false );
  // }

  init_placement( placement_config_file );

  if ( is_report_placement )
  {
    // iPLAPIInst.reportWLInfo();
  }

  ProfilePlacement* profile = lfNmINST->get_profile_place();
  eval_placement( profile );
  // dmInst->saveDef( workspace + "/ipl.def" );
}

} // namespace ieda
} // namespace netlist
} // namespace lf