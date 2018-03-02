// Defines isometric View

//=================================
// include guard
#ifndef __ISOMETRICVIEW_H_INCLUDED__
#define __ISOMETRICVIEW_H_INCLUDED__

//=================================
// included dependencies
#include <vector>
#include "twoDEdge.h"
#include "twoDPoint.h"

class isometricView
{
public:
  // data members
  std::vector<twoDPoint> pointSet;
  std::vector<twoDEdge> edgeSet; // Should ONLY have points from pointSet

  // functions
  isometricView();
  ~isometricView(); 

  void addPoint(twoDPoint *p)
  {
    // pointSet.push_back(p);
  }
};

#endif // __ISOMETRICVIEW_H_INCLUDED__
