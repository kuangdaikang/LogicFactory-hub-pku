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
 * @brief Reads file into the current logic network.
 * @example
 *  read_aiger [options] [filename]
 *  options: -c
 * @note
 */
void read_bench( const std::string& file, bool is_checking = false )
{
  if ( !lf::utility::endsWith( file, ".bench" ) )
  {
    std::cerr << "Unmatched bench suffix type." << std::endl;
    assert( false );
    return;
  }

  lfLmINST->update_logic( lf::misc::E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_SOP );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 1; // command name
  argc += 1;    // file name
  if ( is_checking )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;

  argv[pos++] = babc::Extra_UtilStrsav( "read_bench" );

  if ( is_checking )
    argv[pos++] = babc::Extra_UtilStrsav( " -c " );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandReadBench( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf