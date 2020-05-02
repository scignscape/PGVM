
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wdb-manager.h"

#include "wdb-instance.h"

extern "C" {
#include "_whitedb/_whitedb.h"
}


USING_KANS(DGDB)


WDB_Manager::WDB_Manager()
  :  max_num_code_(1000), default_mem_size_(0), current_white_(0)
{


}

WDB_Instance* WDB_Manager::get_current_white()
{
 if(!current_white_)
 {
  current_white_ = new_white();
 }
 return current_white_;
}


WDB_Instance* WDB_Manager::new_white(u2 num_code, u8 mem, QString name)
{
 if(num_code == 0)
 {
  max_num_code_ += 100;
  num_code = max_num_code_;
 }
 if(mem == 0)
   mem = default_mem_size_;

 void* db = wg_attach_database(QString::number(num_code).toLatin1().data(), mem);
 WDB_Instance* result = new WDB_Instance(db, name);
 whites_[num_code] = result;

 if(!name.isEmpty())
 {
  whites_by_name_[name] = result;
 }

 return result; 
}

