#ifndef ENTERDATA_H
#define ENTERDATA_H

#include <QWidget>
#include "include/common.h"

namespace Ui
{
class EnterData;
}

class EnterData : public QWidget
{
    Q_OBJECT

  public:
    explicit EnterData(int mode, QWidget *parent = 0);
    ~EnterData();

  private slots:
    void on_start_clicked();

  private:
    Ui::EnterData *ui;

    QWidget *my_parent;
    int mode;

    /** Prompts User for entering a 3D Point */
    threeDPoint *enter3DPoint(int index);

    /** Takes multiple 3D points and returns a point set */
    PointVector3D enter3DPointSet();

    /** Prompts User for entering an Edge */
    Edge *enterEdge(int index, int pointSetSize);

    /** Takes multiple 3D Edges and returns an edge set */
    EdgeVector3D enter3DEdgeSet(int pointSetSize);

    /** Prompts User for Entering 3D Object. Calls other functions such as input 3D edges and points*/
    void enter3DObject();
};

#endif // ENTERDATA_H
