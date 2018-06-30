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

  /**Function takes filename as input and constructs point and edge sets */
  twoDProjectionView * getProjectionDrawing(const char * path);

};

#endif 
