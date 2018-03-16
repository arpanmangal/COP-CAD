#include "include/QT/enterdata.h"
#include "ui_enterdata.h"

EnterData::EnterData(int mode, QWidget *parent) : QWidget(parent),
                                                  ui(new Ui::EnterData)
{
    ui->setupUi(this);
    setWindowTitle(tr("Enter Data"));

    this->mode = mode;
}

EnterData::~EnterData()
{
    delete ui;
}
