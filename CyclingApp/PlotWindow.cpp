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
    setupSpeedPlot();
}

PlotWindow::~PlotWindow() {
   delete ui;
}

void PlotWindow::setupSpeedPlot() {
    // generate some data:
    QVector<double> x(101), y(101); // initialize with entries 0..100
    for (int i=0; i<101; ++i)
    {
        x[i] = i/50.0 - 1; // x goes from -1 to 1
        y[i] = x[i]*x[i]; // let's plot a quadratic function
    }
    // create graph and assign data to it:
    ui->speedPlot->addGraph();
    ui->speedPlot->graph(0)->setData(x, y);
    // give the axes some labels:
    ui->speedPlot->xAxis->setLabel("x");
    ui->speedPlot->yAxis->setLabel("y");
    // set axes ranges, so we see all data:
    ui->speedPlot->xAxis->setRange(-1, 1);
    ui->speedPlot->yAxis->setRange(0, 1);
    ui->speedPlot->replot();
}
