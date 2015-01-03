/*
 * ActivityDB.h
 *
 *  Created on: Nov 11, 2014
 *      Author: hornja
 */

#ifndef ACTIVITYDB_H_
#define ACTIVITYDB_H_

#include <stdint.h>
#include <QSqlDatabase>
#include <QList>
#include <QDir>
#include "../gpsdata/Activity.h"

class ActivityDB {
public:
    ActivityDB();
    virtual ~ActivityDB();

    /**
     * Adds the activity to DB storage.
     * Throws an exception if there was an issue.
     */
    qint64 insertActivity(const Activity& a);
    void removeActivity(int64_t id);

    /**
     * Get all the activities from the DB.
     * This will just get the meta in fo for the activity.
     * If you want to get detailed information, including lap and trackpoint info, then
     * call getActivity()
     */
    QList<Activity> getAllActivities();

    /**
     * Get a full activity from the DB
     */
    Activity getActivity(qint64 activity_id);

    Lap getLap(qint64 lap_id);
    QVector<Lap> getLaps(qint64 activity_id);
    Trackpoint getTrackpoint(qint64 trackpoint_id);
    QList<Trackpoint> getTrackpoints(qint64 lap_id);

    qint64 insertLap(qint64 activity_id,const Lap& lap);
    qint64 insertTrackpoint(qint64 activity_id,const Trackpoint& lap);

protected:
    qint64 lastRowId();

    void loadActivity(QSqlQuery & query,Activity & a);
    void bindActivity(QSqlQuery & query,const Activity & a);


    void loadLap(QSqlQuery & query,Lap & lap);
    void bindLap(QSqlQuery & query,const Lap & lap);


    void loadTrackpoint(QSqlQuery & query,Trackpoint & lap);
    void bindTrackpoint(QSqlQuery & query,const Trackpoint & lap);



    void query(const QString& str);

    QSqlDatabase m_db;
    QDir m_dataDir;
};

#endif /* ACTIVITYDB_H_ */
