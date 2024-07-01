#pragma once
#include "kernel/yosys.h"

namespace lf
{
namespace arch
{

enum class E_ToolArchType
{
  E_ARCH_YOSYS,
  E_ARCH_IVERILOG,
};

class ArchManager
{
public:
  ArchManager()
      : type_prev_( E_ToolArchType::E_ARCH_YOSYS ),
        type_curr_( E_ToolArchType::E_ARCH_YOSYS )
  {
  }

  void start()
  {
    Yosys::log_streams.push_back( &std::cout );
    Yosys::log_error_stderr = true;
    Yosys::yosys_setup();
    frame_yosys_ = Yosys::yosys_get_design();
  }

  void stop()
  {
    Yosys::yosys_shutdown();
  }

  template<typename T>
  T current()
  {
    if constexpr ( std::is_same_v<T, Yosys::RTLIL::Design*> )
    {
      return frame_yosys_;
    }
  }

private:
  Yosys::RTLIL::Design* frame_yosys_;
  E_ToolArchType type_prev_;
  E_ToolArchType type_curr_;

}; // class ArchManager

} // namespace arch

} // namespace lf