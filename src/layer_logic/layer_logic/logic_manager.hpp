#pragma once

#include "layer_logic/api/abc/frame.hpp"
#include "layer_logic/api/lsils/frame.hpp"

#include "misc/anchor.hpp"
#include "misc/ntktye.hpp"
#include "misc/ports.hpp"

#include <assert.h>
#include <iostream>

// logic manager instance
#define lfLmINST lf::logic::LogicManager::get_instance()

namespace lf
{

namespace logic
{

/**
 * @class LogicManager
 * @brief manager the logic type for the logic tools, also it namanger all the list netowrks
 *
 * @code
 *
 */
class LogicManager
{
public:
  static LogicManager* get_instance()
  {
    if ( instance_ == nullptr )
    {
      instance_ = new LogicManager;
    }
    return instance_;
  }

  void start()
  {
    babc::Abc_Start();
    frame_abc_ = babc::Abc_FrameGetGlobalFrame();
  }

  void stop()
  {
    babc::Abc_Stop();
  }

  /**
   * @brief get the current network for the given type
   * @tparam T current network type
   * @return ntk
   */
  template<typename T>
  T current()
  {
    if constexpr ( std::is_same_v<T, babc::Abc_Frame_t*> )
    {
      return frame_abc_;
    }
    else if constexpr ( std::is_same_v<T, lsils::Lsils_Frame_t> )
    {
      return frame_lsils_;
    }
    else if constexpr ( std::is_same_v<T, lsils::aig_seq_network> )
    {
      return frame_lsils_.curr_aig;
    }
    else if constexpr ( std::is_same_v<T, lsils::oig_seq_network> )
    {
      return frame_lsils_.curr_oig;
    }
    else if constexpr ( std::is_same_v<T, lsils::aog_seq_network> )
    {
      return frame_lsils_.curr_aog;
    }
    else if constexpr ( std::is_same_v<T, lsils::xag_seq_network> )
    {
      return frame_lsils_.curr_xag;
    }
    else if constexpr ( std::is_same_v<T, lsils::xog_seq_network> )
    {
      return frame_lsils_.curr_xog;
    }
    else if constexpr ( std::is_same_v<T, lsils::mig_seq_network> )
    {
      return frame_lsils_.curr_mig;
    }
    else if constexpr ( std::is_same_v<T, lsils::xmg_seq_network> )
    {
      return frame_lsils_.curr_xmg;
    }
    else if constexpr ( std::is_same_v<T, lsils::primary_seq_network> )
    {
      return frame_lsils_.curr_primary;
    }
    else if constexpr ( std::is_same_v<T, lsils::gtg_seq_network> )
    {
      return frame_lsils_.curr_gtg;
    }
    else if constexpr ( std::is_same_v<T, lsils::cvg_seq_network> )
    {
      return frame_lsils_.curr_cvg;
    }
    else if constexpr ( std::is_same_v<T, lsils::blut_seq_network> )
    {
      return frame_lsils_.curr_asic;
    }
    else if constexpr ( std::is_same_v<T, lsils::klut_seq_network> )
    {
      return frame_lsils_.curr_fpga;
    }
    else if constexpr ( std::is_same_v<T, lsils::lib_gates> )
    {
      return frame_lsils_.gates;
    }
    else
    {
      std::cerr << "Unhandled current type provided." << std::endl;
      assert( false );
      return nullptr;
    }
  }

  template<typename T>
  void set_current( T obj )
  {
    // Update specific network pointer based on the type of T
    if constexpr ( std::is_same_v<T, lsils::Lsils_Frame_t> )
    {
      frame_lsils_ = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::aig_seq_network> )
    {
      frame_lsils_.curr_aig = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::oig_seq_network> )
    {
      frame_lsils_.curr_oig = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::aog_seq_network> )
    {
      frame_lsils_.curr_aog = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::xag_seq_network> )
    {
      frame_lsils_.curr_xag = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::xog_seq_network> )
    {
      frame_lsils_.curr_xog = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::mig_seq_network> )
    {
      frame_lsils_.curr_mig = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::xmg_seq_network> )
    {
      frame_lsils_.curr_xmg = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::primary_seq_network> )
    {
      frame_lsils_.curr_primary = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::gtg_seq_network> )
    {
      frame_lsils_.curr_gtg = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::cvg_seq_network> )
    {
      frame_lsils_.curr_cvg = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::blut_seq_network> )
    {
      frame_lsils_.curr_asic = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::klut_seq_network> )
    {
      frame_lsils_.curr_fpga = obj;
    }
    else if constexpr ( std::is_same_v<T, lsils::lib_gates> )
    {
      frame_lsils_.gates = obj;
    }
    else
    {
      std::cerr << "Unhandled current type provided." << std::endl;
      assert( false );
    }
  }

  // process the ports
  lf::misc::Ports& ports() { return ports_; }
  lf::misc::Ports ports() const { return ports_; }

private:
  LogicManager() = default;
  ~LogicManager() = default;
  LogicManager( const LogicManager& ) = delete;
  LogicManager& operator=( const LogicManager& ) = delete;

private:
  static LogicManager* instance_;

  babc::Abc_Frame_t* frame_abc_ = nullptr; // store the abc frame
  lsils::Lsils_Frame_t frame_lsils_;       // store the lsils frame
  lf::misc::Ports ports_;                  // store the input/output port names
}; // class LogicManager

LogicManager* LogicManager::instance_ = nullptr;

} // end namespace logic

} // end namespace lf