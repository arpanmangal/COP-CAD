/**Defines interface for Orthographic Projections.
Uses three projection vies as data members */

#include <vector>
#include <2D/twoDPoint.h>
#include <2D/twoDEdge.h>
#include <2D/twoDProjection.h>
#include <3D/threeDPoint.h>
#include <3D/threeDEdge.h>

typedef std::vector<threeDPoint> PointVector3D;
typedef std::vector<twoDEdge> EdgeVector2D;
typedef std::vector<threeDEdge> EdgeVector3D;

		twoDProjectionView(twoDProjection *f, twoDProjection *t, twoDProjection *s);
		twoDProjectionView::twoDProjectionView(twoDProjection *f, twoDProjection *t){
			frontview = f;
			topview = t;
			sideview = s
		}

		/**projects a point in 3D space*/
		PointVector3D pointReconstruction();
		EdgeVector3D edgeReconstruction(PointVector3D p, EdgeVector2D e);

		/**removes edges which are redundant*/
		EdgeVector3D pruneEdges(EdgeVector3D e);
		
};
#endif