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
#include <QBuffer>
#include <stdexcept>

#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
#include <QStandardPaths>
#else
#include <QDesktopServices>
#endif

#include <QtGlobal>

// TODO: Switch to sqlite directly, qt just doesn't give good error messages.
// TODO: in Trackpoint, cadence is not correct, longitude is not correct

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

    // I generally try to keep everything in meters, seconds, or meters/second
    query(  "CREATE TABLE IF NOT EXISTS sport ("
            "sport_id INTEGER PRIMARY KEY,"
            "name VARCHAR(255),"
            "color VARCHAR(7)"
            "); ");
    query(
            "CREATE TABLE IF NOT EXISTS athlete ("
            "athlete_id INTEGER PRIMARY KEY,"
            "name VARCHAR(255),"
            "weight REAL,"
            "resting_heart_rate REAL,"
            "maxhr REAL);");

    query(
            "CREATE TABLE IF NOT EXISTS activity ("
            "activity_id INTEGER PRIMARY KEY,"
            "title TEXT," // User defined name (or the imported name)
            "sport_id INTEGER,"
            "athlete_id INTEGER,"
            "comments TEXT,"
            "start_time DATETIME," // Start of activity
            "distance REAL," // Distance in meters
            "duration REAL," // Total duration in seconds
            "stopped REAL," // stopped time in seconds (amount of time when speed == 0)
            "avg_heart_rate REAL," // average Beats/second for activity
            "max_heart_rate REAL," // max beats/second for activity
            "avg_speed REAL," // average speed in meters/second
            "max_speed REAL," // max speed in meters/second
            "avg_cadence REAL," // average cadence in rotations per second
            "max_cadence REAL," // max cadence in rotations per second
            "elev_gain REAL," // Total elevation gain for activity
            "elev_loss REAL," // Total elevation loss for activity
            "calories INTEGER," // Total calories burned for activity
            "preview BLOB," // Preview in PNG format
            "FOREIGN KEY(athlete_id) REFERENCES athlete(athlete_id),"
            "FOREIGN KEY(sport_id) REFERENCES sport(sport_id)"
            ");");

    query(
            "CREATE TABLE IF NOT EXISTS  lap ("
            "lap_id INTEGER PRIMARY KEY,"
            "activity_id INTEGER,"
            "lap_number INTEGER,"
            "start_time DATETIME," // Start of activity
            "distance REAL," // Distance in meters
            "duration REAL," // Total duration in seconds
            "stopped REAL," // stopped time in seconds (amount of time when speed == 0)
            "avg_heart_rate REAL," // average Beats/second for activity
            "max_heart_rate REAL," // max beats/second for activity
            "avg_speed REAL," // average speed in meters/second
            "max_speed REAL," // max speed in meters/second
            "avg_cadence REAL," // average cadence in rotations per second
            "max_cadence REAL," // max cadence in rotations per second
            "elev_gain REAL," // Total elevation gain for activity
            "elev_loss REAL," // Total elevation loss for activity
            "calories INTEGER," // Total calories burned for activity
            "FOREIGN KEY(activity_id) REFERENCES activity(activity_id));");
    query(
            "CREATE TABLE IF NOT EXISTS  trackpoint ("
            "trackpoint_id INTEGER PRIMARY KEY,"
            "lap_id INTEGER,"
            "time DATETIME,"
            "distance REAL,"
            "heart_rate REAL,"
            "cadence REAL,"
            "latitude REAL,"
            "longitude REAL,"
            "altitude REAL"
            ");");

}

ActivityDB::~ActivityDB() {
    m_db.close();
}

qint64 ActivityDB::lastRowId() {
    QSqlQuery query("SELECT last_insert_rowid()",m_db);
    if(query.next()) {
        return query.value(0).toInt();
    }
    return -1;
}

void ActivityDB::query(const QString& queryStr) {
    QSqlQuery query(queryStr,m_db);
    if(!query.exec()) {
        qDebug() << "Unable to execute query:" << query.lastError().text();
        qDebug() << "query: " << queryStr;
    }
}
/********************* Activity ********************/

QString activityFields = "title,sport_id,athlete_id,comments,start_time,distance,duration,stopped,"
        "avg_heart_rate,max_heart_rate,avg_speed,max_speed,avg_cadence,max_cadence,elev_gain,elev_loss,"
        "calories,preview";
QString activityPlaceholders = ":title,:sport_id,:athlete_id,:comments,:start_time,:distance,:duration,:stopped,"
        ":avg_heart_rate,:max_heart_rate,:avg_speed,:max_speed,:avg_cadence,:max_cadence,:elev_gain,:elev_loss,"
        ":calories,:preview";

void ActivityDB::loadActivity(QSqlQuery & query,Activity & a) {

    a.setTitle(query.value(1).toString());
    a.setSportId(query.value(2).toInt());
    a.setAthleteId(query.value(3).toInt());
    a.setComments(query.value(4).toString());
    a.setStartTime(query.value(5).toDateTime());
    a.setDistance(query.value(6).toDouble());
    a.setDuration(query.value(7).toDouble());
    a.setStopped(query.value(8).toDouble());
    a.setAvgHeartRate(query.value(9).toDouble());
    a.setMaxHeartRate(query.value(10).toDouble());
    a.setAvgSpeed(query.value(11).toDouble());
    a.setMaxSpeed(query.value(12).toDouble());
    a.setAvgCadence(query.value(13).toDouble());
    a.setMaxCadence(query.value(14).toDouble());
    a.setElevGain(query.value(15).toDouble());
    a.setElevLoss(query.value(16).toDouble());
    a.setCalories(query.value(17).toInt());
    QImage preview;
    preview.loadFromData(query.value(18).toByteArray());
    a.setPreview(preview);
}
void ActivityDB::bindActivity(QSqlQuery & query,const Activity & a) {
    query.addBindValue(a.getTitle());
    query.addBindValue(a.getSportId());
    query.addBindValue(a.getAthleteId());
    query.addBindValue(a.getComments());
    query.addBindValue(a.getStartTime());
    query.addBindValue(a.getDistance());
    query.addBindValue(a.getDuration());
    query.addBindValue(a.getStopped());
    query.addBindValue(a.getAvgHeartRate());
    query.addBindValue(a.getMaxHeartRate());
    query.addBindValue(a.getAvgSpeed());
    query.addBindValue(a.getMaxSpeed());
    query.addBindValue(a.getAvgCadence());
    query.addBindValue(a.getMaxCadence());
    query.addBindValue(a.getElevGain());
    query.addBindValue(a.getElevLoss());
    query.addBindValue(a.getCalories());
    QByteArray ba;
    QBuffer buffer(&ba);
    buffer.open(QIODevice::WriteOnly);
    a.getPreview().save(&buffer, "PNG"); // writes image into ba in PNG format
    query.addBindValue(ba);

}

qint64 ActivityDB::insertActivity(const Activity& a) {

    if(a.isNull()) {
        qWarning() << "activity was null!";
        return -1;
    }

    m_db.transaction();

    try {
        QSqlQuery query(m_db);
        query.prepare(QString("INSERT INTO activity (%1) values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)").arg(activityFields));
        bindActivity(query,a);
    //    query.bindValue(0,a.getTitle());
    //    query.bindValue(1,filePath);

        if(!query.exec()) {
            qDebug() << "Unable to add activity:" << query.lastError().text();
            throw std::runtime_error("Unable to add activity.");
        }
        qint64 activity_id = lastRowId();
        for(int i=0;i<a.getLaps().size();i++) {
            insertLap(activity_id,a.getLaps()[i]);
        }
        m_db.commit();
        return activity_id;

    } catch(...) {
        m_db.rollback();
    }
    return -1;
}


/************** Lap **********************/
QString lapFields = "lap_number,start_time,distance,duration,stopped,"
        "avg_heart_rate,max_heart_rate,avg_speed,max_speed,avg_cadence,max_cadence,elev_gain,elev_loss,calories";

void ActivityDB::loadLap(QSqlQuery & query,Lap & lap) {
    lap.setLapNumber(query.value(1).toInt());
    lap.setStartTime(query.value(2).toDateTime());
    lap.setDistance(query.value(3).toDouble());
    lap.setDuration(query.value(4).toDouble());
    lap.setStopped(query.value(5).toDouble());
    lap.setAvgHeartRate(query.value(6).toDouble());
    lap.setMaxHeartRate(query.value(7).toDouble());
    lap.setAvgSpeed(query.value(8).toDouble());
    lap.setMaxSpeed(query.value(9).toDouble());
    lap.setAvgCadence(query.value(10).toDouble());
    lap.setMaxCadence(query.value(11).toDouble());
    lap.setElevGain(query.value(12).toDouble());
    lap.setElevLoss(query.value(13).toDouble());
    lap.setCalories(query.value(14).toInt());
}
void ActivityDB::bindLap(QSqlQuery & query,const Lap & lap) {
    query.addBindValue(lap.getLapNumber());
    query.addBindValue(lap.getStartTime());
    query.addBindValue(lap.getDistance());
    query.addBindValue(lap.getDuration());
    query.addBindValue(lap.getStopped());
    query.addBindValue(lap.getAvgHeartRate());
    query.addBindValue(lap.getMaxHeartRate());
    query.addBindValue(lap.getAvgSpeed());
    query.addBindValue(lap.getMaxSpeed());
    query.addBindValue(lap.getAvgCadence());
    query.addBindValue(lap.getMaxCadence());
    query.addBindValue(lap.getElevGain());
    query.addBindValue(lap.getElevLoss());
    query.addBindValue(lap.getCalories());

}

qint64 ActivityDB::insertLap(qint64 activity_id,const Lap& lap) {

    if(lap.isNull()) {
        qWarning() << "lap name was null!";
        return -1;
    }

    QSqlQuery query(m_db);
    query.prepare(QString("INSERT INTO lap (activity_id,%1) values (?,?,?,?,?,?,?,?,?,?,?,?,?,?,?)").arg(lapFields));
    query.addBindValue(activity_id);
    bindLap(query,lap);

//    query.bindValue(0,a.getTitle());
//    query.bindValue(1,filePath);

    if(!query.exec()) {
        qDebug() << "Unable to add lap:" << m_db.lastError().text();
        throw std::runtime_error("Unable to add lap.");
    }
    qint64 lap_id = lastRowId();
    for(int i=0;i<lap.getTrackpoints().size();i++) {
        insertTrackpoint(lap_id,lap.getTrackpoints().at(i));
    }
    return lap_id;

}


Lap ActivityDB::getLap(qint64 lap_id) {
    QSqlQuery query(QString("SELECT lap_id,%1 FROM lap WHERE lap_id=?").arg(lapFields));
    query.bindValue(0,lap_id);
    if(!query.exec()) {
        qDebug() << "Unable to get lap:" << query.lastError().text();
    }


    Lap lap;
    if(query.next()) {
        lap.setId(query.value(0).toInt());
        loadLap(query,lap);
    }

    QList<Trackpoint> points = getTrackpoints(lap.getId());
    lap.setTrackpoints(points);

    return lap;
}


QVector<Lap> ActivityDB::getLaps(qint64 activity_id) {
    QSqlQuery query(QString("SELECT lap_id,%1 FROM lap WHERE activity_id=?").arg(lapFields));
    query.bindValue(0,activity_id);
    if(!query.exec()) {
        qDebug() << "Unable to get lap:" << query.lastError().text();
    }

    QVector<Lap> lapList;
    while(query.next()) {
        Lap lap;
        lap.setId(query.value(0).toInt());
        loadLap(query,lap);
        lapList.push_back(lap);
    }

    for(int i=0;i<lapList.size();i++) {
        QList<Trackpoint> points = getTrackpoints(lapList[i].getId());
        lapList[i].setTrackpoints(points);
    }
    return lapList;
}
/************* Trackpoint ***************/

QString trackpointFields = "time, distance, heart_rate, cadence, latitude, longitude, altitude";

void ActivityDB::loadTrackpoint(QSqlQuery & query,Trackpoint & t) {
    t.setTime(query.value(0).toDateTime());
    t.setDistance(query.value(1).toDouble());
    t.setHeartRate(query.value(2).toDouble());
    t.setCadence(query.value(3).toDouble());
    t.setLatitude(query.value(4).toDouble());
    t.setLongitude(query.value(5).toDouble());
    t.setAltitude(query.value(6).toInt());
}
void ActivityDB::bindTrackpoint(QSqlQuery & query,const Trackpoint & t) {
    query.addBindValue(t.getTime());
    query.addBindValue(t.getDistance());
    query.addBindValue(t.getHeartRate());
    query.addBindValue(t.getCadence());
    query.addBindValue(t.getLatitude());
    query.addBindValue(t.getLongitude());
    query.addBindValue(t.getAltitude());
}

qint64 ActivityDB::insertTrackpoint(qint64 lap_id,const Trackpoint& t) {

    if(t.isNull()) {
        qWarning() << "trackpoint time was null!";
        return -1;
    }

    QSqlQuery query(
                QString("INSERT INTO trackpoint (%1,lap_id) values (?,?,?,?,?,?,?,?);").arg(trackpointFields),m_db);
    bindTrackpoint(query,t);
    query.addBindValue(lap_id);
//    query.bindValue(0,a.getTitle());
//    query.bindValue(1,filePath);

    if(!query.exec()) {
        qDebug() << "Unable to add trackpoint:" << query.lastError().text();
        throw std::runtime_error("Unable to add trackpoint.");
    }
    qint64 id = lastRowId();
    return id;

}

Trackpoint ActivityDB::getTrackpoint(qint64 trackpoint_id) {
    QSqlQuery query(m_db);
    query.prepare(QString("SELECT %1,trackpoint_id FROM trackpoint WHERE trackpoint_id=?").arg(trackpointFields));
    query.addBindValue(trackpoint_id);

    if(!query.exec()) {
        qDebug() << "Unable to get trackpoint:" << query.lastError().text();
    }
    qDebug() << query.executedQuery();

    Trackpoint t;

    if(query.next()) {
        loadTrackpoint(query,t);
        t.setId(query.value(7).toInt());
    }
    return t;
}


QList<Trackpoint> ActivityDB::getTrackpoints(qint64 lap_id) {
    QSqlQuery query(m_db);
    query.prepare(QString("SELECT %1,trackpoint_id FROM trackpoint WHERE lap_id=?").arg(trackpointFields));
    query.addBindValue(lap_id);

    if(!query.exec()) {
        qDebug() << "Unable to get trackpoint:" << query.lastError().text();
    }
    qDebug() << query.executedQuery();

    QList<Trackpoint> pointList;
    while(query.next()) {
        Trackpoint t;
        loadTrackpoint(query,t);
        t.setId(query.value(7).toInt());
        pointList.push_back(t);
    }
    return pointList;
}
void ActivityDB::removeActivity(int64_t id) {
}

QList<Activity> ActivityDB::getAllActivities() {
    QList<Activity> activityList;
    QSqlQuery query(QString("SELECT activity_id,%1 FROM activity").arg(activityFields));
    while(query.next()) {
        Activity activity;
        activity.setId(query.value(0).toInt());
        loadActivity(query,activity);
        activityList.push_back(activity);
    }
    return activityList;
}

Activity ActivityDB::getActivity(qint64 activity_id) {
    QSqlQuery query(QString("SELECT activity_id,%1 FROM activity WHERE activity_id=?").arg(activityFields));
    query.bindValue(0,activity_id);

    if(!query.exec()) {
        qDebug() << "Unable to get activity:" << query.lastError().text();
    }
    Activity activity;
    if(query.next()) {
        activity.setId(query.value(0).toInt());
        loadActivity(query,activity);
        activity.setLaps(getLaps(activity_id));
    } else {

    }
    return activity;
}






