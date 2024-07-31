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
 *  write_aiger [options] [filename]
 *  options: -s -c -u -v
 * @note
 */
void write_aiger( const std::string& file, bool is_save_names = false, bool is_compact = false, bool is_unique = false, bool is_verbose = false )
{
  if ( !lf::utility::endsWith( file, ".aig" ) )
  {
    std::cerr << "Unmatched aig suffix type." << std::endl;
    assert( false );
    return;
  }

  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 1; // command name
  argc += 1;    // file name
  if ( is_save_names )
    argc += 1;
  if ( is_compact )
    argc += 1;
  if ( is_unique )
    argc += 1;
  if ( is_verbose )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "write_aiger" );

  if ( is_save_names )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -s " ).c_str() );
  if ( is_compact )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -c " ).c_str() );
  if ( is_unique )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -u " ).c_str() );
  if ( is_verbose )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -v " ).c_str() );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandWriteAiger( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf