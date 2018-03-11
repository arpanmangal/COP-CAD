/** This file contains forward declarations of classes and typedefs of frequently occuring long constructs in the header files */

// include guard
#ifndef __COMMON_H__
#define __COMMON_H__

// Included Dependencies
#include <vector>

// Forward Declarations
class twoDPoint;
class threeDPoint;
class Edge;

// List TypeDefs
typedef std::vector<twoDPoint *> PointVector2D;
typedef std::vector<Edge *> EdgeVector2D;

typedef std::vector<threeDPoint *> PointVector3D;
typedef std::vector<Edge *> EdgeVector3D;

#endif // __COMMON_H__
