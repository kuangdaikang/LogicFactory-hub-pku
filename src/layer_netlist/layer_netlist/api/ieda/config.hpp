#pragma once

#include <iostream>
#include <vector>
#include <string>

#include <chrono>
#include <iomanip>
#include <sstream>

namespace lf
{
namespace netlist
{
namespace ieda
{

class ConfigiEDA
{
public:
  ConfigiEDA()
  {
    auto now = std::chrono::system_clock::now();
    auto now_c = std::chrono::system_clock::to_time_t( now );
    std::tm now_tm = *std::localtime( &now_c );
    std::stringstream ss;
    ss << std::put_time( &now_tm, "%Y-%m-%d-%H-%M-%S" );
    timestamp_ = ss.str();
  }

  ~ConfigiEDA() = default;

  void set_lib_files( const std::vector<std::string>& files ) { lib_files_ = files; }
  void set_lib_files( const std::vector<const char*>& files ) { lib_files_ = std::vector<std::string>( files.begin(), files.end() ); }

  void set_lef_files( const std::vector<std::string>& files ) { lef_files_ = files; }
  void set_lef_files( const std::vector<const char*>& files ) { lef_files_ = std::vector<std::string>( files.begin(), files.end() ); }

  void set_tlef_file( const std::string& file ) { tlef_file_ = file; }
  void set_tlef_file( const char* file ) { tlef_file_ = file; }

  void set_verilog_file( const std::string& file ) { verilog_file_ = file; }
  void set_verilog_file( const char* file ) { verilog_file_ = file; }

  void set_top_module( const std::string& name ) { top_module_ = name; }
  void set_top_module( const char* name ) { top_module_ = name; }

  void set_sdc_file( const std::string& file ) { sdc_file_ = file; }
  void set_sdc_file( const char* file ) { sdc_file_ = file; }

  void set_config_floorplan_file( const std::string& filePath ) { config_floorplan_file_ = filePath; }
  void set_config_floorplan_file( const char* filePath ) { config_floorplan_file_ = filePath; }

  void set_config_pdn_file( const std::string& filePath ) { config_pdn_file_ = filePath; }
  void set_config_pdn_file( const char* filePath ) { config_pdn_file_ = filePath; }

  void set_config_placement_file( const std::string& filePath ) { config_placement_file_ = filePath; }
  void set_config_placement_file( const char* filePath ) { config_placement_file_ = filePath; }

  void set_config_cts_file( const std::string& filePath ) { config_cts_file_ = filePath; }
  void set_config_cts_file( const char* filePath ) { config_cts_file_ = filePath; }

  void set_config_routing_file( const std::string& filePath ) { config_routing_file_ = filePath; }
  void set_config_routing_file( const char* filePath ) { config_routing_file_ = filePath; }

  void set_workspace( const std::string& file ) { workspace_ = file; }
  void set_workspace( const char* file ) { workspace_ = file; }

  std::vector<std::string> get_lib_files() const { return lib_files_; }

  std::vector<std::string> get_lef_files() const { return lef_files_; }

  std::string get_tlef_file() const { return tlef_file_; }

  std::string get_verilog_file() const { return verilog_file_; }

  std::string get_top_module() const { return top_module_; }

  std::string get_sdc_file() const { return sdc_file_; }

  std::string get_config_floorplan_file() const { return config_floorplan_file_; }

  std::string get_config_pdn_file() const { return config_pdn_file_; }

  std::string get_config_placement_file() const { return config_placement_file_; }

  std::string get_config_cts_file() const { return config_cts_file_; }

  std::string get_config_routing_file() const { return config_routing_file_; }

  std::string get_workspace() const { return workspace_ + "/" + timestamp_ + "/"; }

  std::string get_workspace_sta() const { return get_workspace() + "/sta/"; }

  std::string get_workspace_fp() const { return get_workspace() + "/fp/"; }

  std::string get_workspace_pl() const { return get_workspace() + "/pl/"; }

  std::string get_workspace_cts() const { return get_workspace() + "/cts/"; }

  std::string get_workspace_rt() const { return get_workspace() + "/rt/"; }

private:
  ///////////////////////////
  //    inputs
  ///////////////////////////
  std::vector<std::string> lib_files_;
  std::vector<std::string> lef_files_;
  std::string tlef_file_;
  std::string verilog_file_;
  std::string top_module_;
  std::string sdc_file_;

  std::string config_floorplan_file_;
  std::string config_pdn_file_;
  std::string config_placement_file_;
  std::string config_cts_file_;
  std::string config_routing_file_;

  ///////////////////////////
  //    output
  ///////////////////////////
  std::string workspace_;
  std::string timestamp_;
};

} // namespace ieda
} // namespace netlist
} // namespace lf