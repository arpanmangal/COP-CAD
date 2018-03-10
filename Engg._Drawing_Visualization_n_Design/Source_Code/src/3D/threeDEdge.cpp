#include <cmath>
#include <3D/threeDPoint.h>
#include <3D/threeDEdge.h>

threeDEdge::threeDEdge(threeDPoint * const &A, threeDPoint * const &B)
{
    start = A;
    end = B;
}

float threeDEdge::length()
{
    return sqrt(pow(start->x - end->x, 2) + pow(start->y - end->y, 2) + pow(start->z - end->z, 2));
}