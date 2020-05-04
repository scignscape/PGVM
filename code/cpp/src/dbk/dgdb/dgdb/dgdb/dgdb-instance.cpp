
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "dgdb-instance.h"

#include "graph/dgdb-node.h"
#include "graph/dgdb-frame.h"

#include "types/dgdb-type-builder.h"
#include "types/dgdb-type.h"

#include "wdb-manager.h"

#include <typeinfo>
#include <QDebug> 

USING_KANS(DGDB)

DgDb_Instance::DgDb_Instance()
{
 default_frame_ = new DgDb_Frame();
 current_frame_ = default_frame_;
 current_type_builder_ = new DgDb_Type_Builder;
 wdb_manager_ = new WDB_Manager(this);
}

void DgDb_Instance::to_ntxh(QString& ty, QString& result)
{
 ty = R"(&type DgDb_Instance {2}
  :folder:1 :cc:2 ;
 )";

 result = QString(R"(!/ DgDb_Instance
$folder: %1
$cc: %2
/!

<+>
)").arg(db_root_folder_).arg(Config.Flags);

}

void* DgDb_Instance::new_wg_record(QByteArray& qba, QMap<u4, WG_Stage_Value>& wsvs,
  u4 qba_index, WDB_Instance* wdbi)
{
 void* pv = wdb_manager_->new_wg_record(wsvs, wdbi);
 wdb_manager_->set_qba_data_field(pv, qba_index, qba);
}


void DgDb_Instance::init_from_ntxh(QString fld, u1 code)
{
 Config.Flags = code;
 qDebug() << "code: " << code;
}

void DgDb_Instance::init()
{
 wdb_manager_->set_db_root_folder(db_root_folder_);
 wdb_manager_->init_from_ntxh();
 wdb_manager_->get_current_white();
}

DgDb_Type& DgDb_Instance::register_type(QString tn, QString ctn)
{
 DgDb_Type* result = get_type_by_name(tn);
 if(!result)
 {
  result = new DgDb_Type();
  result->set_name(tn);
  result->set_cname(ctn);
  types_by_name_[tn] = result;
 }
 return *result;
}

void DgDb_Instance::build_default_types()
{
 current_type_builder_->build(&types_by_name_);
}

DgDb_Type* DgDb_Instance::get_type_by_name(QString tn)
{
 return types_by_name_.value(tn);
}

DgDb_Node* DgDb_Instance::_add(void* v, QString tn)
{
 DgDb_Node* result = new DgDb_Node(v);
 current_frame_->add(result);

 qDebug() << "TN is: " << tn;

 return result;
}


