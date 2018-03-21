#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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

  private slots:

    void on_actionExit_triggered();

    void on_actionAbout_triggered();

    void on_actionAbout_QT_triggered();

    /** Prompt the user to provide a 3D Object, and then does the reconstruction work */
    void on_genOrthoProjec_clicked();

    /** Prompt the user to provide a 2D Object, then proceeds with reconstruction */
    void on_threeDReconstruction_clicked();

private:
    Ui::MainWindow *ui;
    void closeEvent(QCloseEvent *event);
};

#endif // MAINWINDOW_H
