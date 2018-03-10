/**Defines interface for a 2D point*/

//=================================
// include guard
#ifndef _twoDPoint_h
#define _twoDPoint_h

class twoDPoint{
	public:
		double a;
  		double b;
	
		//Constructor and destructor
		twoDPoint (double xcord = 0, double ycord = 0){
			a = xcord;
			b = ycord;
		}

		bool operator== (twoDPoint &p){
			return (a==p.a)&&(b==p.b);
		}
};

#endif
