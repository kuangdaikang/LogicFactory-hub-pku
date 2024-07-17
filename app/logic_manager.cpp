#include "layer_logic/logic_manager.hpp"

#include "layer_logic/io/read_gtech.hpp"
#include "layer_logic/io/read_genlib.hpp"
#include "layer_logic/io/read_liberty.hpp"

#include "layer_logic/api/abc/opt/rewrite.hpp"
#include "layer_logic/api/lsils/opt/balance.hpp"
#include "layer_logic/api/lsils/opt/rewrite.hpp"

#include "layer_logic/api/abc/map/map_asic.hpp"
#include "layer_logic/api/abc/map/map_fpga.hpp"
#include "layer_logic/api/lsils/map/map_asic.hpp"
#include "layer_logic/api/lsils/map/map_fpga.hpp"

int main( int argc, char** argv )
{
  std::string file = std::string( argv[1] );
  std::string genlib = std::string( argv[2] );

  lfLmINST->start();

  lf::logic::read_gtech( file );
  lf::logic::read_genlib( genlib );

  mockturtle::write_dot<lf::logic::lsils::gtg_seq_network>( lfLmINST->current<lf::logic::lsils::gtg_seq_network>(), file + ".gtg.start.dot" );

  lf::logic::lsils::balance_sop<lf::logic::lsils::aig_seq_network>();
  lf::logic::abc::rewrite();
  lf::logic::lsils::rewrite_cut<lf::logic::lsils::aig_seq_network>();
  lf::logic::abc::rewrite();
  lf::logic::lsils::balance_sop<lf::logic::lsils::aig_seq_network>();
  lf::logic::abc::rewrite();
  lf::logic::lsils::rewrite_cut<lf::logic::lsils::aig_seq_network>();

  mockturtle::write_dot<lf::logic::lsils::aig_seq_network>( lfLmINST->current<lf::logic::lsils::aig_seq_network>(), file + ".aig.stop.dot" );

  // lf::logic::abc::map_asic(  );
  // lf::logic::abc::map_fpga(  );

  lf::logic::lsils::map_asic();
  lf::logic::lsils::map_fpga();

  lfLmINST->stop();

  return 1;
}