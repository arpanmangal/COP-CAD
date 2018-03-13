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
	edgeCollinearityCheck();
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

void twoDProjection::edgeCollinearityCheck(){
	int start_ind,end_ind;
	twoDPoint *start,*end;
	Edge *temp;
	EdgeVector2D detailedEdgeSet;
	for (int i=0;i<EdgeSet.size();i++){
		detailedEdgeSet.push_back(EdgeSet.at(i));
		start_ind=EdgeSet.at(i)->start_index;
		start = PointSet.at(start_ind);
		end_ind=EdgeSet.at(i)->end_index;
		end = PointSet.at(end_ind);
		for (int j=start_ind+1;j<PointSet.size();j++){
			if (*start==*PointSet.at(j))
			{	
				temp = new Edge(j,end_ind);
				detailedEdgeSet.push_back(temp);
			}
			if (*end==*PointSet.at(j))
			{
				temp = new Edge(start_ind,j);
				detailedEdgeSet.push_back(temp);
			}
		} 
	}
	EdgeSet = detailedEdgeSet;
	Edge *e;
	for (int i = 0; i < EdgeSet.size(); i++)
	{
		e = EdgeSet.at(i);
		std::cout << e->start_index << " " << e->end_index << "\n";
	}
	
}

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