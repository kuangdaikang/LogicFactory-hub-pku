#include "layer_logic/op/graphmize.hpp"
#include "layer_logic/op/convert.hpp"
#include "lorina/lorina.hpp"
#include "mockturtle/mockturtle.hpp"

#include <iostream>

int main( int argc, char** argv )
{
  std::string file = std::string( argv[1] );

  mockturtle::gtg_network gtg; // load into gtg

  mockturtle::aig_network aig;
  mockturtle::xmg_network xmg;
  mockturtle::xag_network xag;
  mockturtle::mig_network mig;

  mockturtle::read_verilog_params ports;
  lorina::text_diagnostics consumer;
  lorina::diagnostic_engine diag( &consumer );

  auto rc = lorina::read_gtech( file, mockturtle::gtech_reader( gtg, ports ), &diag );

  if ( rc != lorina::return_code::success )
  {
    std::cout << "parser wrong!" << std::endl;
  }

  std::cout << "create aig ing\n";
  aig = lf::convert<mockturtle::aig_network, mockturtle::gtg_network>( gtg );
  std::cout << "create xmg ing\n";
  xmg = lf::convert<mockturtle::xmg_network, mockturtle::gtg_network>( gtg );
  std::cout << "create xag ing\n";
  xag = lf::convert<mockturtle::xag_network, mockturtle::gtg_network>( gtg );
  std::cout << "create mig ing\n";
  mig = lf::convert<mockturtle::mig_network, mockturtle::gtg_network>( gtg );

  lf::graphmize( gtg, "test.gtg.graphml" );
  lf::graphmize( aig, "test.aig.graphml" );
  lf::graphmize( xmg, "test.xmg.graphml" );
  lf::graphmize( xag, "test.xag.graphml" );
  lf::graphmize( mig, "test.mig.graphml" );

  std::cout << "success!\n";
  return 1;
}
