
// // license___here


#include "TransformationStack.h"

#include "Transformation.h"

// package facsanadu.transformations;


// // A set of transformations
TransformationStack::TransformationStack()
{
 
}


 // // Transform a point. Returns a new point. Might be the same array (optimization)
QList<double> TransformationStack::perform(QList<double> v)
{
 if(list_.isEmpty())
   return v;
 else
 {
  QList<double> n(v); // new double[v.length];
  // System.arraycopy(v, 0, n, 0, v.length);
  for(Transformation* one : list_)
    one->transform(n);
  return n;
 }
}

QVector<double> TransformationStack::perform(QVector<double> v)
{
 if(list_.isEmpty())
   return v;
 else
 {
  QVector<double> n(v); // new double[v.length];
  // System.arraycopy(v, 0, n, 0, v.length);
  for(Transformation* one : list_)
    one->transform(n.toList());
  return n;
 }

}
 
 /**
  * Invert a point. Returns a new point. Might be the same array (optimization)
  */
QList<double> TransformationStack::invert(QList<double> v)
{

}

void TransformationStack::set(int index, Transformation* trans)
{

}

double TransformationStack::perform(double x, int indexX)
{

}

double TransformationStack::invert(double x, int indexX)
{

}


bool TransformationStack::isEmpty()
{
 return list_.isEmpty();
}


