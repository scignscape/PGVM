
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef WG_STAGE_VALUE__H
#define WG_STAGE_VALUE__H

#include <QVector>

#include "accessors.h"

#include "global-types.h"

#include "kans.h"

KANS_(DGDB)

class DgDb_Node;

class WG_Stage_Value  
{
 u1 info_;
 void* data_;

public:

 WG_Stage_Value();

 void note_unspec();
 void note_null();
 void note_rec();
 void note_int();
 void note_dbl();
 void note_str(); 
 void note_xml();
 void note_uri();
 void note_blob();
 void note_char();
 void note_fixp();
 void note_date();
 void note_time();
 void note_mrec();
 void note_tbd();

 void note_data_has_type();
 void clear_data_has_type();
 void note_byte_length(u1 len);
 void note_raw();
 void note_ptr();
};



_KANS(DGDB)

#endif // WG_STAGE_VALUE__H


