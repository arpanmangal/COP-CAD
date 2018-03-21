#include "include/QT/inputwindowtwod.h"
#include "ui_inputwindowtwod.h"

InputWindowTwoD::InputWindowTwoD(int num_views, QWidget *parent) : QWidget(parent),
                                                                   ui(new Ui::InputWindowTwoD)
{
    ui->setupUi(this);
    this->num_views = (num_views == 2) ? 2 : 3;

    QString instruction = ("<h3>Enter Data for 2D Object </h3> Please enter point set and edge set for the 2D Object. <br>");
    ui->InstructionLabel->setText(instruction);

    setupButtons();
}

InputWindowTwoD::~InputWindowTwoD()
{
    delete ui;
}

void InputWindowTwoD::setupButtons()
{
    // Disable buttons
    ui->FinishPointAdd_Front->setEnabled(false);
    ui->FinishPointAdd_Top->setEnabled(false);
    ui->FinishPointAdd_Side->setEnabled(false);
    ui->EnterPoint_Top->setEnabled(false);
    ui->EnterPoint_Side->setEnabled(false);

    ui->topA->setEnabled(false);
    ui->topB->setEnabled(false);
    ui->sideA->setEnabled(false);
    ui->sideB->setEnabled(false);

    ui->EnterEdge_Front->setEnabled(false);
    ui->EnterEdge_Top->setEnabled(false);
    ui->EnterEdge_Side->setEnabled(false);
    ui->FinishEdgeAdd_Front->setEnabled(false);
    ui->FinishEdgeAdd_Top->setEnabled(false);
    ui->FinishEdgeAdd_Side->setEnabled(false);

    ui->frontStart->setEnabled(false);
    ui->frontEnd->setEnabled(false);
    ui->topStart->setEnabled(false);
    ui->topEnd->setEnabled(false);
    ui->sideStart->setEnabled(false);
    ui->sideEnd->setEnabled(false);

    ui->ContinueButton->setEnabled(false);

    if (num_views == 2)
    {
        // no side view required
        ui->PointLabel_Side->setEnabled(false);
        ui->EdgeLabel_Side->setEnabled(false);
        ui->Alabel_Side->setEnabled(false);
        ui->Blabel_Side->setEnabled(false);
        ui->StartLabel_Side->setEnabled(false);
        ui->EndLabel_Side->setEnabled(false);
    }
}

void InputWindowTwoD::on_EnterPoint_Front_clicked()
{
}

void InputWindowTwoD::on_FinishPointAdd_Front_clicked()
{
}

void InputWindowTwoD::on_EnterEdge_Front_clicked()
{
}

void InputWindowTwoD::on_FinishEdgeAdd_Front_clicked()
{
}

void InputWindowTwoD::on_EnterPoint_Top_clicked()
{
}

void InputWindowTwoD::on_FinishPointAdd_Top_clicked()
{
}

void InputWindowTwoD::on_EnterEdge_Top_clicked()
{
}

void InputWindowTwoD::on_FinishEdgeAdd_Top_clicked()
{
}

void InputWindowTwoD::on_EnterPoint_Side_clicked()
{
}

void InputWindowTwoD::on_FinishPointAdd_Side_clicked()
{
}

void InputWindowTwoD::on_EnterEdge_Side_clicked()
{
}

void InputWindowTwoD::on_FinishEdgeAdd_Side_clicked()
{
}

void InputWindowTwoD::on_ContinueButton_clicked()
{
}
