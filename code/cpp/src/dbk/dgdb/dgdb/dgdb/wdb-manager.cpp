
//           Copyright Nathaniel Christen 2020.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)


#include "wdb-manager.h"

#include "wdb-instance.h"

#include "wg-stage-value.h"

#include "dgdb-instance.h"

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


WDB_Manager::WDB_Manager(DgDb_Instance* dgdb_instance)
  :  dgdb_instance_(dgdb_instance), 
     max_num_code_(1000), default_mem_size_(0), current_white_(0)
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
 //QString wty;

 QString dty; 
 QString dr;
 dgdb_instance_->to_ntxh(dty, dr);

 //result = WDB_Instance::static_to_ntxh();
 result = QString(R"(

%1

%2

&/

%3
 )").arg(dty).arg(WDB_Instance::static_to_ntxh()).arg(dr);

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

 QVectorIterator<hypernode_type*> it(hns);

 hypernode_type* hn = it.next();
 doc.graph()->get_sfs(hn, {1,2}, 
   [this](QVector<QPair<QString, void*>>& prs)
 {
  QString fld = prs[0].first;
  qDebug() << "fld: " << fld;
  u1 code = prs[1].first.toInt();
  dgdb_instance_->init_from_ntxh(fld, code);
 });

 //for(hypernode_type* hn : hns)
 while(it.hasNext())
 {
  hypernode_type* hn = it.next();
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

void* WDB_Manager::new_wg_record(QMap<u4, WG_Stage_Value>& wsvs,
  WDB_Instance* wdbi)
{
 if(!wdbi)
   wdbi = current_white_;

 void* wh = wdbi->white();

 QMutableMapIterator<u4, WG_Stage_Value> it(wsvs);

 QMap<u4, wg_int> wgim;

 u4 max = 0;

 while(it.hasNext())
 {
  it.next();

  u1 index = it.key();
  if(index > max)
    max = index;

  WG_Stage_Value& wsv = it.value();

  u1 et = wsv.get_encoding_type();


  switch(et)
  {
  case WG_RECORDTYPE: 
   {
    wg_int wi = wg_encode_record(wh, (void*) wsv.data());
    wgim[index] = wi;
   }
   break; 

  case WG_INTTYPE:
   {
    wg_int wi = wg_encode_int(wh, wsv.data());
    wgim[index] = wi;
//    int i = wg_decode_int(wh, wi);
//    qDebug() << "Ti: " << i;
   }
   break;

  case WG_DOUBLETYPE:
   {
    double* dbl = (double*) wsv.data();
    wg_int wi = wg_encode_double(wh, *dbl);
    wgim[index] = wi;
    wsv.cleanup();
   }
   break;

  case WG_STRTYPE:
   {
    char* cs = (char*) wsv.data();
    wg_int wi = wg_encode_str(wh, cs, nullptr);
    wgim[index] = wi;    
    wsv.cleanup();
   }
   break;

  case WG_XMLLITERALTYPE:
   {
    char* cs = (char*) wsv.data();
    wg_int wi = wg_encode_xmlliteral(wh, cs, nullptr);
    wgim[index] = wi;
    wsv.cleanup();
   }
   break;

  case WG_URITYPE:
   {
    char* cs = (char*) wsv.data();
    wg_int wi = wg_encode_uri(wh, cs, nullptr);
    wgim[index] = wi;
    wsv.cleanup();
   }
   break;

  case WG_BLOBTYPE:
   {
    QPair<u4, char*>* pr = (QPair<u4, char*>*) wsv.data();
    wg_int wi = wg_encode_blob(wh, pr->second, nullptr, pr->first);
    wgim[index] = wi;
    wsv.cleanup();
   }
   break;

  case WG_CHARTYPE:
   {
    wg_int wi = wg_encode_char(wh, wsv.data());
    wgim[index] = wi;
   }
   break;

  case WG_FIXPOINTTYPE:
   {
    u4 rgt = wsv.data() & 0xFFFFFFFF;
    u4 lft = wsv.data() >> 32;
    double dbl = rgt + (lft/10000);
    wg_int wi = wg_encode_double(wh, dbl);
    wgim[index] = wi;
   }
   break;

  case WG_DATETYPE:
   {
    wg_int wi = wg_encode_date(wh, wsv.data());
    wgim[index] = wi;   
   }
   break;

  case WG_TIMETYPE:
   {
    wg_int wi = wg_encode_date(wh, wsv.data());
    wgim[index] = wi;
   }
   break;

  case 13: // qstring
   {
    QString* qs = (QString*) wsv.data();
    wg_int wi = wg_encode_str(wh, qs->toLatin1().data(), nullptr);
    wgim[index] = wi;
    wsv.cleanup();    

//    char* cs = wg_decode_str(wh, wi);
//    QString testqs(cs);
//    qDebug() << "TQS: " << testqs;
   }
   break;

  default: 
    break;
  }
 }

 void* result = wg_create_record(wh, max + 1);
 QMapIterator<u4, wg_int> wit(wgim);

 while(wit.hasNext())
 {
  wit.next();
  wg_set_field(wh, result, wit.key(), wit.value());
 }

 return result;
}

/*
void WDB_Manager::decode_value(void* rec, u4 index, void* target, 
  WDB_Instance* wdbi)
{
 if(!wdbi)
   wdbi = current_white_;
 
 void* wh = wdbi->white();
}
*/

void WDB_Manager::decode_value(void* rec, u4 index, 
   WG_Stage_Value& wsv, WDB_Instance* wdbi)
{
 if(!wdbi)
  wdbi = current_white_;
 
 void* wh = wdbi->white();

 u1 et = wsv.get_encoding_type();
//  u1 et = wsv.get_encoding_type();

 switch(et)
 {
 case WG_RECORDTYPE: 
  {
  }
  break; 

 case WG_INTTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
   wsv.data_to_ref<u2>() = wg_decode_int(wh, wi);
  }
  break;

 case WG_DOUBLETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

 case WG_STRTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

 case WG_XMLLITERALTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

 case WG_URITYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

 case WG_BLOBTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

 case WG_CHARTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

 case WG_FIXPOINTTYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

 case WG_DATETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

 case WG_TIMETYPE:
  {
   wg_int wi = wg_get_field(wh, rec, index);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

 case 13: // qstring
  {
   wg_int wi = wg_get_field(wh, rec, index);
   const char* cs = wg_decode_str(wh, wi);
//   wg_int len = wg_decode_str_len(wh, wi);
   wsv.data_to_ref<QString>() = QString(cs);
//   wg_int wi = wg_decode_double(wh, *dbl);
  }
  break;

  default: 
   break;
 }

 
}


void WDB_Manager::get_qba_from_record(void* rec, QByteArray& qba, 
  u4 qba_index, WDB_Instance* wdbi)
{
 if(!wdbi)
   wdbi = current_white_;
 
 void* wh = wdbi->white();

 wg_int wi = wg_get_field(wh, rec, qba_index);

 char* blob = wg_decode_blob(wh, wi);
 wg_int wlen = wg_decode_blob_len(wh, wi);
 qba = QByteArray(blob, wlen);
 
}

void WDB_Manager::set_qba_data_field(void* rec, QByteArray& qba,
  u4 qba_index, WDB_Instance* wdbi)
{
 if(!wdbi)
   wdbi = current_white_;
 
 void* wh = wdbi->white();
 wg_int wi = wg_encode_blob(wh, qba.data(), nullptr, qba.size());
 wg_set_field(wh, rec, qba_index, wi); 
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

