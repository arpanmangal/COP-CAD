#ifndef _twoDPoint_h
#define _twoDPoint_h

// #include <vector>
typedef std::vector <double> Coordinates;

class twoDPoint
{
private:
  double x;
  double y;

public:
  twoDPoint (double xcord = 0, double ycord = 0);
  ~ twoDPoint ();

  // Return the point as an ordered pair of (x, y) in form of a vector
  Coordinates getCoords ();
};

#endif
