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
 *  strash [options]
 *  options: -lzvw
 * @note
 */
void strash( bool is_all_nodes, bool is_cleanup, bool is_record_used, bool is_inverted_pos )
{
  lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_ABC_NTK_STRASH_AIG );

  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;

  if ( is_all_nodes )
    argc++;
  if ( is_cleanup )
    argc++;
  if ( is_record_used )
    argc++;
  if ( is_inverted_pos )
    argc++;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "rewrite" );

  if ( is_all_nodes )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -a " ).c_str() );
  if ( is_cleanup )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -c " ).c_str() );
  if ( is_record_used )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -r " ).c_str() );
  if ( is_inverted_pos )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -i " ).c_str() );

  babc::Abc_CommandStrash( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf