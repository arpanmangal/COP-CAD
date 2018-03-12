/**Defines interface for a 2D edge*/

//=================================
// include guard
#ifndef __EDGE_H__
#define __EDGE_H__

class Edge
{
  public:
	int start_index;
	int end_index;

	/** Constructor */
	Edge(int s, int e);

	/** Overloaded bool operator == */
	bool operator==(Edge &e)
	{
		return ((start_index == e.start_index) && (end_index == e.end_index)) || ((end_index == e.start_index) && (start_index == e.end_index));
	}
};

#endif // __EDGE_H__