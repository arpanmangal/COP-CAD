#ifndef PROJECTION_WIDGET_H
#define PROJECTION_WIDGET_H

#include <QWidget>

class ProjectionWidget : public QWidget
{
    Q_OBJECT

  public:
    ProjectionWidget(QWidget *parent);

  protected:
    void paintEvent(QPaintEvent *event) override;

  private:
};

#endif // PROJECTION_WIDGET_H
