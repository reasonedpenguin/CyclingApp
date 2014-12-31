#ifndef SRC_H
#define SRC_H

#include <QString>
#include <QObject>


class Activity;

class IDataSource : public QObject
{
    Q_OBJECT

public:
    static Activity loadActivity(const QString& filename);

protected:
    IDataSource();
    virtual Activity getActivityFromFile(const QString& filename) = 0;

};

#endif // SRC_H
