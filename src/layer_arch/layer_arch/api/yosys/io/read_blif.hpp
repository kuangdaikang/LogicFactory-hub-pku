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
 *  read_blif [options] [filename]
 *  read_blif -sop -wideports
 *
 * @note
 *  it could be better to load with the map file
 */
void read_blif( const std::string& file,
                bool is_sop_cover = false, bool is_wideports = false )
{
  std::string script = "read_blif ";
  if ( !lf::utility::endsWith( file, ".blif" ) )
  {
    std::cerr << "Unmatched blif suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( is_sop_cover )
    script += " -sop ";
  if ( is_wideports )
    script += " -wideports ";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf