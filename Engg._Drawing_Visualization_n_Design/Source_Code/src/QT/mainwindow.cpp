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

void MainWindow::on_action_Exit_triggered()
{
    std::cout << "triggered";
    QApplication::quit();

}

void MainWindow::on_pushButton_clicked()
{
    QMessageBox::information(this, "Help", "About");
}

void MainWindow::on_pushButton_2_clicked()
{

}
