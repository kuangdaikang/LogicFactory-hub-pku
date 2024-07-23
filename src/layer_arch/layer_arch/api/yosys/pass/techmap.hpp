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
 * @brief Pass: generic technology mapper
 * @example
 *  opt [options] [selection]
 *  opt
 *
 * @note
 */
void techmap( const std::string& file_map = "",
              bool is_extern = false, int max_iter = -1, bool is_recursive = false, bool is_autoproc = false, bool is_wb = false, bool is_assert = false )
{
  std::string script = "techmap ";

  if ( !file_map.empty() )
    script += " -map " + file_map;
  if ( is_extern )
    script += " -extern ";
  if ( max_iter > 0 )
    script += " -max_iter " + std::to_string( max_iter );
  if ( is_recursive )
    script += " -recursive ";
  if ( is_autoproc )
    script += " -extern ";
  if ( is_wb )
    script += " -wb ";
  if ( is_assert )
    script += " -assert ";

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf