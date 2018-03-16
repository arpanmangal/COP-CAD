#include "include/QT/choosefile.h"
#include "ui_choosefile.h"

ChooseFile::ChooseFile(QWidget *parent, int mode) : QWidget(parent),
                                          ui(new Ui::ChooseFile)
{
    ui->setupUi(this);

    my_parent = parent;
    this->mode = mode;
}

ChooseFile::~ChooseFile()
{
    delete ui;
}
