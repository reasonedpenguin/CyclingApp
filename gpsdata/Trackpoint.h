#ifndef TRACKPOINT_H
#define TRACKPOINT_H

#include <QDateTime>

class Trackpoint
{
public:
    Trackpoint();

    bool isNull();

    QDateTime time() const;
    void setTime(const QDateTime &time);

    double distance() const;
    void setDistance(double distance);

    int heartRate() const;
    void setHeartRate(int heartRate);

    double latitude() const;
    void setLatitude(double latitude);

    double longitude() const;
    void setLongitude(double longitude);

    double altitude() const;
    void setAltitude(double altitude);

private:
    QDateTime m_time;
    double m_distance;
    int m_heartRate;
    double m_latitude;
    double m_longitude;
    double m_altitude;
};

#endif // TRACKPOINT_H
