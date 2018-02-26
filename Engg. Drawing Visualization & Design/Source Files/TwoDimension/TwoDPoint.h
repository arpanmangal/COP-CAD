#ifndef _TwoDPoint_h_included_
#define _TwoDPoint_h_included_

#include <bits/stdc++.h>
using namespace std;

class TwoDPoint{
	private:
		vector<float> coordinates(2);
	public:
		TwoDPoint(int xcord = 0, int ycord = 0);
		~TwoDPoint();
		vector<float> getcords();
};
#endif
