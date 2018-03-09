#include <cmath>
#include <3D/threeDPoint.h>

threeDPoint::threeDPoint(float X, float Y, float Z)
{
    x = X;
    y = Y;
    z = Z;
}

float threeDPoint::norm()
{
    return sqrt(x * x + y * y + z * z);
}
