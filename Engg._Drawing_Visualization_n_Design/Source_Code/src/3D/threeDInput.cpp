#include <algorithm>
#include <iostream>
#include <string>
#include <3D/threeDPoint.h>
#include <3D/threeDEdge.h>
#include <3D/threeDObject.h>
#include <3D/threeDInput.h>

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
    if (pointSet.empty() || std::find(pointSet.begin(), pointSet.end(), point) != pointSet.end())
    {
        // Point is not inside the pointSet
        pointSet.push_back(point);
    }
}

// TODO: Check duplicate Edge
void threeDInput::addEdge(threeDPoint *const &start, threeDPoint *const &end)
{
    if (std::find(pointSet.begin(), pointSet.end(), start) == pointSet.end())
    {
        // point a not in point set => throw exception
        throw "Edge_Not_Valid";
    }
    else if (std::find(pointSet.begin(), pointSet.end(), end) == pointSet.end())
    {
        // point b not in point set => throw exception
        throw "Edge_Not_Valid";
    }
    else
    {
        // valid points a & b
        edgeSet.push_back(new threeDEdge(start, end));
    }
}

// Point input function
void threeDInput::inputPoints()
{
    int n = 0;
    float x, y, z;
    std::cout << "Please Enter the Points as x, y, z Pairs:\n(Enter x = -1.25 for stopping)" << std::endl;

    // May need to do this => pointSet.resize(0);

    do
    {
        std::cout << "\nEnter " + std::to_string(++n) + "th point:" << std::endl;

        std::cout << "Enter x: ";
        std::cin >> x;

        std::cout << "Enter y: ";
        std::cin >> y;

        std::cout << "Enter z: ";
        std::cin >> z;

        threeDPoint point(x, y, z);

        addPoint(&point);

    } while (x != -1.25);

    pointSet.pop_back();

    // Ask user whether he is satisfied with his choices.
    // If yes return, else retake the input;
}

// Edge input function
void threeDInput::inputEdges()
{
    int n = 0;
    int start, end;
    std::cout << "Please Enter the Edges as (start, end) Pairs:\n(Enter start = end for stopping)" << std::endl;

    // May need to do this => edgeSet.resize(0);

    int numPoints = pointSet.size();

    if (numPoints < 2)
    {
        std::cout << "\nGo Away!!" << std::endl;
        ;
        return;
    }

    do
    {
        std::cout << "\nEnter " + std::to_string(n + 1) + "th edge:" << std::endl;

        std::cout << "Enter start: ";
        std::cin >> start;

        std::cout << "Enter end: ";
        std::cin >> end;

        if (start == end)
        {
            // End of Input
            break;
        }
        else if (start > numPoints || end > numPoints)
        {
            // invalid edge
            std::cout << "Invalid Edge!!" << std::endl;
            continue;
        } else {
            addEdge(pointSet.at(start - 1), pointSet.at(end - 1));
            n++;
        }
    } while (true);

    pointSet.pop_back();

    // Ask user whether he is satisfied with his choices.
    // If yes return, else retake the input;
}