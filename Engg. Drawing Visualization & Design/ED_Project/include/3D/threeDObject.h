// Defines a 3 dimensional object

//=================================
// include guard
#ifndef __THREEDOBJECT_H_INCLUDED__
#define __THREEDOBJECT_H_INCLUDED__

//=================================
// included dependencies
#include <vector>
#include "threeDEdge.h" // required by length ()

//=================================
// the actual class
class threeDObject
{
  public:
    // data members
    std::vector <threeDPoint> pointSet;
    std::vector <threeDEdge> edgeSet; // Should ONLY have points from pointSet

    // functions
};

#endif // __THREEDOBJECT_H_INCLUDED__
