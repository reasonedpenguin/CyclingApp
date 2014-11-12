#ifndef SRC_H
#define SRC_H

#include "src_global.h"
#include <QString>
#include <QObject>

class Activity;

class SRCSHARED_EXPORT IDataSource : public QObject
{
    Q_OBJECT
protected:
    IDataSource();

public:
    virtual Activity getActivityFromFile(const QString& filename) = 0;
    virtual QString getErrorMsg();

protected:
    QString m_errorMsg;
};

#endif // SRC_H
