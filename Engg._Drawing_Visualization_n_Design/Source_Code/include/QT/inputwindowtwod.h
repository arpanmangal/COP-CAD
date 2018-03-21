#ifndef INPUTWINDOWTWOD_H
#define INPUTWINDOWTWOD_H

#include <QWidget>

namespace Ui {
class InputWindowTwoD;
}

class InputWindowTwoD : public QWidget
{
    Q_OBJECT

public:
    explicit InputWindowTwoD(QWidget *parent = 0);
    ~InputWindowTwoD();

private:
    Ui::InputWindowTwoD *ui;
};

#endif // INPUTWINDOWTWOD_H
