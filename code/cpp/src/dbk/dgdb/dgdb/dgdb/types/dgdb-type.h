
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef DGDB_TYPE__H
#define DGDB_TYPE__H

#include <functional>

#include "global-types.h"

#include "accessors.h"

#include "kans.h"

KANS_(DGDB)

class DgDb_Node;

class DgDb_Type
{
 std::function<void*(DgDb_Node*, 
   std::function<void*(u8)> )> binary_encoder_;
 void* xnode_;

public:

 ACCESSORS(MACRO_PASTE(std::function<void*(DgDb_Node*, 
   std::function<void*(u8)> )>) ,binary_encoder)

 DgDb_Type();

 

};


_KANS(DGDB)

#endif // DGDB_NODE__H


