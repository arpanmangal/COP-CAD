#include "include/2D/isometricView.h"
#include "include/3D/threeDPoint.h"
#include "include/2D/Edge.h"
#include "include/2D/twoDPoint.h"

#include <iostream>

isometricView::isometricView(PointVector3D const & p, EdgeVector3D const & e)
{
    float x,y;
    twoDPoint *tempPoint;
    threeDPoint *temp3DPoint;
    // PointVector2D pointSet;

    PointVector3D pointVect = p;
    EdgeVector3D edgeVect = e;

    for (iterPoint3d it = pointVect.begin(); it != pointVect.end(); it++)
    {
        temp3DPoint = *it;
        x = 0.707 * (temp3DPoint->x - temp3DPoint->z );
        y =0.408 * (temp3DPoint->x - 2*temp3DPoint->y + temp3DPoint->z);

        pointSet.push_back(new twoDPoint (x, y));
    }

    // for (int i = 0; i<p.size(); i++)
    // {
    //     temp3DPoint = p.at(i);
    //     x = 0.707 * (temp3DPoint->x - temp3DPoint->y );
    //     y =0.408 * (temp3DPoint->x + 2*temp3DPoint->y + temp3DPoint->z);
    //     tempPoint = new twoDPoint(x,y);
    //     pointSet.push_back(tempPoint);
    // }

    edgeSet = edgeVect;

    std::cout << "in iso view, num_points = " << pointSet.size() << ", num_edges = " << edgeSet.size() << std::endl;
}