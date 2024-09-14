#pragma once

#include "layer_logic/logic_manager.hpp"
#include "layer_logic/api/abc/frame.hpp"
#include "utility/string.hpp"

#include <iostream>
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
void rename( std::string top_name = "" )
{
  // checking the ntktype
  auto ntktype = lfLntINST->get_ntktype_curr();
  assert( ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG ||
          ntktype == lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG );
  if ( ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_STRASH_AIG &&
       ntktype != lf::misc::E_LF_NTK_TYPE::E_LF_NTK_TYPE_ABC_LOGIC_AIG )
  {
    std::cerr << "Error: The current network is not a strash aig network." << std::endl;
    return;
  }

  auto pAbc = lfLmINST->current<babc::Abc_Frame_t*>();
  babc::Abc_Ntk_t* pNtk = babc::Abc_FrameReadNtk( pAbc );
  if ( !top_name.empty() )
  {
    char* top_name_c = babc::Abc_UtilStrsav( top_name.c_str() );
    babc::Abc_NtkSetName( pNtk, top_name_c );
  }
  else
  {
    std::cout << "warningL: no top name is specified, use the default top name.\n";
  }
}

} // namespace abc

} // namespace logic

} // end namespace lf