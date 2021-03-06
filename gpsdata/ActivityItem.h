/*
 * ActivityItem.h
 *
 *  Created on: Nov 11, 2014
 *      Author: hornja
 */

#ifndef ACTIVITYITEM_H_
#define ACTIVITYITEM_H_

#include "../gpsdata/Activity.h"
#include "../gpsdata/TreeItem.h"

class ActivityItem: public TreeItem {
public:
    ActivityItem(const Activity& a);
    virtual ~ActivityItem();

    QVariant data(int column) const;
    int columnCount() const;

    Activity activity();
    void setActivity(const Activity & activity);
private:
    Activity m_activity;

};

#endif /* ACTIVITYITEM_H_ */
