#include <2D/isometricView.h>

isometricView::isometricView(PointVector3D const & p, EdgeVector3D const & e)
{
    float x,y;
    twoDPoint *tempPoint;
    threeDPoint *temp3DPoint;
    pointSet = new PointVector2D();
    for (int i = 0; i<p.size(); i++)
    {
        temp3DPoint = p.at(i);
        x = 0.707 * (temp3DPoint->x - temp3DPoint->y );
        y =0.408 * (temp3DPoint->x + 2*temp3Dpoint->y + temp3DPoint->z);
        tempPoint = new twoDPoint(x,y);
        pointSet.push_back(tempPoint);
    }

    edgeSet = e;
}