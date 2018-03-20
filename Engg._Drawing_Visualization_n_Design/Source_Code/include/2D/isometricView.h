/** Defines interface Isometric View*/

//=================================
// include guard
#ifndef __ISOMETRICVIEW_H_INCLUDED__
#define __ISOMETRICVIEW_H_INCLUDED__

//=================================
// included dependencies
#include "include/common.h"

class isometricView
{
public:
  // data members
  PointVector2D pointSet;
  EdgeVector2D edgeSet; // Should ONLY have points from pointSet

  // functions
  /** Empty Constructor */
  isometricView(){};

  /** Constructs the Isometric View from given 3D Point Set and Edge Set */
  isometricView(PointVector3D const & p, EdgeVector3D const & e);

};

#endif // __ISOMETRICVIEW_H_INCLUDED__
