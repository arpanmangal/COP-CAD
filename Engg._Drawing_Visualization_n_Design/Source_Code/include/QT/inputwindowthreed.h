#ifndef INPUTWINDOWTHREED_H
#define INPUTWINDOWTHREED_H

#include <QWidget>

namespace Ui {
class InputWindowThreeD;
}

class InputWindowThreeD : public QWidget
{
    Q_OBJECT

public:
    explicit InputWindowThreeD(QWidget *parent = 0);
    ~InputWindowThreeD();

private slots:
    void on_enterPoint_clicked();

    void on_finishPointAddition_clicked();

    void on_enterEdge_clicked();

    void on_finishEdgeAddition_clicked();

    void on_ContinueButton_clicked();

private:
    Ui::InputWindowThreeD *ui;
};

#endif // INPUTWINDOWTHREED_H
