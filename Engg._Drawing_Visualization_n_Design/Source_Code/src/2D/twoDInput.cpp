#include <algorithm>
#include <iostream>
#include <string>
#include <2D/twoDInput.h>
#include <2D/Edge.h>
#include <2D/twoDPoint.h>

// Constructor and Destructor
twoDInput::twoDInput()
{
    // empty constructor
}

twoDInput::~twoDInput()
{
    // empty destructor
}

void twoDInput::addPoint(twoDPoint *const &point)
{
    if (pointSet.empty() || std::find(pointSet.begin(), pointSet.end(), point) != pointSet.end())
    {
        // Point is not inside the pointSet
        pointSet.push_back(point);
    }
}

// TODO: Check duplicate Edge
void twoDInput::addEdge(int start, int end)
{
    int pointSet_size = pointSet.size();

    if (start < 0 || end < 0 || start >= pointSet_size || end >= pointSet_size)
    {
        throw "Edge_Not_Valid";
    }
    else
    {
        // valid points start and end
        edgeSet.push_back(new Edge(start, end));
    }
}

// Point input function
void twoDInput::inputPoints()
{
    int n = 0;
    float x, y;
    std::cout << "Please Enter the Points as x, y Pairs:\n(Enter x = -3.1414 for stopping)" << std::endl;

    // May need to do this => pointSet.resize(0);

    do
    {
        std::cout << "\nEnter " + std::to_string(++n) + "th point:" << std::endl;

        std::cout << "Enter x: ";
        std::cin >> x;

        std::cout << "Enter y: ";
        std::cin >> y;

        twoDPoint point(x, y);

        addPoint(&point);

    } while (x != -3.1414);

    pointSet.pop_back();

    // Ask user whether he is satisfied with his choices.
    // If yes return, else retake the input;
}

// Edge input function
void twoDInput::inputEdges()
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
        else
        {
            try
            {
                addEdge(start - 1, end - 1);
            }
            catch (std::string e)
            {
                // invalid edge

                std::cout << "Invalid Edge!!" << std::endl;
                continue;
            }
        }

        n++;
    } while (true);

    pointSet.pop_back();

    // Ask user whether he is satisfied with his choices.
    // If yes return, else retake the input;
}

PointVector2D twoDInput::getPoints(){
    return pointSet;
}

EdgeVector2D twoDInput::getEdges(){
    return edgeSet;
}