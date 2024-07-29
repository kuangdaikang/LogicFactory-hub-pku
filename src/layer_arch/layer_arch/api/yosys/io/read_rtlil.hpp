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
 *  read_rtlil [options] [filename]
 *  read_rtlil -nooverwrite -overwrite -lib
 *
 * @note
 *  it could be better to load with the map file
 */
void read_rtlil( const std::string& file,
                 bool is_nooverwrite = false, bool is_overwrite = false, bool is_lib = false )
{
  std::string script = "read_rtlil ";
  if ( !lf::utility::endsWith( file, ".rtlil" ) )
  {
    std::cerr << "Unmatched rtlil suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( is_nooverwrite )
    script += " -nooverwrite ";
  if ( is_overwrite )
    script += " -overwrite ";
  if ( is_lib )
    script += " -lib ";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf