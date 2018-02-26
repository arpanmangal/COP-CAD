// twoDPoint.h
//

#ifndef LZZ_twoDPoint_h
#define LZZ_twoDPoint_h
#include <vector>
typedef std::vector<float> Coordinates;
#define LZZ_INLINE inline
class twoDPoint
{
private:
  Coordinates coordinates;
public:
  twoDPoint (int xcord = 0, int ycord = 0);
  ~ twoDPoint ();
  Coordinates getcords ();
};
#undef LZZ_INLINE
#endif
