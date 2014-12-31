#ifndef LAP_H
#define LAP_H

#include <QString>
#include <QList>

#include "../gpsdata/Trackpoint.h"


class Lap
{
public:
    Lap();

    bool isNull();

    double totalTime() const;
    void setTotalTime(double totalTime);

    double distance() const;
    void setDistance(double distance);

    double maxSpeed() const;
    void setMaxSpeed(double maxSpeed);

    int calories() const;
    void setCalories(int calories);

    int avgHR() const;
    void setAvgHR(int avgHR);

    int maxHR() const;
    void setMaxHR(int maxHR);

    int cadence() const;
    void setCadence(int cadence);

    QList<Trackpoint> trackpoints() const;
    void setTrackpoints(const QList<Trackpoint> &trackpoints);

private:
    double m_totalTime;
    double m_distance;
    double m_maxSpeed;
    int m_calories;
    int m_avgHR;
    int m_maxHR;
    int m_cadence;
    QList<Trackpoint> m_trackpoints;
};

#endif // LAP_H
