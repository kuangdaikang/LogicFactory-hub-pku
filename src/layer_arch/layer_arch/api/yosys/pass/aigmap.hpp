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
 *  aigmap [options] [selection]
 *  aigmap -nand -select
 *
 * @note
 */
void aigmap( bool is_enable_nand = false, bool is_enable_select = false )
{
  std::string script = "aigmap ";

  if ( is_enable_nand )
    script += " -nand ";
  if ( is_enable_select )
    script += " -select ";

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf