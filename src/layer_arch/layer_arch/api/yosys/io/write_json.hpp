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
 *  write_json [options] [filename]
 *  otions:
 *
 * @note
 */
void write_json( const std::string& file = "", bool is_aig = false, bool is_compat_int = false )
{
  std::string script = "write_json ";
  if ( !lf::utility::endsWith( file, ".json" ) )
  {
    std::cerr << "Unmatched json suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( is_aig )
    script += " -aig ";
  if ( is_compat_int )
    script += " -compat-int ";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf