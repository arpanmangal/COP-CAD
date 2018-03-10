#include <cmath>
#include <3D/threeDPoint.h>

// Constructor and Destructor
threeDPoint::threeDPoint(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

threeDPoint::~threeDPoint()
{
    // Empty Destructor
}

float threeDPoint::norm()
{
    return sqrt(x * x + y * y + z * z);
}
