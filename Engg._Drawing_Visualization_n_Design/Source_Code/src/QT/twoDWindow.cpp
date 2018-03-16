
#include "include/QT/twoDWindow.h"

#include <QGridLayout>
#include <QLabel>

twoDWindow::twoDWindow()
{
    setMinimumSize(800, 800);
    setWindowTitle(tr("2D Painting on Native and OpenGL Widgets"));

    ProjectionWidget *topView = new ProjectionWidget(this);
    QLabel *topViewLabel = new QLabel(tr("Top View"));
    topViewLabel->setAlignment(Qt::AlignHCenter);
    topViewLabel->setBuddy(topView);

    ProjectionWidget *frontView = new ProjectionWidget(this);
    QLabel *frontViewLabel = new QLabel(tr("FrontView"));
    frontViewLabel->setAlignment(Qt::AlignHCenter);
    frontViewLabel->setBuddy(frontView);

    ProjectionWidget *sideView = new ProjectionWidget(this);
    QLabel *sideViewLabel = new QLabel(tr("Side View"));
    sideViewLabel->setAlignment(Qt::AlignHCenter);
    sideViewLabel->setBuddy(sideView);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(topViewLabel, 1, 1);
    layout->addWidget(topView, 1, 0);

    layout->addWidget(frontViewLabel, 1, 2);
    layout->addWidget(frontView, 1, 3);

    layout->addWidget(sideViewLabel, 0, 2);
    layout->addWidget(sideView, 0, 3);
    setLayout(layout);
}
