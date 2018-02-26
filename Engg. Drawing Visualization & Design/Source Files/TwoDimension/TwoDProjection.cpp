#include <bits/stdc++.h>
using namespace std;

class TwoDPoint{
	private:
		vector<float> coordinates(2);
	public:
		TwoDPoint(int xcord = 0, int ycord = 0){
			coordinates[0] = xcord;
			coordinates[1] = ycord;
		}
		~TwoDPoint();

		vector<float> getcords(){
			return coordinates;
};

class TwoDEdge{
	private:
		vector<TwoDPoint> points(2);
	public:
		TwoDEdge(){
			points[0] = TwoDPoint();
			points[1] = TwoDPoint();
		}

		TwoDEdge(TwoDPoint a, TwoDPoint b){
			points[0] = a;
			points[1] = b;
		}
		~TwoDEdge();	
};

class TwoDProjection{
	private:
		vector<TwoDPoint> PointSet;
		vector<TwoDEdge> EdgeSet;
	public:
		TwoDProjection();
		~TwoDProjection();

	void add_point(TwoDPoint a){
		PointSet.push_back(a);
	}

	void add_edge(TwoDEdge a){
		EdgeSet.push_back(a);
	}
};