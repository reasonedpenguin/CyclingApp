/*
 * ActivityListModel.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#include <QStringList>
#include "ActivityListModel.h"


ActivityListModel::ActivityListModel(const QString &data,QObject* parent) : QAbstractItemModel(parent) {
    QList<QVariant> rootData;
    rootData << "Title" << "Summary";
    rootItem = new TreeItem(rootData);
    setupModelData(data.split(QString("\n")), rootItem);
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

void ActivityListModel::setupModelData(const QStringList& lines,TreeItem* parent) {

}
