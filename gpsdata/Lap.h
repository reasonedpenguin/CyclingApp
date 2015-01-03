#ifndef LAP_H
#define LAP_H

#include <QString>
#include <QList>

#include "../gpsdata/Trackpoint.h"


class Lap
{
public:
    Lap();

    bool isNull() const;
    double getAvgCadence() const;
    void setAvgCadence(double avgCadence);
    double getAvgHeartRate() const;
    void setAvgHeartRate(double avgHeartRate);
    double getAvgSpeed() const;
    void setAvgSpeed(double avgSpeed);
    int getCalories() const;
    void setCalories(int calories);
    double getDistance() const;
    void setDistance(double distance);
    double getDuration() const;
    void setDuration(double duration);
    double getElevGain() const;
    void setElevGain(double elevGain);
    double getElevLoss() const;
    void setElevLoss(double elevLoss);
    int getLapNumber() const;
    void setLapNumber(int lapNumber);
    double getMaxCadence() const;
    void setMaxCadence(double maxCadence);
    double getMaxHeartRate() const;
    void setMaxHeartRate(double maxHeartRate);
    double getMaxSpeed() const;
    void setMaxSpeed(double maxSpeed);
    const QDateTime& getStartTime() const;
    void setStartTime(const QDateTime& startTime);
    double getStopped() const;
    void setStopped(double stopped);
    const QList<Trackpoint>& getTrackpoints() const;
    void setTrackpoints(const QList<Trackpoint>& trackpoints);
    int getId() const;
    void setId(int id);

private:
    int m_id;
    int m_lapNumber;
    QDateTime m_startTime;
    double m_distance;
    double m_duration;
    double m_stopped;
    double m_avgHeartRate;
    double m_maxHeartRate;
    double m_avgSpeed;
    double m_maxSpeed;
    double m_avgCadence;
    double m_maxCadence;
    double m_elevGain;
    double m_elevLoss;
    int m_calories;

    QList<Trackpoint> m_trackpoints;
};

#endif // LAP_H
