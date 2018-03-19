#include "include/QT/choosefile.h"
#include "ui_choosefile.h"
#include "include/QT/inputmode.h"

#include "include/3D/threeDObject.h"
#include "include/3D/threeDInput.h"
#include "include/2D/twoDProjection.h"
#include "include/2D/twoDProjectionView.h"
#include "include/2D/twoDInput.h"
#include "include/QT/twoDWindow.h"

#include "include/QT/projectionwindow.h"
#include <QFileDialog>
#include <QMessageBox>

#include <iostream>

ChooseFile::ChooseFile(int mode, QWidget *parent) : QWidget(parent),
                                                    ui(new Ui::ChooseFile)
{
    ui->setupUi(this);

    setWindowTitle(tr("Open File"));

    switch (mode)
    {
    case 1:
        type = "2D Projection (*.cop2DProj)";
        break;
    case 2:
        type = "2D Orthographic Views (*.cop2D)";
        break;
    default:
        type = "3D File (*.cop3D)";
    }

    ui->label->setText("Please choose an \"" + type + "\" file:");

    this->mode = mode;
}

ChooseFile::~ChooseFile()
{
    delete ui;
}

void ChooseFile::on_select_File_clicked()
{
    // Open a Select File Menu
    QString filename = QFileDialog::getOpenFileName(
        this,
        tr("Open File"),
        ".",
        type);

    if (filename == "")
    {
        QMessageBox::information(this, tr("Warning"), "Please Choose a File");
    }
    else
    {
        // QMessageBox::information(this, tr("File Name"), "You have chosen: " + filename);
        if (QMessageBox::Yes == QMessageBox::question(this, "File Name", "You have chosen: " + filename + "\nContinue?", QMessageBox::Yes | QMessageBox::No))
        {
            // Approved File Opening, Go Ahead
            threeDInput input3d;
            twoDInput input2d;

            std::cout << "Mode is " << mode << std::endl;

            switch (mode)
            {
            case 3:
                input3d.inputData(qPrintable(filename));
                chosenObject(input3d.get3DObject());
                break;
            default:
                chosenProjection(input2d.getProjectionDrawing(qPrintable(filename)));
            }

            // Destroy itself
            this->~ChooseFile();
        }
    }
}

void ChooseFile::chosenObject(threeDObject *object)
{
    // Chosen Object
    isometricView *isoView = object->genIsoView();

    twoDProjection *topView = object->genProjection(1);
    twoDProjection *frontView = object->genProjection(3);
    twoDProjection *sideView = object->genProjection(2);

    twoDProjectionView *orthoProjections = new twoDProjectionView(frontView, topView, sideView);
    
    // Draw the isometric view
    ProjectionWindow *window = new ProjectionWindow(orthoProjections, isoView);
    window->show();

    if (QMessageBox::Yes == QMessageBox::question(this, "Save Orthographic Projections", "Do You wish to save the projections in a file?", QMessageBox::Yes | QMessageBox::No))
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
}

void ChooseFile::chosenProjection(twoDProjectionView *projection)
{
    // Chosen Projection
    threeDObject *object = projection->create3Dmodel();
    object->printer();

    // std::cout << "after printer \n";
    isometricView *isoView = object->genIsoView();

    // See the projection
    ProjectionWindow *window = new ProjectionWindow(projection, isoView);
    window->show();
}

void ChooseFile::on_Cancel_clicked()
{
    // The User does not want to open File, go back
    InputMode *input_mode = new InputMode(mode);
    input_mode->show();

    this->~ChooseFile();
}
