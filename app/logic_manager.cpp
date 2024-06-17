#include "lorina/lorina.hpp"
#include "mockturtle/mockturtle.hpp"

#include "layer_logic/logic_manager.hpp"

// #include "layer_logic/io/read_gtech.hpp"

// #include "layer_logic/api/abc/opt/rewrite.hpp"
// #include "layer_logic/api/lsils/opt/balance_sop.hpp"
// #include "layer_logic/api/lsils/opt/rewrite_cut.hpp"

int main( int argc, char** argv )
{
  std::string file = std::string( argv[1] );

  lf::logic::LogicManager manager;

  //   lf::logic::read_gtech<mockturtle::aig_network>( file, manager );

  //   lf::logic::lsils::balance_sop( manager );
  //   lf::logic::abc::rewrite( manager );
  //   lf::logic::lsils::rewrite_cut( manager );
  //   lf::logic::abc::rewrite( manager );
  //   lf::logic::lsils::balance_sop( manager );
  return 1;
}