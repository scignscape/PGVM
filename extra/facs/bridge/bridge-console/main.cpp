
#include <QDebug>

#include "bridge/qvector-matrix-r8.h"

int main(int argc, char* argv[])
{
 QVector_Matrix_R8 v(7, 5);
 v[7][5] = 99;
 v[2][1] = 3;
 
 qDebug() << v[7][5] + v[2][1];

 return 0;
}

