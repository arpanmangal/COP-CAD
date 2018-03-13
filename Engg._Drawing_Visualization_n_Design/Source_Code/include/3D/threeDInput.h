/** Defines front-end interface for a inputing a 3 dimensional object */

//=================================
// include guard
#ifndef __THREE_D_INPUT__
#define __THREE_D_INPUT__

// forward declared dependencies
class threeDObject;
class twoDProjection;

// included dependencies
#include <common.h>

class threeDInput
{
private:
  // data members
  PointVector3D pointSet;
  EdgeVector3D edgeSet; // Should ONLY have points from pointSet

  // functions

  /** Add a point to the pointSet
   * Time Complexity: O ( length (pointSet) )
   * Does not raise any exception */
  void addPoint(threeDPoint *const &point);

  /** Add an edge to the edgeSet
   * Time Complexity: O (1)
   *  Throws an exception: Edge_Not_Valid if the given start and end indices are out of range */
  void addEdge(int start, int end);

public:
  // functions

  /** constructor: initialises pointSet and edgeSet to empty vectors */
  threeDInput();

  /** destructor: simply let pointSet and edgeSet go out of scope */
  ~threeDInput();

  /** Function for taking points as input.
   * Has implementation of deleting a point if user wants. The point is deleted from pointSet and the corresponding edge is deleted from the edgeSet
   *  Will be calling the function addPoint and finally threeDObject::addPointSet() */
  void inputPoints();

  /** Function for taking edges as input.
   * Will be calling the function addEdge and finally threeDObject::addEdgeSet() */
  void inputEdges();

  /**Functions takes file as input and constructs point and edge sets */
  void inputData();

  /** Return the object created, with edge set and point set as the corresponding sets of input object */
  void get3DObject (threeDObject * const &object); 
};

#endif // __THREE_D_INPUT__
