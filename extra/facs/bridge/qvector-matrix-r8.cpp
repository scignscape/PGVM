
// nc_license

 
#include "qvector-matrix-r8.h"

#include <cstring>


QVector_Matrix_R8::QVector_Matrix_R8(u4 r, u4 c, r8 defaultv)
 : n_rows_(r << 1), n_cols_(c << 1), 
   elems_( (r && c)? new QVector<r8>((r * c) + 1) : nullptr) 
{
 if(elems_)
   (*elems_)[0] = defaultv;
}

u4 QVector_Matrix_R8::n_rows() const
{
 return n_rows_ >> 1;
}

void QVector_Matrix_R8::set_n_rows(u4 n_rows)
{
 n_rows_ = n_rows << 1;
}

u4 QVector_Matrix_R8::n_cols() const
{
 if(n_cols_ <= 1)
   return n_rows();
 return n_cols_ >> 1;
}

void QVector_Matrix_R8::set_n_cols(u4 n_cols)
{
 n_cols_ = n_cols << 1;
}

void QVector_Matrix_R8::symmetric(u4 n_rows)
{
 u4 cm = n_rows_ & 1;
 n_rows_ = n_rows << 1;
 n_rows_ |= cm;
 n_cols_ = 0;
}

void QVector_Matrix_R8::skew_symmetric(u4 n_rows)
{
 u4 cm = n_rows_ & 1;
 n_rows_ = n_rows << 1;
 n_rows_ |= cm;
 n_cols_ = 0;
}

void QVector_Matrix_R8::diagonal(u4 n_rows)
{
 diagonal(n_rows, n_rows);
}

void QVector_Matrix_R8::diagonal(u4 n_rows, u4 n_cols)
{
 u4 cm = n_rows_ & 1;
 n_rows_ = n_rows << 1;
 n_rows_ |= cm;
 n_cols_ = n_cols << 1;
 n_cols_ |= 1;
}

void QVector_Matrix_R8::diagonal()
{
 diagonal(n_rows());
}

void QVector_Matrix_R8::rmajor()
{
 if(n_rows_ & 1)
   n_rows_ ^= 1;
}

void QVector_Matrix_R8::cmajor()
{
 n_rows_ |= 1;
}


void QVector_Matrix_R8::_to_raw_data(QByteArray& qba, u4 offset, u4 count)
{
 if(!elems_)
   return;
 if(elems_->size() <= 1)
   return;
// if(ts < count)
//   count = ts;

 const r8* rr = elems_->constData();
 rr += offset * value_byte_size();
 qba = QByteArray( (const char*) rr, count * value_byte_size());
}

void QVector_Matrix_R8::to_raw_data(QByteArray& qba)
{
 if(!elems_)
   return;
 u4 ts = total_size();
 if(ts == 0)
   return;
 _to_raw_data(qba, 1, ts);
}

void QVector_Matrix_R8::_from_raw_data_with_encoded_default(
  const QByteArray& qba, QPair<u4, u4> dims)
{
 u4 ts = (dims.first * dims.second) + 1;

 if(elems_)
 {
  if((u4) elems_->size() < ts)
    elems_->resize(ts);
  else if((u4) elems_->size() > ts)
  {
   elems_->resize(ts);
   elems_->squeeze();
  }
 }
 else 
   elems_ = new QVector<r8>(ts);

 r8* d = elems_->data();
 memcpy(d, qba.constData(), ts * value_byte_size()); 
}

void QVector_Matrix_R8::_from_raw_data(const QByteArray& qba, 
  QPair<u4, u4> dims, r8 defaultv)
{
 u4 ts = dims.first * dims.second;

 if(elems_)
 {
  if((u4) elems_->size() < ts + 1)
    elems_->resize(ts + 1);
  else if((u4) elems_->size() > ts + 1)
  {
   elems_->resize(ts + 1);
   elems_->squeeze();
  }
 }
 else 
   elems_ = new QVector<r8>(ts + 1);

 r8* d = elems_->data();
 *d = defaultv;
 memcpy(d + value_byte_size(), qba.constData(), ts * value_byte_size()); 
}

void QVector_Matrix_R8::from_raw_data(const QByteArray& qba, 
  QPair<u4, u4> dims, r8 defaultv)
{
 set_n_rows(dims.first);
 set_n_cols(dims.second);
 _from_raw_data(qba, dims, defaultv);
}

void QVector_Matrix_R8::from_raw_data(const QByteArray& qba, r8 defaultv)
{
 _from_raw_data(qba, {n_rows(), n_cols()}, defaultv);
}

void QVector_Matrix_R8::to_raw_data_with_encoded_default(QByteArray& qba)
{
 if(!elems_)
   return;
 u4 ts = total_size();
 if(ts == 0)
   return;
 _to_raw_data(qba, 0, ts + 1);
}

void QVector_Matrix_R8::from_raw_data_with_encoded_default(const QByteArray& qba)
{
 _from_raw_data_with_encoded_default(qba, {n_rows(), n_cols()});
}

void QVector_Matrix_R8::from_raw_data_with_encoded_default(
  const QByteArray& qba, QPair<u4, u4> dims)
{
 set_n_rows(dims.first);
 set_n_cols(dims.second);
 _from_raw_data_with_encoded_default(qba, dims);
}

QVector_Matrix_R8::_one_opbracket 
 QVector_Matrix_R8::operator[](u4 r)
{
 return {*this, r};
}


r8& QVector_Matrix_R8::_one_opbracket::operator[](u4 c)
{
 return *_this.fetch(row, c);
}

r8* QVector_Matrix_R8::_defaultv()
{
 static r8* result = nullptr;
 if(!result)
   result = new r8(0);
 return result; 
}


template<>
const r8& QVector_Matrix_R8::_at<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c)
{

}

template<>
const r8& QVector_Matrix_R8::_at<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c)
{

}

template<>
const r8& QVector_Matrix_R8::_at<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c)
{

}

const r8& QVector_Matrix_R8::at(u4 r, u4 c)
{
 if(is_symmetric())
   return _at<QVector_Matrix_R8::special_mode::Sym>(r, c);
 if(is_skew_symmetric())
   return _at<QVector_Matrix_R8::special_mode::Skew>(r, c);
 if(is_diagonal())
   return _at<QVector_Matrix_R8::special_mode::Diag>(r, c);

 return *fetch(r, c);
}

template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c)
{

}

template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c)
{

}

template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c)
{

}

r8 QVector_Matrix_R8::value(u4 r, u4 c)
{
 if(is_symmetric())
   return _value<QVector_Matrix_R8::special_mode::Sym>(r, c);
 if(is_skew_symmetric())
   return _value<QVector_Matrix_R8::special_mode::Skew>(r, c);
 if(is_diagonal())
   return _value<QVector_Matrix_R8::special_mode::Diag>(r, c);

 return value(r, c, 0);
}


template<>
r8* QVector_Matrix_R8::_fetch<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c)
{

}

template<>
r8* QVector_Matrix_R8::_fetch<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c)
{

}

template<>
r8* QVector_Matrix_R8::_fetch<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c)
{

}

r8* QVector_Matrix_R8::fetch(u4 r, u4 c)
{
 if(is_symmetric())
   return _fetch<QVector_Matrix_R8::special_mode::Sym>(r, c);
 if(is_skew_symmetric())
   return _fetch<QVector_Matrix_R8::special_mode::Skew>(r, c);
 if(is_diagonal())
   return _fetch<QVector_Matrix_R8::special_mode::Diag>(r, c);


 if(elems_)
 { 
  u4 pos = 0;
  if(r <= n_rows())
  {
   if(c <= n_cols())
   {  
    pos = ((r - 1) * n_cols()) + c;
    if(pos >= (u4) elems_->size())
      pos = 0;
   }
  }
  return &(*elems_)[pos];
 }
 elems_ = new QVector<r8>(1);
 (*elems_)[0] = *_defaultv();
 return &(*elems_)[0];
}


template<>
r8* QVector_Matrix_R8::_get<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c)
{

}

template<>
r8* QVector_Matrix_R8::_get<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c)
{

}

template<>
r8* QVector_Matrix_R8::_get<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c)
{

}

r8* QVector_Matrix_R8::get(u4 r, u4 c)
{
 if(is_symmetric())
   return _get<QVector_Matrix_R8::special_mode::Sym>(r, c);
 if(is_skew_symmetric())
   return _get<QVector_Matrix_R8::special_mode::Skew>(r, c);
 if(is_diagonal())
   return _get<QVector_Matrix_R8::special_mode::Diag>(r, c);

 if(elems_)
 {
  if(r > n_rows())
    return nullptr;
  if(c > n_cols())
    return nullptr;

  u4 pos = ((r - 1) * n_cols()) + c;
  if(pos >= (u4) elems_->size())
    return nullptr; 
  
  return &(*elems_)[pos];
 }
 return nullptr;
}


template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Sym>(u4 r, u4 c, r8 defaultv)
{

}

template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Skew>(u4 r, u4 c, r8 defaultv)
{

}

template<>
r8 QVector_Matrix_R8::_value<QVector_Matrix_R8::special_mode::Diag>(u4 r, u4 c, r8 defaultv)
{

}


r8 QVector_Matrix_R8::value(u4 r, u4 c, r8 defaultv)
{
 if(is_symmetric())
   return _value<QVector_Matrix_R8::special_mode::Sym>(r, c, defaultv);
 if(is_skew_symmetric())
   return _value<QVector_Matrix_R8::special_mode::Skew>(r, c, defaultv);
 if(is_diagonal())
   return _value<QVector_Matrix_R8::special_mode::Diag>(r, c, defaultv);


 if(elems_)
 {
  u4 pos = ((r - 1) * n_cols()) + c;
  return elems_->value(pos, defaultv);
 }
 return defaultv;
}


/*
const r8& QVector_Matrix_R8::at(u4 r, u4 c)
{
 if(elems_)
 {
  return elems_->value( ((r - 1) * n_cols()) + c );
 }
 return 0;
}
*/

void QVector_Matrix_R8::resize(u4 r, u4 c)
{
 resize(r * c);
}

u4 QVector_Matrix_R8::total_size()
{
 return n_rows() * n_cols();
}

void QVector_Matrix_R8::resize(u4 total)
{
 if(elems_)
 {
  elems_->resize(total + 1);
 }
 else
   elems_ = new QVector<r8>(total + 1);
}





//  data=double matrix

// n_cols
// n_elem
// n_rows

// vec_state
// mem_state
// mem_local


