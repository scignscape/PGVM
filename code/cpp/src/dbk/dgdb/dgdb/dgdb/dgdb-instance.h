
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DGDB_INSTANCE__H
#define DGDB_INSTANCE__H

#include <QString>


#include "accessors.h"

#include "kans.h"

KANS_(DGDB)

class DgDb_Node;
class DgDb_Frame;

class DgDb_Instance
{
 QString db_root_folder_;
 DgDb_Frame* default_frame_;
 DgDb_Frame* current_frame_;

 DgDb_Node* _add(void* v);

public:

 ACCESSORS(QString ,db_root_folder)

 DgDb_Instance();

 template<typename VERTEX_Type>
 DgDb_Node* add(VERTEX_Type* v)
 {
  _add((void*) v);
 }

};


_KANS(DGDB)

#endif // DGDB_INSTANCE__H
