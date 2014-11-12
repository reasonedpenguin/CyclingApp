/*
 * MainWindow.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#include <QtGlobal>
#include <QFileDialog>
#include <QStandardPaths>
#include "MainWindow.h"
#include "ui_MainWindowBase.h"

MainWindow::MainWindow() : QMainWindow(),
    m_fileDialog(NULL)
{
    ui = new Ui::MainWindowBase();
    ui->setupUi(this);

    connect(ui->actionImport, SIGNAL(triggered()),this,SLOT(importTriggered()));

    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
    //for(int i=0;i<dataDir.size();i++)
        qDebug("Data directory: %s", dataDir.data());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::importTriggered() {
    if(!m_fileDialog) {
        m_fileDialog = new QFileDialog(this,"Open GPS Activity file");
        m_fileDialog->setNameFilter("GPS Activities (*.tcx *.fit)");
    }
    if (m_fileDialog->exec()) {
        QStringList fileNames = m_fileDialog->selectedFiles();

    }
}
