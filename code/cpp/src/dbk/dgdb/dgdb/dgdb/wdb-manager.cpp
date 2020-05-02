
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wdb-manager.h"

#include "wdb-instance.h"


#include <QDebug>

#include "kans.h"
#include "textio.h"

#include "phaong/phaong.h"
#include "phaong/phaong-types.h"

#include "ntxh-parser/ntxh-document.h"

// #include "ntxh/ntxh-parser/ntxh-document.h"


USING_KANS(TextIO)

extern "C" {
#include "_whitedb/_whitedb.h"
}


USING_KANS(DGDB)


WDB_Manager::WDB_Manager()
  :  max_num_code_(1000), default_mem_size_(0), current_white_(0)
{


}

WDB_Instance* WDB_Manager::get_current_white()
{
 if(!current_white_)
 {
  current_white_ = new_white();
 }
 return current_white_;
}

void WDB_Manager::update_ntxh()
{
 QString ntxh;
 to_ntxh(ntxh);
 save_file(db_root_folder_ + "/" + "manager.ntxh", ntxh);  
}

void WDB_Manager::to_ntxh(QString& result)
{
 result = R"(
&type WDB_Instance {4}
  :name:1 :created:2 :attached:3 :llff:4 ;

&/
 )";

 for(WDB_Instance* white : whites_.values())
 {
  QString wr;
  white->to_ntxh(wr);
  result += "\n" + wr + "\n";
 }

 result += "/&\n\n";
}


void WDB_Manager::init_from_ntxh()
{
 //QString ntxh;
 //load_file(db_root_folder_ + "/" + "manager.ntxh", ntxh);   
 NTXH_Document doc(db_root_folder_ + "/" + "manager.ntxh");
 doc.parse();

 typedef NTXH_Graph::hypernode_type hypernode_type;

 QVector<hypernode_type*>& hns = doc.top_level_hypernodes(); 
 for(hypernode_type* hn : hns)
 {
  QString name;
  QVector<QDateTime> dts {{},{},{}}; 

  doc.graph()->get_sfsr(hn, {{1,4}}, 
  [&name, &dts, this](QVector<QPair<QString, void*>>& prs)
  {
   name = prs[0].first;
   std::transform(prs.begin() + 1, prs.end(), dts.begin(), 
     [](const QPair<QString, void*>& pr) -> QDateTime
     { 
      if(!pr.first.isEmpty())
        return QDateTime::fromString(pr.first);
     });
  });

  qDebug() << "Name: " << name;

  qDebug() << "dts: " << dts;
 }
 
}


WDB_Instance* WDB_Manager::new_white(u2 num_code, u8 mem, QString name)
{
 if(num_code == 0)
 {
  max_num_code_ += 100;
  num_code = max_num_code_;
 }
 if(mem == 0)
   mem = default_mem_size_;

 void* db = wg_attach_database(QString::number(num_code).toLatin1().data(), mem);
 WDB_Instance* result = new WDB_Instance(db, name);
 result->set_creation_datetime();

 whites_[num_code] = result;

 if(!name.isEmpty())
 {
  whites_by_name_[name] = result;
 }

 update_ntxh();

 return result; 
}

