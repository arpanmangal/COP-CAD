#ifndef _TwoDEdge_h_included_
#define _TwoDEdge_h_included_

#include <bits/stdc++.h>
#include "TwoDEdge.h"
using namespace std;

class TwoDEdge{
	private:
		vector<TwoDPoint> points(2);
	public:
		TwoDEdge();
		TwoDEdge(TwoDPoint a, TwoDPoint b);
		~TwoDEdge();	
};