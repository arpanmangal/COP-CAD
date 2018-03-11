/**Defines interface for a 2D edge*/


//=================================
// include guard
#ifndef _Edge_h
#define _Edge_h


class Edge{
	public:
		int start_index;
		int end_index;

		//constructor
		Edge(int s,int e);

		bool operator== (Edge &e){
			return ((start_index==e.start_index)&&(end_index==e.end_index))||((end_index==e.start_index)&&(start_index==e.end_index));
		} 
};

#endif