#include <QString>
#include <QtTest>
#include "TcxDataSource.h"
#include "Activity.h"

class ExportTest : public QObject
{
    Q_OBJECT

public:
    ExportTest();

private Q_SLOTS:
    void exportActivity();
};

