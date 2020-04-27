
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


class DgDb_Instance
{
 QString db_root_folder_;

public:

 ACCESSORS(QString ,db_root_folder)

 DgDb_Instance();

};


_KANS(DGDB)

#endif // DGDB_INSTANCE__H
