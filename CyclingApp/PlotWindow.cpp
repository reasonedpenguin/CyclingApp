/*
 * PlotWindow.cpp
 *
 *  Created on: Nov 2, 2014
 *      Author: hornja
 */

#include "../CyclingApp/PlotWindow.h"

#include "ui_PlotWindowBase.h"

PlotWindow::PlotWindow(QWidget* parent, Qt::WindowFlags f) : QWidget(parent,f) {
    ui = new Ui::PlotWindowBase;
    ui->setupUi(this);

    configurePlot(ui->speedPlot, Qt::blue);
//    configurePlot(ui->heartRatePlot, Qt::orange);
//    configurePlot(ui->elevationPlot, Qt::green);
}

PlotWindow::~PlotWindow() {
   delete ui;
}

void PlotWindow::setActivity(const Activity& activity) {
    m_activity = activity;

    updateMap();
    updateSpeedPlot();
    updateHeartRatePlot();
    updateElevationPlot();
}

void PlotWindow::updateMap() {

}


double PlotWindow::calculateSpeed(double dist1, QDateTime dt1, double dist2, QDateTime dt2) {
    double distance = dist1 - dist2;
    double msecs = dt2.msecsTo(dt1);
    double speed = distance / (msecs/1000);
    // convert m/s to mi/hr TODO: add setting for display units.
    return speed*2.236936292054;
}

void PlotWindow::configurePlot(QCustomPlot* plot, QColor color) {
    plot->addGraph();
    plot->xAxis->setTickLabelType(QCPAxis::ltDateTime);
    plot->xAxis->setDateTimeFormat("H:mm");
//    QPen pen;
//    pen.setColor(QColor(0, 0, 255, 200));
//    plot->graph()->setLineStyle(QCPGraph::lsLine);
//    plot->graph()->setPen(pen);
//    plot->graph()->setBrush(QBrush(color));
}

void PlotWindow::updateSpeedPlot() {
    QVector<double> time, speed;
    double maxSpeed = 0;
    QDateTime startTime = m_activity.getStartTime();
    for(int i=0;i<m_activity.getLaps().size();i++) {
        Lap currentLap = m_activity.getLaps().at(i);
        for(int j=1;j<currentLap.getTrackpoints().size();j++) {
            Trackpoint t1 = currentLap.getTrackpoints().at(j);
            Trackpoint t2 = currentLap.getTrackpoints().at(j-1);
            time.push_back(t1.getTime().toTime_t() - startTime.toTime_t());
            double s = calculateSpeed(
                    t1.getDistance(),
                    t1.getTime(),
                    t2.getDistance(),
                    t2.getTime());
            maxSpeed = fmax(s,maxSpeed);
            speed.push_back(s);
        }
    }

    ui->speedPlot->graph()->setData(time,speed);
    if(time.size() > 1) {
        double first = time.first();
        double last = time.last();
        ui->speedPlot->xAxis->setRange(first, last);
        ui->speedPlot->yAxis->setRange(0, maxSpeed);
    }
//
//    QVector<double> x(101), y(101); // initialize with entries 0..100
//    for (int i=0; i<101; ++i)
//    {
//        x[i] = i/50.0 - 1; // x goes from -1 to 1
//        y[i] = x[i]*x[i]; // let's plot a quadratic function
//    }
//    // create graph and assign data to it:
//    ui->speedPlot->addGraph();
//    ui->speedPlot->graph(0)->setData(x, y);
//    // give the axes some labels:
//    ui->speedPlot->xAxis->setLabel("x");
//    ui->speedPlot->yAxis->setLabel("y");
//    // set axes ranges, so we see all data:
//    ui->speedPlot->xAxis->setRange(-1, 1);
//    ui->speedPlot->yAxis->setRange(0, 1);
    ui->speedPlot->replot();
}

void PlotWindow::updateHeartRatePlot() {

}

void PlotWindow::updateElevationPlot() {

}

