#include "include/QT/projectionWidget.h"

#include <QPainter>

ProjectionWidget::ProjectionWidget(QWidget *parent)
    : QWidget(parent)
{
    setFixedSize(700, 450);
}

void ProjectionWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter;
    painter.begin(this);
    painter.drawLine(10, 10, 100, 100);

    QRect rec(0, 0, 699, 449);
    painter.drawRect(rec);
    painter.end();
}
//! [2]
