// Class for object returned after Draw or from file import

//=================================
// include guard
#ifndef __THREEDDRAWING_H_INCLUDED__
#define __THREEDDRAWING_H_INCLUDED__

//=================================
// included dependencies
#include "threeDPoint.h" // required by length ()

class threeDdrawing
{
  public:
    // data members
    threeDPoint *a;
    threeDPoint *b;

    // functions
    // constructor
    threeDdrawing(threeDPoint *A, threeDPoint *B)
    {
        a = A;
        b = B;
    }

    double length()
    {
        return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
    }
};

#endif // __THREEDDRAWING_H_INCLUDED__
