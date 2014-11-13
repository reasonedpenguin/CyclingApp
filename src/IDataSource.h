#ifndef SRC_H
#define SRC_H

#include "src_global.h"
#include <QString>
#include <QObject>

class Activity;

class SRCSHARED_EXPORT IDataSource : public QObject
{
    Q_OBJECT

public:
    static Activity loadActivity(const QString& filename);

protected:
    IDataSource();
    virtual Activity getActivityFromFile(const QString& filename) = 0;

};

#endif // SRC_H
