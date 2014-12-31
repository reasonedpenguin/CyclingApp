/*
 * MainWindow.h
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <QMainWindow>

class QFileDialog;
class ActivityListModel;

namespace Ui {
class MainWindowBase;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();
    virtual ~MainWindow();

public slots:
    void importTriggered();

private:
    Ui::MainWindowBase* ui;
    QFileDialog* m_fileDialog;
    ActivityListModel* m_activityModel;
};

#endif /* MAINWINDOW_H_ */
