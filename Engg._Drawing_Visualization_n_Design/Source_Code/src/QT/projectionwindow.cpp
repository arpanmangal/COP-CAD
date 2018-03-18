#include "include/QT/projectionwindow.h"
#include "ui_projectionwindow.h"

#include "include/QT/projectionWidget.h"
#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"
#include "include/2D/twoDProjection.h"
#include "include/2D/twoDProjectionView.h"

#include <iostream>

ProjectionWindow::ProjectionWindow(twoDProjectionView *orthographicViews, QWidget *parent) : QWidget(parent),
                                                                                             ui(new Ui::ProjectionWindow)
{
    ui->setupUi(this);

    // ui->TopView->show();
    // ui->FrontView->paintEvent();

    std::cout << "Success";

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

    twoDProjection *frontView = orthographicViews->frontview;
    twoDProjection *topView = orthographicViews->topview;
    twoDProjection *sideView = orthographicViews->sideview;

    ui->FrontView->setPointSet(frontView->PointSet);
    ui->FrontView->setEdgeSet(frontView->EdgeSet);
    ui->FrontView->update();

    ui->TopView->setPointSet(topView->PointSet);
    ui->TopView->setEdgeSet(topView->EdgeSet);
    ui->TopView->update();

    ui->SideView->setPointSet(sideView->PointSet);
    ui->SideView->setEdgeSet(sideView->EdgeSet);
    ui->SideView->update();
}

ProjectionWindow::~ProjectionWindow()
{
    delete ui;
}
