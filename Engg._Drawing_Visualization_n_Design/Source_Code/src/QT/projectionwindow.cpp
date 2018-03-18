#include "include/QT/projectionwindow.h"
#include "ui_projectionwindow.h"

#include "include/QT/projectionWidget.h"

#include <iostream>

ProjectionWindow::ProjectionWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ProjectionWindow)
{
    ui->setupUi(this);

    // ui->TopView->show();

    std::cout << "Success";
}

ProjectionWindow::~ProjectionWindow()
{
    delete ui;
}
