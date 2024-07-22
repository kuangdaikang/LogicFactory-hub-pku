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
 *  write_bench [options] [filename]
 *  options: -l
 * @note
 */
void write_bench( const std::string& file, bool is_lut = false )
{
  if ( !lf::utility::endsWith( file, ".bench" ) )
  {
    std::cerr << "Unmatched bench suffix type." << std::endl;
    assert( false );
    return;
  }

  lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;
  if ( is_lut )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "write_bench" );

  if ( is_lut )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -l " ).c_str() );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandWriteBench( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf