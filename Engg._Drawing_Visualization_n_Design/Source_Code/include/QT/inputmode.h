/** Defines a QT Widget which allows user to choose what input mode he wants: read from file, or enter data manually */

#ifndef INPUTMODE_H
#define INPUTMODE_H

#include <QWidget>

namespace Ui
{
class InputMode;
}

class InputMode : public QWidget
{
    Q_OBJECT

  public:
    /** Constructor */
    explicit InputMode(int mode, QWidget *parent = 0);
    ~InputMode();

  private slots:
    void on_submit_clicked();

    void on_goBack_clicked();

  private:
    Ui::InputMode *ui;

    int mode;
};

#endif // INPUTMODE_H
