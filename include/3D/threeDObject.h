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

  /** Constructor: initialises pointSet and edgeSet to empty vectors */
  threeDObject();

  /** Destructor: simply let pointSet and edgeSet go out of scope */
  ~threeDObject();


  /* Functions to add points to the object */

  /** Set the point set of the object to pSet */
  void addPointSet(PointVector3D const &pSet);

  /** Set the edge set of the object to eSet*/
  void addEdgeSet(EdgeVector3D const &eSet);


  /* Functions for modifying the object */

  /** Translate the current three dimensional object to origin specified by point P */
  void translate(threeDPoint * const &O);

  /**Accepts values of rotation along X axis and rotates the object accordingly*/
  void rotationalTransformationX(float alpha_x);

  /**Accepts values of rotation along Y axis and rotates the object accordingly*/
  void rotationalTransformationY(float alpha_y);

  /**Accepts values of rotation along Z axis and rotates the object accordingly*/
  void rotationalTransformationZ(float alpha_z);

  /**Translates origin to a suitable point so as to render the object properly*/
  void correctTranslation();


  /**Prints the object onto console*/
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


  /**Calculate scaling factor for projections*/
  float calculateFactor(int height, int width);

};

#endif // __THREEDOBJECT_H_INCLUDED__
