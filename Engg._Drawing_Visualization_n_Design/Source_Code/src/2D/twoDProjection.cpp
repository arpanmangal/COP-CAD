#include <vector>
#include <2D/twoDPoint.h>
#include <2D/twoDEdge.h>

twoDProjection::add_pointSet(PointVector2D const & a){
	pointSet = a;
}

twoDProjection::add_edgeSet(PointVector3D const & a){
	EdgeSet = a;	
}
	
