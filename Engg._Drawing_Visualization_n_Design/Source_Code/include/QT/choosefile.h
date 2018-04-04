/** Defines a QT Widget which allows user to choose an appropriate file with a file dialog */

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
  /** Constructor */
  explicit ChooseFile(int mode, QWidget *parent = 0);
  ~ChooseFile();

private slots:
  void on_select_File_clicked();

  void on_Cancel_clicked();

private:
  Ui::ChooseFile *ui;

  int mode;
  QString type;

  /** Processes the 3D object, and sends it to projection window, after it is loaded form a .cop3D file */
  void chosenObject(threeDObject *object);

  /** Processes the 2D object, and sends it to the projection window, after it is loaded from a .cop2D file */
  void chosenProjection(twoDProjectionView *projection);
};

#endif // CHOOSEFILE_H
