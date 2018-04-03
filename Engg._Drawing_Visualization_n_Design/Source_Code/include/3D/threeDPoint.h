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
  /** Constructor accepts coordinate as parameters */
  threeDPoint(float X, float Y, float Z);

  /** Destructor */
  ~threeDPoint();

};

#endif // __THREEDPOINT_H_INCLUDED__