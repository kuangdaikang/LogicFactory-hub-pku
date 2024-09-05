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
 * @brief Reads current logic into a file.
 * @example
 *  write_lut [options] [filename]
 * @note
 */
void write_lut( const std::string& file, bool is_fixed = false )
{
  auto pAbc = lfLmINST->current<babc::Abc_Frame_t*>(); // the the network from shared_ptr
  babc::Io_WriteVerilogLut( babc::Abc_FrameReadNtk( pAbc ), file.c_str(), 6, is_fixed, 0 );
}

} // namespace abc

} // namespace logic

} // end namespace lf