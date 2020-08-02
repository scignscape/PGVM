
// nc_license

 
#include "qvector-matrix-r8.h"

#include <cstring>


QVector_Matrix_R8::QVector_Matrix_R8(u4 r, u4 c, r8 defaultv)
 : n_rows_(r), n_cols_(c), 
   elems_( (r && c)? new QVector<r8>((r * c) + 1) : nullptr) 
{
 if(elems_)
   (*elems_)[0] = defaultv;
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
 qba = QByteArray(rr, count * value_byte_size());
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
  if(elems_.size() < ts)
    elems_.resize(ts);
  else if(elems_.size() > ts)
    elems_.squeeze(ts);
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
  if(elems_.size() < ts + 1)
    elems_.resize(ts + 1);
  else if(elems_.size() > ts + 1)
    elems_.squeeze(ts + 1);
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
 n_rows = dims.first;
 n_cols = dims.first;
 _from_raw_data(qba, dims, defaultv);
}

void QVector_Matrix_R8::from_raw_data(const QByteArray& qba, r8 defaultv)
{
 _from_raw_data(qba, {n_rows, n_cols}, defaultv);
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
 _from_raw_data_with_encoded_default(qba, {n_rows, n_cols});
}

void QVector_Matrix_R8::from_raw_data_with_encoded_default(
  const QByteArray& qba, QPair<u4, u4> dims)
{
 n_rows = dims.first;
 n_cols = dims.first;
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


const r8& QVector_Matrix_R8::at(u4 r, u4 c)
{
 return *fetch(r, c);
}

r8 QVector_Matrix_R8::value(u4 r, u4 c)
{
 return value(r, c, 0);
}

r8* QVector_Matrix_R8::fetch(u4 r, u4 c)
{
 if(elems_)
 { 
  u4 pos = 0;
  if(r <= n_rows_)
  {
   if(c <= n_cols_)
   {  
    pos = ((r - 1) * n_cols_) + c;
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


r8* QVector_Matrix_R8::get(u4 r, u4 c)
{
 if(elems_)
 {
  if(r > n_rows_)
    return nullptr;
  if(c > n_cols_)
    return nullptr;

  u4 pos = ((r - 1) * n_cols_) + c;
  if(pos >= (u4) elems_->size())
    return nullptr; 
  
  return &(*elems_)[pos];
 }
 return nullptr;
}

r8 QVector_Matrix_R8::value(u4 r, u4 c, r8 defaultv)
{
 if(elems_)
 {
  u4 pos = ((r - 1) * n_cols_) + c;
  return elems_->value(pos, defaultv);
 }
 return defaultv;
}


/*
const r8& QVector_Matrix_R8::at(u4 r, u4 c)
{
 if(elems_)
 {
  return elems_->value( ((r - 1) * n_cols_) + c );
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
 return n_rows_ * n_cols_;
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


