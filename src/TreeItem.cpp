/*
 * TreeItem.cpp
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#include "TreeItem.h"
#include <QtAlgorithms>


TreeItem::TreeItem(TreeItem* parent) :
parentItem(parent)
{

}

TreeItem::TreeItem(const QList<QVariant>& data, TreeItem* parent) :
    parentItem(parent),
    itemData(data)
{

}

TreeItem::~TreeItem() {
    qDeleteAll(childItems);
}

void TreeItem::appendChild(TreeItem* child) {
    if(!child) return;
    child->parentItem = this;
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

void TreeItem::setData(int column, QVariant newData) {
    while(itemData.count() <= column) {
        itemData.push_back(QVariant());
    }
    itemData.replace(column,newData);
}



TreeItem* TreeItem::parent() {
    return parentItem;
}
