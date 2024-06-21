#include "layer_logic/op/graphmize.hpp"
#include "layer_logic/op/convert.hpp"

#include "lorina/lorina.hpp"
#include "mockturtle/mockturtle.hpp"

#include <iostream>

int main( int argc, char** argv )
{
  std::string file_in = std::string( argv[1] );
  std::string file_out = std::string( argv[2] );

  mockturtle::gtg_network gtg; // load into gtg

  mockturtle::aig_network aig;
  mockturtle::xmg_network xmg;
  mockturtle::xag_network xag;
  mockturtle::mig_network mig;

  mockturtle::read_verilog_params ports;
  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );

  auto rc = lorina::read_gtech( file_in, mockturtle::gtech_reader( gtg, ports ), &diag );

  if ( rc != lorina::return_code::success )
  {
    std::cout << "parser wrong!" << std::endl;
  }

  std::cout << "create aig ing\n";
  aig = lf::logic::convert_lsils_internal<mockturtle::aig_network, mockturtle::gtg_network>( gtg );
  std::cout << "create xmg ing\n";
  xmg = lf::logic::convert_lsils_internal<mockturtle::xmg_network, mockturtle::gtg_network>( gtg );
  std::cout << "create xag ing\n";
  xag = lf::logic::convert_lsils_internal<mockturtle::xag_network, mockturtle::gtg_network>( gtg );
  std::cout << "create mig ing\n";
  mig = lf::logic::convert_lsils_internal<mockturtle::mig_network, mockturtle::gtg_network>( gtg );

  lf::logic::graphmize( gtg, file_out + ".gtg.graphml" );
  lf::logic::graphmize( aig, file_out + ".aig.graphml" );
  lf::logic::graphmize( xmg, file_out + ".xmg.graphml" );
  lf::logic::graphmize( xag, file_out + ".xag.graphml" );
  lf::logic::graphmize( mig, file_out + ".mig.graphml" );

  std::cout << "success!\n";
  return 1;
}
