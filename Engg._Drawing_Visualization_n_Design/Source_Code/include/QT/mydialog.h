#ifndef MYDIALOG_H
#define MYDIALOG_H

#include <QDialog>
// #include "include/QT/frontview.h"
namespace Ui {
class MyDialog;
}

class MyDialog : public QDialog
{
    Q_OBJECT

public:
    explicit MyDialog(QWidget *parent = 0);
    ~MyDialog();

private:
    Ui::MyDialog *ui;

    // FrontView* front_view_widget;
};

#endif // MYDIALOG_H
