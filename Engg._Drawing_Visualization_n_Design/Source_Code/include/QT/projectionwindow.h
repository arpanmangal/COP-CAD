#ifndef PROJECTIONWINDOW_H
#define PROJECTIONWINDOW_H

#include <QWidget>
#include <QMenuBar>
#include <QLabel>

// Forward Declaration
class threeDObject;
class twoDProjection;
class isometricView;

namespace Ui
{
class ProjectionWindow;
}

class ProjectionWindow : public QWidget
{
  Q_OBJECT

public:
  explicit ProjectionWindow(threeDObject *object, QWidget *parent = 0);
  ~ProjectionWindow();

private slots:
  // Slots for Menu
  void save3D();
  void save2D();
  void exit();
  void helpUsage();
  void helpProjec();

  // Slots for Rotation
  void on_yaw_sliderPressed();
  void on_pitch_sliderPressed();
  void on_roll_sliderPressed();
  void on_yaw_sliderReleased();
  void on_pitch_sliderReleased();
  void on_roll_sliderReleased();
  // void on_yaw_valueChanged(int value);
  // void on_pitch_valueChanged(int value);
  // void on_roll_valueChanged(int value);

private:
  Ui::ProjectionWindow *ui;

  threeDObject *object;
  twoDProjection *frontView;
  twoDProjection *topView;
  twoDProjection *sideView;
  isometricView *isoView;

  // Object Angles
  int yaw;
  int pitch;
  int roll;

  /** Create Actions */
  void createMenus();
  /** Create Menu Actions */
  void createActions();

  QMenuBar *menuBar;
  QMenu *fileMenu;
  QMenu *helpMenu;

  QAction *save3DAct;
  QAction *save2DAct;
  QAction *exitAct;
  QAction *helpUsageAct;
  QAction *helpProjecAct;
  QLabel *infoLabel;

  /** Creates the Projection of the 3D Object including Isometric View and Displays it */
  void createProjections();
};

#endif // PROJECTIONWINDOW_H
