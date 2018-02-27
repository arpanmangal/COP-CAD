#ifndef _twoDEdge_h
#define _twoDEdge_h

#include <vector>
#include "twoDPoint.h"

typedef std::vector<twoDPoint> EdgeVector2D;

class twoDEdge{
	private:
		EdgeVector2D points; // in .cpp do a twoDEdge::twoDEdge() {points.resize(2)}
	public:
		twoDEdge();
		twoDEdge(twoDPoint a, twoDPoint b);
		~twoDEdge();
};

#endif