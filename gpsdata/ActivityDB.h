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

    int64_t addActivity(const Activity& a);
    void removeActivity(int64_t id);
    QList<Activity> getAllActivities();

private:
    int64_t lastRowId();

    QSqlDatabase m_db;
    QDir m_dataDir;
};

#endif /* ACTIVITYDB_H_ */
