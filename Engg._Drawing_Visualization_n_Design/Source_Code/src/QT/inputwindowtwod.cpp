#include "include/QT/inputwindowtwod.h"
#include "ui_inputwindowtwod.h"

InputWindowTwoD::InputWindowTwoD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputWindowTwoD)
{
    ui->setupUi(this);
}

InputWindowTwoD::~InputWindowTwoD()
{
    delete ui;
}
