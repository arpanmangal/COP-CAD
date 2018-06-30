#include "include/QT/mainwindow.h"
#include <ui_mainwindow.h>

#include <QCloseEvent>
#include <QMessageBox>

#include "include/QT/inputmode.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("COP-CAD"));
    QString Description = tr("<b>CopCAD</b> is an out-of-the-box ready to use Engineering Drawing tool. The tool provides an easy-to-use and fast way to user to render any three dimensional object as wireframe and visualise its orthographic projections. \
                             Also, given the three orthographic projections user can generate a wireframe to check the prototype of his/her model. \
                             The tool also allows user to rotate the object with an easy to use slider, and view orthographic projections of the rotated object.<br> \
                            <br> \
                             The software expects the projection drawing or the three dimensional model to be input in the form of its vertex set and edge set.<br> \
                            <br> \
                             <small>Known issues : Extra coplanar edges when given only two projection views which are insufficient to determine a unique wireframe.</small><br> \
                            <br> \
                             For documentation related to source code look at <a href = **insert link here**>doc</a>. \
                             For raising issues and code look at <a href = **insert link here**>repo</a>.");

    ui->Description->setText(Description);
    ui->Description->setMinimumHeight(300);
    ui->Description->setWordWrap(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::closeEvent(QCloseEvent *event) // show prompt when user wants to close app
{
    event->ignore();
    if (QMessageBox::Yes == QMessageBox::question(this, "Close Confirmation", "Exit?", QMessageBox::Yes | QMessageBox::No))
    {
        event->accept();
    }
}

// Menus
void MainWindow::on_actionExit_triggered()
{
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Menu"),
                       tr("<b>CopCAD</b> is an out-of-the-box ready to use Engineering Drawing tool. The tool provides an easy-to-use and fast way to user to render any three dimensional object as wireframe and visualise its orthographic projections. \
                             Also, given the three orthographic projections user can generate a wireframe to check the prototype of his/her model. \
                             The tool also allows user to rotate the object with an easy to use slider, and view orthographic projections of the rotated object.<br> \
                            <br> "));
}

void MainWindow::on_actionAbout_QT_triggered()
{
    QMessageBox::about(this, tr("About QT"),
                       tr("Qt (pronounced as 'cute', not 'cu-tee') is a cross-platform framework that is usually used as a graphical toolkit, although it is also very helpful in creating CLI applications. \
    It runs on the three major desktop OSes, as well as on mobile OSes, such as Symbian, Nokia Belle, Meego Harmattan, MeeGo or BB10, and on embedded devices.\
     Ports for Android (Necessitas) and iOS are also in development."));
}

// Buttons
void MainWindow::on_genOrthoProjec_clicked()
{
    // Take 3D Input
    InputMode *mode = new InputMode(3);
    mode->show();
}

void MainWindow::on_threeDReconstruction_clicked()
{
    // Take 2D Input
    InputMode *mode = new InputMode(2);
    mode->show();
}
