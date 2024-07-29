#pragma once

#include "utils.hpp"

#include <tcl8.6/tcl.h>
#include <iostream>

namespace lf
{
namespace tcl
{
class TclOption
{
public:
  TclOption( const char* option_name, unsigned is_arg )
      : _option_name( copyCharStar( option_name ) ), _is_arg( is_arg )
  {}

  virtual ~TclOption() { _option_name = nullptr; }

  const char* get_option_name() { return _option_name; }

  unsigned is_arg() const { return _is_arg; }

  void set_description( const std::string& description ) { _description = description; }

  std::string get_description() const { return _description; }

  void set_tool( const std::string& tool ) { _tool = tool; }

  std::string get_tool() const { return _tool; }

  virtual unsigned isSwitchOption() { return 0; }

  virtual unsigned isDoubleOption() { return 0; }

  virtual unsigned isStringOption() { return 0; }

  virtual unsigned isIntOption() { return 0; }

  virtual unsigned isDoubleListOption() { return 0; }

  virtual unsigned isStringListOption() { return 0; }

  virtual unsigned isIntListOption() { return 0; }

  virtual unsigned isStringListListOption() { return 0; }

  virtual bool getSwitchVal()
  {
    std::cerr << "The option do not has switch val.\n";
    return 0;
  }

  virtual bool getDefaultSwitchVal()
  {
    std::cerr << "The option do not has default switch val.\n";
    return 0;
  }

  virtual int getIntVal()
  {
    std::cerr << "The option do not has int val.\n";
    return 0;
  }

  virtual int getDefaultIntVal()
  {
    std::cerr << "The option do not has default int val.\n";
    return 0;
  }

  virtual double getDoubleVal()
  {
    std::cerr << "The option do not has float val.\n";
    return 0.0;
  }

  virtual double getDefaultDoubleVal()
  {
    std::cerr << "The option do not has default float val.\n";
    return 0.0;
  }

  virtual char* getStringVal()
  {
    std::cerr << "The option do not has string val\n";
    return nullptr;
  }

  virtual char* getDefaultStringVal()
  {
    std::cerr << "The option do not has default string val.\n";
    return nullptr;
  }

  virtual std::vector<int> getIntList()
  {
    std::cerr << "The option do not has int list.\n";
    return {};
  }

  virtual std::vector<int> getDefaultIntList()
  {
    std::cerr << "The option do not has default int list.\n";
    return {};
  }

  virtual std::vector<double> getDoubleList()
  {
    std::cerr << "The option do not has double list.\n";
    return {};
  }

  virtual std::vector<double> getDefaultDoubleList()
  {
    std::cerr << "The option do not has default double list.\n";
    return {};
  }

  virtual std::vector<std::string> getStringList()
  {
    std::cerr << "The option do not has string list.\n";
    return {};
  }

  virtual std::vector<std::string> getDefaultStringList()
  {
    std::cerr << "The option do not has default string list.\n";
    return {};
  }

  virtual std::vector<std::vector<std::string>> getStringListList()
  {
    std::cerr << "The option do not has string list list.\n";
    return {};
  }

  virtual std::vector<std::vector<std::string>> getDefaultStringListList()
  {
    std::cerr << "The option do not has default string list list.\n";
    return {};
  }

  virtual void setVal( const char* val ) { std::cerr << "The option can not set float val.\n"; }

  virtual void resetVal() { std::cerr << "The option has not reset value.\n"; }

  unsigned is_set_val() { return _is_set_val; }

protected:
  unsigned _is_set_val = 0;

private:
  const char* _option_name;
  unsigned _is_arg;
  std::string _description = "";
  std::string _tool = ""; // flag the tool of this option
};

/**
 * @brief Tcl switch option.
 * @example
 *  cmd -switch, and this mean that the switch args is set to 1
 *
 */
class TclSwitchOption : public TclOption
{
public:
  explicit TclSwitchOption( const char* option_name )
      : TclOption( option_name, 0 )
  {}

  ~TclSwitchOption() override = default;

  unsigned isSwitchOption() override { return 1; }

  bool getSwitchVal() override { return _is_set_val; }

  void setVal( const char* val ) override { _is_set_val = 1; }

  void resetVal() override { _is_set_val = 0; }

  bool getDefaultSwitchVal() override { return false; }
};

/**
 * @brief Tcl int option.
 * @example
 *  cmd -abc 123, and this mean that the abc args is set to 123
 */
class TclIntOption : public TclOption
{
public:
  TclIntOption( const char* option_name, unsigned is_arg, int default_val = 0 )
      : TclOption( option_name, is_arg ), _default_val( default_val )
  {}

  ~TclIntOption() override = default;

  unsigned isIntOption() override { return 1; }

  int getIntVal() override { return _is_set_val ? _val : _default_val; }

  void setVal( const char* val ) override
  {
    _val = std::atoi( val );
    _is_set_val = 1;
  }

  void resetVal() override { _is_set_val = 0; }

  int getDefaultIntVal() override { return _default_val; }

private:
  int _default_val = 0;
  int _val;
};

/**
 * @brief Tcl double option.
 * @example
 *  cmd -abc 123, and this mean that the abc args is set to 123.0f
 */
class TclDoubleOption : public TclOption
{
public:
  TclDoubleOption( const char* option_name, unsigned is_arg, float default_val = 0.0 )
      : TclOption( option_name, is_arg ), _default_val( default_val )
  {}

  ~TclDoubleOption() override = default;

  unsigned isDoubleOption() override { return 1; }

  double getDoubleVal() override { return _is_set_val ? _val : _default_val; }

  void setVal( const char* val ) override
  {
    _val = std::atof( val );
    _is_set_val = 1;
  }

  void resetVal() override { _is_set_val = 0; }

  double getDefaultDoubleVal() override { return _default_val; }

private:
  double _default_val = 0.0;
  double _val;
};

/**
 * @brief Tcl string option.
 * @example
 *  cmd -abc 123, and this mean that the abc args is set to "123"
 */
class TclStringOption : public TclOption
{
public:
  TclStringOption( const char* option_name, unsigned is_arg, const char* default_val = nullptr )
      : TclOption( option_name, is_arg ), _default_val( copyCharStar( default_val ) )
  {
  }

  ~TclStringOption() override = default;

  unsigned isStringOption() override { return 1; }

  char* getStringVal() override { return _is_set_val ? (char*)( _val.c_str() ) : _default_val; }

  void setVal( const char* val ) override
  {
    _val = val;
    _is_set_val = 1;
  }

  void resetVal() override { _is_set_val = 0; }

  char* getDefaultStringVal() override { return _default_val; }

private:
  char* _default_val = nullptr;
  std::string _val;
};

/**
 * @brief Tcl int list option.
 * @example
 *  cmd -abc 123 456, and this mean that the abc args is set to {123, 456}
 */
class TclIntListOption : public TclOption
{
public:
  TclIntListOption( const char* option_name, unsigned is_arg, std::vector<int> default_val = {} )
      : TclOption( option_name, is_arg ), _default_val( default_val )
  {}

  ~TclIntListOption() override = default;

  unsigned isIntListOption() override { return 1; }

  std::vector<int> getIntList() override { return _is_set_val ? _val : _default_val; }

  void setVal( const char* val ) override
  {
    _val = splitInt( val, " " );
    _is_set_val = 1;
  }

  void resetVal() override
  {
    std::vector<int>().swap( _val );
    _is_set_val = 0;
  }

  std::vector<int> getDefaultIntList() override { return _default_val; }

private:
  std::vector<int> _default_val = {};
  std::vector<int> _val;
};

class TclDoubleListOption : public TclOption
{
public:
  TclDoubleListOption( const char* option_name, unsigned is_arg, std::vector<double> default_val = {} )
      : TclOption( option_name, is_arg ), _default_val( default_val )
  {}

  ~TclDoubleListOption() override = default;

  unsigned isStringOption() override { return 1; }

  std::vector<double> getDoubleList() override { return _is_set_val ? _val : _default_val; }

  void setVal( const char* val ) override
  {
    while ( *val == '{' || *val == ' ' )
    {
      val++;
    }

    _val = splitDouble( val, " " );
    _is_set_val = 1;
  }

  void resetVal() override
  {
    std::vector<double>().swap( _val );
    _is_set_val = 0;
  }

  std::vector<double> getDefaultDoubleList() override { return _default_val; }

private:
  std::vector<double> _default_val = {};
  std::vector<double> _val;
};

class TclStringListOption : public TclOption
{
public:
  TclStringListOption( const char* option_name, unsigned is_arg, std::vector<std::string> default_val = {} )
      : TclOption( option_name, is_arg ), _default_val( default_val )
  {}

  ~TclStringListOption() override = default;

  unsigned isStringOption() override { return 1; }

  std::vector<std::string> getStringList() override { return _is_set_val ? _val : _default_val; }

  void setVal( const char* val ) override
  {
    _val = splitString( val, " " );
    _is_set_val = 1;
  }

  void resetVal() override
  {
    // clear string vector, and release memory(is it needed for string?)
    std::vector<std::string>().swap( _val );
    _is_set_val = 0;
  }

  std::vector<std::string> getDefaultStringList() override { return _default_val; }

private:
  std::vector<std::string> _default_val = {};
  std::vector<std::string> _val;
};

class TclStringListListOption : public TclOption
{
public:
  using StrList = std::vector<std::string>;
  TclStringListListOption( const char* option_name, unsigned is_arg, std::vector<StrList>&& default_val = {} )
      : TclOption( option_name, is_arg ), _default_val( std::move( default_val ) )
  {}

  ~TclStringListListOption() override = default;

  unsigned isStringListListOption() override { return 1; }

  std::vector<StrList> getStringListList() override { return _is_set_val ? _val : _default_val; }

  void setVal( const char* val ) override
  {
    val += ignoreNext<' '>( val );

    if ( *val == '{' )
    {
      auto pos_len_list = getStrListPosLen( val );
      for ( auto& [pos, len] : pos_len_list )
      {
        _val.emplace_back( split<' ', ','>( val + pos, len ) );
      }
    }
    else
    {
      _val.emplace_back( splitString( val, " " ) );
    }

    _is_set_val = 1;
  }

  void resetVal() override
  {
    std::vector<StrList>().swap( _val );
    _is_set_val = 0;
  }

  std::vector<StrList> getDefaultStringListList() override { return _default_val; }

private:
  std::vector<StrList> _default_val;
  std::vector<StrList> _val;
};

} // namespace tcl

} // namespace lf