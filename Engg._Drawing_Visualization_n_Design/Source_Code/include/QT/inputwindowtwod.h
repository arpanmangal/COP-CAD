#ifndef INPUTWINDOWTWOD_H
#define INPUTWINDOWTWOD_H

#include <QWidget>
#include "include/common.h"

namespace Ui {
class InputWindowTwoD;
}

class InputWindowTwoD : public QWidget
{
    Q_OBJECT

public:
    explicit InputWindowTwoD(int num_views, QWidget *parent = 0);
    ~InputWindowTwoD();

private slots:
    void on_EnterPoint_Front_clicked();

    void on_FinishPointAdd_Front_clicked();

    void on_EnterEdge_Front_clicked();

    void on_FinishEdgeAdd_Front_clicked();

    void on_EnterPoint_Top_clicked();

    void on_FinishPointAdd_Top_clicked();

    void on_EnterEdge_Top_clicked();

    void on_FinishEdgeAdd_Top_clicked();

    void on_EnterPoint_Side_clicked();

    void on_FinishPointAdd_Side_clicked();

    void on_EnterEdge_Side_clicked();

    void on_FinishEdgeAdd_Side_clicked();

    void on_ContinueButton_clicked();

private:
    Ui::InputWindowTwoD *ui;

    int num_views;

    PointVector2D frontViewPoints;
    PointVector2D topViewPoints;
    PointVector2D sideViewPoints;

    EdgeVector2D frontViewEdges;
    EdgeVector2D topViewEdges;
    EdgeVector2D sideViewEdges;

    void setupButtons();
};

#endif // INPUTWINDOWTWOD_H
