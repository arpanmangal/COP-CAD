/**Defines interface for Orthographic Projections.
Uses three projection vies as data members */

#include <vector>
#include <2D/twoDPoint.h>
#include <2D/twoDEdge.h>
#include <2D/twoDProjection.h>
#include <2D/twoDProjectionView.h>
#include <3D/threeDPoint.h>
#include <3D/threeDEdge.h>



twoDProjectionView::twoDProjectionView(twoDProjection *f, twoDProjection *t, twoDProjection *s){
	frontview = f;
	topview = t;
	sideview = s;
}
twoDProjectionView::twoDProjectionView(twoDProjection *f, twoDProjection *t){
	frontview = f;
	topview = t;
	sideview = NULL;
}

PointVector3D twoDProjectionView::pointReconstruction(){
	twoDPoint frontPointTemp;
	twoDPoint topPointTemp;
	twoDPoint sidePointTemp;
	PointVector3D retVal;
	if (sideview==NULL){
		
	}
	
}
//EdgeVector3D edgeReconstruction(PointVector3D p, EdgeVector2D e);

/**removes edges which are redundant*/
//EdgeVector3D pruneEdges(EdgeVector3D e);
		