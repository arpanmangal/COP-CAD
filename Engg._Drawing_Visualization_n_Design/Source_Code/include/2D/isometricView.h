// Defines isometric View

//=================================
// include guard
#ifndef __ISOMETRICVIEW_H_INCLUDED__
#define __ISOMETRICVIEW_H_INCLUDED__

//=================================
// included dependencies
#include <vector>
#include "Edge.h"
#include "twoDPoint.h"

class isometricView
{
public:
  // data members
  std::vector<twoDPoint> pointSet;
  std::vector<Edge> edgeSet; // Should ONLY have points from pointSet

  // functions
  isometricView();

  void addPoint(twoDPoint *p)
  {
    // pointSet.push_back(p);
  }
};

#endif // __ISOMETRICVIEW_H_INCLUDED__
