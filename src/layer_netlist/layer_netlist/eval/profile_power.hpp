#pragma once

#include "operation/iPW/api/PowerEngine.hh"
#include "operation/iPW/source/module/ops/plot_power/PwrReport.hh"
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
class ProfilePower
{
public:
  ProfilePower() = default;
  ~ProfilePower() = default;

  void set_power_engine( ipower::PowerEngine* engine )
  {
    engine_ = engine;

    // calc group summary data.
    auto& type_to_group_data = engine_->get_power()->get_type_to_group_data();
    double net_switching_power = 0.0;
    double cell_internal_power = 0.0;
    double cell_leakage_power = 0.0;
    for ( auto& [group_type, group_datas] : type_to_group_data )
    {
      double group_internal_power = 0.0;
      double group_switch_power = 0.0;
      double group_leakage_power = 0.0;

      for ( auto& group_data : group_datas )
      {
        group_internal_power += group_data->get_internal_power();
        group_switch_power += group_data->get_switch_power();
        group_leakage_power += group_data->get_leakage_power();

        cell_internal_power += group_data->get_internal_power();
        net_switching_power += group_data->get_switch_power();
        cell_leakage_power += group_data->get_leakage_power();
      }
    }
    internal_power_ = cell_internal_power;
    switch_power_ = net_switching_power;
    leakage_power_ = cell_leakage_power;
  }

  double get_internal_power()
  {
    return internal_power_;
  }

  double get_leakage_power()
  {
    return leakage_power_;
  }

  double get_dynamic_power()
  {
    return switch_power_;
  }

  double get_total_power()
  {
    return internal_power_ + switch_power_ + leakage_power_;
  }

private:
  ipower::PowerEngine* engine_ = nullptr;
  double internal_power_ = 0.0f;
  double leakage_power_ = 0.0f;
  double switch_power_ = 0.0f;
}; // class ProfilePower

} // namespace netlist

} // namespace lf