#ifndef _TwoDProjection_h_included_
#define _TwoDProjection_h_included_

#include <bits/stdc++.h>
#include "TwoDEdge.h"

using namespace std;

class TwoDProjection{
	private:
		vector<TwoDPoint> PointSet;
		vector<TwoDEdge> EdgeSet;
	public:
		TwoDProjection();
		~TwoDProjection();

	void add_point(TwoDPoint a);

	void add_edge(TwoDEdge a);

	void delete_point(TwoDPoint a);

	void delete_edge(TwoDPoint a);
};