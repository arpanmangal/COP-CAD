#include <algorithm>
#include <3D/threeDPoint.h>
#include <3D/threeDEdge.h>
#include <3D/threeDObject.h>
#include <2D/twoDProjection.h>
#include <2D/isometricView.h>

// Constructor
threeDObject::threeDObject()
{
    // Initialise the point and edge set to empty sets
    pointSet.resize(0);
    edgeSet.resize(0);
}

void threeDObject::addPoint(threeDPoint *point)
{
    if (std::find(pointSet.begin(), pointSet.end(), point) != pointSet.end())
    {
        // Point is not inside the pointSet
        pointSet.push_back(point);
    }
}

void threeDObject::addEdge(threeDPoint *a, threeDPoint *b)
{
    if (std::find(pointSet.begin(), pointSet.end(), a) == pointSet.end())
    {
        // point a not in point set => throw exception
        throw "Edge_Not_Valid";
    }
    else if (std::find(pointSet.begin(), pointSet.end(), b) == pointSet.end())
    {
        // point b not in point set => throw exception
        throw "Edge_Not_Valid";
    }
    else
    {
        // valid points a & b
        edgeSet.push_back(new threeDEdge(a, b));
    }
}

// functions for changing the object
void threeDObject::rotate(int rotMatrix[][3])
{
    // The Rotate function takes a rotation matrix as input as a 3*3 array
    // It applies the rotation matrix to each and every point of the point Set.
    // Since points are pointers to actual points, it will modify actual points, in turn automatically modifying the edges and the current object.
    // It's the job of the controller to provide the rotation matrix

    // Code here ...
}

void threeDObject::flip(int flipMatrix[][3])
{
    // Yet to decide how flip matrix will look

    // Code here...
}

twoDProjection threeDObject::genProjection(int projectionPlane){
    // This function takes a plane as input
    // The plane will always be one of XY, YZ, ZX which is achieved by appropriate rotation by the controller
    // For the corresponding projection it will simply remove the third component
    // 1 => XY, 2 => YZ, 3 => ZX
    // Throws an exception: Invalid_Plane if plane not in the range 1 to 3

    // Code here ...
};

isometricView *threeDObject::genIsoView()
{
    // generats the isometric view of the object
    // generated with respect to standard viewing of the object
    // rotate the object in case of getting different view

    // Code here ...
    return new isometricView();
}