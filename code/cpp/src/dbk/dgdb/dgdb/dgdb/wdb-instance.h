
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef WDB_INSTANCE__H
#define WDB_INSTANCE__H

#include <QString>

#include "kans.h"

KANS_(DGDB)


class WDB_Instance
{
 void* white_;
 QString name_; 

public:

 WDB_Instance(void* w, QString n = {}); 

};


_KANS(DGDB)


#endif // WDB_INSTANCE__H


