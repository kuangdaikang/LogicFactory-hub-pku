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
void write_aiger( const std::string& file )
{
  lf::logic::lsils::aig_seq_network ntk = lfLmINST->current<lf::logic::lsils::aig_seq_network>();
  mockturtle::write_aiger( ntk, file );
}

} // end namespace lsils

} // end namespace logic

} // end namespace lf
