#include "include/QT/mainwindow.h"
#include <ui_mainwindow.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setCentralWidget(ui->plainTextEdit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionNew_Window_triggered()
{
//    MyDialog myDialog;
//    myDialog.setModal(false);
//    myDialog.exec();

    myDialog = new MyDialog();
    myDialog->show();
}
