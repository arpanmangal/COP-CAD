#include "include/QT/inputmode.h"
#include "ui_inputmode.h"

#include "include/QT/choosefile.h"
#include "include/QT/enterdata.h"

InputMode::InputMode(QWidget *parent, int mode) : QWidget(parent),
                                                  ui(new Ui::InputMode)
{
    ui->setupUi(this);

    my_parent = parent;
    this->mode = mode;
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
        ChooseFile *fileRead = new ChooseFile(my_parent, mode);
        fileRead->show();
    }
    else
    {
        // The User wants to enter the data manually
        EnterData *enter_data = new EnterData(my_parent, mode);
        enter_data->show();
    }

    // Destroy Self
    this->~InputMode();
}
