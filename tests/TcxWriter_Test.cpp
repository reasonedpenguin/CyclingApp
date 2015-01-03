#include <QString>
#include <gtest/gtest.h>
#include "Activity.h"
#include "TcxDataSource.h"
#include "TcxWriter.h"

class TcxWriterTest : public ::testing::Test {
protected:
    //virtual void SetUp() {}
    // virtual void TearDown() {}

};



TEST_F(TcxWriterTest,exportActivity)
{
//    TcxDataSource tds;
//    Activity inputActivity = tds.getActivityFromFile(":/q/data/sample.tcx");
//
//    TcxWriter tw;
//    QString tmpFile = "/tmp/sample.tcx";
//    tw.save(inputActivity, tmpFile);
//
//    Activity activity = tds.getActivityFromFile(tmpFile);
//
//    QVERIFY2(!activity.isNull(), "Unable to parse file");
//
//    QCOMPARE(activity.getTitle(),QString("2012-10-14T10:02:42.000Z"));
//    //QVERIFY(activity->creator() == "");
//    QCOMPARE(int(activity.getDuration()), int(2391.59));
//    QCOMPARE(int(activity.getDistance()), int(10119.7));
//    QCOMPARE(int(activity.getMaxSpeed()), int(5.388));
//    QCOMPARE(activity.getCalories(), 679);
//    QCOMPARE(activity.getAvgHeartRate(), 170.0);
//    QCOMPARE(activity.getMaxHeartRate(), 185.0);
//    // TODO check the sport
//    //QCOMPARE(activity.getSportId(), QString("Running"));
//    QCOMPARE(activity.getLaps().size(), 11);
//    QCOMPARE(activity.getLaps()[0].getTrackpoints().size(), 61);
}
