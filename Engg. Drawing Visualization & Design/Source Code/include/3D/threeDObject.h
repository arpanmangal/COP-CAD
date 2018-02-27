// Defines a 3 dimensional object

//=================================
// include guard
#ifndef __THREEDOBJECT_H_INCLUDED__
#define __THREEDOBJECT_H_INCLUDED__

// forward declared dependencies
// class twoDProjection;
class isometricView;

// included dependencies
#include <vector>
#include "threeDEdge.h"
#include "../2D/twoDProjection.h"

class threeDObject
{
public:
  // data members
  std::vector<threeDPoint> pointSet;
  std::vector<threeDEdge> edgeSet; // Should ONLY have points from pointSet

  // functions

  // The Rotate function takes a rotation matrix as input as a 3*3 array
  // It applies the rotation matrix to each and every point of the point Set and Edge and return a new object
  // It's the job of the controller to provide the rotation matrix
  threeDObject rotate (int rotMatrix [][3]);

  // Yet to decide how flip matrix will look
  threeDObject flip (int flipMatrix [][3]);

  // This function takes a plane as input
  // The plane will always be one of XY, YZ, ZX which is achieved by appropriate rotation by the controller
  // For the corresponding projection it will simply remove the third component
  // 1 => XY, 2 => YZ, 3 => ZX
  twoDProjection genProjection (int projectionPlane);

  // generats the isometric view of the object
  // generated with respect to standard viewing of the object
  // rotate the object in case of getting different view
  isometricView genIsoView ();
};

#endif // __THREEDOBJECT_H_INCLUDED__
