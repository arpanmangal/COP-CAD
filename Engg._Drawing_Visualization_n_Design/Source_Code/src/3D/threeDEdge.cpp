#include <cmath>
// #include <3D/threeDPoint.h>
#include <3D/threeDEdge.h>

threeDEdge::threeDEdge(int start, int end)
{
    start_index = start;
    end_index = end;
}

// Destructor
threeDEdge::~threeDEdge()
{
    // Empty Destructor
}

// float threeDEdge::length()
// {
//     return sqrt(pow(start->x - end->x, 2) + pow(start->y - end->y, 2) + pow(start->z - end->z, 2));
// }