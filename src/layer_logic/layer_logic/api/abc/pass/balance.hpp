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
 *  balance [options]
 *  options: -lzvw
 * @note
 */
void balance( bool is_level_preserved = false, bool is_dump_logic = false, bool is_dump_critical = false, bool is_multi_exors = false, bool is_verbose = false )
{
  // checking the ntktype
  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG );
  if ( ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG )
  {
    std::cerr << "Error: The current network is not a strash aig network." << std::endl;
    return;
  }

  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 1; // command name

  if ( is_level_preserved )
    argc++;
  if ( is_dump_logic )
    argc++;
  if ( is_dump_critical )
    argc++;
  if ( is_multi_exors )
    argc++;
  if ( is_verbose )
    argc++;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "balance" );

  if ( is_level_preserved )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -l " ).c_str() );
  if ( is_dump_logic )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -d " ).c_str() );
  if ( is_dump_critical )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -s " ).c_str() );
  if ( is_multi_exors )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -x " ).c_str() );
  if ( is_verbose )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -v " ).c_str() );

  babc::Abc_CommandBalance( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf