#ifndef _twoDProjectionView_h
#define _twoDProjectionView_h

#include <vector>
#include "twoDProjection.h"
#include "../3D/threeDEdge.h"

typedef std::vector<threeDPoint> PointVector3D;
typedef std::vector<twoDEdge> EdgeVector2D;
typedef std::vector<threeDEdge> EdgeVector3D;

class twoDProjectionView{
	private:
		twoDProjection frontview;
		twoDProjection topview;
		twoDProjection sideview;

	public:
		twoDProjectionView();
		~twoDProjectionView();
		PointVector3D pointReconstruction();
		EdgeVector2D edgeSegmentation();
		EdgeVector2D edgeCollinearityCheck();
		EdgeVector2D edgeIdentification();
		EdgeVector3D edgeReconstruction(PointVector3D p, EdgeVector2D e);
		EdgeVector3D pruneEdges(EdgeVector3D e);
		EdgeVector3D create3Dmodel();
		
};
#endif