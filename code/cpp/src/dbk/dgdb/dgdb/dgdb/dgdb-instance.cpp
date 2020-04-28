
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-instance.h"

#include "graph/dgdb-node.h"
#include "graph/dgdb-frame.h"

USING_KANS(DGDB)

DgDb_Instance::DgDb_Instance()
{
 default_frame_ = new DgDb_Frame();
 current_frame_ = default_frame_;
}

DgDb_Node* DgDb_Instance::_add(void* v)
{
 DgDb_Node* result = new DgDb_Node(v);
 current_frame_->add(result);
 return result;
}


