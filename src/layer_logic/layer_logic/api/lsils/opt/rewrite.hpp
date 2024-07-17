#pragma once

#include "layer_logic/logic_manager.hpp"

#include "mockturtle/algorithms/cut_rewriting.hpp"
#include "mockturtle/algorithms/node_resynthesis/xag_npn.hpp"

namespace lf
{

namespace logic
{

namespace lsils
{

/**
 * @brief rewrite current network
 * @param ntk   network
 * @param rebalancing_fn function
 * @param ps    params
 * @param pst   stats
 * @code
 *  mockturtle::aig_network aig;
 *  // ...
 *  mockturtle::aig_network aig_rewrite = rewrite_cut(aig);
 *
 */
template<class Ntk>
void rewrite_cut()
{
  if constexpr ( std::is_same_v<Ntk, aig_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_AIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xag_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XAG );
  }
  else if constexpr ( std::is_same_v<Ntk, mig_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_MIG );
  }
  else if constexpr ( std::is_same_v<Ntk, xmg_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_XMG );
  }
  else if constexpr ( std::is_same_v<Ntk, gtg_seq_network> )
  {
    lfLmINST->update_logic( E_ToolLogicType::E_LOGIC_MOCKTURTLE_GTG );
  }
  else
  {
    std::cerr << "Unhandled network type provided." << std::endl;
    assert( false );
  }

  auto ntk = lfLmINST->current<Ntk>();

  mockturtle::xag_npn_resynthesis<Ntk> npn_resyn;
  mockturtle::cut_rewriting_params ps;
  ps.cut_enumeration_ps.cut_size = 4u;
  Ntk ntk_new = mockturtle::cut_rewriting<Ntk, mockturtle::xag_npn_resynthesis<Ntk>>( ntk, npn_resyn, ps );
  lfLmINST->set_current<Ntk>( ntk_new );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
