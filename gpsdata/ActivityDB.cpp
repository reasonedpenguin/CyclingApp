/*
 * ActivityDB.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: hornja
 */

#include "../gpsdata/ActivityDB.h"

#include <QtGlobal>
#include <QDir>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QtDebug>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QStandardPaths>
#else
#include <QDesktopServices>
#endif

#include <QtGlobal>

ActivityDB::ActivityDB() {
    m_db = QSqlDatabase::addDatabase("QSQLITE");
//    QString dataDir = QStandardPaths::writableLocation(QStandardPaths::DataLocation);
//    qDebug("Data directory: %s", dataDir.data());
//    //m_db.setDatabaseName()
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
    m_dataDir = QDir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
#else
    m_dataDir = QDir(QDesktopServices::storageLocation(QDesktopServices::DataLocation));
#endif

    QString indexFile = m_dataDir.filePath("index.db");
    qDebug("Data directory from desktop services: %s", m_dataDir.path().toLocal8Bit().constData());
    qDebug("index: %s", indexFile.toLocal8Bit().constData());

    m_dataDir.mkpath(QString("."));
    m_db.setDatabaseName(indexFile);
    if(!m_db.open()) {
        qDebug() << "Unable to open database:" << m_db.lastError().text();
        return;
    }

    QSqlQuery query(
            "CREATE TABLE IF NOT EXISTS activity ("
            "id INT PRIMARY KEY,"
            "name TEXT,"
            "datafile TEXT"
            ");",m_db);
    if(!query.exec()) {
        qDebug() << "Unable to create database:" << m_db.lastError().text();
    }
}

ActivityDB::~ActivityDB() {
    m_db.close();
}

int64_t ActivityDB::lastRowId() {
    QSqlQuery query("SELECT last_insert_rowid()",m_db);
    if(query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}

int64_t ActivityDB::addActivity(const Activity& a) {

    if(a.name().isNull()) {
        qWarning() << "activity name was null!";
        return -1;
    }
    int counter = 0;
    QString filePath;
    do {
        if(counter == 0)
            filePath = m_dataDir.filePath(QString("%1.tcx").arg(a.name()));
        else
            filePath = m_dataDir.filePath(QString("%1_%2.tcx").arg(a.name()).arg(counter));
        ++counter;
    } while(QFileInfo(filePath).exists());

    if(filePath.isNull()) {
        qWarning() << "activity file was null!";
        return -1;
    }
    QSqlQuery query(
                "INSERT INTO activity (name,datafile) values (?,?);",m_db);
    query.bindValue(0,a.name());
    query.bindValue(1,filePath);

    if(!query.exec()) {
        qDebug() << "Unable to add activity:" << m_db.lastError().text();
        return -1;
    }
    return lastRowId();

}

void ActivityDB::removeActivity(int64_t id) {
}

QList<Activity> ActivityDB::getAllActivities() {
    QList<Activity> activityList;
    QSqlQuery query("SELECT id,name,datafile FROM activity");
    while(query.next()) {
        Activity activity;
        activity.setId(query.value(0).toInt());
        activity.setName(query.value(1).toString());
        activity.setDataFile(query.value(2).toString());
        //activity.load();
        activityList.push_back(activity);
    }
    return activityList;
}
