/*
 * ActivityItem.cpp
 *
 *  Created on: Nov 11, 2014
 *      Author: hornja
 */

#include "../gpsdata/ActivityItem.h"


ActivityItem::ActivityItem(const Activity& a) :
    m_activity(a)
{

}

ActivityItem::~ActivityItem() {

}

QVariant ActivityItem::data(int column) const {
    return QVariant(m_activity.getTitle());
}

int ActivityItem::columnCount() const {
    return 1;
}

Activity ActivityItem::activity() {
    return m_activity;
}

void ActivityItem::setActivity(const Activity& activity) {
    m_activity = activity;
}
