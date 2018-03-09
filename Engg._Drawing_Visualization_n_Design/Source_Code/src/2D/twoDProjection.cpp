#include <vector>
#include <2D/twoDPoint.h>
#include <2D/twoDEdge.h>
#include <2D/twoDProjection.h>

void twoDProjection::add_pointSet(PointVector2D const & a){
	PointSet = a;
}

void twoDProjection::add_edgeSet(EdgeVector2D const & a){
	EdgeSet = a;	
}
	
