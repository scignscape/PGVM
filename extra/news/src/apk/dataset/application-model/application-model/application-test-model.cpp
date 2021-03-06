
//          Copyright Nathaniel Christen 2019.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include "application-test-model.h"

#include "phaon-ir/runtime/phr-command-package.h"

#include <QNetworkAccessManager>
#include <QNetworkReply>

#include <QDebug>

#include "defines.h"

#ifdef USING_KPH
#include "phaon-ir/phaon-ir.h"
#include "phaon-ir/channel/phr-channel-system.h"

USING_KANS(Phaon)

extern void default_phr_startup(PhaonIR& phr);
#endif

//?USING_KANS(Phaon)
USING_KANS(DSM)

Application_Test_Model::Application_Test_Model()
  :  qnam_(nullptr)
{

}


void Application_Test_Model::init_kph_qba(QByteArray& qba, QString path)
{
#ifdef USING_KPH

 PHR_Channel_System pcs;
 PhaonIR phr(&pcs);
 default_phr_startup(phr);

 PHR_Command_Package pcp(phr.channel_system(), phr.type_system());

 pcp.parse_from_file(path);
 pcp.supply_data(qba);
 qba.append("<//>");

 QByteArray pre = "<<>>kph@";
 quint64 ms = QDateTime::currentMSecsSinceEpoch();
 pre.append(QByteArray::number(ms));
 pre.append(':');
 qba.prepend(pre);
#endif // USING_KPH
}


void Application_Test_Model::run_kph_test(QString path,
  std::function<void()> okcb, std::function<void()> errcb)
{
 qDebug() << path;

#ifdef USING_KPH

// //  This version seems slower, since it relies on an
 //    extra communication step.  But the QNAM version
 //    relying on a RemoteHostClosedError may be a bit
 //    hackneyed ...
#ifdef USE_SOCKET_WITHOUT_QNAM

 QByteArray* qba = new QByteArray;
 init_kph_qba(*qba, path);

 QTcpSocket* socket = new QTcpSocket;
 int port = 18261; // // r z 1

 socket->connectToHost("Localhost", port);

 QObject::connect(socket, &QNetworkReply::readyRead,
  [socket, qba, okcb, errcb]()
 {
  QString result = QString::fromLatin1( socket->readAll() );
  if(result == "OK")
  {
   socket->write(*qba);
  }
  else if(result == "END")
  {
   qDebug() << "OK\n";
   socket->disconnectFromHost();
   socket->deleteLater();
   delete qba;
   okcb();
  }
  else
  {
   qDebug() << "Unexpected response: " << result << "\n";
   socket->disconnectFromHost();
   socket->deleteLater();
   delete qba;
   errcb();
  }
 });


#else //  USE_SOCKET_WITHOUT_QNAM not defined
 if(!qnam_)
   qnam_ = new QNetworkAccessManager;

 QByteArray qba;

 init_kph_qba(qba, path);

 int port = 18261; // // r z 1
 QString addr = QString("http://localhost:%1/").arg(port);

 QNetworkRequest req;// = new QNetworkRequest;

 req.setUrl( QUrl(addr) );
 req.setHeader(QNetworkRequest::ContentTypeHeader, "text/plain");

 QNetworkReply* reply = qnam_->post(req, qba);

 QObject::connect(reply, QOverload<QNetworkReply::NetworkError>::of(&QNetworkReply::error),
  [reply, okcb, errcb](QNetworkReply::NetworkError code)
 {
  if(code != QNetworkReply::RemoteHostClosedError)
  {
   qDebug() << "Unexpected error: " << code << "\n";
   errcb();
  }
  else
  {
   okcb();
  }
  reply->deleteLater();
 });
#endif // USE_SOCKET_WITHOUT_QNAM

#else
 qDebug() << "This library was built without KPH!";
#endif  //  USING_KPH
}

Application_Test_Model::~Application_Test_Model()
{
 delete qnam_;
}
