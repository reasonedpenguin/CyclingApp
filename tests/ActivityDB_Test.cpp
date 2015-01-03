
#include <unistd.h>
#include <gtest/gtest.h>
#include <QString>
#include <QApplication>
#include <QDesktopServices>
#include "Activity.h"
#include "Trackpoint.h"
#include "TcxDataSource.h"
#include "ActivityDB.h"
#include <QTest>


class ActivityDBTest : public ::testing::Test {
public:
    ActivityDBTest() {
        int argc =0;
        char * argv[] = {0};
        app = new QCoreApplication(argc, argv);
        app->setApplicationName("CyclingAppTest");
        app->setOrganizationName("CyclingAppTest");
#if (QT_VERSION >= QT_VERSION_CHECK(5, 0, 0))
        QDir dataDir = QDir(QStandardPaths::writableLocation(QStandardPaths::DataLocation));
#else
        QDir dataDir = QDir(QDesktopServices::storageLocation(QDesktopServices::DataLocation));
#endif
        QString indexFile = dataDir.filePath("index.db");
        unlink(indexFile.toLocal8Bit().constData());

    }
    ~ActivityDBTest() {
        delete app;
    }
protected:
    virtual void SetUp() {

    }
    // virtual void TearDown() {}
    QCoreApplication *app;
};

TEST_F(ActivityDBTest,createDatabase)
{
    ActivityDB *m_db = new ActivityDB();
    QList<Activity> activities = m_db->getAllActivities();
    EXPECT_EQ(0,activities.size());

    delete m_db;
}


TEST_F(ActivityDBTest,insertActivity)
{
    TcxDataSource tds;
    Activity activity = tds.getActivityFromFile(":/q/data/sample.tcx");
    ASSERT_FALSE(activity.isNull()) << "Unable to parse file";

    ActivityDB *m_db = new ActivityDB();

    qint64 activity_id = m_db->insertActivity(activity);
    activity = m_db->getActivity(activity_id);
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

TEST_F(ActivityDBTest,verifyTrackpointTime) {
    TcxDataSource tds;
    Activity activity = tds.getActivityFromFile(":/q/data/sample.tcx");
    ASSERT_FALSE(activity.isNull()) << "Unable to parse file";
    ASSERT_EQ(activity.getLaps().size(), 11);
    EXPECT_EQ(activity.getLaps()[0].getTrackpoints()[0].getTime(), QDateTime(QDate(2012,10,14),QTime(10,2,41)));

    // The second trackpoint has is missing the milliseconds, but we need to be able to parse both.
    EXPECT_EQ(activity.getLaps()[0].getTrackpoints()[1].getTime(), QDateTime(QDate(2012,10,14),QTime(10,2,43)));
}

TEST_F(ActivityDBTest,insertTrackpoint)
{
    TcxDataSource tds;
    Activity activity = tds.getActivityFromFile(":/q/data/sample.tcx");
    ASSERT_FALSE(activity.isNull()) << "Unable to parse file";

    ActivityDB *m_db = new ActivityDB();

    Trackpoint t;
    QDateTime now = QDateTime::currentDateTime();
    t.setTime(now);
    t.setDistance(50);
    t.setCadence(100);
    t.setHeartRate(180);
    t.setLatitude(30);
    t.setLongitude(40);
    t.setAltitude(10);
    qint64 trackpoint_id = m_db->insertTrackpoint(1,t);
    ASSERT_GT(trackpoint_id,0);
    t.setId(trackpoint_id);
    Trackpoint t2 = m_db->getTrackpoint(trackpoint_id);

    ASSERT_EQ(t.getId(),t2.getId());
    ASSERT_EQ(t.getTime().toTime_t(),t2.getTime().toTime_t()) << t.getTime().toString().toStdString() << " != " << t2.getTime().toString().toStdString();
    ASSERT_EQ(t.getDistance(),t2.getDistance());
    ASSERT_EQ(t.getHeartRate() , t2.getHeartRate());
    ASSERT_EQ(t.getCadence() , t2.getCadence());
    ASSERT_EQ(t.getLatitude() , t2.getLatitude());
    ASSERT_EQ(t.getLongitude(), t2.getLongitude());
    ASSERT_EQ(t.getAltitude(), t2.getAltitude());
}


TEST_F(ActivityDBTest,insertLap)
{

    ActivityDB *m_db = new ActivityDB();

    Lap lap;
    lap.setLapNumber(2);
    lap.setStartTime(QDateTime::currentDateTime());
    lap.setDistance(3);
    lap.setDuration(4);
    lap.setStopped(3);
    lap.setAvgHeartRate(100);
    lap.setMaxHeartRate(150);
    lap.setAvgSpeed(3);
    lap.setMaxSpeed(10);
    lap.setAvgCadence(80);
    lap.setMaxCadence(90);
    lap.setElevGain(1000);
    lap.setElevLoss(2000);
    lap.setCalories(70);

    qint64 lap_id = m_db->insertLap(1,lap);
    ASSERT_GT(lap_id,0);
    lap.setId(lap_id);
    Lap lap2 = m_db->getLap(lap_id);

    ASSERT_EQ(lap.getId(),lap2.getId());
    ASSERT_EQ(lap.getLapNumber(),lap2.getLapNumber());
    ASSERT_EQ(lap.getStartTime().toTime_t(),lap2.getStartTime().toTime_t()) <<
        lap.getStartTime().toString().toStdString() << " != " << lap2.getStartTime().toString().toStdString();
    ASSERT_EQ(lap.getDistance(),lap2.getDistance());
    ASSERT_EQ(lap.getDuration(),lap2.getDuration());
    ASSERT_EQ(lap.getAvgHeartRate() , lap2.getAvgHeartRate());
    ASSERT_EQ(lap.getMaxHeartRate() , lap2.getMaxHeartRate());
    ASSERT_EQ(lap.getAvgSpeed() , lap2.getAvgSpeed());
    ASSERT_EQ(lap.getMaxSpeed() , lap2.getMaxSpeed());
    ASSERT_EQ(lap.getAvgCadence() , lap2.getAvgCadence());
    ASSERT_EQ(lap.getMaxCadence() , lap2.getMaxCadence());
    ASSERT_EQ(lap.getElevGain() , lap2.getElevGain());
    ASSERT_EQ(lap.getElevLoss(), lap2.getElevLoss());
    ASSERT_EQ(lap.getCalories(), lap2.getCalories());
}


