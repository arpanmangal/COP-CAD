#ifndef _twoDPoint_h
#define _twoDPoint_h

#include <vector>
typedef std::vector <double> Coordinates;

class twoDPoint
{
private:
  Coordinates coordinates;
public:
  twoDPoint (double xcord = 0, double ycord = 0);
  ~ twoDPoint ();
  Coordinates getcords ();
};

#endif
