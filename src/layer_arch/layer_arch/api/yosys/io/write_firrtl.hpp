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
 * @brief Write the current design into aig file .
 * @example
 *  write_firrtl [options] [filename]
 *  otions:
 *
 * @note
 */
void write_firrtl( const std::string& file = "" )
{
  std::string script = "write_firrtl ";
  if ( !lf::utility::endsWith( file, ".firrtl" ) )
  {
    std::cerr << "Unmatched firrtl suffix type." << std::endl;
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