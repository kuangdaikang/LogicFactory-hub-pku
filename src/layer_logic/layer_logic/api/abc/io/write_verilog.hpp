#pragma once

#include "layer_logic/logic_manager.hpp"
#include "layer_logic/api/abc/frame.hpp"
#include "utility/string.hpp"

#include "layer_logic/api/abc/io/write_lut.hpp"

#include <cstdio>
#include <string>

namespace lf
{

namespace logic
{

namespace abc
{

/**
 * @brief Reads current logic into a file.
 * @example
 *  write_verilog [options] [filename]
 *  options: -K <k-feasible-cut> -f -a -m
 * @note
 */
void write_verilog( const std::string& file, int K = -1, bool is_fixed_format = false, bool is_only_ands = false, bool is_modules = false )
{
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  if ( K > 0 )
  {
    lf::logic::abc::write_lut( file, is_fixed_format );
    return;
  }

  int argc = 1; // command name
  argc += 1;    // file name
  if ( K > 0 )
    argc += 1;
  if ( is_fixed_format )
    argc += 1;
  if ( is_only_ands )
    argc += 1;
  if ( is_modules )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "write_verilog" );

  if ( K > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -K " + K ).c_str() );
  if ( is_fixed_format )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -f " ).c_str() );
  if ( is_only_ands )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -a " ).c_str() );
  if ( is_modules )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -m " ).c_str() );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandWriteVerilog( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf