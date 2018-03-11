/**Defines interface for a 2D edge*/


//=================================
// include guard
#ifndef _twoDEdge_h
#define _twoDEdge_h


class twoDEdge{
	public:
		int start_index;
		int end_index;

		//constructor
		twoDEdge(int s,int e);

		bool operator== (twoDEdge &e){
			return ((start_index==e.start_index)&&(end_index==e.end_index))||((end_index==e.start_index)&&(start_index==e.end_index));
		} 
};

#endif