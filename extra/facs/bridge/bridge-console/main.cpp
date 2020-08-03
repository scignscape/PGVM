
#include <QDebug>

#include "bridge/qvector-matrix-r8.h"

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

int main(int argc, char* argv[])
{
 QVector_Matrix_R8 v;
 v.diagonal(7, 5);

 v[4][4] = 99;
 v[3][3] = 22;
 
 qDebug() << v[4][4] + v[2][1];
 qDebug() << v[4][4] + v[1][2];

 QByteArray qba;
 v.to_raw_data(qba);

 QVector_Matrix_R8 v1; //(7, 5);
 v1.from_raw_data().diagonal(qba, {7, 5});

 qDebug() << v1[4][4] + v[2][1];
 qDebug() << v1[3][3] + v[1][2];

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

