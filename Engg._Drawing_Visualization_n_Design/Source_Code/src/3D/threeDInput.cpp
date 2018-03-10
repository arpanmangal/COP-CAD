#include <algorithm>
#include <3D/threeDPoint.h>
#include <3D/threeDEdge.h>
#include <3D/threeDInput.h>


void threeDInput::addPoint(threeDPoint * const& point)
{
    if (std::find(pointSet.begin(), pointSet.end(), point) != pointSet.end())
    {
        // Point is not inside the pointSet
        pointSet.push_back(point);
    }
}

// TODO: Check duplicate Edge
void threeDInput::addEdge(threeDPoint * const &start, threeDPoint * const &end)
{
    if (std::find(pointSet.begin(), pointSet.end(), start) == pointSet.end())
    {
        // point a not in point set => throw exception
        throw "Edge_Not_Valid";
    }
    else if (std::find(pointSet.begin(), pointSet.end(), end) == pointSet.end())
    {
        // point b not in point set => throw exception
        throw "Edge_Not_Valid";
    }
    else
    {
        // valid points a & b
        edgeSet.push_back(new threeDEdge(start, end));
    }
}
