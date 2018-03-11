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

typedef PointVector3D::iterator iterPoint3d;
typedef EdgeVector3D::iterator iterEdge3d;

typedef PointVector2D::iterator iterPoint2d;
typedef EdgeVector2D::iterator iterEdge2d;

#endif // __COMMON_H__
