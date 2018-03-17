/** Defines front-end interface for a inputing 2 dimensional projections */

//=================================
// include guard
#ifndef _twoDInput_h_
#define _twoDInput_h_

// forward declared dependencies
class twoDProjection;
class twoDProjectionView;

// included dependencies
#include "include/common.h"

class twoDInput
{
private:
  // data members
  PointVector2D pointSet;
  EdgeVector2D edgeSet; // Should ONLY have points from pointSet

  // functions

  /** Add a point to the pointSet
       Time Complexity: O ( 1 ) */
  void addPoint(twoDPoint *const &point);

  /** Add an edge to the edgeSet
      Time Complexity: O ( 1 )
      Throws an exception: Edge_Not_Valid if the index doesn't exist in the pointSet */
  void addEdge(int start, int end);

public:
  // functions

  /** Constructor: Initialises pointSet and edgeSet to empty vectors */
  twoDInput();

  /** Destructor: Simply let pointSet and edgeSet go out of scope */
  ~twoDInput();

  /** Function for taking points as input.
     * Has implementation of deleting a point if user wants. The point is deleted from pointSet and the corresponding edge is deleted from the edgeSet
     *  Will be calling the function addPoint and finally twoDProjection:add_pointSet() */
  void inputPoints();

  /** Function for taking edges as input.
     * Will be calling the function addEdge and finally threeDObject::add_edgeSet() */
  void inputEdges();

  /**Functions takes file as input and constructs point and edge sets */
  twoDProjectionView * getProjectionDrawing(const char * path);

};

#endif 
