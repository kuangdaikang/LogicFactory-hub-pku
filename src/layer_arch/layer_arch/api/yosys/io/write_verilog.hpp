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
 * @brief Write the current design into a verilog file.
 * @example
 *  write_verilog [options] [filename]
 *  options: -sv -norename -renameprefix <prefix>
 *           -noattr -attr2comment -noexpr -noparallelcase -siminit -nodec -decimal -nohex -nostr -simple-lhs -extmem -defparam -blackboxes -selected -v
 *
 * @note
 *
 */
void write_verilog( const std::string& file, bool is_sv = false, bool is_norename = false, const std::string& renameprefix = "",
                    bool is_noattr = false, bool is_attr2comment = false, bool is_noexpr = false, bool is_noparallelcase = false, bool is_siminit = false, bool is_nodec = false, bool is_decimal = false, bool is_nohex = false, bool is_nostr = false, bool is_simple_lhs = false, bool is_extmem = false, bool is_defparam = false, bool is_blackboxes = false, bool is_selected = false, bool is_v = false )
{
  std::string script = "write_verilog ";
  if ( !lf::utility::endsWith( file, ".v" ) )
  {
    std::cerr << "Unmatched verilog suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( is_sv )
    script += " -sv ";
  if ( is_norename )
    script += " -norename ";
  if ( !renameprefix.empty() )
    script += " -renameprefix " + renameprefix;
  if ( is_noattr )
    script += " -noattr ";
  if ( is_attr2comment )
    script += " -attr2comment ";
  if ( is_noexpr )
    script += " -noexpr ";
  if ( is_noparallelcase )
    script += " -noparallelcase ";
  if ( is_siminit )
    script += " -siminit ";
  if ( is_nodec )
    script += " -nodec ";
  if ( is_decimal )
    script += " -decimal ";
  if ( is_nohex )
    script += " -nohex ";
  if ( is_nostr )
    script += " -nostr ";
  if ( is_simple_lhs )
    script += " -simple-lhs ";
  if ( is_extmem )
    script += " -extmem ";
  if ( is_defparam )
    script += " -defparam ";
  if ( is_blackboxes )
    script += " -blackboxes ";
  if ( is_selected )
    script += " -selected ";
  if ( is_v )
    script += " -v ";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf