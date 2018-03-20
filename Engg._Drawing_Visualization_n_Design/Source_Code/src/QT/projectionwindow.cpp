#include "include/QT/projectionwindow.h"
#include "ui_projectionwindow.h"

#include "include/QT/projectionWidget.h"
#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"
#include "include/3D/threeDObject.h"
#include "include/2D/twoDProjection.h"
#include "include/2D/twoDProjectionView.h"
#include "include/2D/isometricView.h"

#include <QFileDialog>
#include <QMessageBox>

// #include <QMenuBar>
#include <iostream>

ProjectionWindow::ProjectionWindow(threeDObject *object, QWidget *parent) : QWidget(parent),
                                                                            ui(new Ui::ProjectionWindow)
{
    ui->setupUi(this);

    // ui->TopView->show();
    // ui->FrontView->paintEvent();

    this->setWindowTitle("COP CAD");
    std::cout << "Success";

    // Set Menu
    infoLabel = new QLabel(tr("<i style=color: red >Choose a menu option, or right-click to invoke a context menu</i>"));
    createActions();
    createMenus();
    this->layout()->setMenuBar(menuBar);

    // Set the Object, and the views
    this->object = object;
    frontView = new twoDProjection(); // Empty dummpy value
    topView = new twoDProjection();
    sideView = new twoDProjection();
    isoView = new isometricView();

    // Display
    createProjections();

    // Generates a sample 2d data
    // twoDPoint *p1 = new twoDPoint(2.4, 3.4);
    // twoDPoint *p2 = new twoDPoint(50.4, 10.6);
    // twoDPoint *p3 = new twoDPoint(20.45, 50.34);
    // twoDPoint *p4 = new twoDPoint(180.23, 269.3);

    // PointVector2D points;
    // points.push_back(p1);
    // points.push_back(p2);
    // points.push_back(p3);
    // points.push_back(p4);

    // EdgeVector2D edges;
    // edges.push_back (new Edge(0, 1));
    // edges.push_back (new Edge(1, 2));
    // edges.push_back (new Edge(1, 3));

    // ui->TopView->setPointSet(points);
    // ui->TopView->setEdgeSet(edges);
    // ui->TopView->update();

    // Error checking
    /* if (orthographicViews != NULL)
    {
        std::cout << "setting ortho views\n";

        twoDProjection *frontView = orthographicViews->frontview;
        twoDProjection *topView = orthographicViews->topview;
        twoDProjection *sideView = orthographicViews->sideview;

        ui->FrontView->setPointSet(frontView->PointSet);
        ui->FrontView->setEdgeSet(frontView->EdgeSet);
        ui->FrontView->update();

        ui->TopView->setPointSet(topView->PointSet);
        ui->TopView->setEdgeSet(topView->EdgeSet);
        ui->TopView->update();

        if (sideView != NULL)
        {
            ui->SideView->setPointSet(sideView->PointSet);
            ui->SideView->setEdgeSet(sideView->EdgeSet);
            ui->SideView->update();
        }
    }

    if (isoView != NULL)
    {
        ui->IsoView->setPointSet(isoView->pointSet);
        ui->IsoView->setEdgeSet(isoView->edgeSet);
    }*/
}

ProjectionWindow::~ProjectionWindow()
{
    delete ui;
}
void ProjectionWindow::createMenus()
{
    menuBar = new QMenuBar();
    fileMenu = new QMenu("File");
    helpMenu = new QMenu("Help");

    menuBar->addMenu(fileMenu);
    menuBar->addMenu(helpMenu);

    fileMenu->addAction(save3DAct);
    fileMenu->addAction(save2DAct);
    fileMenu->addAction("Close");

    helpMenu->addAction("Usage");
    helpMenu->addAction("Orthographic Projections");
}

void ProjectionWindow::createActions()
{

    save2DAct = new QAction(tr("Save the 2D Orthographic Projections"), this);
    // save2D->setShortcuts(QKeySequence::Save);
    save2DAct->setStatusTip(tr("Save the current orthographic projections into a .cop2D file"));
    connect(save2DAct, &QAction::triggered, this, &ProjectionWindow::save2D);

    save3DAct = new QAction(tr("Save the 3D Object"), this);
    save3DAct->setStatusTip(tr("Save the current 3D Object into a .cop3D file"));
    connect(save3DAct, &QAction::triggered, this, &ProjectionWindow::save3D);
}

void ProjectionWindow::save2D()
{
    // Save the 2D Objects

    // Create the ProjectionView Object
    twoDProjectionView *orthoProjections = new twoDProjectionView(frontView, topView, sideView);

    // Write into the File
    QString filename = QFileDialog::getSaveFileName(0, tr("Save File"), ".", "2D Orthographic Views (*.cop2D)");

    if (!filename.endsWith(".cop2D"))
    {
        filename = filename + ".cop2D";
    }

    QTextStream cout(stdout);
    cout << filename;

    // Write the data to the file
    orthoProjections->filewriter(qPrintable(filename));
}

void ProjectionWindow::save3D()
{
    // Save the Object
    QString filename = QFileDialog::getSaveFileName(0, tr("Save File"), ".", "3D File (*.cop3D)");

    if (!filename.endsWith(".cop3D"))
    {
        filename = filename + ".cop3D";
    }
    QTextStream cout(stdout);
    cout << filename;

    // Write the data to the file
    object->filewriter(qPrintable(filename));
}
void ProjectionWindow::exit()
{
}
void ProjectionWindow::helpUsage()
{
}
void ProjectionWindow::helpProjec()
{
}

// Based on the 3D Object, makes its projections
void ProjectionWindow::createProjections()
{
    // Delete the old Objects
    delete frontView;
    delete topView;
    delete sideView;
    delete isoView;

    // Assign new Values
    isoView = object->genIsoView();

    topView = object->genProjection(1);
    frontView = object->genProjection(3);
    sideView = object->genProjection(2);

    std::cout << "view generated" << std::endl;

    ui->FrontView->setPointSet(frontView->PointSet);
    ui->FrontView->setEdgeSet(frontView->EdgeSet);
    ui->FrontView->update();

    ui->TopView->setPointSet(topView->PointSet);
    ui->TopView->setEdgeSet(topView->EdgeSet);
    ui->TopView->update();

    ui->SideView->setPointSet(sideView->PointSet);
    ui->SideView->setEdgeSet(sideView->EdgeSet);
    ui->SideView->update();

    ui->IsoView->setPointSet(isoView->pointSet);
    ui->IsoView->setEdgeSet(isoView->edgeSet);
    ui->IsoView->update();

    std::cout << "Rendered views\n";
    
}

// void ProjectionWindow::on_yaw_valueChanged(int value)
// {
//     object->rotationalTransformation(value * 3.142 / 5, 0, 0);
//     createProjections();
//     // object->printer();
// }

// void ProjectionWindow::on_pitch_valueChanged(int value)
// {
// }

// void ProjectionWindow::on_roll_valueChanged(int value)
// {
// }

void ProjectionWindow::on_yaw_sliderPressed()
{
    yaw = ui->yaw->value();
}

void ProjectionWindow::on_pitch_sliderPressed()
{
    pitch = ui->pitch->value();
}

void ProjectionWindow::on_roll_sliderPressed()
{
    roll = ui->roll->value();
}

void ProjectionWindow::on_yaw_sliderReleased()
{
    int old_yaw = yaw;
    yaw = ui->yaw->value();
    object->rotationalTransformation((yaw - old_yaw) * 3.142 / 18, 0, 0);
    // object->printer();
    createProjections();
}

void ProjectionWindow::on_pitch_sliderReleased()
{
    int old_pitch = pitch;
    pitch = ui->pitch->value();
    object->rotationalTransformation(0, (pitch - old_pitch) * 3.142 / 18, 0);
    // object->printer();
    createProjections();
}

void ProjectionWindow::on_roll_sliderReleased()
{
    int old_roll = roll;
    roll = ui->roll->value();
    object->rotationalTransformation(0, 0, (roll - old_roll) * 3.142 / 18);
    // object->printer();
    createProjections();
}
