#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "include/QT/dialog2d.h"
#include "include/QT/mydialog.h"
#include "include/QT/twoDWindow.h"
#include "include/QT/inputmode.h"

namespace Ui
{
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

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_QT_triggered();

    /** Prompt the user to provide a 3D Object, and then does the reconstruction work */
    void on_genOrthoProjec_clicked();

    /** Prompt the user to provide a 2D Object, then proceeds with reconstruction */
    void on_threeDReconstruction_clicked();

    /** Give a detailed Help about the Usage of the Software */
    void on_help_clicked();

private:
    Ui::MainWindow *ui;
    Dialog2D *paint2d;
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
