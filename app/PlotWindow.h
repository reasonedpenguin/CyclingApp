/*
 * PlotWindow.h
 *
 *  Created on: Nov 2, 2014
 *      Author: hornja
 */

#ifndef PLOTWINDOW_H_
#define PLOTWINDOW_H_

#include <QWidget>

namespace Ui {
class PlotWindowBase;
}

class PlotWindow: public QWidget {
    Q_OBJECT
public:
    PlotWindow(QWidget* parent = 0, Qt::WindowFlags f = 0);
    virtual ~PlotWindow();

    void setupSpeedPlot();

private:
    Ui::PlotWindowBase *ui;
};

#endif /* PLOTWINDOW_H_ */
