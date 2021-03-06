
//           Copyright Nathaniel Christen 2019.
//  Distributed under the Boost Software License, Version 1.0.
//     (See accompanying file LICENSE_1_0.txt or copy at
//           http://www.boost.org/LICENSE_1_0.txt)

#ifndef PHR_FUNCTION__H
#define PHR_FUNCTION__H


#include "kans.h"

#include "accessors.h"

#include "relae-graph/relae-caon-ptr.h"

KANS_(Phaon)

class PHR_Function
{
 struct _base
 {
  void* raw_ptr_;
 };

 caon_ptr<_base> base_ptr_;


 void augment(caon_ptr<_base>* bs);


public:

 PHR_Function(void* raw_ptr);


 PHR_Function();


 template<typename T>
 PHR_Function(T* t): PHR_Function( reinterpret_cast<void*>(t) )
 {

 }

 PHR_Function(const PHR_Function& rhs);

 template<typename T>
 void augment(caon_ptr<T> pt)
 {
  caon_ptr<_base>* bs = new caon_ptr<_base>[2];
  bs[0] = pt.template caon_cast<_base>();
  augment(bs);
 }

 template<typename T>
 void* de_augment(T*& t)
 {
  if(base_ptr_.is_array())
  {
   void* rp = base_ptr_.raw_pointer();
   caon_ptr<_base>* brp = (caon_ptr<_base>*) rp;
   caon_ptr<_base> b0 = brp[0];
   caon_ptr<_base> b1 = brp[1];
   t = (T*) b0.raw_pointer();
   return b1.raw_value_as_pointer();
  }
  else
  {
   t = nullptr;
   return base_ptr_.raw_pointer();
  }
 }

 void base_run();
 void descriptive_base_run();

};

_KANS(Phaon)


#endif //PHR_FUNCTION__H
