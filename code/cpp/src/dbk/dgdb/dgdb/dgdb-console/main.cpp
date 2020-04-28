
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include <QDebug>

#include "dgdb/dgdb-instance.h"
#include "dgdb/dgenvironment.h"

USING_KANS(DGDB)

struct Test
{
 QString title;
 QString author;
}

int main(int argc, char* argv[])
{
 DgDb_Instance* dgi = DGEnvironment(
   DEFAULT_DEV_DGDB_FOLDER "/instances/t1");

 QString* qs = new QString("OK");
 DgDb_Node* dgn = dgi->add(qs);

 qDebug() << "OK: " << dgi->db_root_folder();
 return 0;
}


