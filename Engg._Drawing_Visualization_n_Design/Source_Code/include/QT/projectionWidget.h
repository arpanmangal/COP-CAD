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

  // Set Width and Height
  void setHeightWidth(int width, int height);

  // Scaling Factor Calculation
  void analysePoints(PointVector2D points);
  float calculateFactor();
  void setFactor(float fact);
  float getFactor();
  void applyFactor(); // Will also do the neccessary transformations

  // Set type of view, 0 for iso, 1 for front, 2 for top, rest for side
  void setViewType(int type);

protected:
  void paintEvent(QPaintEvent *event);

private:
  PointVector2D pointSet;
  EdgeVector2D edgeSet;

  // Size
  int width = 400;
  int height = 300;

  // type
  int type = 1; // Front by default

  // Factor
  float factor = 1;
  float max_a = -100000.0;
  float min_a = 100000.0;
  float max_b = -100000.0;
  float min_b = 100000.0;

  // 2D Painter
  QPainter *painter2D;
  QPen strLinePen;
  QPen thinPen;
  QPen dottedPen;
  QPen pointPen;

  // void test();
  void setPens();
  void makeDrawing();
  void drawStrLine(QPoint p1, QPoint p2);
  void drawThinLine(QPoint p1, QPoint p2);
  void drawDottedLine(QPoint p1, QPoint p2);
  void drawPoint(QPoint p);
};

#endif // PROJECTION_WIDGET_H
