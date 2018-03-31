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

  void on_Xrotate_valueChanged(int value);

  void on_Yrotate_valueChanged(int value);

  void on_Zrotate_valueChanged(int value);

private:
  Ui::ProjectionWindow *ui;

  threeDObject *object;
  twoDProjection *frontView;
  twoDProjection *topView;
  twoDProjection *sideView;
  isometricView *isoView;

  // Object Angles
  int Xval;
  int Yval;
  int Zval;

  // Calculation factor
  float calc_factor;

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
