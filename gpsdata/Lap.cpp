#include "../gpsdata/Lap.h"

Lap::Lap()
{
}

bool Lap::isNull()
{
    return m_trackpoints.isEmpty();
}

double Lap::totalTime() const
{
    return m_totalTime;
}

void Lap::setTotalTime(double totalTime)
{
    m_totalTime = totalTime;
}
double Lap::distance() const
{
    return m_distance;
}

void Lap::setDistance(double distance)
{
    m_distance = distance;
}
double Lap::maxSpeed() const
{
    return m_maxSpeed;
}

void Lap::setMaxSpeed(double maxSpeed)
{
    m_maxSpeed = maxSpeed;
}
int Lap::calories() const
{
    return m_calories;
}

void Lap::setCalories(int calories)
{
    m_calories = calories;
}
int Lap::avgHR() const
{
    return m_avgHR;
}

void Lap::setAvgHR(int avgHR)
{
    m_avgHR = avgHR;
}
int Lap::maxHR() const
{
    return m_maxHR;
}

void Lap::setMaxHR(int maxHR)
{
    m_maxHR = maxHR;
}
int Lap::cadence() const
{
    return m_cadence;
}

void Lap::setCadence(int cadence)
{
    m_cadence = cadence;
}
QList<Trackpoint> Lap::trackpoints() const
{
    return m_trackpoints;
}

void Lap::setTrackpoints(const QList<Trackpoint> &trackpoints)
{
    m_trackpoints = trackpoints;
}








