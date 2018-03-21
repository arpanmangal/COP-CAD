#include <vector>
#include <iostream>
#include <fstream>
#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"
#include "include/2D/twoDProjection.h"
using namespace std;

void twoDProjection::add_pointSet(PointVector2D const &a)
{
	PointSet = a;
}

void twoDProjection::add_edgeSet(EdgeVector2D const &a)
{
	EdgeSet = a;
	edgeCollinearityCheck();
}

void twoDProjection::add_edgeSetfrom3D(EdgeVector2D const &a){
	EdgeSet =a;
}

void twoDProjection::edgeCollinearityCheck()
{
	int start_ind, end_ind;
	int size = PointSet.size();
	int adjacency_matrix[size][size] = {0};
	int coincidency_matrix[size][size] = {0};

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			coincidency_matrix[i][j] = 0;
			adjacency_matrix[i][j] = 0;
		}
	}

	for (int i = 0; i < size; i++)
	{
		for (int j = i ; j < size; j++)
		{
			if (*PointSet.at(i) == *PointSet.at(j))
			{
				coincidency_matrix[i][j] = 1;
				coincidency_matrix[j][i] = 1;
			}
		}
	}


	for (int i = 0; i < EdgeSet.size(); i++)
	{
		start_ind = EdgeSet.at(i)->start_index;
		end_ind = EdgeSet.at(i)->end_index;
		adjacency_matrix[start_ind][end_ind] = 1;
		adjacency_matrix[end_ind][start_ind] = 1;

		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				if ((coincidency_matrix[end_ind][j]==1)&&(coincidency_matrix[start_ind][k]==1))
				{
					adjacency_matrix[k][j]=1;
					adjacency_matrix[j][k]=1;
				}
			}
		}
	}
	EdgeSet = EdgeVector2D();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (adjacency_matrix[i][j] == 1)
			{
				EdgeSet.push_back(new Edge(i, j));
			}
		}
	}
}

void twoDProjection::printer()
{
	twoDPoint *p;
	Edge *e;
	std::cout << "Points\n";
	for (int i = 0; i < PointSet.size(); i++)
	{
		p = PointSet.at(i);
		std::cout << i << " " << p->a << " " << p->b << "\n";
	}
	std::cout << "Edges\n";
	for (int i = 0; i < EdgeSet.size(); i++)
	{
		e = EdgeSet.at(i);
		std::cout << e->start_index << " " << e->end_index << "\n";
	}
}

void twoDProjection::filewriter(const char * path)
{
	ofstream file;
	file.open(path,ios::out);
	file<<PointSet.size();
	for (int i= 0;i<PointSet.size();i++)
	{
		file<<"\n"<<PointSet.at(i)->a<<" "<<PointSet.at(i)->b;
	}
	file<<endl;
	file<<EdgeSet.size();
	for (int i=0; i<EdgeSet.size();i++)
	{
		file<<"\n"<<EdgeSet.at(i)->start_index<<" "<<EdgeSet.at(i)->end_index;
	}
	file.close();
}