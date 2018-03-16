#include <algorithm>
#include <iostream>
#include "include/3D/threeDPoint.h"
#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"
#include "include/3D/threeDObject.h"
#include "include/2D/twoDProjection.h"
#include "include/2D/isometricView.h"

// Constructor and Destructor
threeDObject::threeDObject()
{
    // Empty Constructor
}

threeDObject::~threeDObject()
{
    // Empty Destructor
}

void threeDObject::addPointSet(std::vector<threeDPoint *> const &pSet)
{
    pointSet = pSet;
}

void threeDObject::addEdgeSet(std::vector<Edge *> const &eSet)
{
    edgeSet = eSet;
}

// functions for changing the object

void threeDObject::translate(threeDPoint *const &O)
{
    /** Given an Origin O'=(X,Y,Z), a point P (x, y, z) will translate to P' (x - X, y - Y, z - Z)
     * We iterate through each point in the pointSet to do the transformation.
     * Edge transformation follows automatically
     */

    for (iterPoint3d point = pointSet.begin(); point != pointSet.end(); ++point)
    {
        (*point)->x = (*point)->x - O->x;
        (*point)->y = (*point)->y - O->y;
        (*point)->z = (*point)->z - O->z;
    }
}

void threeDObject::rotate(int rotMatrix[][3])
{
    /** Given a 3*3 rotation matrix M, a Point P (x, y, z) will translate to M*P
     * We iterate through each point in the pointSet to do the transformation.
     * Edge transformation follows automatically
     */

    for (iterPoint3d point = pointSet.begin(); point != pointSet.end(); ++point)
    {
        float _x, _y, _z;
        _x = (rotMatrix[0][0] * (*point)->x) + (rotMatrix[0][1] * (*point)->y) + (rotMatrix[0][2] * (*point)->z);
        _y = (rotMatrix[1][0] * (*point)->x) + (rotMatrix[1][1] * (*point)->y) + (rotMatrix[1][2] * (*point)->z);
        _z = (rotMatrix[2][0] * (*point)->x) + (rotMatrix[2][1] * (*point)->y) + (rotMatrix[2][2] * (*point)->z);

        (*point)->x = _x;
        (*point)->y = _y;
        (*point)->z = _z;
    }
}

void threeDObject::flip(int flipMatrix[][3])
{
    // Yet to decide how flip matrix will look

    // Code here...
}

twoDProjection *threeDObject::genProjection(int projectionPlane)
{

    // Throw exception for invalid plane choice
    if (projectionPlane < 0 || projectionPlane > 3)
    {
        throw "Invalid_Plane";
    }

    /** According to the specified plane remove corresponding component
     * 1 => XY, 2 => YZ, 3 => ZX
     */

    // CAUTION: Create a new copy of edge set and DO NOT give pointers to the original edge set
    PointVector2D pointSet2D;

    if (projectionPlane == 1)
    {
        // Drop Z
        for (iterPoint3d point = pointSet.begin(); point != pointSet.end(); ++point)
        {
            pointSet2D.push_back(new twoDPoint((*point)->x, (*point)->y));
        }
    }
    else if (projectionPlane == 2)
    {
        // Drop X
        for (iterPoint3d point = pointSet.begin(); point != pointSet.end(); ++point)
        {
            pointSet2D.push_back(new twoDPoint((*point)->y, (*point)->z));
        }
    }
    else
    {
        // Drop Y
        for (iterPoint3d point = pointSet.begin(); point != pointSet.end(); ++point)
        {
            pointSet2D.push_back(new twoDPoint((*point)->z, (*point)->x));
        }
    }

    // Construct the Edge Set, removing in turn any edge having self loops
    EdgeVector2D edgeSet2D;

    for (iterEdge3d edge = edgeSet.begin(); edge != edgeSet.end(); ++edge)
    {
        // Simply creating a copy of the original edge
        edgeSet2D.push_back(new Edge((*edge)->start_index, (*edge)->end_index));
    }

    // Construct a Projection Object
    twoDProjection *projection = new twoDProjection();
    projection->add_pointSet(pointSet2D);
    projection->add_edgeSet(edgeSet2D);

    // Return the projection
    return projection;
};

isometricView *threeDObject::genIsoView()
{
    // generats the isometric view of the object
    // generated with respect to standard viewing of the object
    // rotate the object in case of getting different view

    // Code here ...
    return new isometricView();
}

void threeDObject::printer(){
    
	threeDPoint *p;
	Edge *e;
    for (int i=0;i<pointSet.size();i++){
        p = pointSet.at(i);
        std::cout<<i<<" "<<p->x<<" "<<p->y<<" "<<p->z<<"\n";
    }
	for (int i=0;i<edgeSet.size();i++){
		e = edgeSet.at(i);
		std::cout<<e->start_index<<" "<<e->end_index<<"\n";
	}

}