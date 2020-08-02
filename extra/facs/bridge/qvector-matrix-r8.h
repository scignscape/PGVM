
// nc_license_h

#ifndef QVECTOR_MATRIX_R8__H
#define QVECTOR_MATRIX_R8__H

#include <QtGlobal>
#include <QVector>
#include <QByteArray>
 
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
  r8& operator[](u4 c);
 };

 enum class special_mode {
  Sym, Skew, Diag
 };

 template<special_mode>
 const r8& _at(u4 r, u4 c);

 template<special_mode>
 r8* _get(u4 r, u4 c);

 template<special_mode>
 r8* _fetch(u4 r, u4 c);

 template<special_mode>
 r8 _value(u4 r, u4 c);

 template<special_mode>
 r8 _value(u4 r, u4 c, r8 defaultv);


 static r8* _defaultv();

 void _to_raw_data(QByteArray& qba, u4 offset, u4 count);

 void _from_raw_data(const QByteArray& qba, QPair<u4, u4> dims, r8 defaultv);
 void _from_raw_data_with_encoded_default(const QByteArray& qba, QPair<u4, u4> dims);

public:

 QVector_Matrix_R8(u4 r = 0, u4 c = 0, r8 defaultv = 0);

 ACCESSORS__DECLARE(u4 ,n_rows)
 ACCESSORS__DECLARE(u4 ,n_cols)

 void symmetric(u4 n_rows);
 void skew_symmetric(u4 n_rows);
 void diagonal(u4 n_rows);
 void diagonal(u4 n_rows, u4 n_cols);
 void diagonal();
 void rmajor();
 void cmajor();

 bool is_diagonal()
 {
  return (n_cols_ & 1) && (n_cols_ > 1); 
 }

 bool is_symmetric()
 {
  return n_cols_ == 0; 
 }

 bool is_skew_symmetric()
 {
  return n_cols_ == 1; 
 }

 static constexpr u4 value_byte_size() { return 8; }

 _one_opbracket operator[](u4 r);

 void to_raw_data(QByteArray& qba);
 void to_raw_data_with_encoded_default(QByteArray& qba);

 void from_raw_data(const QByteArray& qba, QPair<u4, u4> dims, r8 defaultv = 0);
 void from_raw_data(const QByteArray& qba, r8 defaultv = 0);
 void from_raw_data_with_encoded_default(const QByteArray& qba);
 void from_raw_data_with_encoded_default(const QByteArray& qba, QPair<u4, u4> dims);

 const r8& at(u4 r, u4 c);
 r8* get(u4 r, u4 c);
 r8* fetch(u4 r, u4 c);
 r8 value(u4 r, u4 c);
 r8 value(u4 r, u4 c, r8 defaultv);

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

