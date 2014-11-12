/*
 * ActivityListModel.h
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#ifndef ACTIVITYLISTMODEL_H_
#define ACTIVITYLISTMODEL_H_

#include <QAbstractItemModel>
#include "TreeItem.h"

class ActivityListModel : public QAbstractItemModel {
public:
    ActivityListModel(const QString &data,QObject *parent);
    virtual ~ActivityListModel();

    QVariant data(const QModelIndex &index, int role) const;

    Qt::ItemFlags flags(const QModelIndex &index) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;

    QModelIndex parent(const QModelIndex &index) const;

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    int columnCount(const QModelIndex &parent = QModelIndex()) const;

private:
    void setupModelData(const QStringList &lines, TreeItem *parent);

    TreeItem *rootItem;
};

#endif /* ACTIVITYLISTMODEL_H_ */
