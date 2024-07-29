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
 *  write_blif [options] [filename]
 *  otions:
 *
 * @note
 */
void write_blif( const std::string& file = "", const std::string& top = "",
                 std::vector<std::string> buf = {}, std::vector<std::string> unbuf = {},
                 std::vector<std::string> true_port = {}, std::vector<std::string> false_port = {}, std::vector<std::string> undef_port = {},
                 bool is_noalias = false, bool is_icells = false, bool is_gates = false, bool is_conn = false, bool is_attr = false, bool is_param = false, bool is_cname = false, bool is_iname = false, bool is_iattr = false, bool is_blackbox = false, bool is_impltf = false )
{
  std::string script = "write_blif ";
  if ( !lf::utility::endsWith( file, ".blif" ) )
  {
    std::cerr << "Unmatched blif suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( !top.empty() )
    script += " -top " + top;
  if ( !buf.empty() )
    script += " -buf " + buf[0] + " " + buf[1] + " " + buf[2];
  if ( !unbuf.empty() )
    script += " -unbuf " + unbuf[0] + " " + unbuf[1] + " " + unbuf[2];
  if ( !true_port.empty() )
    script += " -true " + true_port[0] + " " + true_port[1];
  if ( !false_port.empty() )
    script += " -false " + false_port[0] + " " + false_port[1];
  if ( !undef_port.empty() )
    script += " -undef " + undef_port[0] + " " + undef_port[1];
  if ( is_noalias )
    script += " -noalias ";
  if ( is_icells )
    script += " -icells ";
  if ( is_gates )
    script += " -gates ";
  if ( is_conn )
    script += " -conn ";
  if ( is_attr )
    script += " -attr ";
  if ( is_param )
    script += " -param ";
  if ( is_cname )
    script += " -cname ";
  if ( is_iname )
    script += " -iname ";
  if ( is_iattr )
    script += " -iattr ";
  if ( is_blackbox )
    script += " -blackbox ";
  if ( is_impltf )
    script += " -impltf ";

  script += " " + file;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf