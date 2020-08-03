
#include <QDebug>

#include "bridge/qvector-matrix-r8.h"


int main(int argc, char* argv[])
{
 QVector_Matrix_R8 v;
 v.skew_symmetric(5);

  // v.cmajor();

 v[4][4] = 99;
 v[1][3] = 22;
 
 qDebug() << v[4][4] + v[1](3);
 qDebug() << v[4][4] + v[3](1);

 QByteArray qba;
 v.to_raw_data(qba);

 QVector_Matrix_R8 v1; //(7, 5);
 v1.from_raw_data() //.cmajor()
   .skew_symmetric(qba, {5});

  //symmetric(qba, {7, 7});

 qDebug() << v1[4][4] + v[1][3];
 qDebug() << v1[4][4] + v[3](1);

 return 0;
}


int main5(int argc, char* argv[])
{
 QVector_Matrix_R8 v(7, 5);

 v.cmajor();

 v[7][5] = 99;
 v[2][1] = 3;
 
 qDebug() << v[7][5] + v[2][1];


 QByteArray qba;
 v.to_raw_data(qba);

 QVector_Matrix_R8 v1; //(7, 5);
 v1.from_raw_data().cmajor(qba, {7, 5});

 qDebug() << v1[7][5] + v1[2][1];


 return 0;
}


int main2(int argc, char* argv[])
{
 QVector<r8> rv(5);
 rv[0] = 8;
 rv[1] = 18;
 rv[2] = 82;
 rv[3] = 38;
 rv[4] = 84;

 const r8* rr = rv.constData();
 //rr += offset * value_byte_size();
 QByteArray qba = QByteArray( (const char*) rr, 40);

 QVector<r8> rv1(6);
 r8* rr1 = rv1.data();
 memcpy(rr1 + 1, qba.constData(), 40);

 return 0;
}

int main4(int argc, char* argv[])
{
 QVector_Matrix_R8 v;
 v.symmetric(5);

  // v.cmajor();

 v[4][4] = 99;
 v[1][3] = 22;
 
 qDebug() << v[4][4] + v[1][3];
 qDebug() << v[4][4] + v[3][1];

 QByteArray qba;
 v.to_raw_data(qba);

 QVector_Matrix_R8 v1; //(7, 5);
 v1.from_raw_data() //.cmajor()
   .symmetric(qba, {5});

  //symmetric(qba, {7, 7});

 qDebug() << v1[4][4] + v[1][3];
 qDebug() << v1[4][4] + v[3][1];

 return 0;
}

int main3(int argc, char* argv[])
{
 QVector_Matrix_R8 v;
// v.symmetric(7);
 v.diagonal(7);

 v[4][4] = 99;
// v[1][3] = 22;
 
 qDebug() << v[4][4] + v[1][3];
 qDebug() << v[4][4] + v[3][1];

 QByteArray qba;
 v.to_raw_data(qba);

 QVector_Matrix_R8 v1; //(7, 5);
 v1.from_raw_data().diagonal(qba, {7});

  //symmetric(qba, {7, 7});

 qDebug() << v1[4][4] + v[1][3];
 qDebug() << v1[4][4] + v[3][1];

 return 0;
}


int main1(int argc, char* argv[])
{
 QVector_Matrix_R8 v(7, 5);
 v[7][5] = 99;
 v[2][1] = 3;
 
 qDebug() << v[7][5] + v[2][1];

 QByteArray qba;
 v.to_raw_data(qba);

 QVector_Matrix_R8 v1; //(7, 5);
 v1.from_raw_data(qba, {7, 5});

 qDebug() << v1[7][5] + v1[2][1];

 return 0;
}

