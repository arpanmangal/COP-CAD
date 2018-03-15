#include "include/QT/frontview.h"

#include <QPainter>
#include <QTimer>

FrontView::FrontView(QWidget *parent)
    : QWidget(parent)
{
    // setFixedSize(200, 200);
}

void FrontView::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawLine(10, 10, 100, 100);
    painter.end();
}
//! [2]
