// Defines a 3 dimensional point

//====================================
// include guard
#ifndef __THREEDPOINT_H_INCLUDED__
#define __THREEDPOINT_H_INCLUDED__

//=================================
// included dependencies
#include <cmath>

class threeDPoint
{
  public:
    // data members
    double x;
    double y;
    double z;

    // functions
    // constructor
    threeDPoint (double X, double Y, double Z)
    {
        x = X;
        y = Y;
        z = Z;
    }

    double norm()
    {
        return sqrt(x * x + y * y + z * z);
    }
};

#endif // __THREEDPOINT_H_INCLUDED__