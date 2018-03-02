// Defines a 3 dimensional point

//====================================
// include guard
#ifndef __THREEDPOINT_H_INCLUDED__
#define __THREEDPOINT_H_INCLUDED__

// included dependencies
#include <vector>

class threeDPoint
{
  private:
    // data members
    double x;
    double y;
    double z;

  public:
    // functions
    // constructor
    threeDPoint (double X, double Y, double Z);

    // Destructor
    ~threeDPoint ();

    // returns norm of the point
    double norm ();

    // return the point for viewing in as a vector
    std::vector<double> getPoint();

    // friend class
    friend class threeDEdge;
};

#endif // __THREEDPOINT_H_INCLUDED__