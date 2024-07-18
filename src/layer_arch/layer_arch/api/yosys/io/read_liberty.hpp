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
 * @brief Read the liberty file into the current design.
 * @example
 *  read_liberty [options] [filename]
 *  options: -lib -wb -nooverwrite -overwrite -ignore_miss_func -ignore_miss_dir -ignore_miss_data_latch -setattr <attribute_name>
 *
 * @note
 *  it is better to read the merged standard cell liberty file
 */
void read_liberty( const std::string& file_lib,
                   bool is_lib = false, bool is_wb = false, bool is_nooverwrite = false, bool is_overwrite = false, bool is_ignore_miss_func = false, bool is_ignore_miss_dir = false, bool is_ignore_miss_data_latch = false,
                   const std::string& setattr = "" )
{
  std::string script = "read_liberty ";
  if ( !lf::utility::endsWith( file_lib, ".lib" ) )
  {
    std::cerr << "Unmatched lib suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( is_lib )
    script += " -lib ";
  if ( is_wb )
    script += " -wb ";
  if ( is_nooverwrite )
    script += " -nooverwrite ";
  if ( is_overwrite )
    script += " -overwrite ";
  if ( is_ignore_miss_func )
    script += " -ignore_miss_func ";
  if ( is_ignore_miss_dir )
    script += " -ignore_miss_dir ";
  if ( is_ignore_miss_data_latch )
    script += " -ignore_miss_data_latch ";
  if ( !setattr.empty() )
    script += " -setattr " + setattr;

  script += " " + file_lib;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf