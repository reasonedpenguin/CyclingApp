/*
 * PlotWindow.h
 *
 *  Created on: Nov 2, 2014
 *      Author: hornja
 */

#ifndef PLOTWINDOW_H_
#define PLOTWINDOW_H_

#include <QWidget>
#include "Activity.h"

class QCustomPlot;
namespace Ui {
class PlotWindowBase;
}

class PlotWindow: public QWidget {
    Q_OBJECT
public:
    PlotWindow(QWidget* parent = 0, Qt::WindowFlags f = 0);
    virtual ~PlotWindow();

    void setActivity(const Activity& activity);

protected:
    double calculateSpeed(double dist1, QDateTime dt1, double dist2, QDateTime dt2);

    void configurePlot(QCustomPlot* plot, QColor color);

    void updateMap();
    void updateSpeedPlot();
    void updateHeartRatePlot();
    void updateElevationPlot();

private:
    Ui::PlotWindowBase *ui;
    Activity m_activity;
};

#endif /* PLOTWINDOW_H_ */
