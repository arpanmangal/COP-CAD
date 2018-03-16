#include "include/QT/enterdata.h"
#include "ui_enterdata.h"

EnterData::EnterData(QWidget *parent, int mode) : QWidget(parent),
                                                  ui(new Ui::EnterData)
{
    ui->setupUi(this);

    my_parent = parent;
    this->mode = mode;
}

EnterData::~EnterData()
{
    delete ui;
}
