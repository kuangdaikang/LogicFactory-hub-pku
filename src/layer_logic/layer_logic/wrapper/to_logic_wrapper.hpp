#pragma once

#include "wrapper_logic.hpp"

namespace lf
{

namespace logic
{
// template<typename Ntk = mockturtle::gtg_network>
mockturtle::gtg_network to_lsils_wrapper( Yosys::RTLIL::Design* frame_yosys )
{
  mockturtle::gtg_network ntk;
  mockturtle::read_verilog_params ports;
  wrapper_yosys_logic( frame_yosys, ntk, ports );
  return ntk;
}

} // namespace logic

} // namespace lf