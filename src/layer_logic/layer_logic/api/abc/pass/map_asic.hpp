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
 * @brief Technology Mapping
 * @example
 *  map_asic [options]
 *  options: [-DABFSG float] [-M num] [-arspfuovh]
 * @note
 */
void map_asic( double DelayGlobal = -1.0f, double AreaMulti = -1.0f, double BDelayMulti = -1.0f, double FanoutLogar = -1.0f, double Slew = -1.0f, double Gain = -1.0f,
               int MinGates = -1,
               bool is_area_only = false, bool is_recovery_area = false, bool is_sweep = false, bool is_power_aware = false,
               bool is_use_stdcell_profile = false, bool is_output_buffer = false, bool is_verbose = false ),
{
  lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_ABC_AIG );
  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 2;

  if ( DelayGlobal > 0.0f )
    argc++;
  if ( AreaMulti > 0.0f )
    argc++;
  if ( BDelayMulti > 0.0f )
    argc++;
  if ( FanoutLogar > 0.0f )
    argc++;
  if ( Slew > 0.0f )
    argc++;
  if ( Gain > 0.0f )
    argc++;

  if ( MinGates > 0 )
    argc++;

  if ( is_area_only )
    argc++;
  if ( is_recovery_area )
    argc++;
  if ( is_sweep )
    argc++;
  if ( is_power_aware )
    argc++;
  if ( is_use_stdcell_profile )
    argc++;
  if ( is_output_buffer )
    argc++;
  if ( is_verbose )
    argc++;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "map" );

  if ( DelayGlobal > 0.0f )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -D " + std::to_string( DelayGlobal ) ).c_str() );
  if ( AreaMulti > 0.0f )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -A " + std::to_string( AreaMulti ) ).c_str() );
  if ( BDelayMulti > 0.0f )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -B " + std::to_string( BDelayMulti ) ).c_str() );
  if ( FanoutLogar > 0.0f )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -F " + std::to_string( FanoutLogar ) ).c_str() );
  if ( Slew > 0.0f )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -S " + std::to_string( Slew ) ).c_str() );
  if ( Gain > 0.0f )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -G " + std::to_string( Gain ) ).c_str() );

  if ( MinGates > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -M " + NodeSizeMax ).c_str() );

  if ( is_area_only )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -a " ).c_str() );
  if ( is_recovery_area )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -r " ).c_str() );
  if ( is_sweep )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -s " ).c_str() );
  if ( is_power_aware )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -p " ).c_str() );
  if ( is_use_stdcell_profile )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -u " ).c_str() );
  if ( is_output_buffer )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -o " ).c_str() );
  if ( is_verbose )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -v " ).c_str() );

  babc::Abc_CommandMap( ntk_ptr, argc, argv );
}

} // namespace abc

} // namespace logic

} // end namespace lf