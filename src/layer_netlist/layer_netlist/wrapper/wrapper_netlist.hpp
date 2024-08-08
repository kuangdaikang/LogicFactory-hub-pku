#pragma once

#include "layer_netlist/netlist_manager.hpp"

#include "layer_logic/api/abc/frame.hpp"
#include "layer_logic/api/lsils/frame.hpp"

#include "platform/data_manager/idm.h"
#include "database/manager/builder/builder.h"
#include "database/data/design/IdbDesign.h"

#include <map>

namespace lf
{

namespace netlist
{

struct WrapperAbcNetlist
{
public:
  babc::Abc_Frame_t* frame_abc = nullptr;
  idb::IdbBuilder* frame_idb = nullptr;

  // mapping
  std::map<idb::IdbInstance*, babc::Abc_Obj_t*> idb2abc_instance;
  std::map<babc::Abc_Obj_t*, idb::IdbInstance*> abc2idb_instance;

  std::map<idb::IdbPin*, babc::Abc_Obj_t*> idb2abc_port;
  std::map<babc::Abc_Obj_t*, idb::IdbPin*> abc2idb_port;

  std::map<idb::IdbNet*, babc::Abc_Obj_t*> idb2abc_net;
  std::map<babc::Abc_Obj_t*, idb::IdbNet*> abc2idb_net;

public:
  WrapperAbcNetlist( babc::Abc_Frame_t* frame_abc, idb::IdbBuilder* frame_idb )
      : frame_abc( frame_abc ),
        frame_idb( frame_idb )
  {
    // assert( babc::Abc_NtkIsMappedNetlist( frame_abc ) );

    // babc::Abc_Obj_t *pObj, *pNode0, *pNode1;

    // auto c_zero = babc::Abc_ObjNot( babc::Abc_AigConst1( pNtk ) );
    // auto c_one = babc::Abc_AigConst1( pNtk );

    // // primary inputs
    // babc::Abc_NtkForEachPi( pNtk, pObj, i )
    // {
    // }
  }
};

void wrapper_abc_netlist( const babc::Abc_Frame_t* frame_abc, idb::IdbBuilder* frame_idb )
{
  WrapperAbcNetlist wrapper( frame_abc, frame_idb );
}

} // namespace netlist

} // namespace lf