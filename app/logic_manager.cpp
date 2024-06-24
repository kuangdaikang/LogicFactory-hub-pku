#include "layer_logic/logic_manager.hpp"
#include "layer_logic/io/read_gtech.hpp"

#include "layer_logic/api/abc/opt/rewrite.hpp"
#include "layer_logic/api/lsils/opt/balance_sop.hpp"
#include "layer_logic/api/lsils/opt/rewrite_cut.hpp"

int main( int argc, char** argv )
{
  std::string file = std::string( argv[1] );

  lf::logic::LogicManager manager;

  manager.read_gtech( file );

  auto ntk = manager.current<mockturtle::gtg_network>();
  mockturtle::gtg_network tmp_ntk( ntk );

  mockturtle::write_dot<mockturtle::gtg_network>( tmp_ntk, file + ".gtg.dot" );

  lf::logic::lsils::balance<mockturtle::aig_network>( manager );
  lf::logic::lsils::balance_sop<mockturtle::aig_network>( manager );
  lf::logic::lsils::rewrite_cut<mockturtle::aig_network>( manager );
  lf::logic::abc::rewrite( manager );
  return 1;
}