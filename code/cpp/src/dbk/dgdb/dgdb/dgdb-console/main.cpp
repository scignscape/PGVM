
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>
#include <QByteArray>
#include <QDataStream>

#include "dgdb/dgdb-instance.h"
#include "dgdb/wdb-manager.h"
#include "dgdb/dgenvironment.h"

#include "dgdb/types/dgdb-type.h"

#include "dgdb/wg-stage-value.h"

#include "global-types.h"


USING_KANS(DGDB)


struct Test
{
 QString title;
 QString author;
 u2 num;

 void encode_wg_stage_values(QByteArray& qba,
    // WG_Stage_Value& wgv, 
   WG_Stage_Value::Callback_type cb); 

 //QMap<u4, WG_Stage_Value*>& indexers);

};

void Test::encode_wg_stage_values(QByteArray& qba,
    // WG_Stage_Value& wgv, 
   WG_Stage_Value::Callback_type cb)
{
 QDataStream qds(&qba, QIODevice::WriteOnly);
 qds << WG_Stage_Value().new_qstring(title).run[1](cb)
   << author 
   << WG_Stage_Value().note_int().set_raw_data(num).run[2](cb);
}




int main(int argc, char* argv[])
{
// std::function<void(Test*, QByteArray& qba, 
//   WG_Stage_Value::Callback_type cb)> fn = &Test::encode_wg_stage_value;

 DgDb_Instance* dgi = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/t1");

 dgi->Config.flags.scratch_mode = true;
 dgi->init();


 dgi->REGISTER_TYPE_NAME_RESOLUTION(QString);
 dgi->REGISTER_TYPE_NAME_RESOLUTION(Test);

 dgi->REGISTER_TYPE(Test)
   .default_object_layout()
   .set_stage_encoder(&Test::encode_wg_stage_values);
 
 DgDb_Type* testt = dgi->get_type_by_name("Test");

 std::function<void(void*, QByteArray& qba, 
   WG_Stage_Value::Callback_type cb)> fn = testt->stage_encoder();

 QMap<u4, WG_Stage_Value> svals;

 WG_Stage_Value::Callback_type cb = [dgi, &svals](u4 u, WG_Stage_Value* v)
 {
  qDebug() << "U4: " << u;
  //QString* vv = (QString*) v->data();
  //qDebug() << "vv: " << *vv;
  svals[u] = *v;
  //QMap<u4, WG_Stage_Value*> qm{{u, v}};//
  //qm[u] = v; //{{u, v}}};
  //dgi->wdb_manager()->new_wg_record(qm);

 };

 //dgi->register_type("Test")

 //dgi->register_type_interface("Test", )

// dgi->register_type_name_resolution<QVector<u1>>("(QVector u1)");

 dgi->REGISTER_TYPE_NAME_RESOLUTION_2_1(QVector ,u1);

 dgi->build_default_types();


 QString* qs = new QString("OK");
 DgDb_Node* dgn = dgi->add(qs);

 Test* test = new Test{"Critique of Pure Reason", "IK", 77};
 QByteArray qba;
 fn(test, qba, cb);

 dgi->wdb_manager()->new_wg_record(svals);

 QDataStream qds(qba);
 u1 uuu;
 qds >> uuu;
 QString ttt;
 qds >> ttt;

 DgDb_Node* dgn1 = dgi->add(test);

 DgDb_Node* dgn2 = dgi->add(new QVector<u1> {4, 44, 64});

// DgDb_Node* dgn3 = dgi->add(new u2 {4});

 
 DgDb_Type* ty_u1 = dgi->get_type_by_name("u1");
 qDebug() << "OK: " << ty_u1->name();   


 qDebug() << "OK: " << dgi->db_root_folder();
 return 0;
}


