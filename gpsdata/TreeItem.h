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
    TreeItem(TreeItem *parent = 0);
    TreeItem(const QList<QVariant> &data,TreeItem *parent = 0);
    virtual ~TreeItem();

    void appendChild(TreeItem *child);

    TreeItem *child(int row);
    virtual int childCount() const;
    virtual int columnCount() const;
    virtual QVariant data(int column) const;
    virtual void setData( int column, QVariant newData);
    int row() const;
    TreeItem *parent();

private:
    TreeItem *parentItem;
    QList<TreeItem*> childItems;
    QList<QVariant> itemData;


};

#endif /* TREEITEM_H_ */
