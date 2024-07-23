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
 * @brief Pass: flattern the hierarchy design into one top module
 * @example
 *  flatten [options] [selection]
 *  flatten -nand -select
 *
 * @note
 */
void flatten( bool is_wb = false, bool is_noscopeinfo = false, bool is_scopename = false )
{
  std::string script = "flatten ";
  if ( is_wb )
    script += " -wb ";
  if ( is_noscopeinfo )
    script += " -noscopeinfo ";
  if ( is_scopename )
    script += " -scopename ";
  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf