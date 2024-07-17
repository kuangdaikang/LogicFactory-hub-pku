#pragma once
#include "layer_logic/logic_manager.hpp"
#include "layer_logic/api/abc/io/read_genlib.hpp"
#include "layer_logic/api/lsils/io/read_genlib.hpp"

#include <cstring>

namespace lf
{

namespace logic
{

/**
 * @brief common interface of the read genlib
 */
void read_genlib( std::string file )
{
  lf::logic::abc::read_genlib( file );
  lf::logic::lsils::read_genlib( file );
}

} // namespace logic

} // namespace lf