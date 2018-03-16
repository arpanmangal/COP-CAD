#include "include/QT/enterdata.h"
#include "ui_enterdata.h"

#include "include/3D/threeDPoint.h"
#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"

#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>

#include <QTextStream>

EnterData::EnterData(int mode, QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::EnterData)
{
    ui->setupUi(this);
    setWindowTitle(tr("Enter Data"));
    ui->instruction->setText("Please enter points and edges for the object");
    this->mode = mode;
}

EnterData::~EnterData()
{
    delete ui;
}

// Input Functions
Edge *EnterData::enterEdge(int index, int pointSetSize)
{
    int start = pointSetSize + 1;
    while (start < 1 || start > pointSetSize)
    {
        // Ask for an edge
        start = QInputDialog::getInt(0,
                                     "Enter 2D Edge: " + QString::number(index),
                                     "Enter a start point between 1 and " + QString::number(pointSetSize));
    }

    int end = pointSetSize + 1;
    while ((end < 1 || end > pointSetSize) && end != start)
    {
        // Ask for an edge
        end = QInputDialog::getInt(0,
                                   "Enter 2D Edge: " + QString::number(index),
                                   "Enter a end point between 1 and " + QString::number(pointSetSize) + " other than start point");
    }

    return new Edge(start - 1, end - 1);
}

// 3D Input
threeDPoint *EnterData::enter3DPoint(int index)
{
    float x = QInputDialog::getDouble(0, "Enter 3D Point: " + QString::number(index), "Enter X", 0.0);
    float y = QInputDialog::getDouble(0, "Enter 3D Point: " + QString::number(index), "Enter Y", 0.0);
    float z = QInputDialog::getDouble(0, "Enter 3D Point: " + QString::number(index), "Enter Z", 0.0);

    return new threeDPoint(x, y, z);
}

PointVector3D EnterData::enter3DPointSet()
{
    PointVector3D pointSet3D;
    int point_count = 1;
    int answer = 0;

    pointSet3D.push_back(enter3DPoint(point_count));
    point_count++;
    do
    {
        pointSet3D.push_back(enter3DPoint(point_count));

        answer = QMessageBox::question(0, "", "Enter More Points?", QMessageBox::Yes | QMessageBox::No);
        point_count++;
    } while (answer == QMessageBox::Yes);

    return pointSet3D;
}

EdgeVector3D EnterData::enter3DEdgeSet(int pointSetSize)
{
    EdgeVector3D edgeSet3D;
    int edge_count = 1;
    int answer = 0;
    do
    {
        edgeSet3D.push_back(enterEdge(edge_count, pointSetSize));

        answer = QMessageBox::question(0, "", "Enter More Edges?", QMessageBox::Yes | QMessageBox::No);
        edge_count++;
    } while (answer == QMessageBox::Yes);

    return edgeSet3D;
}

void EnterData::enter3DObject()
{
    QMessageBox::information(0, "Enter Points", "Please enter 3D points as (x, y, z) pairs");
    PointVector3D pointSet3D = enter3DPointSet();
    QMessageBox::information(0, "Enter Edges", "Now please enter edges as a pair of start and end points");
    EdgeVector3D edgeSet3D = enter3DEdgeSet(pointSet3D.size());

    int saveToFile = QMessageBox::question(0, "Save to File", "Save the Input to a File?", QMessageBox::Yes | QMessageBox::No);
    if (saveToFile == QMessageBox::Yes)
    {
        QString filename = QFileDialog::getSaveFileName(0, tr("Save File"), ".", "3D File (*.cop3D)");
        QTextStream cout(stdout);
        cout << filename;
    }
}

// 2D Input
twoDPoint *EnterData::enter2DPoint(int index)
{
    float x = QInputDialog::getDouble(0, "Enter 2D Point: " + QString::number(index), "Enter X", 0.0);
    float y = QInputDialog::getDouble(0, "Enter 2D Point: " + QString::number(index), "Enter Y", 0.0);

    return new twoDPoint(x, y);
}

PointVector2D EnterData::enter2DPointSet()
{
    PointVector2D pointSet2D;
    int point_count = 1;
    int answer = 0;

    pointSet2D.push_back(enter2DPoint(point_count));
    point_count++;
    do
    {
        pointSet2D.push_back(enter2DPoint(point_count));

        answer = QMessageBox::question(0, "", "Enter More Points?", QMessageBox::Yes | QMessageBox::No);
        point_count++;
    } while (answer == QMessageBox::Yes);

    return pointSet2D;
}

EdgeVector2D EnterData::enter2DEdgeSet(int pointSetSize)
{
    EdgeVector2D edgeSet2D;
    int edge_count = 1;
    int answer = 0;
    do
    {
        edgeSet2D.push_back(enterEdge(edge_count, pointSetSize));

        answer = QMessageBox::question(0, "", "Enter More Edges?", QMessageBox::Yes | QMessageBox::No);
        edge_count++;
    } while (answer == QMessageBox::Yes);

    return edgeSet2D;
}

void EnterData::enter2DProjection()
{
    QMessageBox::information(0, "Enter Points", "Please enter 2D points as (x, y) pairs");
    PointVector2D pointSet2D = enter2DPointSet();
    QMessageBox::information(0, "Enter Edges", "Now please enter edges as a pair of start and end points");
    EdgeVector2D edgeSet2D = enter2DEdgeSet(pointSet2D.size());

    int saveToFile = QMessageBox::question(0, "Save to File", "Save the Input Projection to a File?", QMessageBox::Yes | QMessageBox::No);
    if (saveToFile == QMessageBox::Yes)
    {
        QString filename = QFileDialog::getSaveFileName(0, tr("Save File"), ".", "2D File (*.cop3D)");
        QTextStream cout(stdout);
        cout << filename;
    }
}

void EnterData::enter2DOrthographicViews()
{
    // Ask the user for the number of views
    int num_views = 0;
    while (num_views != 2 && num_views != 3)
    {
        num_views = QInputDialog::getInt(0, "View Count", "Please enter number of views: (2 or 3)", 2);
    }

    enter2DProjection();
}

void EnterData::on_start_clicked()
{
    // Take User Data
    if (mode == 3)
    {
        // Take 3D input
        enter3DObject();
    }
    else
    {
        // Take 2D input
        enter2DOrthographicViews();
    }
}
