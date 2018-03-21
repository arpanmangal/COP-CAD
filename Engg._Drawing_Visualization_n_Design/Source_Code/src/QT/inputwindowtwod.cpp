#include "include/QT/inputwindowtwod.h"
#include "ui_inputwindowtwod.h"

#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"
#include "include/2D/twoDProjection.h"
#include "include/2D/twoDProjectionView.h"
#include "include/3D/threeDObject.h"

#include "include/QT/projectionwindow.h"

InputWindowTwoD::InputWindowTwoD(int num_views, QWidget *parent) : QWidget(parent),
                                                                   ui(new Ui::InputWindowTwoD)
{
    ui->setupUi(this);
    this->num_views = (num_views == 2) ? 2 : 3;
    setWindowTitle("Enter Orthographic Views");

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
    frontViewPoints.push_back(new twoDPoint(ui->frontA->value(), ui->frontB->value()));
    ui->frontA->setValue(0);
    ui->frontB->setValue(0);

    if (frontViewPoints.size() >= 2)
    {
        // Minimum 2 points required
        ui->FinishPointAdd_Front->setEnabled(true);
    }
}

void InputWindowTwoD::on_FinishPointAdd_Front_clicked()
{
    // All points have been entered
    ui->EnterPoint_Front->setEnabled(false);
    ui->FinishPointAdd_Front->setEnabled(false);
    ui->frontA->setEnabled(false);
    ui->frontB->setEnabled(false);

    ui->frontStart->setEnabled(true);
    ui->frontEnd->setEnabled(true);
    ui->EnterEdge_Front->setEnabled(true);

    ui->frontStart->setRange(1, frontViewPoints.size());
    ui->frontEnd->setRange(1, frontViewPoints.size());
    ui->frontStart->setValue(1);
    ui->frontEnd->setValue(frontViewPoints.size());
}

void InputWindowTwoD::on_EnterEdge_Front_clicked()
{
    int start = ui->frontStart->value();
    int end = ui->frontEnd->value();
    ui->frontStart->setValue(1);
    ui->frontEnd->setValue(frontViewPoints.size());

    // Push the edge
    if (start != end)
    {
        frontViewEdges.push_back(new Edge(start - 1, end - 1));
        ui->FinishEdgeAdd_Front->setEnabled(true);
    }
}

void InputWindowTwoD::on_FinishEdgeAdd_Front_clicked()
{
    ui->EnterEdge_Front->setEnabled(false);
    ui->FinishEdgeAdd_Front->setEnabled(false);

    ui->frontStart->setEnabled(false);
    ui->frontEnd->setEnabled(false);

    ui->EnterPoint_Top->setEnabled(true);
    ui->topA->setEnabled(true);
    ui->topB->setEnabled(true);
}

void InputWindowTwoD::on_EnterPoint_Top_clicked()
{
    topViewPoints.push_back(new twoDPoint(ui->topA->value(), ui->topB->value()));
    ui->topA->setValue(0);
    ui->topB->setValue(0);

    if (topViewPoints.size() >= 2)
    {
        // Minimum 2 points required
        ui->FinishPointAdd_Top->setEnabled(true);
    }
}

void InputWindowTwoD::on_FinishPointAdd_Top_clicked()
{
    // All points have been entered
    ui->EnterPoint_Top->setEnabled(false);
    ui->FinishPointAdd_Top->setEnabled(false);
    ui->topA->setEnabled(false);
    ui->topB->setEnabled(false);

    ui->topStart->setEnabled(true);
    ui->topEnd->setEnabled(true);
    ui->EnterEdge_Top->setEnabled(true);

    ui->topStart->setRange(1, topViewPoints.size());
    ui->topEnd->setRange(1, topViewPoints.size());
    ui->topStart->setValue(1);
    ui->topEnd->setValue(topViewPoints.size());
}

void InputWindowTwoD::on_EnterEdge_Top_clicked()
{
    int start = ui->topStart->value();
    int end = ui->topEnd->value();
    ui->topStart->setValue(1);
    ui->topEnd->setValue(topViewPoints.size());

    // Push the edge
    if (start != end)
    {
        topViewEdges.push_back(new Edge(start - 1, end - 1));
        ui->FinishEdgeAdd_Top->setEnabled(true);
    }
}

void InputWindowTwoD::on_FinishEdgeAdd_Top_clicked()
{
    ui->EnterEdge_Top->setEnabled(false);
    ui->FinishEdgeAdd_Top->setEnabled(false);

    ui->topStart->setEnabled(false);
    ui->topEnd->setEnabled(false);

    if (num_views == 3)
    {
        ui->EnterPoint_Side->setEnabled(true);
        ui->sideA->setEnabled(true);
        ui->sideB->setEnabled(true);
    } 
    else 
    {
        ui->ContinueButton->setEnabled(true);
    }
}

void InputWindowTwoD::on_EnterPoint_Side_clicked()
{
    sideViewPoints.push_back(new twoDPoint(ui->sideA->value(), ui->sideB->value()));
    ui->sideA->setValue(0);
    ui->sideB->setValue(0);

    if (sideViewPoints.size() >= 2)
    {
        // Minimum 2 points required
        ui->FinishPointAdd_Side->setEnabled(true);
    }
}

void InputWindowTwoD::on_FinishPointAdd_Side_clicked()
{
    // All points have been entered
    ui->EnterPoint_Side->setEnabled(false);
    ui->FinishPointAdd_Side->setEnabled(false);
    ui->sideA->setEnabled(false);
    ui->sideB->setEnabled(false);

    ui->sideStart->setEnabled(true);
    ui->sideEnd->setEnabled(true);
    ui->EnterEdge_Side->setEnabled(true);

    ui->sideStart->setRange(1, sideViewPoints.size());
    ui->sideEnd->setRange(1, sideViewPoints.size());
    ui->sideStart->setValue(1);
    ui->sideEnd->setValue(sideViewPoints.size());
}

void InputWindowTwoD::on_EnterEdge_Side_clicked()
{
    int start = ui->sideStart->value();
    int end = ui->sideEnd->value();
    ui->sideStart->setValue(1);
    ui->sideEnd->setValue(sideViewPoints.size());

    // Push the edge
    if (start != end)
    {
        sideViewEdges.push_back(new Edge(start - 1, end - 1));
        ui->FinishEdgeAdd_Side->setEnabled(true);
    }
}

void InputWindowTwoD::on_FinishEdgeAdd_Side_clicked()
{
    ui->EnterEdge_Side->setEnabled(false);
    ui->FinishEdgeAdd_Side->setEnabled(false);

    ui->sideStart->setEnabled(false);
    ui->sideEnd->setEnabled(false);

    ui->ContinueButton->setEnabled(true);
}

void InputWindowTwoD::on_ContinueButton_clicked()
{
    // Create the twoD Projection Views
    twoDProjection* frontView = new twoDProjection();
    twoDProjection* topView = new twoDProjection();
    twoDProjection* sideView = (num_views == 2) ? NULL : new twoDProjection();

    frontView->add_pointSet(frontViewPoints);
    frontView->add_edgeSet(frontViewEdges);

    topView->add_pointSet(topViewPoints);
    topView->add_edgeSet(topViewEdges);

    if (num_views == 3)
    {
        sideView->add_pointSet(sideViewPoints);
        sideView->add_edgeSet(sideViewEdges);
    }

    twoDProjectionView * orthographicProjections = new twoDProjectionView(frontView, topView, sideView);
    threeDObject * object = orthographicProjections->create3Dmodel();

    ProjectionWindow *window = new ProjectionWindow(object);
    window->show();
    
    // Self-Destruct
    this->~InputWindowTwoD();
}
