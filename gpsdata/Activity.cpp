#include "../gpsdata/Activity.h"

#include <math.h>


Activity::Activity() :
    m_id(-1)
{
}

bool Activity::isNull()
{
    return m_name.isNull();
}

int64_t Activity::id() const {
    return m_id;
}

void Activity::setId(int64_t id) {
    m_id = id;
}

QString Activity::name() const
{
    return m_name;
}

void Activity::setName(const QString &nameStr)
{
    m_name = nameStr;
}


QString Activity::creator() const
{
    return m_creator;
}

void Activity::setCreator(const QString &creator)
{
    m_creator = creator;
}
double Activity::totalTime() const
{
    return m_totalTime;
}

void Activity::setTotalTime(double totalTime)
{
    m_totalTime = totalTime;
}
double Activity::distance() const
{
        return m_distance;
}

void Activity::setDistance(double distance)
{
    m_distance = distance;
}
double Activity::maxSpeed() const
{
    return m_maxSpeed;
}

void Activity::setMaxSpeed(double maxSpeed)
{
    m_maxSpeed = maxSpeed;
}
int Activity::calories() const
{
    return m_calories;
}

void Activity::setCalories(int calories)
{
    m_calories = calories;
}
int Activity::averageHeartRate() const
{
    return m_averageHeartRate;
}

void Activity::setAverageHeartRate(int averageHeartRate)
{
    m_averageHeartRate = averageHeartRate;
}
int Activity::maxHeartRate() const
{
    return m_maxHeartRate;
}

void Activity::setMaxHeartRate(int maxHeartRate)
{
    m_maxHeartRate = maxHeartRate;
}
int Activity::cadence() const
{
    return m_cadence;
}

void Activity::setCadence(int cadence)
{
    m_cadence = cadence;
}
QVector<Lap> & Activity::laps()
{
    return m_laps;
}

void Activity::setLaps(const QVector<Lap> &laps)
{
    m_laps = laps;
    m_distance = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_distance += m_laps[i].distance();
    }

    m_totalTime = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_totalTime += m_laps[i].totalTime();
    }

    m_maxSpeed = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_maxSpeed = fmax(m_laps[i].maxSpeed(),m_maxSpeed);
    }

    m_calories = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_calories += m_laps[i].calories();
    }

    m_averageHeartRate = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_averageHeartRate += m_laps[i].totalTime()/m_totalTime * m_laps[i].avgHR();
    }

    m_maxHeartRate = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_maxHeartRate = fmax(m_laps[i].maxHR(),m_maxHeartRate);
    }
}
QString Activity::sport() const
{
    return m_sport;
}

void Activity::setSport(const QString &sport)
{
    m_sport = sport;
}

QString Activity::dataFile() const {
    return m_dataFile;
}


void Activity::setDataFile(const QString& dataFile) {
    m_dataFile = dataFile;
}
