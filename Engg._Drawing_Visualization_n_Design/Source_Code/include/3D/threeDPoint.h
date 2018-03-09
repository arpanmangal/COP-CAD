/** Defines interface for a 3 dimensional point */

//====================================
// include guard
#ifndef __THREEDPOINT_H_INCLUDED__
#define __THREEDPOINT_H_INCLUDED__

// included dependencies
#include <vector>

class threeDPoint
{
  public:
    // data members
    float x;
    float y;
    float z;

    // functions
    /** constructor */
    threeDPoint (float X, float Y, float Z);

    /** Destructor */
    ~threeDPoint ();

    /** returns norm of the point */
    float norm ();

};

#endif // __THREEDPOINT_H_INCLUDED__