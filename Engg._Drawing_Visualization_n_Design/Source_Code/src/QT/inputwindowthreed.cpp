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

void InputWindowThreeD::on_enterPoint_clicked()
{

}

void InputWindowThreeD::on_finishPointAddition_clicked()
{

}

void InputWindowThreeD::on_enterEdge_clicked()
{

}

void InputWindowThreeD::on_finishEdgeAddition_clicked()
{

}

void InputWindowThreeD::on_ContinueButton_clicked()
{

}
