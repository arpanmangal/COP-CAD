#include <vector>
#include<2D/twoDPoint.h>
#include <2D/twoDEdge.h>

typedef std::vector<twoDPoint> PointVector2D;
typedef std::vector<twoDEdge> EdgeVector2D;

class twoDProjection{
	private:
		PointVector2D PointSet;
		EdgeVector2D EdgeSet;
	public:
		twoDProjection();
		~twoDProjection();

	void add_point(twoDPoint a);

	void add_edge(twoDEdge a);

	void delete_point(twoDPoint a);

	void delete_edge(twoDPoint a);
};

#endif