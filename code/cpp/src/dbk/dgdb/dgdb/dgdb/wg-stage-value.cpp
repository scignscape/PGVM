
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wg-stage-value.h"

USING_KANS(DGDB)

WG_Stage_Value::WG_Stage_Value()
  :  info_(0), data_(0), run({this})
{

}

WG_Stage_Value& WG_Stage_Value::set_ptr_data(void* ptr)
{
 data_ = (u8) ptr;
 return *this;
}

u1 WG_Stage_Value::_run_hold::_run::operator()(WG_Stage_Value::Callback_type cb)
{
 return _this->_run(cb, arg);
}

u1 WG_Stage_Value::_run_hold::operator()(WG_Stage_Value::Callback_type cb)
{
 return _this->_run(cb);
}

u1 WG_Stage_Value::_run(Callback_type cb, u4 field_index)
{
 cb(field_index, this);
 return info_;
}

WG_Stage_Value& WG_Stage_Value::new_qstring(const QString& qs)
{
 note_qstring().set_data(qs);
}



// // #define WG_NULLTYPE 1
// // #define WG_RECORDTYPE 2
// // #define WG_INTTYPE 3
// // #define WG_DOUBLETYPE 4
// // #define WG_STRTYPE 5
// // #define WG_XMLLITERALTYPE 6
// // #define WG_URITYPE 7
// // #define WG_BLOBTYPE 8
// // #define WG_CHARTYPE 9
// // #define WG_FIXPOINTTYPE 10
// // #define WG_DATETYPE 11
// // #define WG_TIMETYPE 12

u1 WG_Stage_Value::get_encoding_type() const
{
 return info_ >> 4;
}

WG_Stage_Value& WG_Stage_Value::note_unspec()
{
 info_ &= 15;
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_null()
{
 info_ &= 15;
 info_ |= (1 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_rec()
{
 info_ &= 15;
 info_ |= (2 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_int()
{
 info_ &= 15;
 info_ |= (3 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_dbl()
{
 info_ &= 15;
 info_ |= (4 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_str()
{
 info_ &= 15;
 info_ |= (5 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_xml()
{
 info_ &= 15;
 info_ |= (6 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_uri()
{
 info_ &= 15;
 info_ |= (7 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_blob()
{
 info_ &= 15;
 info_ |= (8 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_char()
{
 info_ &= 15;
 info_ |= (9 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_fixp()
{
 info_ &= 15;
 info_ |= (10 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_date()
{
 info_ &= 15;
 info_ |= (11 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_time()
{
 info_ &= 15;
 info_ |= (12 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_qstring()
{
 info_ &= 15;
 info_ |= (13 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_mrec()
{
 info_ &= 15;
 info_ |= (14 << 4);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_tbd()
{
 info_ &= 15;
 info_ |= (15 << 4);
 return *this;
}


WG_Stage_Value& WG_Stage_Value::note_data_has_type()
{
 info_ |= 8;
 return *this;
}

WG_Stage_Value& WG_Stage_Value::clear_data_has_type()
{
 info_ &= (255 - 8);
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_byte_length(u1 len)
{
 switch(len)
 {
 case 1: info_  |= 3; break;
 case 2: info_ &= (255 - 1); info_  |= 2; break;
 case 4: info_ &= (255 - 2); info_  |= 1; break;
 default:
 case 8: info_ &= (255 - 3); break;
 }
 return *this;
}

WG_Stage_Value& WG_Stage_Value::note_raw()
{
 info_ |= 16;
 return *this;
}

WG_Stage_Value& WG_Stage_Value::clear_raw()
{
 info_ &= (255 - 16);
 return *this;
}


