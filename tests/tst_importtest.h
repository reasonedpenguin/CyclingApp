#include <QString>
#include <QtTest>
#include "TcxDataSource.h"
#include "Activity.h"

class ImportTest : public QObject
{
    Q_OBJECT

public:
    ImportTest();

private Q_SLOTS:
    void verifySchema();
    void verifyActivity();
};
