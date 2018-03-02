#ifndef _twoDProjection_h
#define _twoDProjection_h

#include <vector>
#include "twoDEdge.h"

// typedef std::vector<twoDPoint> PointVector2D;
// typedef std::vector<twoDEdge> EdgeVector2D;

class twoDProjection{
	private:
		std::vector<twoDPoint> PointSet;
		std::vector<twoDEdge> EdgeSet;
	public:
		twoDProjection();
		~twoDProjection();

	void add_point(twoDPoint a);

	void add_edge(twoDEdge a);

	void delete_point(twoDPoint a);

	void delete_edge(twoDPoint a);
};

#endif