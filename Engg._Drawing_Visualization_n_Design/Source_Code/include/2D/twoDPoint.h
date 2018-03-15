/**Defines interface for a 2D point*/

//=================================
// include guard
#ifndef _twoDPoint_h
#define _twoDPoint_h
#include <cmath>
class twoDPoint
{
  public:
	float a;
	float b;

	//Constructor
	twoDPoint(float xcord, float ycord)
	{
		a = xcord;
		b = ycord;
	}

	/** Overloaded bool operator == */
	bool operator==(twoDPoint &p)
	{
		return ((abs(a-p.a)<0.001) && (abs(b- p.b)<0.001));
	}
};

#endif
