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
 *  read_json [options] [filename]
 *  option:
 * @note
 *  it could be better to load with the map file
 */
void read_json( const std::string& file )
{
  std::string script = "read_json ";
  if ( !lf::utility::endsWith( file, ".json" ) )
  {
    std::cerr << "Unmatched json suffix type." << std::endl;
    assert( false );
    return;
  }

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf