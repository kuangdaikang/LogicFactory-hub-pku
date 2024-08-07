#pragma once

#include "layer_logic/logic_manager.hpp"

namespace lf
{

namespace logic
{

namespace lsils
{

/**
 * @brief
 *
 */
void write_blif( const std::string& file )
{
  std::ofstream os( file.c_str(), std::ofstream::out );

  auto ntktype = lfLntINST->get_nkt_type();
  if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_AIG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_AIG );
    lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();
    mockturtle::write_blif( ntk, os );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_XAG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XAG );
    lf::logic::lsils::xag_seq_network ntk = lfLmINST->current<lf::logic::lsils::xag_seq_network>();
    mockturtle::write_blif( ntk, os );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_XMG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_XMG );
    lf::logic::lsils::xmg_seq_network ntk = lfLmINST->current<lf::logic::lsils::xmg_seq_network>();
    mockturtle::write_blif( ntk, os );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_MIG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_MIG );
    lf::logic::lsils::mig_seq_network ntk = lfLmINST->current<lf::logic::lsils::mig_seq_network>();
    mockturtle::write_blif( ntk, os );
  }
  else if ( ntktype == lf::logic::E_LF_LOGIC_NTK_TYPE::E_LF_LOGIC_NTK_TYPE_GTG )
  {
    lfLmINST->update_logic( lf::misc::E_LF_ANCHOR::E_LF_ANCHOR_LOGIC_LSILS_NTK_LOGIC_GTG );
    lf::logic::lsils::gtg_seq_network ntk = lfLmINST->current<lf::logic::lsils::gtg_seq_network>();
    mockturtle::write_blif( ntk, os );
  }
  else
  {
    std::cerr << "unsupport network type!\n";
    assert( false );
  }
  os.close();
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
