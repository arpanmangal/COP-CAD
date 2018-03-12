#include <vector>
#include <iostream>
#include <2D/twoDPoint.h>
#include <2D/Edge.h>
#include <2D/twoDProjection.h>

void twoDProjection::add_pointSet(PointVector2D const &a)
{
	PointSet = a;
}

void twoDProjection::add_edgeSet(EdgeVector2D const &a)
{
	EdgeSet = a;
}

// void twoDProjection::cleanPointSet()
// {
// 	for (int i = 0; i < PointSet.size(); i++)
// 	{
// 		for (int j = i; j < PointSet.size(); j++)
// 		{
// 			if (*PointSet.at(i)==*PointSet.at(j)){
// 				PointSet.erase(PointSet.begin() + j);
// 			}
// 		}
// 	}
// }

// void twoDProjection::cleanEdgeSet()
// {
// 	for (int i = 0; i < EdgeSet.size(); i++)
// 	{
// 		for (int j = i; j < EdgeSet.size(); j++)
// 		{
// 			if (*EdgeSet.at(i)==*EdgeSet.at(j)){
// 				EdgeSet.erase(EdgeSet.begin() + j);
// 			}
// 		}
// 	}
// }

void twoDProjection::printer()
{
	twoDPoint *p;
	Edge *e;
	for (int i = 0; i < PointSet.size(); i++)
	{
		p = PointSet.at(i);
		std::cout << i << " " << p->a << " " << p->b << "\n";
	}
	for (int i = 0; i < EdgeSet.size(); i++)
	{
		e = EdgeSet.at(i);
		std::cout << e->start_index << " " << e->end_index << "\n";
	}
}