#pragma once

#include "operation/iSTA/api/TimingEngine.hh"
#include <vector>
#include <string>
#include <unordered_map>
#include <cfloat>

namespace lf
{
namespace netlist
{
/**
 * @brief
 */
class ProfileTiming
{
public:
  ProfileTiming() = default;
  ~ProfileTiming() = default;

  void set_timing_engine( ista::TimingEngine* sta )
  {
    ista_manager_ = sta;
  }

  double get_wrost_arrive_time()
  {
    return ista_manager_->getWorstArriveTime();
  }

private:
  ista::TimingEngine* ista_manager_ = nullptr;
}; // class ProfileTiming

} // namespace netlist

} // namespace lf