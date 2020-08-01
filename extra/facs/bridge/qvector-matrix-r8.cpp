
// nc_license

 
#include "qvector-matrix-r8.h"

QVector_Matrix_R8::QVector_Matrix_R8(u4 r, u4 c)
 : n_rows_(r), n_cols_(c), 
   elems_( (r && c)? new QVector<r8>((r * c) + 1) : nullptr) 
{

}

QVector_Matrix_R8::_one_opbracket QVector_Matrix_R8::operator[](u4 r)
{
 return {*this, r};
}


r8 QVector_Matrix_R8::_one_opbracket::operator[](u4 c)
{ 
 return _this.at(row, c); 
}


r8 QVector_Matrix_R8::at(u4 r, u4 c)
{
 if(elems_)
 {
  return elems_->value( ((r - 1) * n_cols_) + c );
 }
 return 0;
}

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


