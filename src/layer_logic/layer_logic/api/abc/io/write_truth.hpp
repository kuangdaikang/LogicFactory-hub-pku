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
 *  write_truth [options] [filename]
 *  options: -x -r
 * @note
 */
void write_truth( const std::string& file, bool is_hex = false, bool is_reversing = false )
{
  if ( !lf::utility::endsWith( file, ".truth" ) )
  {
    std::cerr << "Unmatched truth suffix type." << std::endl;
    assert( false );
    return;
  }

  lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;
  if ( is_hex )
    argc += 1;
  if ( is_reversing )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "write_truth" );

  if ( is_hex )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -x " ).c_str() );
  if ( is_reversing )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -r " ).c_str() );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandWriteTruth( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf