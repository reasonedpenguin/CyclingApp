/*
 * MainWindow.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#include "../CyclingApp/MainWindow.h"

#include <QtDebug>
#include <QFileDialog>
//#include <QStandardPaths>
#include <QDesktopServices>
#include "../gpsdata/ActivityListModel.h"
#include "../gpsdata/IDataSource.h"
#include "ui_MainWindowBase.h"

MainWindow::MainWindow() : QMainWindow(),
    m_fileDialog(NULL)
{
    ui = new Ui::MainWindowBase();
    ui->setupUi(this);

    connect(ui->actionImport, SIGNAL(triggered()),this,SLOT(importTriggered()));
    connect(ui->activityView, SIGNAL(clicked(const QModelIndex&)),
            this,SLOT(activitySelected(const QModelIndex&)));
    m_activityModel = new ActivityListModel();
    ui->activityView->setModel(m_activityModel);
//    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
//    qDebug("Data directory: %s", dataDir.data());



}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::importTriggered() {
    if(!m_fileDialog) {
        m_fileDialog = new QFileDialog(this,"Open GPS Activity file");
        m_fileDialog->setNameFilter("GPS Activities (*.tcx *.fit)");
        m_fileDialog->setFileMode(QFileDialog::ExistingFiles);
    }
    if (m_fileDialog->exec()) {
        QStringList fileNames = m_fileDialog->selectedFiles();
        for(int i=0;i<fileNames.size();i++) {
            qDebug() << "Loading: " << fileNames[i];
            Activity a = IDataSource::loadActivity(fileNames[i]);
            if(!a.isNull())
                m_activityModel->addActivity(a);
        }
    }
}

void MainWindow::activitySelected(const QModelIndex& index) {
//    QModelIndexList indexes = selected.indexes();
//    for(int i=0;i<indexes.size();i++) {
//        QModelIndex index = indexes.at(i);
        if(index.column() == 0) {
            Activity a = m_activityModel->getActivity(index);
            if(!a.isNull())
                ui->plotWindow->setActivity(a);
        }
//    }
}
