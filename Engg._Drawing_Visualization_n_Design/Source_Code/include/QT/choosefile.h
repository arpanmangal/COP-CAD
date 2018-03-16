#ifndef CHOOSEFILE_H
#define CHOOSEFILE_H

#include <QWidget>

namespace Ui {
class ChooseFile;
}

class ChooseFile : public QWidget
{
    Q_OBJECT

public:
    explicit ChooseFile(QWidget *parent, int mode);
    ~ChooseFile();

private:
    Ui::ChooseFile *ui;

    QWidget *my_parent;
    int mode;
};

#endif // CHOOSEFILE_H
