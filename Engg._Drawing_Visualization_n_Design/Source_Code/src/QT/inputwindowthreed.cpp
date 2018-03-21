#include "include/QT/inputwindowthreed.h"
#include "ui_inputwindowthreed.h"

#include "include/3D/threeDPoint.h"
#include "include/2D/Edge.h"
#include "include/3D/threeDObject.h"
#include "include/QT/projectionwindow.h"

InputWindowThreeD::InputWindowThreeD(QWidget *parent) : QWidget(parent),
                                                        ui(new Ui::InputWindowThreeD)
{
    ui->setupUi(this);
    setWindowTitle("Enter 3D Object");

    QString instruction = ("<h3>Enter Data for 3D Object </h3> Please enter point set and edge set for the 3D Object.<br>");

    ui->InstructionLabel->setText(instruction);
    setupButtons();
}

InputWindowThreeD::~InputWindowThreeD()
{
    delete ui;
}

void InputWindowThreeD::setupButtons()
{
    // Sets up which buttons are disabled and which are enabled
    ui->finishPointAddition->setEnabled(false);
    ui->StartEdge->setEnabled(false);
    ui->EndEdge->setEnabled(false);
    ui->enterEdge->setEnabled(false);
    ui->finishEdgeAddition->setEnabled(false);
    ui->ContinueButton->setEnabled(false);
}
// Slots
void InputWindowThreeD::on_enterPoint_clicked()
{
    points.push_back(new threeDPoint(ui->Xpoint->value(), ui->Ypoint->value(), ui->Zpoint->value()));
    ui->Xpoint->setValue(0);
    ui->Ypoint->setValue(0);
    ui->Zpoint->setValue(0);

    if (points.size() >= 2)
    {
        // Minimum 2 points required
        ui->finishPointAddition->setEnabled(true);
    }
}

void InputWindowThreeD::on_finishPointAddition_clicked()
{
    // All points have been entered
    ui->Xpoint->setEnabled(false);
    ui->Ypoint->setEnabled(false);
    ui->Zpoint->setEnabled(false);
    ui->enterPoint->setEnabled(false);
    ui->finishPointAddition->setEnabled(false);
    ui->StartEdge->setEnabled(true);
    ui->EndEdge->setEnabled(true);
    ui->enterEdge->setEnabled(true);

    ui->StartEdge->setRange(1, points.size());
    ui->EndEdge->setRange(1, points.size());
    ui->StartEdge->setValue(1);
    ui->EndEdge->setValue(points.size());
}

void InputWindowThreeD::on_enterEdge_clicked()
{
    // Push the entered edge if valid edge
    int start = ui->StartEdge->value();
    int end = ui->EndEdge->value();
    ui->StartEdge->setValue(1);
    ui->EndEdge->setValue(points.size());

    if (start == end || start > points.size() || end > points.size())
    {
        // Invalid Edge
    }
    else
    {
        // Push it
        edges.push_back(new Edge(start - 1, end - 1));

        // Unlock end edge
        ui->finishEdgeAddition->setEnabled(true);
    }
}

void InputWindowThreeD::on_finishEdgeAddition_clicked()
{
    ui->StartEdge->setEnabled(false);
    ui->EndEdge->setEnabled(false);
    ui->enterEdge->setEnabled(false);
    ui->finishEdgeAddition->setEnabled(false);

    ui->ContinueButton->setEnabled(true);
}

void InputWindowThreeD::on_ContinueButton_clicked()
{
    // Generate the 3D Object, and send to projection window
    threeDObject *object = new threeDObject();
    object->addPointSet(points);
    object->addEdgeSet(edges);

    ProjectionWindow *window = new ProjectionWindow(object);
    window->show();

    // Self Destruct
    this->~InputWindowThreeD();
}
