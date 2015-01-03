#include "../gpsdata/Trackpoint.h"

Trackpoint::Trackpoint()
{
}

bool Trackpoint::isNull() const {
    return m_time.isNull();
}

int Trackpoint::getId() const {
    return m_id;
}

void Trackpoint::setId(int id) {
    this->m_id = id;
}

double Trackpoint::getAltitude() const {
    return m_altitude;
}

void Trackpoint::setAltitude(double altitude) {
    m_altitude = altitude;
}

double Trackpoint::getDistance() const {
    return m_distance;
}

void Trackpoint::setDistance(double distance) {
    m_distance = distance;
}

double Trackpoint::getHeartRate() const {
    return m_heartRate;
}

void Trackpoint::setHeartRate(double heartRate) {
    m_heartRate = heartRate;
}

double Trackpoint::getLatitude() const {
    return m_latitude;
}

void Trackpoint::setLatitude(double latitude) {
    m_latitude = latitude;
}

double Trackpoint::getLongitude() const {
    return m_longitude;
}

void Trackpoint::setLongitude(double longitude) {
    m_longitude = longitude;
}

const QDateTime& Trackpoint::getTime() const {
    return m_time;
}

void Trackpoint::setTime(const QDateTime& time) {
    m_time = time;
}



double Trackpoint::getCadence() const {
    return m_cadence;
}

void Trackpoint::setCadence(double cadence) {
    m_cadence = cadence;
}

bool operator==(const Trackpoint& lhs, const Trackpoint& rhs) {
    return lhs.getId() == rhs.getId() && lhs.getTime() == rhs.getTime() &&
            lhs.getDistance() == rhs.getDistance() && lhs.getHeartRate() == rhs.getHeartRate() &&
            lhs.getCadence() == rhs.getCadence() && lhs.getLatitude() == rhs.getLatitude() &&
            lhs.getLongitude() == rhs.getLongitude() && lhs.getAltitude() == rhs.getAltitude();
}

std::ostream& operator<<(std::ostream& os, const Trackpoint& obj)
{
  os << QString("{%1,%2,%3,%4,%5,%6,%7,%8}").arg(obj.getId()).arg(obj.getTime().toString())
          .arg(obj.getDistance()).arg(obj.getHeartRate()).arg(obj.getCadence())
          .arg(obj.getLatitude()).arg(obj.getLongitude()).arg(obj.getAltitude()).toStdString();
  return os;
}

