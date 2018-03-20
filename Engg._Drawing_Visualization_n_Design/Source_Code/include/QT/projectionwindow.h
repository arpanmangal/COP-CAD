#ifndef PROJECTIONWINDOW_H
#define PROJECTIONWINDOW_H

#include <QWidget>

// Forward Declaration
class twoDProjectionView;
class isometricView;

namespace Ui {
class ProjectionWindow;
}

class ProjectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectionWindow(twoDProjectionView* orthographicViews, isometricView* isoView = NULL, QWidget *parent = 0);
    ~ProjectionWindow();

private slots:
    void on_yaw_valueChanged(int value);

    void on_pitch_valueChanged(int value);

    void on_roll_valueChanged(int value);

private:
    Ui::ProjectionWindow *ui;
};

#endif // PROJECTIONWINDOW_H
