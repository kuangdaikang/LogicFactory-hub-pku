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
 *  read_liberty [filename]
 *
 * @note
 */
void read_liberty( const std::string& file )
{
  if ( !lf::utility::endsWith( file, ".lib" ) )
  {
    std::cerr << "Unmatched liberty suffix type." << std::endl;
    assert( false );
    return;
  }

  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;
  char** argv = ABC_ALLOC( char*, argc + 1 );

  argv[0] = babc::Extra_UtilStrsav( "read" );
  argv[1] = const_cast<char*>( file.c_str() );

  babc::IoCommandRead( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf