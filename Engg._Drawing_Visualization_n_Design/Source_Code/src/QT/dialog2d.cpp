#include <include/QT/dialog2d.h>
#include <ui_dialog2d.h>

#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"

Dialog2D::Dialog2D(QWidget *parent, int halogen) : QDialog(parent),
                                      ui(new Ui::Dialog2D)
{
    ui->setupUi(this);
}

Dialog2D::~Dialog2D()
{
    delete ui;

    // Remove garbage
    delete painter2D;
}

void Dialog2D::test()
{
    // Generates a sample 2d data
    twoDPoint *p1 = new twoDPoint(2.4, 3.4);
    twoDPoint *p2 = new twoDPoint(50.4, 10.6);
    twoDPoint *p3 = new twoDPoint(20.45, 50.34);
    twoDPoint *p4 = new twoDPoint(180.23, 269.3);

    PointVector2D points;
    points.push_back(p1);
    points.push_back(p2);
    points.push_back(p3);
    points.push_back(p4);

    EdgeVector2D edges;
    edges.push_back (new Edge(0, 1));
    edges.push_back (new Edge(1, 2));
    edges.push_back (new Edge(1, 3));
    

    makeDrawing(points, edges);
}

void Dialog2D::paintEvent(QPaintEvent *e)
{
    painter2D = new QPainter(this);

    strLinePen.setColor(Qt::black);
    strLinePen.setWidth(1.4);

    dottedPen.setColor(Qt::black);
    dottedPen.setWidth(1.4);
    dottedPen.setStyle(Qt::DotLine);

    pointPen.setColor(Qt::black);
    pointPen.setWidth(4);

    // painter2D->drawLine(10, 10, 100, 100);
    // QPoint p1(10, 10);
    // QPoint p2(100, 400);
    // drawStrLine(p1, p2);
    // QPoint p3(200, 300);
    // drawDottedLine(p1, p3);
    // drawPoint(p3);

    test();
}

QPoint *pointToQPoint(twoDPoint* p)
{
    QPoint *qp = new QPoint();
    qp->setX(p->a);
    qp->setY(p->b);

    return qp;
}

void Dialog2D::makeDrawing(PointVector2D points, EdgeVector2D edges)
{
    for (iterPoint2d it = points.begin(); it != points.end(); it++)
    {
        QPoint p = *pointToQPoint (*it);

        drawPoint(p);
    }

    for (iterEdge2d it = edges.begin(); it != edges.end(); it++)
    {
        QPoint p1 = *pointToQPoint (points.at((*it)->start_index));
        QPoint p2 = *pointToQPoint (points.at((*it)->end_index));

        drawStrLine (p1, p2);
    }
}

void Dialog2D::drawStrLine(QPoint p1, QPoint p2)
{
    painter2D->setPen(strLinePen);
    painter2D->drawLine(p1, p2);
}

void Dialog2D::drawDottedLine(QPoint p1, QPoint p2)
{
    painter2D->setPen(dottedPen);
    painter2D->drawLine(p1, p2);
}

void Dialog2D::drawPoint(QPoint p)
{
    painter2D->setPen(pointPen);
    painter2D->drawPoint(p);
}
