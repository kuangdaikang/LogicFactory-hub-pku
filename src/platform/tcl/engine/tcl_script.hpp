#pragma once

#include <tcl8.6/tcl.h>

#include <iostream>
#include <vector>
#include <memory>
#include <mutex>

namespace lf
{
namespace tcl
{
class TclScript
{
private:
  TclScript()
  {
    _interp = Tcl_CreateInterp();
  }

  virtual ~TclScript()
  {
    Tcl_DeleteInterp( _interp );
  }

  TclScript( const TclScript& ) = delete;
  TclScript& operator=( const TclScript& ) = delete;

public:
  static TclScript* getOrCreateInstance()
  {
    static std::mutex mt;
    if ( _instance == nullptr )
    {
      std::lock_guard<std::mutex> lock( mt );
      if ( _instance == nullptr )
      {
        _instance = new TclScript();
      }
    }
    return _instance;
  }

  static void destroyInstance()
  {
    delete _instance;
    _instance = nullptr;
  }

  Tcl_Interp* get_interp() { return _interp; }

  Tcl_Command createCmd( const char* cmd_name, Tcl_ObjCmdProc* proc, void* cmd_data = nullptr, Tcl_CmdDeleteProc* delete_proc = nullptr )
  {
    return Tcl_CreateObjCommand( _interp, cmd_name, proc, cmd_data, delete_proc );
  }

  int evalScriptFile( const char* file_name )
  {
    return Tcl_EvalFile( _interp, file_name );
  }

  int evalString( const char* cmd_str )
  {
    return Tcl_Eval( _interp, cmd_str );
  }

  const char* getTclFileName()
  {
    evalString( "set fileName [dict get [info frame 2] file]" );
    const char* file_name = Tcl_GetVar( _interp, "fileName", 0 );
    return file_name;
  }

  unsigned getTclLineNo()
  {
    evalString( "set lineNum [dict get [info frame 2] line]" );
    const char* line_no = Tcl_GetVar( _interp, "lineNum", 0 );
    return std::atoi( line_no );
  }

  void setResult( char* result )
  {
    Tcl_SetResult( _interp, result, nullptr );
  }

  void appendResult( char* result )
  {
    Tcl_AppendResult( _interp, result, nullptr );
  }

  const char* getResult()
  {
    return Tcl_GetStringResult( _interp );
  }

private:
  static TclScript* _instance;
  Tcl_Interp* _interp;
}; // class TclScript

TclScript* TclScript::_instance = nullptr;

} // namespace tcl

} // namespace lf