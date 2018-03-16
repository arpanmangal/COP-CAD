#include "include/QT/mainwindow.h"
#include <ui_mainwindow.h>
#include <QCloseEvent>
#include <QMessageBox>
#include <QInputDialog>
#include <QComboBox>

#include <QTextStream>
QTextStream cout(stdout);

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent),
                                          ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle(tr("COP-CAD"));
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
    cout << "\nExiting the Application\n";
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

/*   ui->setupUi(this);
    mode = new QComboBox();

    QString file = "Choose a File";
    QString enter = "Enter Point set and Edge Set";

    mode->addItem(file);
    mode->addItem(enter);

    mode->showPopup(); */

void MainWindow::on_genOrthoProjec_clicked()
{
    //  paint2d = new Dialog2D(this);
    //  paint2d->show();

    //  MyDialog *dia = new MyDialog;
    //  dia->show();

    //  MainWindow *win2 = new MainWindow();
    //  win2->show();

    // twoDWindow *win = new twoDWindow();
    // win->show();

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
