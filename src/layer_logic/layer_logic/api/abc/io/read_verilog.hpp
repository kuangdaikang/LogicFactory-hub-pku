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
 *  options: -m -c -b
 * @note
 */
void read_aiger( const std::string& file, bool is_mapped = false, bool is_checking = false, bool is_barrier_buffer = false )
{
  if ( !lf::utility::endsWith( file, ".v" ) )
  {
    std::cerr << "Unmatched verilog suffix type." << std::endl;
    assert( false );
    return;
  }

  lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;
  if ( is_mapped )
    argc += 1;
  if ( is_checking )
    argc += 1;
  if ( is_barrier_buffer )
    argc += 1;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;

  argv[pos++] = babc::Extra_UtilStrsav( "read_verilog" );

  if ( is_mapped )
    argv[pos++] = babc::Extra_UtilStrsav( " -m " );
  if ( is_checking )
    argv[pos++] = babc::Extra_UtilStrsav( " -c " );
  if ( is_barrier_buffer )
    argv[pos++] = babc::Extra_UtilStrsav( " -b " );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandReadVerilog( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf