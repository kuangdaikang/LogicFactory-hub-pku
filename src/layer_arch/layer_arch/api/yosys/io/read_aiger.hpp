#pragma once

#include "layer_arch/arch_manager.hpp"
#include "utility/string.hpp"

#include <cstdio>
#include <string>
#include <assert.h>

namespace lf
{

namespace arch
{

namespace yosys
{

/**
 * @brief Reads aig file into the current design.
 * @example
 *  read_aiger [options] [filename]
 *  read_aiger -module_name <module_name> -clk_name <wire_name> -map <filename> -wideports -xaiger
 *
 * @note
 *  it could be better to load with the map file
 */
void read_aiger( const std::string& file_aiger,
                 const std::string& module_name = "", const std::string& clk_name = "", const std::string& file_map = "",
                 bool is_wideports = false, bool is_xaiger = false )
{
  std::string script = "read_aiger ";
  if ( !lf::utility::endsWith( file_aiger, ".aig" ) )
  {
    std::cerr << "Unmatched aig suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( !module_name.empty() )
    script += " -module_name " + module_name;
  if ( !clk_name.empty() )
    script += " -clk_name " + clk_name;
  if ( !file_map.empty() )
    script += " -map " + file_map;
  if ( is_wideports )
    script += " -wideports ";
  if ( is_xaiger )
    script += " -xaiger ";

  script += " " + file_aiger;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf