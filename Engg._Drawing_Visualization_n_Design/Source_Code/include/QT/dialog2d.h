// #ifndef DIALOG2D_H
// #define DIALOG2D_H

// #include <QDialog>
// #include <QtGui>
// #include <QtCore>

// #include <include/common.h>

// namespace Ui
// {
// class Dialog2D;
// }

// class Dialog2D : public QDialog
// {
//   Q_OBJECT

// public:
//   explicit Dialog2D(QWidget *parent = 0, int halogen = 9);
//   ~Dialog2D();

// private:
//   Ui::Dialog2D *ui;

//   // 2D Painter
//   QPainter *painter2D;
//   QPen strLinePen;
//   QPen dottedPen;
//   QPen pointPen;

//   void test();
//   void makeDrawing(PointVector2D points, EdgeVector2D edges);
//   void drawStrLine(QPoint p1, QPoint p2);
//   void drawDottedLine(QPoint p1, QPoint p2);
//   void drawPoint(QPoint p);

// protected:
//   void paintEvent(QPaintEvent *e);
// };

// #endif // DIALOG2D_H
