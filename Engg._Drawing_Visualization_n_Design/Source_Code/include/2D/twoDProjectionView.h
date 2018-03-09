/**Defines interface for Orthographic Projections.
Uses three projection vies as data members */

//=================================
// include guard
#ifndef _twoDProjectionView_h
#define _twoDProjectionView_h

//=================================
// included dependencies
#include <vector>

class twoDPoint;
class twoDEdge;
class twoDProjection;
class threeDPoint;
class threeDEdge;

typedef std::vector<threeDPoint *> PointVector3D;
typedef std::vector<twoDEdge *> EdgeVector2D;
typedef std::vector<threeDEdge *> EdgeVector3D;

class twoDProjectionView{
	private:
		twoDProjection * frontview;
		twoDProjection * topview;
		twoDProjection * sideview;

	public:
		twoDProjectionView();

		/**projects a point in 3D space*/
		PointVector3D pointReconstruction();

		/*finds all possible line segments in a 2D edge which can for edges in 3D*/
		//EdgeVector2D edgeSegmentation();

		/*finds all possible line segments in a 2D edge which can for edges in 3D*/
		//EdgeVector2D edgeCollinearityCheck();

		/*finds edges which are compatible in all the three views*/
		//EdgeVector2D edgeIdentification();

		/**projects edges in 3D space*/
		EdgeVector3D edgeReconstruction(PointVector3D p, EdgeVector2D e);

		/**removes edges which are redundant*/
		EdgeVector3D pruneEdges(EdgeVector3D e);

		/**function to convert an Orthographic Porojections Drawing to 3D Model*/
		EdgeVector3D create3Dmodel();
		
};
#endif