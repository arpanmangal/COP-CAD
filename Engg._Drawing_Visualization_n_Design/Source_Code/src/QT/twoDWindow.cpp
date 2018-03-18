
#include "include/QT/twoDWindow.h"

#include <QGridLayout>
#include <QLabel>
#include <QScrollArea>
#include <QtGui>
#include <QtCore>

twoDWindow::twoDWindow()
{
    setMinimumSize(200, 200);
    setWindowTitle(tr("2D Painting on Native and OpenGL Widgets"));

    // ProjectionWidget *topView = new ProjectionWidget(this);
    // QLabel *topViewLabel = new QLabel(tr("Top View"));
    // topViewLabel->setAlignment(Qt::AlignHCenter);
    // topViewLabel->setBuddy(topView);

    // ProjectionWidget *frontView = new ProjectionWidget(this);
    // QLabel *frontViewLabel = new QLabel(tr("FrontView"));
    // frontViewLabel->setAlignment(Qt::AlignHCenter);
    // frontViewLabel->setBuddy(frontView);

    // ProjectionWidget *sideView = new ProjectionWidget(this);
    // QLabel *sideViewLabel = new QLabel(tr("Side View"));
    // sideViewLabel->setAlignment(Qt::AlignHCenter);
    // sideViewLabel->setBuddy(sideView);

    // QGridLayout *layout = new QGridLayout(this);
    // layout->addWidget(topViewLabel, 1, 1);
    // layout->addWidget(topView, 1, 0);

    // layout->addWidget(frontViewLabel, 1, 2);
    // layout->addWidget(frontView, 1, 3);

    // layout->addWidget(sideViewLabel, 0, 2);
    // layout->addWidget(sideView, 0, 3);
    // setLayout(layout);

    // QLabel *imageLabel = new QLabel;
    // QImage image("happyguy.png");
    // imageLabel->setPixmap(QPixmap::fromImage(image));

    QLabel *l = new QLabel;
    QPicture pi;
    QPainter p(&pi);

    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(QPen(Qt::black, 5, Qt::DashDotLine, Qt::RoundCap));
    p.drawLine(0, 0, 200, 200);
    p.end();

    l->setPicture(pi);
    auto scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(l);
}
