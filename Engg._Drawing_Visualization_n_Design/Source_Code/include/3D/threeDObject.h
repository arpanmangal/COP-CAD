/** Defines interface for a 3 dimensional object */

//=================================
// include guard
#ifndef __THREEDOBJECT_H_INCLUDED__
#define __THREEDOBJECT_H_INCLUDED__

// forward declared dependencies
class twoDProjection;
class isometricView;

// included dependencies
#include "include/common.h"

class threeDObject
{
private:
  // data members
  PointVector3D pointSet;
  EdgeVector3D edgeSet; // Should ONLY have points from pointSet

public:
  // functions

  /** constructor: initialises pointSet and edgeSet to empty vectors */
  threeDObject();

  /** destructor: simply let pointSet and edgeSet go out of scope */
  ~threeDObject();


  /* Functions to add points to the object */

  /** Set the point set of the object to pSet */
  void addPointSet(PointVector3D const &pSet);

  /** Set the edge set of the object to eSet*/
  void addEdgeSet(EdgeVector3D const &eSet);


  /* Functions for modifying the object */

  /** Translate the current three dimensional object to origin specified by point P */
  void translate(threeDPoint * const &O);


  /** The Rotate function takes a rotation matrix as input as a 3*3 array
   * It applies the rotation matrix to each and every point of the point Set.
   * Since points are pointers to actual points, it will modify actual points, in turn automatically modifying the edges and the current object.
   * It's the job of the controller to provide the rotation matrix 
   */
  void rotate(float rotMatrix[3][3]);

  /** Yet to decide how flip matrix will look */
  void flip(int flipMatrix[][3]);

  void printer();

  /* Projections */

  /** This function takes a plane as input
   * The plane will always be one of XY, YZ, ZX which is achieved by appropriate rotation by the controller
   * For the corresponding projection it will simply remove the third component
   * 1 => XY, 2 => YZ, 3 => ZX
   * Throws an exception: Invalid_Plane if plane not in the range 1 to 3 
   */
  twoDProjection *genProjection(int projectionPlane);

  /** generats the isometric view of the object
     generated with respect to standard viewing of the object
    rotate the object in case of getting different view */
  isometricView *genIsoView();

  /**Writes the object to file*/
	void filewriter(const char * path);

  /**Accepts values of rotation along X, Y and Z axes and rotates the object accordingly*/
  void rotationalTransformation(float alpha_x, float alpha_y, float alpha_z);
};

#endif // __THREEDOBJECT_H_INCLUDED__
