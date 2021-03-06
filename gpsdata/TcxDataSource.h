#ifndef TCXDATASOURCE_H
#define TCXDATASOURCE_H

#include <QString>
#include <QDomElement>

#include "../gpsdata/Activity.h"
#include "../gpsdata/IDataSource.h"
#include "../gpsdata/Lap.h"
#include "../gpsdata/Trackpoint.h"

class TcxDataSource : public IDataSource
{
    Q_OBJECT
public:
    TcxDataSource();

    virtual Activity getActivityFromFile(const QString& filename);

private:
    Activity parseActivityElement(QDomElement child);
    Lap parseLapElement(QDomElement child);
    QList<Trackpoint> parseTrackElement(QDomElement child);
};

#endif // TCXDATASOURCE_H
