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
 *  write_edif [options] [filename]
 *  otions:
 *
 * @note
 */
void write_edif( const std::string& file = "", const std::string& top = "",
                 bool is_nogndvcc = false, bool is_gndvccy = false, bool is_attrprop = false, bool is_keep = false, const std::string& pvector = "", bool is_lsbidx = false )
{
  std::string script = "write_edif ";
  if ( !lf::utility::endsWith( file, ".edif" ) )
  {
    std::cerr << "Unmatched edif suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( !top.empty() )
    script += " -top " + top;
  if ( is_nogndvcc )
    script += " -nogndvcc ";
  if ( is_gndvccy )
    script += " -gndvccy ";
  if ( is_attrprop )
    script += " -attrprop ";
  if ( is_keep )
    script += " -keep ";
  if ( !pvector.empty() )
    script += " -pvector " + pvector;
  if ( is_lsbidx )
    script += " -lsbidx ";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf