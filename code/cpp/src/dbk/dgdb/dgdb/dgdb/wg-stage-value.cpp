
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wg-stage-value.h"

USING_KANS(DGDB)

WG_Stage_Value::WG_Stage_Value()
  :  info_(0), data_(nullptr)
{

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


void WG_Stage_Value::note_unspec()
{
 info_ ^= 240; 
}

void WG_Stage_Value::note_null()
{
 info_ ^= 240; 
 info_ |= (1 << 4);
}

void WG_Stage_Value::note_rec()
{
 info_ ^= 240; 
 info_ |= (2 << 4);
}

void WG_Stage_Value::note_int()
{
 info_ ^= 240; 
 info_ |= (3 << 4);
}

void WG_Stage_Value::note_dbl()
{
 info_ ^= 240; 
 info_ |= (4 << 4);
}

void WG_Stage_Value::note_str()
{
 info_ ^= 240; 
 info_ |= (5 << 4);
}

void WG_Stage_Value::note_xml()
{
 info_ ^= 240; 
 info_ |= (6 << 4);
}

void WG_Stage_Value::note_uri()
{
 info_ ^= 240; 
 info_ |= (7 << 4);
}

void WG_Stage_Value::note_blob()
{
 info_ ^= 240; 
 info_ |= (8 << 4);
}

void WG_Stage_Value::note_char()
{
 info_ ^= 240; 
 info_ |= (9 << 4);
}

void WG_Stage_Value::note_fixp()
{
 info_ ^= 240; 
 info_ |= (10 << 4);
}

void WG_Stage_Value::note_date()
{
 info_ ^= 240; 
 info_ |= (11 << 4);
}

void WG_Stage_Value::note_time()
{
 info_ ^= 240; 
 info_ |= (12 << 4);
}

void WG_Stage_Value::note_mrec()
{
 info_ ^= 240; 
 info_ |= (13 << 4);
}

void WG_Stage_Value::note_tbd()
{
 info_ ^= 240; 
 info_ |= (14 << 4);
}


void WG_Stage_Value::note_data_has_type()
{
 info_ |= 8; 
}

void WG_Stage_Value::clear_data_has_type()
{
 info_ ^= 8; 
}

void WG_Stage_Value::note_byte_length(u1 len)
{
 switch(len)
 {
 case 1: info_  |= 3; break;
 case 2: info_ ^= 1; info_  |= 2; break;
 case 4: info_ ^= 2; info_  |= 1; break;
 default:
 case 8: info_ ^= 3; break; 
 }
}

void WG_Stage_Value::note_raw()
{
 info_ |= 16; 
}

void WG_Stage_Value::note_ptr()
{
 info_ ^= 16; 
}




