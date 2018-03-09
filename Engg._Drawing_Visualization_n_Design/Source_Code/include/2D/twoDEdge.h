/**Defines interface for a 2D edge*/


//=================================
// include guard
#ifndef _twoDEdge_h
#define _twoDEdge_h

//=================================
// forward dependency
class twoDPoint;

class twoDEdge{
	public:
		twoDPoint * start;
		twoDPoint * end;

		//constructor and destructor
		twoDEdge(twoDPoint *a, twoDPoint *b);
		~twoDEdge();

		bool operator== (twoDEdge &e){
			return ((start==e.start)&&(end==e.end))||((end==e.start)&&(start==e.end));
		} 
};

#endif