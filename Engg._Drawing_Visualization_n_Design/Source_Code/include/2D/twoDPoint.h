//defines interface for a 2D point

//=================================
// include guard
#ifndef _twoDPoint_h
#define _twoDPoint_h

//=================================
// included dependencies
#include <vector>
typedef std::vector <double> Coordinates;

class twoDPoint
{
private:
  double x;
  double y;

public:
	//Constructor and destructor
  	twoDPoint (double xcord = 0, double ycord = 0){
  		x = xcord;
  		y = ycord;
  	}
  	~ twoDPoint ();

  	// Return the point as an ordered pair of (x, y) in form of a vector
  	Coordinates getCoords (){
  		Coordinates retVal = {x,y};
  		return retVal;
  	};
};

#endif
