
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
  r8 operator()(u4 c);
  r8 operator()(u4 c, r8 defaultv);
 };

 enum class special_mode {
  Sym, Skew, Diag
 };

 enum class special_mode_x {
  N_A, Sym, Skew, Diag, ED, Sym_ED, Skew_ED, Diag_ED, 
 };

 enum class special_mode_for_raw_data {
  Normal, ED, CM, ED_CM 
 };

 struct _from_raw_data_special 
 {
  QVector_Matrix_R8& _this;
  special_mode_for_raw_data mfrd;

  _from_raw_data_special cmajor()
  {
   return ( (mfrd == special_mode_for_raw_data::ED)
       || (mfrd == special_mode_for_raw_data::ED_CM) )
     ? _from_raw_data_special{_this, special_mode_for_raw_data::ED_CM} 
     : _from_raw_data_special{_this, special_mode_for_raw_data::CM}; 
  }

  void cmajor(const QByteArray& qba, QPair<u4, u4> dims = {0, 0}, r8 defaultv = 0);
  void diagonal(const QByteArray& qba, QPair<u4, u4> dims = {0, 0}, r8 defaultv = 0);
  void symmetric(const QByteArray& qba, QPair<u4, u4> dims = {0, 0}, r8 defaultv = 0);
  void skew(const QByteArray& qba, QPair<u4, u4> dims = {0, 0}, r8 defaultv = 0);

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

 template<special_mode>
 u4 _total_size();

 template<special_mode>
 u4 _get_index(u4 r, u4 c);

 u4 get_sym_index(u4 r, u4 c);

 static r8* _defaultv();

 void _to_raw_data(QByteArray& qba, u4 offset, u4 count);

 void _from_raw_data(const QByteArray& qba, QPair<u4, u4> dims, r8 defaultv,
   u4 total_size = 0);

 void _from_raw_data_with_encoded_default(const QByteArray& qba, 
   QPair<u4, u4> dims, u4 total_size = 0);

 void _from_raw_data(const QByteArray& qba, QPair<u4, u4> dims, 
   r8 defaultv, special_mode_x smx);

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

 u4 covers(u4 r, u4 c);
 u4 get_index(u4 r, u4 c);

 u4 operator %(QPair<u4, u4> pos)
 {
  return covers(pos.first, pos.second);
 }

 bool is_diagonal()
 {
  return (n_cols_ & 1) && (n_cols_ > 1); 
 }

 bool is_cmajor()
 {
  return (n_rows_ & 1) && !is_diagonal();
 }

 bool is_rmajor()
 {
  return (n_rows_ & 1) == 0;
 }

 u4 get_diagonal_length()
 {
  if(n_rows_ & 1)
    return n_cols();
  return n_rows();
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

 _from_raw_data_special from_raw_data()
 {
  return {*this, special_mode_for_raw_data::Normal};
 }

 const r8& at(u4 r, u4 c);
 r8* get(u4 r, u4 c);
 r8* fetch(u4 r, u4 c);
 r8 value(u4 r, u4 c);
 r8 value(u4 r, u4 c, r8 defaultv);
 r8 get_value(u4 r, u4 c);

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

