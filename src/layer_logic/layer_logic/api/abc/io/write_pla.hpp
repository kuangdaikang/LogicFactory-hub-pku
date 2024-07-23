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
 *  write_pla [options] [filename]
 *  options: [-M <num>] [-mh]
 * @note
 */
void write_pla( const std::string& file, int M = -1, bool is_multi_output = false )
{
  if ( !lf::utility::endsWith( file, ".pla" ) )
  {
    std::cerr << "Unmatched pla suffix type." << std::endl;
    assert( false );
    return;
  }

  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;
  if ( M > 0 )
  {
    argc += 1;
  }
  if ( is_multi_output )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "write_pla" );

  if ( M > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -M " + M ).c_str() );
  if ( is_multi_output )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -m " ).c_str() );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandWritePla( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf