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
 * @brief Pass: mapping current design to And-Inverter Graph
 * @example
 *  rename old_name new_name
 *  rename
 *
 * @note
 */
void rename( const std::string& top = "" )
{
  std::string script = "rename ";

  if ( !top.empty() )
    script += " -top " + top;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf