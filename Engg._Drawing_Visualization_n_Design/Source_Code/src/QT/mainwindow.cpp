#include "include/QT/mainwindow.h"
#include <ui_mainwindow.h>
#include <QCloseEvent>
#include <QMessageBox>
#include <QInputDialog>
#include <QComboBox>

#include <iostream>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;

    delete paint2d;
}

//void MainWindow::on_actionNew_Window_triggered()
//{
////    MyDialog myDialog;
////    myDialog.setModal(false);
////    myDialog.exec();

//    exitDialog = new ExitConfirm();
//    exitDialog->show();
//}

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
    //  paint2d = new Dialog2D(this);
    //  paint2d->show();

    //  MyDialog *dia = new MyDialog;
    //  dia->show();

    //  MainWindow *win2 = new MainWindow();
    //  win2->show();

    twoDWindow *win = new twoDWindow();
    win->show();
}

void MainWindow::on_threeDInput_clicked()
{
    // double point = QInputDialog::getDouble(this, "lsf", "dl", 1.0);
    //     QTextStream cout(stdout);
    // cout << point;

    InputMode *mode = new InputMode(2);
    mode->show();
    // QStringList commands = {"Q", "W", "E", "R"};
    // QComboBox *combo = new QComboBox(this);
    // combo->addItems(commands);
    // connect(combo, &QComboBox::currentTextChanged, this, &MainWindow::commandChanged);
}

void MainWindow::commandChanged(const QString &command_text)
{
    //Do the logic based on command_text
}


  /*   ui->setupUi(this);
    mode = new QComboBox();

    QString file = "Choose a File";
    QString enter = "Enter Point set and Edge Set";

    mode->addItem(file);
    mode->addItem(enter);

    mode->showPopup(); */