/*
 * ActivityListModel.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#include "ActivityListModel.h"

#include <QStringList>

#include "IDataSource.h"
#include "ActivityDB.h"
#include "ActivityItem.h"

ActivityListModel::ActivityListModel(QObject* parent) : QAbstractItemModel(parent) {
    QList<QVariant> rootData;
    rootData << "Title" << "Summary";
    rootItem = new TreeItem(rootData);
    setupModelData(rootItem);
}

ActivityListModel::~ActivityListModel() {
    if(rootItem) delete rootItem;
}

QVariant ActivityListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role != Qt::DisplayRole)
        return QVariant();

    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags ActivityListModel::flags(const QModelIndex& index) const {
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant ActivityListModel::headerData(int section, Qt::Orientation orientation,int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        return rootItem->data(section);

    return QVariant();
}

QModelIndex ActivityListModel::index(int row, int column, const QModelIndex& parent) const {
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex ActivityListModel::parent(const QModelIndex& index) const {
    if (!index.isValid())
        return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int ActivityListModel::rowCount(const QModelIndex& parent) const {
    TreeItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<TreeItem*>(parent.internalPointer());

    return parentItem->childCount();
}

int ActivityListModel::columnCount(const QModelIndex& parent) const {
    if (parent.isValid())
        return static_cast<TreeItem*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

void ActivityListModel::setupModelData(TreeItem* parentItem) {
    m_db = new ActivityDB();
    QList<Activity> activityList = m_db->getAllActivities();
//    Activity test1,test2;
//    test1.setName("Test1");
//    test2.setName("Test2");
//    activityList.push_back(test1);
//    activityList.push_back(test2);
    for(int i=0;i<activityList.size();i++) {
        TreeItem * childItem = new ActivityItem(activityList.value(i));
        parentItem->appendChild(childItem);
    }

}

TreeItem* ActivityListModel::nodeFromIndex(const QModelIndex& index) const {
    if(index.isValid()) {
        return static_cast<TreeItem*>(index.internalPointer());
    } else {
        return rootItem;
    }
}

void ActivityListModel::addActivity(Activity a,const QModelIndex &parent) {
    TreeItem *parentItem = static_cast<TreeItem*>(parent.internalPointer());
    if(!parentItem) parentItem = rootItem;
    try {
        qint64 id = m_db->insertActivity(a);
        Activity newActivity = m_db->getActivity(id);
        int currentCount = rowCount(parent);
        beginInsertRows(parent,currentCount,currentCount);
        TreeItem * childItem = new ActivityItem(newActivity);
        parentItem->appendChild(childItem);
        endInsertRows();
    } catch(std::exception& e) {
        // Error adding activity.
    }
}

void ActivityListModel::loadActivity(ActivityItem * item) {
//    Activity a = IDataSource::loadActivity(item->activity().dataFile());
//    item->setActivity(a);
    Activity a = m_db->getActivity(item->activity().getId());
    item->setActivity(a);
}

Activity ActivityListModel::getActivity(const QModelIndex& index){
    ActivityItem* item = static_cast<ActivityItem*>(nodeFromIndex(index));
    if(item) {
        loadActivity(item);
        return item->activity();
    } else {
        return Activity();
    }
}

