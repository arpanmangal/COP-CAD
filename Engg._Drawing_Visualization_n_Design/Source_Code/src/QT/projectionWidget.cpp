#include "include/QT/projectionWidget.h"

// #include <QPainter>
#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"

#include <iostream>

ProjectionWidget::ProjectionWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(700, 450);


}

void ProjectionWidget::paintEvent(QPaintEvent *event)
{
    // Assign the QPainter
    painter2D = new QPainter(this);
    // QPainter painter;
    // painter.begin(this);
    // painter.drawLine(10, 10, 100, 100);

    QRect rec(0, 0, 699, 449);
    painter2D->drawRect(rec);
    // painter.end();

    makeDrawing(); // Draw the edges and points
}

// Setters
void ProjectionWidget::setPointSet(PointVector2D const &pointVect)
{
    pointSet = pointVect;
}

void ProjectionWidget::setEdgeSet(EdgeVector2D const &edgeVect)
{
    edgeSet = edgeVect;
}

// Functions for Painting
void ProjectionWidget::setPens()
{
    strLinePen.setColor(Qt::black);
    strLinePen.setWidth(1.4);

    dottedPen.setColor(Qt::black);
    dottedPen.setWidth(1.4);
    dottedPen.setStyle(Qt::DotLine);

    pointPen.setColor(Qt::black);
    pointPen.setWidth(4);
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
