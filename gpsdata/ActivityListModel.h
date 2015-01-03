/*
 * ActivityListModel.h
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#ifndef ACTIVITYLISTMODEL_H_
#define ACTIVITYLISTMODEL_H_

#include <QModelIndex>
#include <QAbstractItemModel>

#include "../gpsdata/Activity.h"
#include "../gpsdata/TreeItem.h"


class ActivityDB;
class ActivityItem;

class ActivityListModel : public QAbstractItemModel {
public:
    ActivityListModel(QObject *parent = NULL);
    virtual ~ActivityListModel();

    QVariant data(const QModelIndex &index, int role) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;

    QModelIndex parent(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    void addActivity(Activity a,const QModelIndex &parent = QModelIndex());

    Activity getActivity(const QModelIndex& index);

private:
    void setupModelData( TreeItem *parent);

    TreeItem *nodeFromIndex(const QModelIndex& index) const;

    void loadActivity(ActivityItem * item);

    TreeItem *rootItem;
    ActivityDB* m_db;
};

#endif /* ACTIVITYLISTMODEL_H_ */
