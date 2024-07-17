#pragma once
#include "layer_logic/logic_manager.hpp"
#include "layer_logic/api/abc/io/read_liberty.hpp"
#include "layer_logic/api/lsils/io/read_liberty.hpp"

#include <cstring>

namespace lf
{

namespace logic
{

/**
 * @brief common interface of the read genlib
 */
void read_liberty( std::string file )
{
  lf::logic::abc::read_liberty( file );
  //   lf::logic::lsils::read_liberty( file );
}

} // namespace logic

} // namespace lf