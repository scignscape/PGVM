
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef WG_STAGE_VALUE__H
#define WG_STAGE_VALUE__H

#include <QVector>

#include <functional>

#include "accessors.h"

#include "global-types.h"

#include "kans.h"

KANS_(DGDB)

class DgDb_Node;

class WG_Stage_Value  
{
 u1 info_;
 u8 data_;

public:

 typedef std::function<void(u4, WG_Stage_Value*)> Callback_type;

private:

 struct _run_hold
 {
  struct _run
  {
   WG_Stage_Value* _this;
   u4 arg;
   u1 operator()(WG_Stage_Value::Callback_type cb);
  };
  WG_Stage_Value* _this;
  _run operator[](u4 field_index)
  {
   return {_this, field_index};
  }
  u1 operator()(WG_Stage_Value::Callback_type cb);
 };

public:

 WG_Stage_Value();

 ACCESSORS(u8 ,data)

 WG_Stage_Value& set_ptr_data(void* ptr);

 u1 _run(Callback_type cb, u4 field_index = 0);

 _run_hold run;

 template<typename T>
 WG_Stage_Value& set_data(const T& data)
 {
  set_ptr_data(new T(data));
 }


 WG_Stage_Value& note_unspec();
 WG_Stage_Value& note_null();
 WG_Stage_Value& note_rec();
 WG_Stage_Value& note_int();
 WG_Stage_Value& note_dbl();
 WG_Stage_Value& note_str(); 
 WG_Stage_Value& note_xml();
 WG_Stage_Value& note_uri();
 WG_Stage_Value& note_blob();
 WG_Stage_Value& note_char();
 WG_Stage_Value& note_fixp();
 WG_Stage_Value& note_date();
 WG_Stage_Value& note_time();
 WG_Stage_Value& note_qstring();
 WG_Stage_Value& note_mrec();
 WG_Stage_Value& note_tbd();

 WG_Stage_Value& note_data_has_type();
 WG_Stage_Value& clear_data_has_type();
 WG_Stage_Value& note_byte_length(u1 len);
 WG_Stage_Value& note_raw();
 WG_Stage_Value& clear_raw();

 WG_Stage_Value& new_qstring(const QString& qs);


};



_KANS(DGDB)

#endif // WG_STAGE_VALUE__H


