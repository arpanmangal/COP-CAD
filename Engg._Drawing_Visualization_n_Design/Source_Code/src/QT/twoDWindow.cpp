
#include "include/QT/twoDWindow.h"

#include <QGridLayout>
#include <QLabel>

twoDWindow::twoDWindow()
{
    setWindowTitle(tr("2D Painting on Native and OpenGL Widgets"));

    FrontView *native = new FrontView(this);
    QLabel *nativeLabel = new QLabel(tr("Native"));
    nativeLabel->setAlignment(Qt::AlignHCenter);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(native, 0, 0);
    layout->addWidget(nativeLabel, 1, 0);
    setLayout(layout);

}
