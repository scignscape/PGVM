
#include <QDebug>

#include "bridge/qvector-matrix-r8.h"

int main(int argc, char* argv[])
{
 QVector_Matrix_R8 v;
 v.diagonal(7, 5);

 v[4][4] = 99;
 
 qDebug() << v[4][4] + v[2][1];
 qDebug() << v[4][4] + v[1][2];

 QByteArray qba;
 v.to_raw_data(qba);

 QVector_Matrix_R8 v1; //(7, 5);
 v1.from_raw_data().diagonal(qba, {7, 5});

 

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

