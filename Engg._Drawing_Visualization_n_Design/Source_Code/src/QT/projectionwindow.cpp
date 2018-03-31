#include "include/QT/projectionwindow.h"
#include "ui_projectionwindow.h"

#include "include/QT/projectionWidget.h"
#include "include/3D/threeDObject.h"
#include "include/2D/twoDProjection.h"
#include "include/2D/twoDProjectionView.h"
#include "include/2D/isometricView.h"
#include <iostream>
#include <QFileDialog>
#include <QMessageBox>

ProjectionWindow::ProjectionWindow(threeDObject *object, QWidget *parent) : QWidget(parent),
                                                                            ui(new Ui::ProjectionWindow)
{
    ui->setupUi(this);

    this->setWindowTitle("COP CAD");
    this->setStyleSheet("background-color:#f0c7fc;");


    // Set Menu
    // infoLabel = new QLabel(tr("<i style=color: red >Choose a menu option, or right-click to invoke a context menu</i>"));
    createActions();
    createMenus();
    this->layout()->setMenuBar(menuBar);

    // Set the Object, and the views
    this->object = object;
    calc_factor = object->calculateFactor(400,300);
    frontView = new twoDProjection(); // Empty dummpy value
    topView = new twoDProjection();
    sideView = new twoDProjection();
    isoView = new isometricView();

    // Initialise types of the different Views
    ui->IsoView->setViewType(0);
    ui->FrontView->setViewType(1);
    ui->TopView->setViewType(2);
    ui->SideView->setViewType(3);

    // Initialisations
    Xval = Yval = Zval = 0;

    // Display
    createProjections();
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
    fileMenu->addAction(exitAct);

    helpMenu->addAction(helpUsageAct);
    helpMenu->addAction(helpProjecAct);
}

void ProjectionWindow::createActions()
{

    save2DAct = new QAction(tr("Save the 2D Orthographic Projections"), this);
    // save2D->setShortcuts(QKeySequence::Save);
    save2DAct->setStatusTip(tr("Save the current orthographic projections into a .cop2D file"));
    connect(save2DAct, &QAction::triggered, this, &ProjectionWindow::save2D);

    save3DAct = new QAction(tr("Save the 3D Object"), this);
    save3DAct->setShortcuts(QKeySequence::Save);
    save3DAct->setStatusTip(tr("Save the current 3D Object into a .cop3D file"));
    connect(save3DAct, &QAction::triggered, this, &ProjectionWindow::save3D);

    exitAct = new QAction(tr("Close"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the Views"));
    connect(exitAct, &QAction::triggered, this, &ProjectionWindow::exit);

    helpUsageAct = new QAction(tr("Usage"), this);
    helpUsageAct->setStatusTip(tr("How to use"));
    connect(helpUsageAct, &QAction::triggered, this, &ProjectionWindow::helpUsage);

    helpProjecAct = new QAction(tr("Orthographic Projections"), this);
    helpProjecAct->setStatusTip(tr("About Orthographic Projections"));
    connect(helpProjecAct, &QAction::triggered, this, &ProjectionWindow::helpProjec);
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

    // Write the data to the file
    object->filewriter(qPrintable(filename));
}
void ProjectionWindow::exit()
{
    // Self Destruct
    this->~ProjectionWindow();
}
void ProjectionWindow::helpUsage()
{
    QMessageBox::information(this, "Usage", "Information");
}
void ProjectionWindow::helpProjec()
{
    QMessageBox::information(this, "About Orthographic Projections", "Help");
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

    ui->IsoView->setPointSet(isoView->pointSet);
    ui->IsoView->setEdgeSet(isoView->edgeSet);
     ui->IsoView->setFactor(calc_factor);
     ui->IsoView->applyFactor();
    ui->IsoView->update();

    ui->FrontView->setPointSet(frontView->PointSet);
    ui->FrontView->setEdgeSet(frontView->EdgeSet);
     ui->FrontView->setFactor(calc_factor);
     ui->FrontView->applyFactor();
    ui->FrontView->update();

    ui->TopView->setPointSet(topView->PointSet);
    ui->TopView->setEdgeSet(topView->EdgeSet);
     ui->TopView->setFactor(calc_factor);
     ui->TopView->applyFactor();
    ui->TopView->update();

    ui->SideView->setPointSet(sideView->PointSet);
    ui->SideView->setEdgeSet(sideView->EdgeSet);
    ui->SideView->setFactor(calc_factor);
    ui->SideView->applyFactor();
    ui->SideView->update();
}

// Slots
void ProjectionWindow::on_Xrotate_valueChanged(int value)
{

    object->rotationalTransformationX((value - Xval) * 3.142 / 90);
    Xval = value;
    createProjections();
}

void ProjectionWindow::on_Yrotate_valueChanged(int value)
{
    object->rotationalTransformationY((value - Yval) * 3.142 / 90);
    Yval = value;
    createProjections();
}

void ProjectionWindow::on_Zrotate_valueChanged(int value)
{
    object->rotationalTransformationZ((value - Zval) * 3.142 / 90);
    Zval = value;
    createProjections();
}
