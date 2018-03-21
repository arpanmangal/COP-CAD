#include "include/QT/projectionWidget.h"

#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"

ProjectionWidget::ProjectionWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(width, height);

    setPens();
}

void ProjectionWidget::paintEvent(QPaintEvent *event)
{
    // Assign the QPainter
    painter2D = new QPainter(this);

    QRect rec(0, 0, 699, 449);
    painter2D->drawRect(rec);

    makeDrawing(); // Draw the edges and points
}

// Setters
void ProjectionWidget::setPointSet(PointVector2D const &pointVect)
{
    pointSet = pointVect;
    
    // Do a rescaling of points
    PointVector2D points;

    float max_a = -100000.0;
    float min_a = 100000.0;

    float max_b = -100000.0;
    float min_b = 100000.0;

    float a, b;

    for (iterPoint2d it = pointSet.begin(); it != pointSet.end(); it++)
    {
        a = (*it)->a;
        b = (*it)->b;

        max_a = (max_a < a) ? a : max_a;
        min_a = (a < min_a) ? a : min_a;

        max_b = (max_b < b) ? b : max_b;
        min_b = (b < min_b) ? b : min_b;
    }

    // map range (max_a - min_a) to width and corresponding b to height
    // If f > 1 => Apply smaller factor
    // If f < 1 => Apply smaller factor
    float factor_a = (max_a - min_a < 0.1) ? 1 : (width - 10) / (max_a - min_a); // division by 0!!
    float factor_b = (max_b - min_b < 0.1) ? 1 : (height - 10) /(max_b - min_b);

    float factor = (factor_a < factor_b) ? factor_a : factor_b;
    factor /= 2;

    for (iterPoint2d it = pointSet.begin(); it != pointSet.end(); it++)
    {
        a = (*it)->a;
        a = (a - min_a) * factor + 10;

        b = (*it)->b;
        b = (b - min_b) * factor + 10;

        points.push_back(new twoDPoint(a, b));
    }

    // Assign the point set
    pointSet = points;
}

void ProjectionWidget::setEdgeSet(EdgeVector2D const &edgeVect)
{
    edgeSet = edgeVect;
}

// Functions for Painting
void ProjectionWidget::setPens()
{
    strLinePen.setColor(Qt::black);
    strLinePen.setWidth(2);

    dottedPen.setColor(Qt::black);
    dottedPen.setWidth(1.4);
    dottedPen.setStyle(Qt::DotLine);

    pointPen.setColor(Qt::darkGreen);
    pointPen.setCapStyle(Qt::RoundCap);
    pointPen.setWidth(8);
}

QPoint *pointToQPoint(twoDPoint *p)
{
    QPoint *qp = new QPoint();
    qp->setX(p->a);
    qp->setY(p->b);

    return qp;
}

void ProjectionWidget::makeDrawing()
{
    for (iterPoint2d it = pointSet.begin(); it != pointSet.end(); it++)
    {
        QPoint p = *pointToQPoint(*it);

        drawPoint(p);
    }

    for (iterEdge2d it = edgeSet.begin(); it != edgeSet.end(); it++)
    {
        QPoint p1 = *pointToQPoint(pointSet.at((*it)->start_index));
        QPoint p2 = *pointToQPoint(pointSet.at((*it)->end_index));

        drawStrLine(p1, p2);
    }

    painter2D->end();
    delete painter2D;
}

void ProjectionWidget::drawStrLine(QPoint p1, QPoint p2)
{
    painter2D->setPen(strLinePen);
    painter2D->drawLine(p1, p2);
}

void ProjectionWidget::drawDottedLine(QPoint p1, QPoint p2)
{
    painter2D->setPen(dottedPen);
    painter2D->drawLine(p1, p2);
}

void ProjectionWidget::drawPoint(QPoint p)
{
    painter2D->setPen(pointPen);
    painter2D->drawPoint(p);
}
