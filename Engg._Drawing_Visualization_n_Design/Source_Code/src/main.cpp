#include "include/QT/mainwindow.h"
#include <QApplication>
// #include <QtGui>
#include <QMessageBox>
#include <QInputDialog>

#include <QtCore>
#include <QtGui>
#include <QLabel>

// #include "include/QT/twoDWindow.h"
#include "include/QT/projectionwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    // twoDWindow *win = new twoDWindow();
    // win->show();

    ProjectionWindow * win = new ProjectionWindow;
    win->show();

    // QLabel w;
    // QPicture pi;
    // QPainter p(&pi);

    // // p.setRenderHint(QPainter::Antialiasing);
    // p.setPen(QPen(Qt::black, 5));
    // p.drawLine(0, 0, 200, 200);

    // p.end();

    // w.setPicture(pi);
    // w.show();

    return app.exec();
}
