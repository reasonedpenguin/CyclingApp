/*
 * TreeItem.h
 *
 *  Created on: Nov 1, 2014
 *      Author: hornja
 */

#ifndef TREEITEM_H_
#define TREEITEM_H_

#include <QList>
#include <QVariant>

class TreeItem {
public:
    TreeItem(const QList<QVariant> &data,TreeItem *parent = 0);
    virtual ~TreeItem();

    void appendChild(TreeItem *child);

    TreeItem *child(int row);
    int childCount() const;
    int columnCount() const;
    QVariant data(int column) const;
    int row() const;
    TreeItem *parent();

private:
    QList<TreeItem*> childItems;
    QList<QVariant> itemData;
    TreeItem *parentItem;

};

#endif /* TREEITEM_H_ */
