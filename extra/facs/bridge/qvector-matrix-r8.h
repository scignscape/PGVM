
// nc_license_h

#ifndef QVECTOR_MATRIX_R8__H
#define QVECTOR_MATRIX_R8__H

#include <QtGlobal>
#include <QVector>
 
#include "_accessors.h"

typedef qreal r8;
typedef quint32 u4;

class QVector_Matrix_R8
{
 u4 n_rows_;
 u4 n_cols_;

 QVector<r8>* elems_;

 struct _one_opbracket
 {
  QVector_Matrix_R8& _this;
  u4 row;
  r8 operator[](u4 c);
 };

public:

 QVector_Matrix_R8(u4 r = 0, u4 c = 0);

 ACCESSORS(u4 ,n_rows)
 ACCESSORS(u4 ,n_cols)

 _one_opbracket operator[](u4 r);

 r8 at(u4 r, u4 c);

 u4 total_size();

 void resize(u4 r, u4 c);
 void resize(u4 total);
 void resize()
 {
  resize(n_rows_, n_cols_);
 }

};



//  data=double matrix

// n_cols
// n_elem
// n_rows

// vec_state
// mem_state
// mem_local


#endif // QVECTOR_MATRIX_R8__H

