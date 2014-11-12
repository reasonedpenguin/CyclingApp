#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>
#include <QVector>
#include "Lap.h"


class Activity
{
public:
    Activity();

    bool isNull();

    QString id() const;
    void setId(const QString &id);

    QString creator() const;
    void setCreator(const QString &creator);

    QString sport() const;
    void setSport(const QString &sport);

    double totalTime() const;
    void setTotalTime(double totalTime);

    double distance() const;
    void setDistance(double distance);

    double maxSpeed() const;
    void setMaxSpeed(double maxSpeed);

    int calories() const;
    void setCalories(int calories);

    int averageHeartRate() const;
    void setAverageHeartRate(int averageHeartRate);

    int maxHeartRate() const;
    void setMaxHeartRate(int maxHeartRate);

    int cadence() const;
    void setCadence(int cadence);

    QVector<Lap> & laps();
    void setLaps(const QVector<Lap> &laps);





private:
    QString m_id;
    QString m_creator;
    QString m_sport;
    double m_totalTime;
    double m_distance;
    double m_maxSpeed;
    int m_calories;
    int m_averageHeartRate;
    int m_maxHeartRate;
    int m_cadence;
    QVector<Lap> m_laps;
};

#endif // ACTIVITY_H
