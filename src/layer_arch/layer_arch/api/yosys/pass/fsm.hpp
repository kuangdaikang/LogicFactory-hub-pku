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
 *  fsm [options] [selection]
 *  fsm
 *
 * @note
 */
void fsm( bool is_expand = false, bool is_norecode = false, bool is_export = false, bool is_nomap = false, bool is_fullexpand = false,
          const std::string& fm_set_fsm_file = "", const std::string& encfile = "", const std::string& encoding = "" )
{
  std::string script = "fsm ";

  if ( is_expand )
    script += " -expand ";
  if ( is_norecode )
    script += " -norecode ";
  if ( is_export )
    script += " -export ";
  if ( is_nomap )
    script += " -nomap ";
  if ( is_fullexpand )
    script += " -fullexpand ";
  if ( !fm_set_fsm_file.empty() )
    script += " -fm_set_fsm_file " + fm_set_fsm_file;
  if ( !encfile.empty() )
    script += " -encfile " + encfile;
  if ( !encoding.empty() )
    script += " -encoding " + encoding;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf