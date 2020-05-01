
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef WDB_MANAGER__H
#define WDB_MANAGER__H

#include <QMap>
#include <QString>

#include "global-types.h"

#include "accessors.h"


#include "kans.h"

KANS_(DGDB)

class WDB_Instance;

class WDB_Manager
{
 u2 max_num_code_;
 u8 default_mem_size_;

 QMap<u2, WDB_Instance*> whites_;

 WDB_Instance* current_white_;  

public:

 WDB_Manager();

 ACCESSORS(u8 ,default_mem_size)

 ACCESSORS(WDB_Instance* ,current_white)

 WDB_Instance* get_current_white();


 WDB_Instance* new_white(u2 num_code = 0, u8 mem = 0, QString name = {});
 WDB_Instance* new_white(QString name)
 {
  return new_white(0, 0, name);
 }
 WDB_Instance* new_white(u2 num_code, QString name)
 {
  return new_white(num_code, 0, name);
 }

};


_KANS(DGDB)


#endif // WDB_MANAGER__H


