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
 * @brief Pass: use ABC for technology mapping
 * @example
 *  abc [options] [selection]
 *  abc -nand -select
 *
 * @note
 */
void abc( const std::string& exe = "", const std::string& script = "",
          const std::vector<std::string>& liberties = {}, const std::vector<std::string>& genlibs = {}, const std::string& constr = "", const std::vector<std::string>& dont_use_cells = {},
          bool is_fast = false, double delay_target = -1.0f, int max_sop_Input_size = -1, int max_sop_Products = -1, int max_lut_input_Shared = -1,
          int lut_Width = -1, const std::vector<std::string>& luts = {},
          bool is_sop = false, const std::vector<std::string>& gates_speicified = {},
          bool is_dff = false, bool is_clk = false, bool is_keepff = false, bool is_nocleanup = false, bool is_showtmp = false, bool is_markgroups = false, bool is_dress = false )
{
  std::string script_shell = "abc ";

  if ( !exe.empty() )
    script_shell += " -exe " + exe;
  if ( !script.empty() )
    script_shell += " -script " + script;
  if ( !liberties.empty() )
  {
    script_shell += " -liberty ";
    for ( auto liberty : liberties )
    {
      script_shell += liberty + " ";
    }
  }
  if ( !genlibs.empty() )
  {
    script_shell += " -genlib ";
    for ( auto genlib : genlibs )
    {
      script_shell += genlib + " ";
    }
  }
  if ( !constr.empty() )
    script_shell += " -constr " + constr;
  if ( !dont_use_cells.empty() )
  {
    script_shell += " -dont_use ";
    for ( auto cell : dont_use_cells )
    {
      script_shell += cell + " ";
    }
  }
  if ( is_fast )
    script_shell += " -fast ";
  if ( delay_target > 0.0f )
    script_shell += " -D " + std::to_string( delay_target );
  if ( max_sop_Input_size > 0 )
    script_shell += " -I " + std::to_string( max_sop_Input_size );
  if ( max_sop_Products > 0 )
    script_shell += " -P " + std::to_string( max_sop_Products );
  if ( max_lut_input_Shared > 0 )
    script_shell += " -S " + std::to_string( max_lut_input_Shared );
  if ( lut_Width > 0 )
    script_shell += " -lut " + std::to_string( lut_Width );
  if ( !luts.empty() )
  {
    script_shell += " -luts ";
    for ( auto lut : luts )
    {
      script_shell += lut + " ";
    }
  }
  if ( is_sop )
    script_shell += " -sop ";
  if ( !gates_speicified.empty() )
  {
    script_shell += " -g ";
    for ( auto gate : gates_speicified )
    {
      script_shell += gate + " ";
    }
  }
  if ( is_dff )
    script_shell += " -dff ";
  if ( is_clk )
    script_shell += " -clk ";
  if ( is_keepff )
    script_shell += " -keepff ";
  if ( is_nocleanup )
    script_shell += " -nocleanup ";
  if ( is_showtmp )
    script_shell += " -showtmp ";
  if ( is_markgroups )
    script_shell += " -markgroups ";
  if ( is_dress )
    script_shell += " -dress ";

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();
  Yosys::run_pass( script_shell, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf