
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef WG_STAGE_VALUE__H
#define WG_STAGE_VALUE__H

#include <QVector>

#include <QDateTime>
#include <QDate>

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
// ACCESSORS(u1 ,info)

 WG_Stage_Value& set_ptr_data(void* ptr);

 u1 get_encoding_type() const;

 u1& operator()(void* pv)
 {
  data_ = (u8) pv;
  return info_;
 }

 u1 _run(Callback_type cb, u4 field_index = 0);

 _run_hold run;

 template<typename T>
 T& data_to_ref()
 {
  return *((T*) data_);
 }

 template<typename T>
 WG_Stage_Value& set_data(const T& data)
 {
  set_ptr_data(new T(data));
  return *this;
 }

 template<typename T>
 WG_Stage_Value& set_raw_data(const T& data)
 {
  data_ = data;
  return *this;
 }

 void cleanup()
 {
  delete (void*) data_;
  data_ = 0;
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

 template<typename T>
 WG_Stage_Value& set_int_data(T t)
 {
  note_int();
  set_raw_data(t);
  return *this;
 }

 WG_Stage_Value& set_null_data()
 {
  note_null();
  set_raw_data(0);
  return *this;
 }

 WG_Stage_Value& set_char_data(u1 chr)
 {
  note_char();
  set_raw_data(chr);
  return *this;
 }

 WG_Stage_Value& set_char_data(QChar chr)
 {
  return set_char_data(chr.toLatin1());
 }

 WG_Stage_Value& set_rec_data(void* rec)
 {
  note_rec();
  set_ptr_data(rec);
  return *this;
 }

 template<typename T>
 WG_Stage_Value& set_double_data(T t)
 {
  T* tt = new T(t);
  note_dbl();
  set_ptr_data(tt);
  return *this;
 }

 template<typename T>
 WG_Stage_Value& set_fixpoint_data(T t)
 {
  u4 lft = (u4) t;
  u4 rgt = (u4) 10000 * (t - lft);
  
  note_fixp();
  set_raw_data( ((u8) (lft << 32)) | rgt);
  return *this;
 }

 WG_Stage_Value& set_date_data(QDate qdt)
 {
  note_date();
  set_raw_data(qdt.toJulianDay());
  return *this;
 }

 WG_Stage_Value& set_time_data(QDateTime qdt)
 {
  note_time();
  set_raw_data(qdt.toMSecsSinceEpoch());
  return *this;
 }

 WG_Stage_Value& set_str_data(char* cs, u4 len = 0)
 {
  if(len == 0) len = strlen(cs) + 1;
  char* ncs = (char*) malloc(len);
  strcpy(ncs, cs);
  note_str();
  set_ptr_data(ncs);
  return *this;
 }

 WG_Stage_Value& set_xml_data(QString str, u4 len = 0) //, QString xsd = {})
 {
  const char* cs = str.toLatin1().constData();
  if(len == 0) len = strlen(cs) + 1;
  char* ncs = (char*) malloc(len);
  strcpy(ncs, cs);
  note_xml();
  set_ptr_data(ncs);
  return *this;
 }

 WG_Stage_Value& set_uri_data(QString str, u4 len = 0) //, QString xsd = {})
 {
  const char* cs = str.toLatin1().constData();
  if(len == 0) len = strlen(cs) + 1;
  char* ncs = (char*) malloc(len);
  strcpy(ncs, cs);
  note_uri();
  set_ptr_data(ncs);
  return *this;
 }

 WG_Stage_Value& set_blob_data(char* blob, u4 len) //, QString xsd = {})
 {
  note_blob();
  QPair<u4, char*>* pr = new QPair<u4, char*>(len, blob);
  set_ptr_data(pr);
  return *this;
 }

};



_KANS(DGDB)

#endif // WG_STAGE_VALUE__H


