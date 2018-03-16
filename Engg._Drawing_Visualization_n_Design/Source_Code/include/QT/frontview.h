#ifndef FRONT_VIEW_H
#define FRONT_VIEW_H

#include <QWidget>

class FrontView : public QWidget
{
    Q_OBJECT

  public:
    FrontView(QWidget *parent);

  protected:
    void paintEvent(QPaintEvent *event) override;

  private:
};

#endif // FRONT_VIEW_H
