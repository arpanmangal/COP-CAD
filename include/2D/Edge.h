/**Defines interface for Edges (both 3D and 2D)*/

//=================================
// include guard
#ifndef __EDGE_H__
#define __EDGE_H__

class Edge
{
  public:
	int start_index;
	int end_index;

	/** Constructor: Accepts the start index and the end index of points in the vector PointSet defining the edge*/
	Edge(int s, int e);

	/** Overloaded bool operator == */
	bool operator==(Edge &e)
	{
		return ((start_index == e.start_index) && (end_index == e.end_index)) || ((end_index == e.start_index) && (start_index == e.end_index));
	}
};

#endif // __EDGE_H__