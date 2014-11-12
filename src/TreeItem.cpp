/*
 * TreeItem.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#include "TreeItem.h"
#include <QtAlgorithms>


TreeItem::TreeItem(const QList<QVariant>& data, TreeItem* parent) :
    parentItem(parent),
    itemData(data)
{

}

TreeItem::~TreeItem() {
    qDeleteAll(childItems);
}

void TreeItem::appendChild(TreeItem* child) {
    childItems.append(child);
}

TreeItem* TreeItem::child(int row) {
    return childItems.at(row);
}

int TreeItem::childCount() const {
    return childItems.count();
}

int TreeItem::columnCount() const {
    return itemData.count();
}

QVariant TreeItem::data(int column) const {
    return itemData.value(column);
}

int TreeItem::row() const {
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<TreeItem*>(this));

    return 0;
}

TreeItem* TreeItem::parent() {
    return parentItem;
}
