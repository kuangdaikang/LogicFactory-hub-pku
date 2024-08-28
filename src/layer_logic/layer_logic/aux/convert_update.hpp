#pragma once

#include "layer_logic/logic_manager.hpp"
#include "layer_logic/aux/convert_node.hpp"
#include "layer_logic/aux/convert_cover.hpp"

#include <unordered_map>

namespace lf
{

namespace logic
{

/**
 * @brief auto update the network by the previous and current
 * @param is_node_method
 */
void convert_update( bool is_node_method = false )
{
  std::string from, to;
  auto ntktype_prev = lfLntINST->get_ntktype_prev();
  auto ntktype_curr = lfLntINST->get_ntktype_curr();

  if ( ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_AIG ||
       ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_STRASH_AIG )
  {
    from = "abc";
  }
  else if ( ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_AIG ||
            ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    from = "aig";
  }
  else if ( ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XAG ||
            ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    from = "xag";
  }
  else if ( ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_MIG ||
            ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    from = "mig";
  }
  else if ( ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XMG ||
            ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    from = "xmg";
  }
  else if ( ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_PRIMARY ||
            ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_PRIMARY )
  {
    from = "primary";
  }
  else if ( ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_GTG ||
            ntktype_prev == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG )
  {
    from = "gtg";
  }
  else
  {
    std::cerr << "Warning: not supported now!" << std::endl;
    return;
  }

  if ( ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_LOGIC_AIG ||
       ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_ABC_STRASH_AIG )
  {
    to = "abc";
  }
  else if ( ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_AIG ||
            ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_AIG )
  {
    to = "aig";
  }
  else if ( ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XAG ||
            ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XAG )
  {
    to = "xag";
  }
  else if ( ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_MIG ||
            ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_MIG )
  {
    to = "mig";
  }
  else if ( ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_XMG ||
            ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_XMG )
  {
    to = "xmg";
  }
  else if ( ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_PRIMARY ||
            ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_PRIMARY )
  {
    to = "primary";
  }
  else if ( ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_LOGIC_GTG ||
            ntktype_curr == lf::misc::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_LSILS_STRASH_GTG )
  {
    to = "gtg";
  }
  else
  {
    std::cerr << "Warning: not supported now!" << std::endl;
    return;
  }

  if ( is_node_method )
  {
    convert_node( from, to );
  }
  else
  {
    convert_cover( from, to );
  }

  lfLntINST->set_ntktype( ntktype_curr );
}

} // end namespace logic

} // end namespace lf