/**Defines interface for a 2D point*/

//=================================
// include guard
#ifndef _twoDPoint_h
#define _twoDPoint_h

class twoDPoint{
	public:
		double x;
  		double y;
	
		//Constructor and destructor
		twoDPoint (double xcord = 0, double ycord = 0){
			x = xcord;
			y = ycord;
		}
		~ twoDPoint ();

		bool operator== (twoDPoint &b){
			return (x==b.x)&&(y==b.y);
		}
};

#endif
