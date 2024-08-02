#pragma once

#include <vector>
#include <string>
#include <unordered_map>
#include "operation/iSTA/api/TimingEngine.hh"

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

  std::vector<std::string> get_clock_name_list()
  {
    const auto& sta_clock_list = ista_manager_->getClockList();
    std::vector<std::string> clock_name_list;
    clock_name_list.reserve( sta_clock_list.size() );
    for ( size_t i = 0; i < sta_clock_list.size(); ++i )
    {
      clock_name_list.emplace_back( sta_clock_list[i]->get_clock_name() );
    }
    return clock_name_list;
  }

  double get_early_cell_delay( const std::string& cell_name, const std::string& ci_name, const std::string& co_name ) const
  {
    double early_delay = 0;

    auto rise_value = ista_manager_->getInstDelay( cell_name.c_str(), ci_name.c_str(), co_name.c_str(), ista::AnalysisMode::kMin, ista::TransType::kRise );
    auto fall_value = ista_manager_->getInstDelay( cell_name.c_str(), ci_name.c_str(), co_name.c_str(), ista::AnalysisMode::kMin, ista::TransType::kFall );

    early_delay = std::min( rise_value, fall_value );

    return early_delay;
  }

  double get_late_cell_delay( const std::string& cell_name, const std::string& ci_name, const std::string& co_name ) const
  {
    double late_delay = 0;

    auto rise_value = ista_manager_->getInstDelay( cell_name.c_str(), ci_name.c_str(), co_name.c_str(), ista::AnalysisMode::kMax, ista::TransType::kRise );
    auto fall_value = ista_manager_->getInstDelay( cell_name.c_str(), ci_name.c_str(), co_name.c_str(), ista::AnalysisMode::kMax, ista::TransType::kFall );

    late_delay = std::min( rise_value, fall_value );

    return late_delay;
  }

  double get_early_slack( const std::string& pin_name ) const
  {
    double early_slack = 0;

    auto rise_value = ista_manager_->getSlack( pin_name.c_str(), ista::AnalysisMode::kMin, ista::TransType::kRise );
    auto fall_value = ista_manager_->getSlack( pin_name.c_str(), ista::AnalysisMode::kMin, ista::TransType::kFall );

    if ( rise_value == std::nullopt || fall_value == std::nullopt )
    {
      return DBL_MAX;
    }

    early_slack = std::min( rise_value.value(), fall_value.value() );

    return early_slack;
  }

  double get_late_slack( const std::string& pin_name ) const
  {
    double late_slack = 0;

    auto rise_value = ista_manager_->getSlack( pin_name.c_str(), ista::AnalysisMode::kMax, ista::TransType::kRise );
    auto fall_value = ista_manager_->getSlack( pin_name.c_str(), ista::AnalysisMode::kMax, ista::TransType::kFall );

    if ( rise_value == std::nullopt || fall_value == std::nullopt )
    {
      return DBL_MAX;
    }

    late_slack = std::min( rise_value.value(), fall_value.value() );

    return late_slack;
  }

  double get_arrival_early_time( const std::string& pin_name ) const
  {
    double arrival_early_time = 0;

    auto rise_value = ista_manager_->getAT( pin_name.c_str(), ista::AnalysisMode::kMin, ista::TransType::kRise );
    auto fall_value = ista_manager_->getAT( pin_name.c_str(), ista::AnalysisMode::kMin, ista::TransType::kFall );

    if ( rise_value == std::nullopt || fall_value == std::nullopt )
    {
      return DBL_MIN;
    }

    arrival_early_time = std::min( rise_value.value(), fall_value.value() );

    return arrival_early_time;
  }

  double get_arrival_late_time( const std::string& pin_name ) const
  {
    double arrival_late_time = 0;

    auto rise_value = ista_manager_->getAT( pin_name.c_str(), ista::AnalysisMode::kMax, ista::TransType::kRise );
    auto fall_value = ista_manager_->getAT( pin_name.c_str(), ista::AnalysisMode::kMax, ista::TransType::kFall );

    if ( rise_value == std::nullopt || fall_value == std::nullopt )
    {
      return DBL_MIN;
    }

    arrival_late_time = std::max( rise_value.value(), fall_value.value() );

    return arrival_late_time;
  }

  double get_required_early_time( const std::string& pin_name ) const
  {
    double required_early_time = 0;

    auto rise_value = ista_manager_->getRT( pin_name.c_str(), ista::AnalysisMode::kMin, ista::TransType::kRise );
    auto fall_value = ista_manager_->getRT( pin_name.c_str(), ista::AnalysisMode::kMin, ista::TransType::kFall );

    if ( rise_value == std::nullopt || fall_value == std::nullopt )
    {
      return DBL_MAX;
    }

    required_early_time = std::max( rise_value.value(), fall_value.value() );

    return required_early_time;
  }

  double get_required_late_time( const std::string& pin_name ) const
  {
    double required_late_time = 0;

    auto rise_value = ista_manager_->getRT( pin_name.c_str(), ista::AnalysisMode::kMax, ista::TransType::kRise );
    auto fall_value = ista_manager_->getRT( pin_name.c_str(), ista::AnalysisMode::kMax, ista::TransType::kFall );

    if ( rise_value == std::nullopt || fall_value == std::nullopt )
    {
      return DBL_MAX;
    }

    required_late_time = std::min( rise_value.value(), fall_value.value() );

    return required_late_time;
  }

  double get_late_WNS( const std::string& clock_name )
  {
    return ista_manager_->getWNS( clock_name.c_str(), ista::AnalysisMode::kMin );
  }

  double get_early_WNS( const std::string& clock_name )
  {
    return ista_manager_->getWNS( clock_name.c_str(), ista::AnalysisMode::kMax );
  }

  double get_early_TNS( const std::string& clock_name )
  {
    return ista_manager_->getTNS( clock_name.c_str(), ista::AnalysisMode::kMin );
  }

  double get_late_TNS( const std::string& clock_name )
  {
    return ista_manager_->getTNS( clock_name.c_str(), ista::AnalysisMode::kMax );
  }

private:
  ista::TimingEngine* ista_manager_ = nullptr;
}; // class ProfileTiming

} // namespace netlist

} // namespace lf