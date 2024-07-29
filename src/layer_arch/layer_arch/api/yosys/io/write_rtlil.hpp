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
 *  write_rtlil [options] [filename]
 *  otions:
 *
 * @note
 */
void write_rtlil( const std::string& file = "", bool is_selected = false )
{
  std::string script = "write_rtlil ";
  if ( !lf::utility::endsWith( file, ".rtlil" ) )
  {
    std::cerr << "Unmatched rtlil suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( is_selected )
    script += " -selected ";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf