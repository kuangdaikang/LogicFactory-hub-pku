#pragma once

#include "platform/data_manager/idm.h"
#include "layer_netlist/api/ieda/config.hpp"

#include "nlohmann/json.hpp"

#include "utility/string.hpp"

#include <fstream>
#include <assert.h>

namespace lf
{

namespace netlist
{

enum class E_ToolNetlistAsicType
{
  E_NETLIST_Asic_iEDA_init,
  E_NETLIST_Asic_iEDA_sta,
  E_NETLIST_Asic_iEDA_fp,
  E_NETLIST_Asic_iEDA_cts,
  E_NETLIST_Asic_iEDA_place,
  E_NETLIST_Asic_iEDA_route,
  E_NETLIST_Asic_iEDA_drc
};

/**
 * @class NetlistAsicManager
 * @brief
 *
 * @code
 */
class NetlistAsicManager
{
public:
  NetlistAsicManager()
      : netlist_step_prev_( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_init ),
        netlist_step_curr_( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_init )
  {
  }

  NetlistAsicManager( const NetlistAsicManager& ) = delete;
  NetlistAsicManager& operator=( const NetlistAsicManager& ) = delete;
  ~NetlistAsicManager() = default;

  void start()
  {
  }

  void stop()
  {
  }

  /**
   * @brief
   */
  void init_config( const std::string& config_input, const std::string& config_output )
  {
    parse_config( config_input, config_output );
  }

  /**
   * @brief update current step for the netlist manager
   */
  void update_step( E_ToolNetlistAsicType step )
  {
    netlist_step_prev_ = netlist_step_curr_;
    netlist_step_curr_ = step;
  }

  lf::netlist::ieda::ConfigiEDA* get_config_ieda() const { return config_ieda_; }

private:
  void parse_config( const std::string& config_input, const std::string& config_output )
  {
    switch ( netlist_step_curr_ )
    {
    case E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_init:
      parse_ieda( config_input, config_output );
      break;
    default:
      assert( false );
      break;
    }
  }

  void parse_ieda( const std::string& config_input, const std::string& config_output )
  {
    assert( lf::utility::endsWith( config_input, ".json" ) );
    assert( lf::utility::endsWith( config_output, ".json" ) );
    config_ieda_ = new lf::netlist::ieda::ConfigiEDA();
    std::ifstream config_input_stream( config_input );
    nlohmann::json data_input = nlohmann::json::parse( config_input_stream );

    assert( data_input.contains( "design" ) );
    assert( data_input.contains( "top_module" ) );
    assert( data_input.contains( "liberty" ) );
    assert( data_input.contains( "clef" ) );
    assert( data_input.contains( "tlef" ) );
    assert( data_input.contains( "sdc" ) );
    assert( data_input.contains( "flow" ) );

    std::string verilog_file;
    std::string top_module;
    std::vector<std::string> lib_files;
    std::vector<std::string> lef_files;
    std::string tlef_file;
    std::string sdc_file;

    std::string config_floorplan_file;
    std::string config_pdn_file;
    std::string config_placement_file;
    std::string config_cts_file;
    std::string config_routing_file;

    data_input.at( "design" ).get_to( verilog_file );
    data_input.at( "top_module" ).get_to( top_module );
    data_input.at( "liberty" ).get_to( lib_files );
    data_input.at( "clef" ).get_to( lef_files );
    data_input.at( "tlef" ).get_to( tlef_file );
    data_input.at( "sdc" ).get_to( sdc_file );
    data_input.at( "flow" ).at( "floorplan" ).get_to( config_floorplan_file );
    data_input.at( "flow" ).at( "pdn" ).get_to( config_pdn_file );
    data_input.at( "flow" ).at( "placement" ).get_to( config_placement_file );
    data_input.at( "flow" ).at( "cts" ).get_to( config_cts_file );
    data_input.at( "flow" ).at( "routing" ).get_to( config_routing_file );

    config_ieda_->set_verilog_file( verilog_file );
    config_ieda_->set_top_module( top_module );
    config_ieda_->set_lib_files( lib_files );
    config_ieda_->set_lef_files( lef_files );
    config_ieda_->set_tlef_file( tlef_file );
    config_ieda_->set_sdc_file( sdc_file );

    config_ieda_->set_config_floorplan_file( config_floorplan_file );
    config_ieda_->set_config_pdn_file( config_pdn_file );
    config_ieda_->set_config_placement_file( config_placement_file );
    config_ieda_->set_config_cts_file( config_cts_file );
    config_ieda_->set_config_routing_file( config_routing_file );

    std::ifstream config_output_stream( config_output );
    nlohmann::json data_output = nlohmann::json::parse( config_output_stream );

    std::string workspace;
    data_input.at( "workspace" ).get_to( workspace );
    config_ieda_->set_workspace( workspace );
  }

private:
  lf::netlist::ieda::ConfigiEDA* config_ieda_ = nullptr;

  E_ToolNetlistAsicType netlist_step_prev_;
  E_ToolNetlistAsicType netlist_step_curr_;

}; // class NelistAsicManager

enum class E_ToolNetlistFpgaType
{
  E_NETLIST_Fpga_VPR_init,
  E_NETLIST_Fpga_VPR_place,
  E_NETLIST_Fpga_VPR_route,
  E_NETLIST_Fpga_VPR_bitstream
};

} // namespace netlist

} // namespace lf