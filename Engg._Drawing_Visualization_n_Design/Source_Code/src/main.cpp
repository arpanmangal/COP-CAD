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
#include "include/QT/inputwindowtwod.h"
#include "include/QT/inputwindowthreed.h"
#include <iostream>
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    // InputWindowTwoD w2(3);
    // w2.show();

    // InputWindowThreeD *w3 = new InputWindowThreeD();
    // w3->show();

    // twoDWindow *win = new twoDWindow();
    // win->show();

    // ProjectionWindow * win = new ProjectionWindow;
    // win->show();

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
