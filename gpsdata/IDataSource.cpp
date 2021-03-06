#include "../gpsdata/IDataSource.h"

#include <stdexcept>
#include <QFileInfo>
#include <QtDebug>
#include "../gpsdata/TcxDataSource.h"

IDataSource::IDataSource()
{
}


Activity IDataSource::loadActivity(const QString& filename) {
    QFileInfo fi(filename);
    QString ext = fi.suffix();

    if(ext == "tcx") {
        TcxDataSource tcx;
        return tcx.getActivityFromFile(filename);
    } else if(ext == "fit") {

    } else {
        qWarning() << "Unknown file type " << ext << " in file " << filename;
    }
    return Activity();
}
