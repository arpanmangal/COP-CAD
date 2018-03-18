#ifndef CHOOSEFILE_H
#define CHOOSEFILE_H

#include <QWidget>

// forward declarations
class threeDObject;
class threeDInput;
class twoDProjectionView;
class twoDInput;

namespace Ui
{
class ChooseFile;
}

class ChooseFile : public QWidget
{
  Q_OBJECT

public:
  explicit ChooseFile(int mode, QWidget *parent = 0);
  ~ChooseFile();

private slots:
  void on_select_File_clicked();

  void on_Cancel_clicked();

private:
  Ui::ChooseFile *ui;

  int mode;
  QString type;

  void chosenObject(threeDObject *object);
  void chosenProjection(twoDProjectionView *projection);
};

#endif // CHOOSEFILE_H
