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
    return QVariant(m_activity.name());
}

int ActivityItem::columnCount() const {
    return 1;
}
