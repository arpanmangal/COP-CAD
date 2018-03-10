/** Defines interface for a 3 dimensional object */

//=================================
// include guard
#ifndef __THREEDOBJECT_H_INCLUDED__
#define __THREEDOBJECT_H_INCLUDED__

// forward declared dependencies
// class twoDProjection;
class threeDPoint;
class threeDEdge;

class twoDProjection;
class isometricView;

// included dependencies
#include <vector>
// #include <2D/twoDProjection.h>

class threeDObject
{
private:
  // data members
  std::vector<threeDPoint *> pointSet;
  std::vector<threeDEdge *> edgeSet; // Should ONLY have points from pointSet

public:
  // functions

  /** constructor: initialises pointSet and edgeSet to empty vectors */
  threeDObject();

  /** destructor: simply let pointSet and edgeSet go out of scope */
  ~threeDObject();

  // /** Add a point to the pointSet
  //    Time Complexity: O ( length (pointSet) )
  //   Does not raise any exception */
  // void addPoint(threeDPoint *point);

  // /** Add an edge to the edgeSet
  //    Time Complexity: O ( length (pointSet) )
  //   Throws an exception: Edge_Not_Valid if either end points of the edge are not in the point set */
  // void addEdge(threeDPoint *a, threeDPoint *b);

  void addPointSet (std::vector<threeDPoint *> const &pSet);

  void addEdgeSet (std::vector<threeDEdge *> const &eSet);

  /** The Rotate function takes a rotation matrix as input as a 3*3 array
     It applies the rotation matrix to each and every point of the point Set.
    Since points are pointers to actual points, it will modify actual points, in turn automatically modifying the edges and the current object.
    It's the job of the controller to provide the rotation matrix */
  void rotate(int rotMatrix[][3]);

  /** Yet to decide how flip matrix will look */
  void flip(int flipMatrix[][3]);

  /** This function takes a plane as input
     The plane will always be one of XY, YZ, ZX which is achieved by appropriate rotation by the controller
    For the corresponding projection it will simply remove the third component
    1 => XY, 2 => YZ, 3 => ZX
    Throws an exception: Invalid_Plane if plane not in the range 1 to 3 */
  twoDProjection *genProjection(int projectionPlane);

  /** generats the isometric view of the object
     generated with respect to standard viewing of the object
    rotate the object in case of getting different view */
  isometricView *genIsoView();
};

#endif // __THREEDOBJECT_H_INCLUDED__
