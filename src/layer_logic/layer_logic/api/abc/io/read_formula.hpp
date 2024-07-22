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
 *  read_formula [options] [formula string]
 *  options:
 * @note
 */
void read_formula( const std::string& file )
{
  lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;

  argv[pos++] = babc::Extra_UtilStrsav( "read_formula" );

  argv[pos++] = babc::Extra_UtilStrsav( file.c_str() );

  babc::IoCommandReadDsd( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf