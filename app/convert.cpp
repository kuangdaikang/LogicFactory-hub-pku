#include "lorina/lorina.hpp"
#include "mockturtle/mockturtle.hpp"

#include "layer_logic/misc/convert.hpp"

#include <iostream>

int main( int argc, char** argv )
{
  std::string file_in = std::string( argv[1] );
  std::string file_out = std::string( argv[2] );

  mockturtle::sequential<mockturtle::gtg_network> gtg; // load into gtg

  mockturtle::sequential<mockturtle::aig_network> aig;
  mockturtle::sequential<mockturtle::xmg_network> xmg;
  mockturtle::sequential<mockturtle::xag_network> xag;
  mockturtle::sequential<mockturtle::mig_network> mig;

  mockturtle::read_verilog_params ports;
  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );

  auto rc = lorina::read_gtech( file_in, mockturtle::gtech_reader( gtg, ports ), &diag );

  if ( rc != lorina::return_code::success )
  {
    std::cout << "parser wrong!" << std::endl;
    return 0;
  }

  std::cout << "create aig ing\n";
  aig = lf::logic::convert_lsils_internal<mockturtle::sequential<mockturtle::aig_network>, mockturtle::sequential<mockturtle::gtg_network>>( gtg );
  std::cout << "create xmg ing\n";
  xmg = lf::logic::convert_lsils_internal<mockturtle::sequential<mockturtle::xmg_network>, mockturtle::sequential<mockturtle::gtg_network>>( gtg );
  std::cout << "create xag ing\n";
  xag = lf::logic::convert_lsils_internal<mockturtle::sequential<mockturtle::xag_network>, mockturtle::sequential<mockturtle::gtg_network>>( gtg );
  std::cout << "create mig ing\n";
  mig = lf::logic::convert_lsils_internal<mockturtle::sequential<mockturtle::mig_network>, mockturtle::sequential<mockturtle::gtg_network>>( gtg );

  mockturtle::write_dot( gtg, file_out + ".gtg.dot" );
  mockturtle::write_dot( aig, file_out + ".aig.dot" );
  mockturtle::write_dot( xmg, file_out + ".xmg.dot" );
  mockturtle::write_dot( xag, file_out + ".xag.dot" );
  mockturtle::write_dot( mig, file_out + ".mig.dot" );

  std::cout << "success!\n";
  return 1;
}
