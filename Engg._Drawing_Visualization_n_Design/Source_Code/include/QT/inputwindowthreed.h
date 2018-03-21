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

private:
    Ui::InputWindowThreeD *ui;
};

#endif // INPUTWINDOWTHREED_H
