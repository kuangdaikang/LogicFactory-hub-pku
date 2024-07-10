#pragma once

#include "wrapper_netlist.hpp"

namespace lf
{

namespace netlist
{

/**
 * @brief abc_to_idb
 * @param frame
 */
idb::IdbBuilder* asic_abc_to_idb( const babc::Abc_Frame_t* frame_abc )
{
  idb::IdbBuilder* idb_builder = dmInst->get_idb_builder();
  wrapper_abc_netlist( frame_abc, idb_builder );

  return idb_builder;
}

} // namespace netlist

} // namespace lf