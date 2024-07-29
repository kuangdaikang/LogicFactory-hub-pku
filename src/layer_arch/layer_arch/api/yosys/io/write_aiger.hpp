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
 *  write_aiger [options] [filename]
 *  options:
 *
 * @note
 */
void write_aiger( const std::string& file,
                  bool is_ascii = false, bool is_zinit = false, bool is_miter = false, bool is_symbols = false,
                  const std::string& map = "", const std::string& vmap = "", bool is_no_startoffset = false,
                  const std::string& ymap = "",
                  bool is_imode = false, bool is_omode = false, bool is_bmode = false, bool is_lmode = false )
{
  std::string script = "write_aiger ";
  if ( !lf::utility::endsWith( file, ".aig" ) )
  {
    std::cerr << "Unmatched aig suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( is_ascii )
    script += " -ascii";
  if ( is_zinit )
    script += " -zinit";
  if ( is_miter )
    script += " -miter";
  if ( is_symbols )
    script += " -symbols";
  if ( !map.empty() )
    script += " -map " + map;
  if ( !vmap.empty() )
    script += " -vmap " + vmap;
  if ( is_no_startoffset )
    script += " -no-startoffset";
  if ( !ymap.empty() )
    script += " -ymap " + ymap;
  if ( is_imode )
    script += " -I";
  if ( is_omode )
    script += " -O";
  if ( is_bmode )
    script += " -B";
  if ( is_lmode )
    script += " -L";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf