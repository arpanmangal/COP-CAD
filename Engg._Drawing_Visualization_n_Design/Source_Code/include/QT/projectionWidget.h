#ifndef PROJECTION_WIDGET_H
#define PROJECTION_WIDGET_H

#include <QWidget>
#include <QtGui>
#include <QtCore>

#include <include/common.h>

class ProjectionWidget : public QWidget
{
  Q_OBJECT

public:
  ProjectionWidget(QWidget *parent);

  void setPointSet(PointVector2D const &pointVect);
  void setEdgeSet(EdgeVector2D const &edgeVect);
  // void draw();

protected:
  void paintEvent(QPaintEvent *event);

private:
  PointVector2D pointSet;
  EdgeVector2D edgeSet;

  // Size
  int width = 700;
  int height = 450;

  // 2D Painter
  QPainter *painter2D;
  QPen strLinePen;
  QPen dottedPen;
  QPen pointPen;

  // void test();
  void setPens();
  void makeDrawing();
  void drawStrLine(QPoint p1, QPoint p2);
  void drawDottedLine(QPoint p1, QPoint p2);
  void drawPoint(QPoint p);
};

#endif // PROJECTION_WIDGET_H
