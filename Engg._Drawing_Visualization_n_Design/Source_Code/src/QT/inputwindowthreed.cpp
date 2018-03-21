#include "include/QT/inputwindowthreed.h"
#include "ui_inputwindowthreed.h"

InputWindowThreeD::InputWindowThreeD(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::InputWindowThreeD)
{
    ui->setupUi(this);
}

InputWindowThreeD::~InputWindowThreeD()
{
    delete ui;
}
