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
    for (int i = 0; i < p.size(); i++)
    {
        temp3DPoint = p.at(i);
        x = 0.707 * (temp3DPoint->x - temp3DPoint->z );
        y =0.408 * (temp3DPoint->x - 2*temp3DPoint->y + temp3DPoint->z);

        pointSet.push_back(new twoDPoint (x, y));
    }

    edgeSet = e;

    std::cout << "in iso view, num_points = " << pointSet.size() << ", num_edges = " << edgeSet.size() << std::endl;
}