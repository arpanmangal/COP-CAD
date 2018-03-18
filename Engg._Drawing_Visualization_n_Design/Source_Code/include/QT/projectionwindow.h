#ifndef PROJECTIONWINDOW_H
#define PROJECTIONWINDOW_H

#include <QWidget>

// Forward Declaration
class twoDProjectionView;

namespace Ui {
class ProjectionWindow;
}

class ProjectionWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ProjectionWindow(twoDProjectionView* orthographicViews, QWidget *parent = 0);
    ~ProjectionWindow();

private:
    Ui::ProjectionWindow *ui;
};

#endif // PROJECTIONWINDOW_H
