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
 * @brief Pass:
 * @example
 *  hierarchy [-check] [-top <module>]
 *  hierarchy -check -simcheck -smtcheck -purge_lib -libdir <directory> -keep_positionals -keep_portwidths -nodefaults -nokeep_prints -nokeep_asserts top <module> -auto-top -chparam name value
 *
 * @note
 */
void hierarchy( bool is_check = false, bool is_simcheck = false, bool is_smtcheck = false, bool is_purge_lib = false,
                const std::vector<std::string> Libdirs = {},
                bool is_keep_positional = false, bool is_keep_portwidths = false, bool is_nodefaults = false, bool is_nokeep_prints = false, bool is_nokeep_asserts = false,
                const std::string& top_name = "", bool is_auto_top = false,
                const std::map<std::string, std::string>& chparam = {} )
{
  std::string script = "hierarchy ";
  if ( is_check )
    script += " -check ";
  if ( is_simcheck )
    script += " -simcheck ";
  if ( is_smtcheck )
    script += " -smtcheck ";
  if ( is_purge_lib )
    script += " -purge_lib ";
  if ( !Libdirs.empty() )
  {
    script += " -libdir ";
    for ( const auto& libdir : Libdirs )
      script += libdir + " ";
  }
  if ( is_keep_positional )
    script += " -keep_positionals ";
  if ( is_keep_portwidths )
    script += " -keep_portwidths ";
  if ( is_nodefaults )
    script += " -nodefaults ";
  if ( is_nokeep_prints )
    script += " -nokeep_prints ";
  if ( is_nokeep_asserts )
    script += " -nokeep_asserts ";
  if ( top_name != "" )
    script += " -top " + top_name;
  if ( is_auto_top )
    script += " -auto-top ";
  if ( !chparam.empty() )
  {
    script += " -chparam ";
    for ( const auto& [name, value] : chparam )
      script += name + " " + value + " ";
  }

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf