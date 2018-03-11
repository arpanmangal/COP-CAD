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

	//Constructor and destructor
	twoDPoint(float xcord, float ycord)
	{
		a = xcord;
		b = ycord;
	}

	bool operator==(twoDPoint &p)
	{
		return (a == p.a) && (b == p.b);
	}
};

#endif
