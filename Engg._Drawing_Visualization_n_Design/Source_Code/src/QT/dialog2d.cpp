#include <include/QT/dialog2d.h>
#include <ui_dialog2d.h>

Dialog2D::Dialog2D(QWidget *parent) : QDialog(parent),
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
    QPoint p1(10, 10);
    QPoint p2(100, 400);
    drawStrLine(p1, p2);
    QPoint p3(200, 300);
    drawDottedLine(p1, p3);
    drawPoint(p3);
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
