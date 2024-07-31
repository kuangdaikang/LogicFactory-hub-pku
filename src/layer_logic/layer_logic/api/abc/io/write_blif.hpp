#pragma once

#include "layer_logic/logic_manager.hpp"
#include "layer_logic/api/abc/frame.hpp"
#include "utility/string.hpp"

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
 *  write_blif [options] [filename]
 *  options: -S str -j -a
 * @note
 */
void write_blif( const std::string& file, const std::string& str_lut = "", bool is_special = false, bool is_hierarchy = false )
{
  if ( !lf::utility::endsWith( file, ".blif" ) )
  {
    std::cerr << "Unmatched blif suffix type." << std::endl;
    assert( false );
    return;
  }

  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 1; // command name
  argc += 1;    // file name
  if ( !str_lut.empty() )
    argc += 1;
  if ( is_special )
    argc += 1;
  if ( is_hierarchy )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "write_blif" );

  if ( !str_lut.empty() )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -S " + str_lut ).c_str() );
  if ( is_special )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -j " ).c_str() );
  if ( is_hierarchy )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -a " ).c_str() );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandWriteBlif( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf