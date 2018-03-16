#ifndef INPUTMODE_H
#define INPUTMODE_H

#include <QWidget>

namespace Ui {
class InputMode;
}

class InputMode : public QWidget
{
    Q_OBJECT

public:
    explicit InputMode(QWidget *parent, int mode);
    ~InputMode();

private slots:
    void on_submit_clicked();

private:
    Ui::InputMode *ui;
    
    int mode;
    QWidget *my_parent;
};

#endif // INPUTMODE_H
