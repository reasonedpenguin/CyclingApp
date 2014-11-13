/*
 * ActivityItem.h
 *
 *  Created on: Nov 11, 2014
 *      Author: hornja
 */

#ifndef ACTIVITYITEM_H_
#define ACTIVITYITEM_H_

#include "TreeItem.h"
#include "Activity.h"

class ActivityItem: public TreeItem {
public:
    ActivityItem(const Activity& a);
    virtual ~ActivityItem();

    QVariant data(int column) const;
    int columnCount() const;

private:
    Activity m_activity;

};

#endif /* ACTIVITYITEM_H_ */
