// Defines a 3 dimensional edge

//=================================
// include guard
#ifndef __THREEDEDGE_H_INCLUDED__
#define __THREEDEDGE_H_INCLUDED__

//=================================
// included dependencies
#include "threeDPoint.h" // required by length ()

//=================================
// the actual class
class threeDEdge
{
  public:
    // data members
    threeDPoint *a;
    threeDPoint *b;

    // functions
    // constructor
    threeDEdge(threeDPoint *A, threeDPoint *B)
    {
        a = A;
        b = B;
    }

    double length()
    {
        return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
    }
};

#endif // __THREEDEDGE_H_INCLUDED__
