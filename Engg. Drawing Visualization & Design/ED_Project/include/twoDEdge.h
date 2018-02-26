#ifndef _twoDEdge_h
#define _twoDEdge_h

#include <vector>
#include "twoDEdge.h"
typedef std::vector<twoDEdge> EdgeVector2D;

class twoDEdge{
	private:
		EdgeVector2D points(2);
	public:
		twoDEdge();
		twoDEdge(twoDPoint a, twoDPoint b);
		~twoDEdge();
};

#endif