/**Defines interface for Orthographic Projections.
Uses three projection vies as data members */

#include <2D/twoDPoint.h>
#include <2D/Edge.h>
#include <2D/twoDProjection.h>
#include <2D/twoDProjectionView.h>
#include <3D/threeDPoint.h>

twoDProjectionView::twoDProjectionView(twoDProjection *f, twoDProjection *t, twoDProjection *s)
{
	frontview = f;
	topview = t;
	sideview = s;
}

twoDProjectionView::twoDProjectionView(twoDProjection *f, twoDProjection *t)
{
	frontview = f;
	topview = t;
	sideview = NULL;
}

PointVector3D twoDProjectionView::pointReconstruction()
{
	twoDPoint frontPointTemp = twoDPoint(0, 0);
	twoDPoint topPointTemp = twoDPoint(0, 0);
	twoDPoint sidePointTemp = twoDPoint(0, 0);
	threeDPoint retPoint = threeDPoint(0, 0, 0);
	PointVector3D retVal;
	if (sideview == NULL)
	{
		for (int i = 0; i < frontview->PointSet.size(); i++)
		{
			frontPointTemp = *(frontview->PointSet.at(i));
			topPointTemp = *(topview->PointSet.at(i));
			if (frontPointTemp.a == topPointTemp.b)
			{
				retPoint = threeDPoint(topPointTemp.a, frontPointTemp.a, frontPointTemp.b);
				retVal.push_back(&retPoint);
			}
			else
			{
				IncompatibleViews e;
				throw e;
			}
		}
		return retVal;
	}
	for (int i = 0; i < frontview->PointSet.size(); i++)
	{
		frontPointTemp = *(frontview->PointSet.at(i));
		topPointTemp = *(topview->PointSet.at(i));
		sidePointTemp = *(sideview->PointSet.at(i));
		if ((frontPointTemp.a == topPointTemp.b) && (frontPointTemp.b == sidePointTemp.b) && (sidePointTemp.a == topPointTemp.a))
		{
			retPoint = threeDPoint(topPointTemp.a, frontPointTemp.a, frontPointTemp.b);
			retVal.push_back(&retPoint);
		}
	}
	return retVal;
}

bool twoDProjectionView::checkEdgeCompatibility_2views(Edge &e)
{
	if (*(topview->PointSet.at(e.start_index)) == *(topview->PointSet.at(e.end_index)))
	{
		return true;
	}
	for (int i = 0; i < topview->EdgeSet.size(); i++)
	{
		if (*(topview->EdgeSet.at(i)) == e)
		{
			return true;
		}
	}
	return false;
}

EdgeVector3D twoDProjectionView::edgeReconstruction()
{
	twoDPoint frontPointTemp = twoDPoint(0, 0);
	twoDPoint topPointTemp = twoDPoint(0, 0);
	twoDPoint sidePointTemp = twoDPoint(0, 0);
	Edge frontEdgeTemp = Edge(0, 0);
	Edge topEdgeTemp = Edge(0, 0);
	Edge sideEdgeTemp = Edge(0, 0);
	Edge retEdge = Edge(0, 0);
	EdgeVector3D retVal;
	if (sideview == NULL)
	{
		for (int i = 0; i < frontview->EdgeSet.size(); i++)
		{
			if (checkEdgeCompatibility_2views(*(frontview->EdgeSet.at(i))))
			{
				retVal.push_back(frontview->EdgeSet.at(i));
			}
		}
		return retVal;
	}
}

/**removes edges which are redundant*/
//EdgeVector3D pruneEdges(EdgeVector3D e);
