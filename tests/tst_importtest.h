#include <QString>
#include <QtTest>

#include "../gpsdata/Activity.h"
#include "../gpsdata/TcxDataSource.h"

class ImportTest : public QObject
{
    Q_OBJECT

public:
    ImportTest();

private Q_SLOTS:
    void verifySchema();
    void verifyActivity();
};
