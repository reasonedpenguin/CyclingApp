#ifndef TRACKPOINT_H
#define TRACKPOINT_H

#include <QDateTime>

class Trackpoint
{
public:
    Trackpoint();

    bool isNull() const;

    int getId() const;
    void setId(int id);

    double getAltitude() const;
    void setAltitude(double altitude);
    double getDistance() const;
    void setDistance(double distance);
    double getHeartRate() const;
    void setHeartRate(double heartRate);
    double getLatitude() const;
    void setLatitude(double latitude);
    double getLongitude() const;
    void setLongitude(double longitude);
    const QDateTime& getTime() const;
    void setTime(const QDateTime& time);

    double getCadence() const;
    void setCadence(double cadence);


private:
    int m_id;
    
    QDateTime m_time;
    double m_distance;
    double m_heartRate;
    double m_cadence;
    double m_latitude;
    double m_longitude;
    double m_altitude;
};

bool operator==(const Trackpoint& lhs, const Trackpoint& rhs);
std::ostream& operator<<(std::ostream& os, const Trackpoint& obj);

#endif // TRACKPOINT_H
