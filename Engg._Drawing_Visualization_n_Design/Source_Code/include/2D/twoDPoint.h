/**Defines interface for a 2D point*/

//=================================
// include guard
#ifndef _twoDPoint_h
#define _twoDPoint_h

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
		return ((a-p.a)<0.01||(p.a-a)<0.01) && ((b- p.b)<0.01||(p.b-b)<0.01);
	}
};

#endif
