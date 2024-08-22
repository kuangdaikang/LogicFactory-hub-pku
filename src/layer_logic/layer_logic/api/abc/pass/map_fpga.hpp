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
 *  map_fpga [options]
 *  options: [-KCFAGRNTXY num] [-DEW float] [-SJ str] [-qarlepmsdbgxyuojiktnczvh]
 * @note
 */
void map_fpga( int KCut = -1, int CPriority = -1, int FlowIter = -1, int AreaIter = -1, int GateMax = -1, int RelaxRatio = -1, int NonDecomMax = -1, int TypeLut = -1, int XDelayAnd = -1, int YAreaAnd = -1,
               double DelayConstraint = -1.0f, double Epsilon = -1.0f, double WireDelay = -1.0f, const std::string& StrLut = "", const std::string& JStrLut = "",
               bool is_preprocessing = false, bool is_area_orienetd = false, bool is_reduction_expansion = false, bool is_latch_optimized = false,
               bool is_edge_aware = false, bool is_power_aware = false, bool is_min_cut = false, bool is_structed_delay = false, bool is_delay_decom = false,
               bool is_bat_feature = false, bool is_gate_sop = false, bool is_x_dsd = false, bool is_y_lib = false, bool is_u_sat_lib = false,
               bool is_out_buffers = false, bool is_jcheck = false, bool is_i_cofactor = false, bool is_k_dsd_manager = false, bool is_t_average = false,
               bool is_n_dsd_cutfunc = false, bool is_cut_new_truth = false, bool is_z_derive_luts = false, bool is_verbose = false )
{
  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_STRASH_AIG );
  lfLmINST->update_logic();

  auto ntk_ptr = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr

  int argc = 1; // command name

  if ( KCut > 0 )
    argc++;
  if ( CPriority > 0 )
    argc++;
  if ( FlowIter > 0 )
    argc++;
  if ( AreaIter > 0 )
    argc++;
  if ( GateMax > 0 )
    argc++;
  if ( RelaxRatio > 0 )
    argc++;
  if ( NonDecomMax > 0 )
    argc++;
  if ( TypeLut > 0 )
    argc++;
  if ( XDelayAnd > 0 )
    argc++;
  if ( YAreaAnd > 0 )
    argc++;

  if ( DelayConstraint > 0.0f )
    argc++;
  if ( Epsilon > 0.0f )
    argc++;
  if ( WireDelay > 0.0f )
    argc++;

  if ( is_preprocessing )
    argc++;
  if ( is_area_orienetd )
    argc++;
  if ( is_reduction_expansion )
    argc++;
  if ( is_latch_optimized )
    argc++;
  if ( is_edge_aware )
    argc++;
  if ( is_power_aware )
    argc++;
  if ( is_min_cut )
    argc++;
  if ( is_structed_delay )
    argc++;
  if ( is_delay_decom )
    argc++;
  if ( is_bat_feature )
    argc++;
  if ( is_gate_sop )
    argc++;
  if ( is_x_dsd )
    argc++;
  if ( is_y_lib )
    argc++;
  if ( is_u_sat_lib )
    argc++;
  if ( is_out_buffers )
    argc++;
  if ( is_jcheck )
    argc++;
  if ( is_i_cofactor )
    argc++;
  if ( is_k_dsd_manager )
    argc++;
  if ( is_t_average )
    argc++;
  if ( is_n_dsd_cutfunc )
    argc++;
  if ( is_cut_new_truth )
    argc++;
  if ( is_z_derive_luts )
    argc++;
  if ( is_verbose )
    argc++;

  char** argv = ABC_ALLOC( char*, argc + 1 );

  int pos = 0;
  argv[pos++] = babc::Extra_UtilStrsav( "if" );

  if ( KCut > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -K " + KCut ).c_str() );
  if ( CPriority > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -C " + CPriority ).c_str() );
  if ( FlowIter > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -F " + FlowIter ).c_str() );
  if ( AreaIter > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -A " + AreaIter ).c_str() );
  if ( GateMax > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -G " + GateMax ).c_str() );
  if ( RelaxRatio > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -R " + RelaxRatio ).c_str() );
  if ( NonDecomMax > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -N " + NonDecomMax ).c_str() );
  if ( TypeLut > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -T " + TypeLut ).c_str() );
  if ( XDelayAnd > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -X " + XDelayAnd ).c_str() );
  if ( YAreaAnd > 0 )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -Y " + YAreaAnd ).c_str() );

  if ( DelayConstraint > 0.0f )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -D " + std::to_string( DelayConstraint ) ).c_str() );
  if ( Epsilon > 0.0f )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -E " + std::to_string( Epsilon ) ).c_str() );
  if ( WireDelay > 0.0f )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -W " + std::to_string( WireDelay ) ).c_str() );

  if ( is_preprocessing )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -q " ).c_str() );
  if ( is_area_orienetd )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -a " ).c_str() );
  if ( is_reduction_expansion )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -r " ).c_str() );
  if ( is_latch_optimized )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -l " ).c_str() );
  if ( is_edge_aware )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -e " ).c_str() );
  if ( is_power_aware )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -p " ).c_str() );
  if ( is_min_cut )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -m " ).c_str() );
  if ( is_structed_delay )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -s " ).c_str() );
  if ( is_delay_decom )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -d " ).c_str() );
  if ( is_bat_feature )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -b " ).c_str() );
  if ( is_gate_sop )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -g " ).c_str() );
  if ( is_x_dsd )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -x " ).c_str() );
  if ( is_y_lib )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -y " ).c_str() );
  if ( is_u_sat_lib )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -u " ).c_str() );
  if ( is_out_buffers )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -o " ).c_str() );
  if ( is_jcheck )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -j " ).c_str() );
  if ( is_i_cofactor )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -i " ).c_str() );
  if ( is_k_dsd_manager )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -k " ).c_str() );
  if ( is_t_average )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -t " ).c_str() );
  if ( is_n_dsd_cutfunc )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -n " ).c_str() );
  if ( is_cut_new_truth )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -c " ).c_str() );
  if ( is_z_derive_luts )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -z " ).c_str() );
  if ( is_verbose )
    argv[pos++] = babc::Extra_UtilStrsav( std::string( " -v " ).c_str() );

  babc::Abc_CommandIf( ntk_ptr, argc, argv );
  lfLntINST->set_ntktype( lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_NETLIST_FPGA );
}

} // namespace abc

} // namespace logic

} // end namespace lf