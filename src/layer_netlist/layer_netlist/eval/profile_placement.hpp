#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "operation/iPL/api/PLAPI.hh"

namespace lf
{
namespace netlist
{

/**
 * @brief
 */
class ProfilePlacement
{
public:
  ProfilePlacement() = default;
  ~ProfilePlacement() = default;

  int64_t get_total_hpwl() const { iPLAPIInst.get_reporter()->getTotalHPWL(); }
  int64_t get_max_hpwl() const { iPLAPIInst.get_reporter()->getMaxHPWL(); }
  int64_t get_constraint_hpwl() const { iPLAPIInst.get_reporter()->getConstraintHPWL(); }
  int64_t get_total_stwl() const { iPLAPIInst.get_reporter()->getTotalSTWL(); }
  int64_t get_max_stwl() const { iPLAPIInst.get_reporter()->getMaxSTWL(); }
  int64_t get_lont_net_cnt() const { iPLAPIInst.get_reporter()->getLongNetCnt(); }

private:
}; // class ProfilePlacement

} // namespace netlist

} // namespace lf