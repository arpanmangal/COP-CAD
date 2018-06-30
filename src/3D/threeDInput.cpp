#include <algorithm>
#include <iostream>
#include "include/3D/threeDPoint.h"
#include "include/2D/Edge.h"
#include "include/3D/threeDObject.h"
#include "include/3D/threeDInput.h"
#include <fstream>
using namespace std;

// Constructor and Destructor
threeDInput::threeDInput()
{
    // empty constructor
}

threeDInput::~threeDInput()
{
    // empty destructor
}

void threeDInput::addPoint(threeDPoint *const &point)
{
    if (pointSet.empty() || std::find(pointSet.begin(), pointSet.end(), point) == pointSet.end())
    {
        // Point is not inside the pointSet
        pointSet.push_back(point);
    }
}

// TODO: Check duplicate Edge
void threeDInput::addEdge(int start, int end)
{
    int pointSet_size = pointSet.size();

    if (start < 0 || end < 0 || start >= pointSet_size || end >= pointSet_size)
    {
        std::cout << "Point set size is " << pointSet_size << " and you are entering " << start + 1 << " and " << end + 1 << std::endl;
        //throw "Edge_Not_Valid";
    }
    else
    {
        // valid points start and end
        edgeSet.push_back(new Edge(start, end));
    }
}

void threeDInput::inputData(const char * path)
{
   ifstream file;
    file.open(path, ios::in);
    if (!file)
    {
     cout<<"File not found\n";   
    }
    int number_of_points, number_of_edges;
    file >> number_of_points;
    float x, y,z;
    threeDPoint *point;
    for (int i = 0; i < number_of_points; i++)
    {
        file>>x>>y>>z;
        point = new threeDPoint(x,y,z);
        addPoint(point);
    }

    /*for (int i = 0; i < pointSet.size(); i++)
    {
        point = pointSet.at(i);
        cout << i << " " << point->x << " " << point->y <<" "<<point->z<< "\n";
    }*/

    int start,end;
    if (number_of_points< 2)
    {
        cout << "\nGo Away! Too Less points !!" << std::endl;
        return;
    }

    file>>number_of_edges;
    //cout << number_of_edges << endl;
    for (int i=0;i<number_of_edges;i++){
        file>>start>>end;
        //cout << i << std::endl;
        try
        {
            addEdge(start, end);
        }
        catch (std::string e)
        {
            // invalid edge

            cout << "Invalid Edge!!" << std::endl;
            continue;
        }
    }
}

// Generating the 3D Object
threeDObject* threeDInput::get3DObject()
{
    threeDObject * object = new threeDObject();
    object->addPointSet(pointSet);
    object->addEdgeSet(edgeSet);

    return object;
}
