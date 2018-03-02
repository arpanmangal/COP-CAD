#include <vector>
#include <cmath>
#include <3D/threeDPoint.h>

threeDPoint::threeDPoint(double X, double Y, double Z)
{
    x = X;
    y = Y;
    z = Z;
}

double threeDPoint::norm()
{
    return sqrt(x * x + y * y + z * z);
}

std::vector<double> threeDPoint::getPoint(){
    std::vector <double> point;
    point.push_back(x);
    point.push_back(y);
    point.push_back(z);
    return point;
}
