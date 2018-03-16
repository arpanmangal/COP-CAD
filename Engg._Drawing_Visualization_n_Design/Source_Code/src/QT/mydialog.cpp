#include <include/QT/mydialog.h>
#include <ui_mydialog.h>

MyDialog::MyDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MyDialog)
{
    ui->setupUi(this);

    // front_view_widget = new FrontView(this);
    // front_view_widget->show();
}

MyDialog::~MyDialog()
{
    delete ui;

    // delete front_view_widget;
}
