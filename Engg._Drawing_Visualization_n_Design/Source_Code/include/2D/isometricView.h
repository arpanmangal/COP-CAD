/** Defines interface Isometric View*/

//=================================
// include guard
#ifndef __ISOMETRICVIEW_H_INCLUDED__
#define __ISOMETRICVIEW_H_INCLUDED__

//=================================
// included dependencies
#include <common.h>

class isometricView
{
public:
  // data members
  PointVector2D pointSet;
  EdgeVector2D edgeSet; // Should ONLY have points from pointSet

  // functions
  isometricView();

  void addPoint(twoDPoint *p)
  {
    // pointSet.push_back(p);
  }
};

#endif // __ISOMETRICVIEW_H_INCLUDED__
