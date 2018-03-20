#ifndef PROJECTIONWINDOW_H
#define PROJECTIONWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QLabel>


// Forward Declaration
class twoDProjectionView;
class isometricView;

namespace Ui
{
class ProjectionWindow;
}

class ProjectionWindow : public QWidget
{
    Q_OBJECT

  public:
    explicit ProjectionWindow(twoDProjectionView *orthographicViews, isometricView *isoView = NULL, QWidget *parent = 0);
    ~ProjectionWindow();

  private slots:
    // Slots for Menu
    void save3D();
    void save2D();
    void exit();
    void helpUsage();
    void helpProjec();

    // Slots for Rotation
    void on_yaw_valueChanged(int value);
    void on_pitch_valueChanged(int value);
    void on_roll_valueChanged(int value);

  private:
    Ui::ProjectionWindow *ui;

    void createActions();
    void createMenus();

    QMenuBar *menuBar;
    QMenu *fileMenu;
    QMenu *helpMenu;

    QAction *save3DAct;
    QAction *save2DAct;
    QAction *exitAct;
    QAction *helpUsageAct;
    QAction *helpProjecAct;
    QLabel *infoLabel;
};

#endif // PROJECTIONWINDOW_H
