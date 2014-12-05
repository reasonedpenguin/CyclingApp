#include <QString>
#include "tst_exporttest.h"
#include "TcxDataSource.h"
#include "Activity.h"
#include "TcxWriter.h"


ExportTest::ExportTest()
{
}


void ExportTest::exportActivity()
{
    TcxDataSource tds;
    Activity inputActivity = tds.getActivityFromFile(":/q/data/sample.tcx");

    TcxWriter tw;
    QString tmpFile = "/tmp/sample.tcx";
    tw.save(inputActivity, tmpFile);

    Activity activity = tds.getActivityFromFile(tmpFile);

    QVERIFY2(!activity.isNull(), "Unable to parse file");

    QCOMPARE(activity.name(),QString("2012-10-14T10:02:42.000Z"));
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
