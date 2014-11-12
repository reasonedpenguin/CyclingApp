#include "Trackpoint.h"

Trackpoint::Trackpoint()
{
}
QDateTime Trackpoint::time() const
{
    return m_time;
}

void Trackpoint::setTime(const QDateTime &time)
{
    m_time = time;
}
double Trackpoint::distance() const
{
    return m_distance;
}

void Trackpoint::setDistance(double distance)
{
    m_distance = distance;
}
int Trackpoint::heartRate() const
{
    return m_heartRate;
}

void Trackpoint::setHeartRate(int heartRate)
{
    m_heartRate = heartRate;
}
double Trackpoint::latitude() const
{
    return m_latitude;
}

void Trackpoint::setLatitude(double latitude)
{
    m_latitude = latitude;
}
double Trackpoint::longitude() const
{
    return m_longitude;
}

void Trackpoint::setLongitude(double longitude)
{
    m_longitude = longitude;
}
double Trackpoint::altitude() const
{
    return m_altitude;
}

void Trackpoint::setAltitude(double altitude)
{
    m_altitude = altitude;
}













