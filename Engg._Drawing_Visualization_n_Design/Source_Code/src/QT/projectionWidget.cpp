#include "include/QT/projectionWidget.h"

#include <QPainter>

ProjectionWidget::ProjectionWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(300, 300);
}

void ProjectionWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawLine(10, 10, 100, 100);

    QRect rec(0, 0, 299, 299);
    painter.drawRect(rec);
    painter.end();
}
//! [2]
