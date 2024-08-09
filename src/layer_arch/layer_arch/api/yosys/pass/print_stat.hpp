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
 * @brief Pass: perform simple optimizations
 * @example
 *  print_stat [options] [selection]
 *  print_stat
 *
 * @note
 */
void print_stat( const std::string& top = "", const std::string& liberty = "", const std::string& tech = "", bool is_width = false, bool is_json = false )
{
  std::string script = "stat ";

  if ( !top.empty() )
    script += " -top " + top;
  if ( !liberty.empty() )
    script += " -liberty " + liberty;
  if ( !tech.empty() )
    script += " -tech " + tech;
  if ( is_width )
    script += " -width ";
  if ( is_json )
    script += " -json ";

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf