#include "include/QT/enterdata.h"
#include "ui_enterdata.h"

#include "include/3D/threeDPoint.h"
#include "include/2D/twoDPoint.h"
#include "include/2D/Edge.h"

#include "include/3D/threeDObject.h"
#include "include/2D/twoDProjection.h"
#include "include/2D/twoDProjectionView.h"
#include "include/QT/projectionwindow.h"


#include <QInputDialog>
#include <QMessageBox>
#include <QFileDialog>

#include <QTextStream>

EnterData::EnterData(int mode, QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::EnterData)
{
    ui->setupUi(this);
    setWindowTitle(tr("Enter Data"));

    this->mode = mode;

    QString type = (mode == 3) ? "3D Object" : "2D Orthographic Views";
    QString instruction = ("<h3>Enter Data for " + type + " </h3>" +
                           "<br>" +
                           "Please enter point set and edge set for the " + type + "<br>after clicking 'Enter Data' ");
    ui->instruction->setText(instruction);
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

threeDObject *EnterData::enter3DObject()
{
    QMessageBox::information(0, "Enter Points", "Please enter 3D points as (x, y, z) pairs");
    PointVector3D pointSet3D = enter3DPointSet();
    QMessageBox::information(0, "Enter Edges", "Now please enter edges as a pair of start and end points");
    EdgeVector3D edgeSet3D = enter3DEdgeSet(pointSet3D.size());

    // Construct a 3D Object
    threeDObject *object = new threeDObject();
    object->addPointSet(pointSet3D);
    object->addEdgeSet(edgeSet3D);

    int saveToFile = QMessageBox::question(0, "Save to File", "Save the Input to a File?", QMessageBox::Yes | QMessageBox::No);
    if (saveToFile == QMessageBox::Yes)
    {
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

    return object;
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

twoDProjection *EnterData::enter2DProjection(int view)
{
    QString viewName;
    switch (view)
    {
    case 1:
        viewName = "Front View";
        break;
    case 2:
        viewName = "Top View";
        break;
    default:
        viewName = "Side View";
    }

    QMessageBox::information(0, "Enter Points for " + viewName, "Please enter 2D points as (x, y) pairs");
    PointVector2D pointSet2D = enter2DPointSet();
    QMessageBox::information(0, "Enter Edges for " + viewName, "Now please enter edges as a pair of start and end points");
    EdgeVector2D edgeSet2D = enter2DEdgeSet(pointSet2D.size());

    // Construct the 2D Projection
    twoDProjection *projection = new twoDProjection();
    projection->add_pointSet(pointSet2D);
    projection->add_edgeSet(edgeSet2D);

    int saveToFile = QMessageBox::question(0, "Save to File", "Save the Input Projection to a File?", QMessageBox::Yes | QMessageBox::No);
    if (saveToFile == QMessageBox::Yes)
    {
        QString filename = QFileDialog::getSaveFileName(0, tr("Save File"), ".", "2D Projection (*.cop2DProj)");

        if (!filename.endsWith(".cop2DProj"))
        {
            filename = filename + ".cop2DProj";
        }

        QTextStream cout(stdout);
        cout << filename;

        // Write the data to the file
        projection->filewriter(qPrintable(filename));
    }

    return projection;
}

twoDProjectionView *EnterData::enter2DOrthographicViews()
{
    // Ask the user for the number of views
    int num_views = 0;
    while (num_views != 2 && num_views != 3)
    {
        num_views = QInputDialog::getInt(0, "View Count", "Please enter number of views: (2 or 3)", 2);
    }

    // Projection View Object
    twoDProjectionView *orthoProjections;

    twoDProjection *frontView = enter2DProjection(1);
    twoDProjection *topView = enter2DProjection(2);

    if (num_views == 3)
    {
        twoDProjection *sideView = enter2DProjection(3);
        orthoProjections = new twoDProjectionView(frontView, topView, sideView);
    }
    else
    {
        orthoProjections = new twoDProjectionView(frontView, topView);
    }

    // Ask for saving in the file
    int saveToFile = QMessageBox::question(0, "Save to File", "Save the Input Orthographic Views to a File?", QMessageBox::Yes | QMessageBox::No);
    if (saveToFile == QMessageBox::Yes)
    {
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

    return orthoProjections;
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
        twoDProjectionView * projections = enter2DOrthographicViews();

        ProjectionWindow *win = new ProjectionWindow(projections);
        win->show();
    }
}
