#pragma once

#include "layer_arch/arch_manager.hpp"
#include "utility/string.hpp"

#include <cstdio>
#include <string>
#include <assert.h>

namespace lf
{

namespace arch
{

namespace yosys
{

/**
 * @brief Read the verilog file into the current design.
 * @example
 *  read_verilog [options] [filename]
 *  options: -sv -formal -nosynthesis -noassert -noassume -norestrict -assume-asserts -assert-assumes -nodisplay
 *           -debug -dump_ast1 -dump_ast2 -no_dump_ptr -dump_vlog1 -dump_vlog2 -dump_rtlil -yydebug
 *           -nolatches -nomem2reg -mem2reg -nomeminit -ppdump -nopp -nodpi -noblackbox -lib -nowb -specify -noopt -icells -pwires -nooverwrite -overwrite -defer -noautowire
 *           -setattr <attribute_name> -Dname[=definition] -Idir <folder>
 *
 * @note
 *
 */
void read_verilog( const std::string& file_verilog,
                   bool is_sv = false, bool is_formal = false, bool is_nosynthesis = false, bool is_noassert = false, bool is_noassume = false, bool is_norestrict = false, bool is_assume_asserts = false, bool is_assert_assumes = false, bool is_nodisplay = false,
                   bool is_debug = false, bool is_dump_ast1 = false, bool is_dump_ast2 = false, bool is_no_dump_ptr = false, bool is_dump_vlog1 = false, bool is_dump_vlog2 = false, bool is_dump_rtlil = false, bool is_yydebug = false,
                   bool is_nolatches = false, bool is_nomem2reg = false, bool is_mem2reg = false, bool is_nomeminit = false, bool is_ppdump = false, bool is_nopp = false, bool is_nodpi = false, bool is_noblackbox = false, bool is_lib = false, bool is_nowb = false, bool is_specify = false, bool is_noopt = false, bool is_icells = false, bool is_pwires = false, bool is_nooverwrite = false, bool is_overwrite = false, bool is_defer = false, bool is_noautowire = false,
                   const std::string& setattr = "", const std::string& Dname = "", const std::string& Idir = "" )
{
  std::string script = "read_verilog ";
  if ( !lf::utility::endsWith( file_verilog, ".v" ) )
  {
    std::cerr << "Unmatched verilog suffix type." << std::endl;
    assert( false );
    return;
  }

  if ( is_sv )
    script += " -sv ";
  if ( is_formal )
    script += " -formal ";
  if ( is_nosynthesis )
    script += " -nosynthesis ";
  if ( is_noassert )
    script += " -noassert ";
  if ( is_noassume )
    script += " -noassume ";
  if ( is_norestrict )
    script += " -norestrict ";
  if ( is_assume_asserts )
    script += " -assume-asserts ";
  if ( is_assert_assumes )
    script += " -assert-assumes ";
  if ( is_nodisplay )
    script += " -nodisplay ";
  if ( is_debug )
    script += " -debug ";
  if ( is_dump_ast1 )
    script += " -dump_ast1 ";
  if ( is_dump_ast2 )
    script += " -dump_ast2 ";
  if ( is_no_dump_ptr )
    script += " -no_dump_ptr ";
  if ( is_dump_vlog1 )
    script += " -dump_vlog1 ";
  if ( is_dump_vlog2 )
    script += " -dump_vlog2 ";
  if ( is_dump_rtlil )
    script += " -dump_rtlil ";
  if ( is_yydebug )
    script += " -yydebug ";
  if ( is_nolatches )
    script += " -nolatches ";
  if ( is_nomem2reg )
    script += " -nomem2reg ";
  if ( is_mem2reg )
    script += " -mem2reg ";
  if ( is_nomeminit )
    script += " -nomeminit ";
  if ( is_ppdump )
    script += " -ppdump ";
  if ( is_nopp )
    script += " -nopp ";
  if ( is_nodpi )
    script += " -nodpi ";
  if ( is_noblackbox )
    script += " -noblackbox ";
  if ( is_lib )
    script += " -lib ";
  if ( is_nowb )
    script += " -nowb ";
  if ( is_specify )
    script += " -specify ";
  if ( is_noopt )
    script += " -noopt ";
  if ( is_icells )
    script += " -icells ";
  if ( is_pwires )
    script += " -pwires ";
  if ( is_nooverwrite )
    script += " -nooverwrite ";
  if ( is_overwrite )
    script += " -overwrite ";
  if ( is_defer )
    script += " -defer ";
  if ( is_noautowire )
    script += " -noautowire ";
  if ( !setattr.empty() )
    script += " -setattr " + setattr;
  if ( !Dname.empty() )
    script += " -Dname " + Dname;
  if ( !Idir.empty() )
    script += " -Idir " + Idir;

  script += " " + file_verilog;

  auto frame = lfAmINST->current<Yosys::RTLIL::Design*>();

  Yosys::run_pass( script, frame );
}

} // namespace yosys

} // namespace arch

} // end namespace lf