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

ImportTest::ImportTest()
{
}

void ImportTest::verifySchema()
{
    TcxDataSource tds;
    //QVERIFY2(tds.isValid(":/q/data/sample.tcx"),"Error checking schema");
}

void ImportTest::verifyActivity()
{
    TcxDataSource tds;
    Activity activity = tds.getActivityFromFile(":/q/data/sample.tcx");
    QVERIFY2(!activity.isNull(), "Unable to parse file");

    QCOMPARE(activity.id(),QString("2012-10-14T10:02:42.000Z"));
    //QVERIFY(activity->creator() == "");
    QCOMPARE(int(activity.totalTime()), int(2391.59));
    QCOMPARE(int(activity.distance()), int(10119.7));
    QCOMPARE(int(activity.maxSpeed()), int(5.388));
    QCOMPARE(activity.calories(), 679);
    QCOMPARE(activity.averageHeartRate(), 170);
    QCOMPARE(activity.maxHeartRate(), 185);
    QCOMPARE(activity.sport(), QString("Running"));
    QCOMPARE(activity.laps().size(), 11);
    QCOMPARE(activity.laps()[0].trackpoints().size(), 61);
}

QTEST_APPLESS_MAIN(ImportTest)

#include "tst_importtest.moc"
