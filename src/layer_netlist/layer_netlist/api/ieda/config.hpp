#pragma once

#include <vector>
#include <string>

namespace lf
{
namespace netlist
{
namespace ieda
{

class ConfigiEDA
{
public:
  ConfigiEDA() = default;
  ~ConfigiEDA() = default;

  void set_lib_files( const std::vector<std::string>& files ) { lib_files_ = files; }
  void set_lib_files( const std::vector<const char*>& files ) { lib_files_ = std::vector<std::string>( files.begin(), files.end() ); }

  void set_lef_files( const std::vector<std::string>& files ) { lef_files_ = files; }
  void set_lef_files( const std::vector<const char*>& files ) { lef_files_ = std::vector<std::string>( files.begin(), files.end() ); }

  void set_tlef_file( const std::string& file ) { tlef_file_ = file; }
  void set_tlef_file( const char* file ) { tlef_file_ = file; }

  void set_verilog_file( const std::string& file ) { verilog_file_ = file; }
  void set_verilog_file( const char* file ) { verilog_file_ = file; }

  void set_sdc_file( const std::string& file ) { sdc_file_ = file; }
  void set_sdc_file( const char* file ) { sdc_file_ = file; }

  std::vector<std::string> get_lib_files() const { return lib_files_; }

  std::vector<std::string> get_lef_files() const { return lef_files_; }

  std::string get_tlef_file() const { return tlef_file_; }

  std::string get_verilog_file() const { return verilog_file_; }

  std::string get_sdc_file() const { return sdc_file_; }

private:
  std::vector<std::string> lib_files_;
  std::vector<std::string> lef_files_;
  std::string tlef_file_;
  std::string verilog_file_;
  std::string sdc_file_;
};

} // namespace ieda
} // namespace netlist
} // namespace lf