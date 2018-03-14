#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "include/QT/exitconfirm.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

// private slots:
//     void on_actionNew_Window_triggered();

private slots:
    void on_action_Exit_triggered();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;

    void closeEvent(QCloseEvent *event);
    ExitConfirm *exitDialog;
};

#endif // MAINWINDOW_H
