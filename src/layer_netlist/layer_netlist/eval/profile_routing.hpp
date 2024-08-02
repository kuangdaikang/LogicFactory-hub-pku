#pragma once

#include <vector>
#include <string>
#include <unordered_map>

namespace lf
{
namespace netlist
{

/**
 * @brief
 */
struct ProfileRouting
{
  std::unordered_map<std::string, double> pins_slack_early;
  std::unordered_map<std::string, double> pins_slack_late;
  std::unordered_map<std::string, double> pins_arrive_time_early;
  std::unordered_map<std::string, double> pins_arrive_time_late;
  std::unordered_map<std::string, double> pins_require_time_early;
  std::unordered_map<std::string, double> pins_require_time_late;
  std::unordered_map<std::string, double> wns; // worst negative slack
  std::unordered_map<std::string, double> tns; // total negative slack
  std::unordered_map<std::string, double> whs; // worst hold slack
  std::unordered_map<std::string, double> ths; // total hold slack
  double delay;
}; // class ProfileRouting

} // namespace netlist

} // namespace lf