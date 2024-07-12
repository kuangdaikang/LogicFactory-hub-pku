#pragma once

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
  NetlistAsicManager( const std::string& config_file )
      : config_file_( config_file ),
        netlist_step_prev_( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_init ),
        netlist_step_curr_( E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_init )
  {
  }

  NetlistAsicManager( const NetlistAsicManager& ) = delete;
  NetlistAsicManager& operator=( const NetlistAsicManager& ) = delete;
  ~NetlistAsicManager() = default;

  void start()
  {
    parse_config();
  }

  void stop()
  {
  }

  /**
   * @brief update current step for the netlist manager
   */
  void update_step( E_ToolNetlistAsicType step )
  {
    netlist_step_prev_ = netlist_step_curr_;
    netlist_step_curr_ = step;
  }

private:
  void parse_config()
  {
    switch ( netlist_step_curr_ )
    {
    case E_ToolNetlistAsicType::E_NETLIST_Asic_iEDA_init:
      parse_ieda();
      break;
    default:
      assert( false );
      break;
    }
  }

  void parse_ieda()
  {
    assert( lf::utility::endsWith( config_file_, ".json" ) );
    config_ieda_ = new lf::netlist::ieda::ConfigiEDA();
    std::ifstream config_stream( config_file_ );
    nlohmann::json data = nlohmann::json::parse( config_stream );

    assert( data.contains( "design" ) );
    assert( data.contains( "liberty" ) );
    assert( data.contains( "clef" ) );
    assert( data.contains( "tlef" ) );
    assert( data.contains( "sdc" ) );

    std::string verilog_file;
    std::vector<std::string> lib_files;
    std::vector<std::string> lef_files;
    std::string tlef_file;
    std::string sdc_file;

    data.at( "design" ).get_to( verilog_file );
    data.at( "liberty" ).get_to( lib_files );
    data.at( "clef" ).get_to( lef_files );
    data.at( "tlef" ).get_to( tlef_file );
    data.at( "sdc" ).get_to( sdc_file );

    config_ieda_->set_verilog_file( verilog_file );
    config_ieda_->set_lib_files( lib_files );
    config_ieda_->set_lef_files( lef_files );
    config_ieda_->set_tlef_file( tlef_file );
    config_ieda_->set_sdc_file( sdc_file );
  }

private:
  std::string config_file_ = "";
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