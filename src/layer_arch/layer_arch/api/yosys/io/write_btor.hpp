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
 *  write_btor [options] [filename]
 *  otions:
 *
 * @note
 */
void write_btor( const std::string& file = "",
                 bool is_v = false, bool is_s = false, bool is_c = false, bool is_i = false, bool is_x = false,
                 const std::string& ywmap = "" )
{
  std::string script = "write_btor ";
  if ( !lf::utility::endsWith( file, ".btor" ) )
  {
    std::cerr << "Unmatched btor suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( is_v )
    script += " -v ";
  if ( is_s )
    script += " -s ";
  if ( is_c )
    script += " -c ";
  if ( is_i )
    script += " -i ";
  if ( is_x )
    script += " -x ";
  if ( !ywmap.empty() )
    script += " -ywmap " + ywmap + " ";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf