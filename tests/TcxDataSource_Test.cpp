
#include <gtest/gtest.h>
#include <QString>

#include "Activity.h"
#include "TcxDataSource.h"


class TcxDataSourceTest : public ::testing::Test {
protected:
    //virtual void SetUp() {}
    // virtual void TearDown() {}

};

TEST_F(TcxDataSourceTest,verifySchema)
{
    TcxDataSource tds;
    //QVERIFY2(tds.isValid(":/q/data/sample.tcx"),"Error checking schema");
}

TEST_F(TcxDataSourceTest,verifyActivity)
{
    TcxDataSource tds;
    Activity activity = tds.getActivityFromFile(":/q/data/sample.tcx");
    ASSERT_FALSE(activity.isNull()) << "Unable to parse file";

    EXPECT_EQ(activity.getTitle(),QString("2012-10-14T10:02:42.000Z"));
    //QVERIFY(activity->creator() == "");
    EXPECT_EQ(int(activity.getDuration()), int(2391.59));
    EXPECT_EQ(int(activity.getDistance()), int(10119.7));
    EXPECT_EQ(int(activity.getMaxSpeed()), int(5.388));
    EXPECT_EQ(activity.getCalories(), 679);
    EXPECT_EQ(int(activity.getAvgHeartRate()), 175);
    EXPECT_EQ(int(activity.getMaxHeartRate()), 185);
    // TODO: check sport
    //QCOMPARE(activity.sport(), QString("Running"));
    ASSERT_EQ(activity.getLaps().size(), 11);
    EXPECT_EQ(activity.getLaps()[0].getTrackpoints().size(), 61);
}

TEST_F(TcxDataSourceTest,verifyTrackpointTime) {
    TcxDataSource tds;
    Activity activity = tds.getActivityFromFile(":/q/data/sample.tcx");
    ASSERT_FALSE(activity.isNull()) << "Unable to parse file";
    ASSERT_EQ(activity.getLaps().size(), 11);
    EXPECT_EQ(activity.getLaps()[0].getTrackpoints()[0].getTime(), QDateTime(QDate(2012,10,14),QTime(10,2,41)));

    // The second trackpoint has is missing the milliseconds, but we need to be able to parse both.
    EXPECT_EQ(activity.getLaps()[0].getTrackpoints()[1].getTime(), QDateTime(QDate(2012,10,14),QTime(10,2,43)));
}


