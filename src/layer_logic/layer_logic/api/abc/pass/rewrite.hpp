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
 * @brief Logic optimization
 * @example
 *  rewrite [options]
 *  options: -lzvw
 * @note
 */
void rewrite( bool is_level_preserved = false, bool is_zero_cost = false, bool is_verbose = false, bool is_very_verbose = false, int NodeSizeMax = 0, int MinSaved = 0 )
{
  lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_NTK_STRASH_AIG );

  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;

  if ( is_level_preserved )
    argc++;
  if ( is_zero_cost )
    argc++;
  if ( is_verbose )
    argc++;
  if ( is_very_verbose )
    argc++;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "rewrite" );

  if ( is_level_preserved )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -l " ).c_str() );
  if ( is_zero_cost )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -z " ).c_str() );
  if ( is_verbose )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -v " ).c_str() );
  if ( is_very_verbose )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -w " ).c_str() );

  babc::Abc_CommandRewrite( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf