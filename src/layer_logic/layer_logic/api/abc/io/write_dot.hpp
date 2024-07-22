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
 *  write_dot [options] [filename]
 *  options:
 * @note
 */
void write_dot( const std::string& file )
{
  if ( !lf::utility::endsWith( file, ".dot" ) )
  {
    std::cerr << "Unmatched dot suffix type." << std::endl;
    assert( false );
    return;
  }

  lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "write_dot" );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandWriteDot( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf