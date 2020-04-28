
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include "dgdb/dgdb-instance.h"
#include "dgdb/dgenvironment.h"

#include "dgdb/types/dgdb-type.h"

#include "global-types.h"


USING_KANS(DGDB)

struct Test
{
 QString title;
 QString author;
};

int main(int argc, char* argv[])
{
 DgDb_Instance* dgi = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/t1");

// dgi->register_type_name_resolution<QString>("QString");
// dgi->register_type_name_resolution<Test>("Test");

 dgi->REGISTER_TYPE_NAME_RESOLUTION(QString);
 dgi->REGISTER_TYPE_NAME_RESOLUTION(Test);
// dgi->register_type_name_resolution<QVector<u1>>("(QVector u1)");

 dgi->REGISTER_TYPE_NAME_RESOLUTION_2_1(QVector ,u1);

 dgi->build_default_types();


 QString* qs = new QString("OK");
 DgDb_Node* dgn = dgi->add(qs);

 Test* test = new Test{"Crit", "IK"};

 DgDb_Node* dgn1 = dgi->add(test);

 DgDb_Node* dgn2 = dgi->add(new QVector<u1> {4, 44, 64});

// DgDb_Node* dgn3 = dgi->add(new u2 {4});

 
 DgDb_Type* ty_u1 = dgi->get_type_by_name("u1");
 qDebug() << "OK: " << ty_u1->name();   


 qDebug() << "OK: " << dgi->db_root_folder();
 return 0;
}


