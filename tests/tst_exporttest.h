#include <QString>
#include <QtTest>

#include "../gpsdata/Activity.h"
#include "../gpsdata/TcxDataSource.h"

class ExportTest : public QObject
{
    Q_OBJECT

public:
    ExportTest();

private Q_SLOTS:
    void exportActivity();
};

