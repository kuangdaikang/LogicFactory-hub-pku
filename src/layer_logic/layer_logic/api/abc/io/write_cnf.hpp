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
 *  write_cnf [options] [filename]
 *  options: -n -f -p -c -v
 * @note
 */
void write_cnf( const std::string& file, bool is_new = false, bool is_fast = false, bool is_primes = false, bool is_adjast = false, bool is_verbose = false )
{
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 1; // command name
  argc += 1;    // file name
  if ( is_new )
    argc += 1;
  if ( is_fast )
    argc += 1;
  if ( is_primes )
    argc += 1;
  if ( is_adjast )
    argc += 1;
  if ( is_verbose )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "write_cnf" );

  if ( is_new )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -n " ).c_str() );
  if ( is_fast )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -f " ).c_str() );
  if ( is_primes )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -p " ).c_str() );
  if ( is_adjast )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -c " ).c_str() );
  if ( is_verbose )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -v " ).c_str() );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandWriteCnf( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf