#include <vector>
#include <cmath>
#include <3D/threeDPoint.h>
#include <3D/threeDEdge.h>

threeDEdge::threeDEdge(threeDPoint *A, threeDPoint *B)
{
    a = A;
    b = B;
}

double threeDEdge::length()
{
    return sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2) + pow(a->z - b->z, 2));
}