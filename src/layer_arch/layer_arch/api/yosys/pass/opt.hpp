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
 *  opt [options] [selection]
 *  opt
 *
 * @note
 */
void opt( bool is_purge = false, bool is_mux_undef = false, bool is_mux_bool = false, bool is_undriven = false, bool is_noclkinv = false,
          bool is_fine = false, bool is_full = false, bool is_keepdc = false, bool is_nodffe = false, bool is_nosdff = false, bool is_sat = false, bool is_share_all = false, bool is_fast = false, bool is_noff = false )
{
  std::string script = "opt ";

  if ( is_purge )
    script += " -purge";
  if ( is_mux_undef )
    script += " -mux_undef";
  if ( is_mux_bool )
    script += " -mux_bool";
  if ( is_undriven )
    script += " -undriven";
  if ( is_noclkinv )
    script += " -noclkinv";
  if ( is_fine )
    script += " -fine";
  if ( is_full )
    script += " -full";
  if ( is_keepdc )
    script += " -keepdc";
  if ( is_nodffe )
    script += " -nodffe";
  if ( is_nosdff )
    script += " -nosdff";
  if ( is_sat )
    script += " -sat";
  if ( is_share_all )
    script += " -share_all";
  if ( is_fast )
    script += " -fast";
  if ( is_noff )
    script += " -noff";

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf