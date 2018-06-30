#include "include/QT/inputmode.h"
#include "ui_inputmode.h"

#include "include/QT/choosefile.h"
#include "include/QT/inputwindowtwod.h"
#include "include/QT/inputwindowthreed.h"

#include <QInputDialog>
InputMode::InputMode(int mode, QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::InputMode)
{
    ui->setupUi(this);
    setWindowTitle(tr("Input Mode"));

    this->mode = (mode == 2) ? 2 : 3;
}

InputMode::~InputMode()
{
    delete ui;
}

void InputMode::on_submit_clicked()
{
    int input_mode = ui->m_comboBox->currentIndex();

    if (input_mode == 0)
    {
        // The User wants to read from a file
        ChooseFile *fileRead = new ChooseFile(mode);
        fileRead->show();
    }
    else
    {
        // The User wants to enter the data manually
        if (mode == 2)
        {
            // Ask the user for the number of views
            int num_views = 0;
            while (num_views != 2 && num_views != 3)
            {
                num_views = QInputDialog::getInt(0, "View Count", "Please enter number of views: (2 or 3)", 2);
            }

            // Create a 2D input window
            InputWindowTwoD* window2D = new InputWindowTwoD(num_views);
            window2D->show();
        }
        else
        {
            // The user wants to enter 3D Object
            InputWindowThreeD *window3D = new InputWindowThreeD();
            window3D->show();
        }
    }

    // Destroy Self
    this->~InputMode();
}

void InputMode::on_goBack_clicked()
{
    // Delete this object
    this->~InputMode();
}
