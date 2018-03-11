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
  int start_index;
  int end_index;

  // functions

  /** constructor */
  threeDEdge(int start, int end);

  /** destructor */
  ~threeDEdge();

  bool operator==(threeDEdge &e)
  {
    return ((start_index == e.start_index) && (end_index == e.end_index)) || ((end_index == e.start_index) && (start_index == e.end_index));
  }
};

#endif // __THREEDEDGE_H_INCLUDED__
