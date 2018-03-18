#ifndef PROJECTIONWINDOW_H
#define PROJECTIONWINDOW_H

#include <QWidget>

namespace Ui {
class ProjectionWindow;
}

class ProjectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectionWindow(QWidget *parent = 0);
    ~ProjectionWindow();

private:
    Ui::ProjectionWindow *ui;
};

#endif // PROJECTIONWINDOW_H
