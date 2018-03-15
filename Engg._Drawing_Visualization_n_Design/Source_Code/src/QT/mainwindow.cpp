#include "include/QT/mainwindow.h"
#include <ui_mainwindow.h>
#include <QCloseEvent>
#include <QMessageBox>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_actionNew_Window_triggered()
//{
////    MyDialog myDialog;
////    myDialog.setModal(false);
////    myDialog.exec();

//    exitDialog = new ExitConfirm();
//    exitDialog->show();
//}


void MainWindow::closeEvent(QCloseEvent *event)  // show prompt when user wants to close app
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
    std::cout << "triggered";
    QApplication::quit();
}

void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, tr("About Menu"),
                       tr("The <b>Menu</b> example shows how to create "
                          "menu-bar menus and context menus."));
}

void MainWindow::on_actionAbout_QT_triggered()
{

}

// Buttons
void MainWindow::on_help_clicked()
{
    QMessageBox::information(this, "Help", "About");
}

void MainWindow::on_genOrthoProjec_clicked()
{
     paint2d = new Dialog2D;
     paint2d->show();
}
