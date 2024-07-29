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
 *  write_spice [options] [filename]
 *  otions:
 *
 * @note
 */
void write_spice( const std::string& file = "", const std::string& top = "",
                  bool is_big_endian = false, const std::string& neg_port = "", const std::string& pos_port = "", const std::string& buf = "", const std::string& nc_prefix = "", bool is_inames = false )
{
  std::string script = "write_spice ";
  if ( !lf::utility::endsWith( file, ".spice" ) )
  {
    std::cerr << "Unmatched spice suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( !top.empty() )
    script += " -top " + top;
  if ( is_big_endian )
    script += " -big_endian";
  if ( !neg_port.empty() )
    script += " -neg " + neg_port;
  if ( !pos_port.empty() )
    script += " -pos " + pos_port;
  if ( !buf.empty() )
    script += " -buf " + buf;
  if ( !nc_prefix.empty() )
    script += " -nc_prefix " + nc_prefix;
  if ( is_inames )
    script += " -inames";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf