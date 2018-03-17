/** Defines interface for a 2D Projection drawing
 * Defines a drawing as a set of points and edges */

//=================================
// include guard
#ifndef _twoDProjection_h
#define _twoDProjection_h

//=================================
// included dependencies
#include "include/common.h"

class twoDProjection
{
  private:
	PointVector2D PointSet;
	EdgeVector2D EdgeSet;

  public:
	twoDProjection() {}

	/**Accepts a vector of twoDPoints and assigns it to the PointSet of the projection*/
	void add_pointSet(PointVector2D const &a);

	/**Accepts a vector of Edges and assigns it to the EdgeSet of the projection and runs collinearity check to find the edges not visible in that view*/
	void add_edgeSet(EdgeVector2D const &a);

	/**Accepts of edgevector from 3D object, and assigns straightaway without running collinearity check*/
	void add_edgeSetfrom3D(EdgeVector2D const &a);

	//void cleanEdgeSet();
	/*finds all possible line segments in a 2D edge which can for edges in 3D*/
	//EdgeVector2D edgeSegmentation();

	/*finds all possible line segments in a 2D edge which can for edges in 3D*/
	void edgeCollinearityCheck();

	/**Prints EdgeSet and PointSet of the projection*/
	void printer();

	/**Writes the object to file*/
	void filewriter(const char * path);

	friend class twoDProjectionView;
};

#endif