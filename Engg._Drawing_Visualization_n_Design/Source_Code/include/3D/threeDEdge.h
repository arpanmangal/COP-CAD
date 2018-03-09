// Defines a 3 dimensional edge

//=================================
// include guard
#ifndef __THREEDEDGE_H_INCLUDED__
#define __THREEDEDGE_H_INCLUDED__

//=================================
// forward declared dependencies
class threeDPoint;

class threeDEdge
{
  private:
    // data members
    threeDPoint *a;
    threeDPoint *b;

  public:
    // functions
    /** constructor */
    threeDEdge(threeDPoint *A, threeDPoint *B);

    /** destructor */
    ~threeDEdge();

    /** returns the length of this edge */ 
    double length();
};

#endif // __THREEDEDGE_H_INCLUDED__
