
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#ifndef DGDB_INSTANCE__H
#define DGDB_INSTANCE__H

#include <QString>

#include <QMap>

#include "accessors.h"

#include "kans.h"

#ifndef REGISTER_TYPE_NAME_RESOLUTION
#define REGISTER_TYPE_NAME_RESOLUTION(tn) \
register_type_name_resolution<tn>(#tn)
#endif


KANS_(DGDB)

class DgDb_Node;
class DgDb_Frame;

class DgDb_Instance
{
 QString db_root_folder_;
 DgDb_Frame* default_frame_;
 DgDb_Frame* current_frame_;

 DgDb_Node* _add(void* v, QString tn);

 QMap<QString, QString> type_name_resolutions_;

public:

 ACCESSORS(QString ,db_root_folder)

 DgDb_Instance();

 template<typename VERTEX_Type>
 QString register_type_name_resolution(QString desired)
 {
  QString tn = QString::fromStdString(typeid(VERTEX_Type).name());
  type_name_resolutions_[tn] = desired;
  return tn;
 }

 template<typename VERTEX_Type>
 DgDb_Node* add(VERTEX_Type* v)
 {
  QString tn = QString::fromStdString(typeid(VERTEX_Type).name());
  tn = type_name_resolutions_.value(tn, tn);
  _add((void*) v, tn);
 }

};


_KANS(DGDB)

#endif // DGDB_INSTANCE__H
