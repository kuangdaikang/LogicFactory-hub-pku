#pragma once

#include <vector>
#include <string>

namespace lf
{

namespace misc
{

/**
 * @brief Ports
 */
struct Ports
{
  std::string module_name{ "top" };
  std::vector<std::string> inputs;
  std::vector<std::string> outputs;

  void set_module_name( const std::string& name ) { this->module_name = name; }
  std::string get_module_name() const { return module_name; }

  void set_inputs( const std::vector<std::string>& inputs ) { this->inputs = inputs; }
  std::vector<std::string> get_inputs() const { return inputs; }

  void set_outputs( const std::vector<std::string>& outputs ) { this->outputs = outputs; }
  std::vector<std::string> get_outputs() const { return outputs; }

  void add_input( const std::string& input ) { this->inputs.push_back( input ); }
  void add_output( const std::string& output ) { this->outputs.push_back( output ); }

  std::string get_input( int pos ) const { return inputs.at( pos ); }
  std::string get_output( int pos ) const { return outputs.at( pos ); }

}; // class Ports

} // namespace misc
} // namespace lf