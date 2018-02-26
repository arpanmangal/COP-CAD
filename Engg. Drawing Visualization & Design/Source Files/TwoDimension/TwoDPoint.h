#ifndef _twoDPoint_h
#define _twoDPoint_h

#include <vector>
typedef std::vector <float> Coordinates;

class twoDPoint
{
private:
  Coordinates coordinates;
public:
  twoDPoint (int xcord = 0, int ycord = 0);
  ~ twoDPoint ();
  Coordinates getcords ();
};

#endif
