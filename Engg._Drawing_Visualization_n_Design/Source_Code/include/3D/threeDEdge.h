/** Defines interface for a 3 dimensional edge */

//=================================
// include guard
#ifndef __THREEDEDGE_H_INCLUDED__
#define __THREEDEDGE_H_INCLUDED__

//=================================
// forward declared dependencies
class threeDPoint;

class threeDEdge
{
  public:
    // data members
    threeDPoint *start;
    threeDPoint *end;

    // functions
    /** constructor */
    threeDEdge(threeDPoint * const &A, threeDPoint * const &B);

    /** destructor */
    ~threeDEdge();

    /** returns the length of this edge */ 
    float length();
};

#endif // __THREEDEDGE_H_INCLUDED__
