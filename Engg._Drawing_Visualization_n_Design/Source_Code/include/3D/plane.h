// Class which defines the orientation of a plane, in terms of origin and coordinate axis

//=================================
// include guard
#ifndef __PLANE_H_INCLUDED__
#define __PLANE_H_INCLUDED__

// forward declared dependencies
class threeDPoint;

class plane
{
    public:
        // data members
        threeDPoint* origin;

        // End points of X & Y axis
        threeDPoint* X;
        threeDPoint* Y;

        // functions
        plane ();
        ~plane();

    private:
        // functions

        // check validity
        bool isRightAngle();
};

#endif  // __PLANE_H_INCLUDED__