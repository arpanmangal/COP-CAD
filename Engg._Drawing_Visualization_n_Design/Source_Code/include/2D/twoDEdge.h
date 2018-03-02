/**Defines interface for a 2D edge*/


//=================================
// include guard
#ifndef _twoDEdge_h
#define _twoDEdge_h

//=================================
// included dependencies
#include <vector>
#include "twoDPoint.h"

typedef std::vector<twoDPoint> EdgeVector2D;

class twoDEdge{
	private:
		EdgeVector2D points; // in .cpp do a twoDEdge::twoDEdge() {points.resize(2)}
	public:
		//constructor and destructor
		twoDEdge();
		twoDEdge(twoDPoint a, twoDPoint b){
			points = {a,b};
		}
		~twoDEdge();
};

#endif