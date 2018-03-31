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

    // Draw the lines

    QRect rec(0, 0, width - 1, height - 1);
    painter2D->drawRect(rec);

    makeDrawing(); // Draw the edges and points
}

// Set Width and Height
void ProjectionWidget::setHeightWidth(int width, int height)
{
    this->width = width;
    this->height = height;
}

// Calculating Scaling Factor
void ProjectionWidget::setFactor(float fact)
{
    factor = fact;
}

float ProjectionWidget::getFactor()
{
    return factor;
}

void ProjectionWidget::analysePoints(PointVector2D points)
{
    // The Job of this function is to compute the bounds on x and y coordinates of points of the given pointSet

    float a, b;

    for (iterPoint2d it = points.begin(); it != points.end(); it++)
    {
        a = (*it)->a;
        b = (*it)->b;

        max_a = (max_a < a) ? a : max_a;
        min_a = (a < min_a) ? a : min_a;

        max_b = (max_b < b) ? b : max_b;
        min_b = (b < min_b) ? b : min_b;
    }
}

float ProjectionWidget::calculateFactor()
{
    // Calculate the scaling factor based on the range data of the points
    analysePoints(pointSet);

    // map range (max_a - min_a) to width and corresponding b to height
    // If f > 1 => Apply smaller factor
    // If f < 1 => Apply smaller factor
    float factor_a = (max_a - min_a < 0.1) ? 1 : (width - 10) / (max_a - min_a); // division by 0!!
    float factor_b = (max_b - min_b < 0.1) ? 1 : (height - 10) / (max_b - min_b);

    float fact = (factor_a < factor_b) ? factor_a : factor_b;
    fact /= 1.5;

    return fact;
}

void ProjectionWidget::applyFactor()
{
    // Do a rescaling of points
    PointVector2D points;

    analysePoints(pointSet); // to calculate new min_a and min_b

    float a, b;
    for (iterPoint2d it = pointSet.begin(); it != pointSet.end(); it++)
    {
        a = (*it)->a;
        a = (a)*factor + 150;

        b = (*it)->b;
        b = (b)*factor + 150;

        // Do the transformations
        if (type == 0)
        {
            // Isometric View

             a += 20;
        }
        else if (type == 1)
        {
            // Front View
            b = height - b;
        }
        else if (type == 2)
        {
            // Top View
            // No transformation Reqd.
        }
        else
        {
            // Side View
            a = width - a;
            b = height - b;
        }

        points.push_back(new twoDPoint(a, b));
    }

    // Assign the point set
    pointSet = points;
}

// Set type of view, 0 for iso, 1 for front, 2 for top, rest for side
void ProjectionWidget::setViewType(int type)
{
    this->type = type;
}

// Setters
void ProjectionWidget::setPointSet(PointVector2D const &pointVect)
{
    pointSet = pointVect;
    //analysePoints(pointSet);

    // applyFactor();
    //setFactor(calculateFactor());
    //applyFactor();
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

    thinPen.setColor(Qt::black);
    thinPen.setWidth(2);

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

void ProjectionWidget::drawThinLine(QPoint p1, QPoint p2)
{
    painter2D->setPen(thinPen);
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
