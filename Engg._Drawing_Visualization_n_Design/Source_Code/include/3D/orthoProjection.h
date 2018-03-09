// Defines the controller which computes orthographic projections from 3D Object

//=================================
// include guard
#ifndef __ORTHOPROJECTION_H_INCLUDED__
#define __ORTHOPROJECTION_H_INCLUDED__

// forward declared dependencies
class threeDdrawing;
class twoDProjection;
class plane;

// included dependencies
#include <vector>
#include "threeDObject.h"
// #include "plane.h"

class orthoProjection
{
  public:
    // data members
    threeDObject *obj;  // Object on which it operates
    plane *projecPlane; //

    // functions

    // constructor and destructor
    orthoProjection(){};
    ~orthoProjection(){};

    // function for taking input of the form threeDdrawing and converting it to a threeDObject
    // and a plane on which to take the projection
    // return type is void since it sets the "obj" of this object to its output
    void processInput (threeDdrawing drawing);

    // Below is the main controller
    // takes a 3D object and a plane on which to project it
    // Calculates the rotation matrix depending on the specifies plane
    // calls the rotate function and retrives the new 3D object
    // calls the genProjection method to compute the projection which it returns
    twoDProjection controller ();
};

#endif // __ORTHOPROJECTION_H_INCLUDED__
