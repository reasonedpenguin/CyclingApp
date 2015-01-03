#ifndef ACTIVITY_H
#define ACTIVITY_H

#include <QString>
#include <QVector>
#include <QImage>

#include "../gpsdata/Lap.h"


class Activity
{
public:
    Activity();

    bool isNull() const;
    qint64 getAthleteId() const;
    void setAthleteId(qint64 athleteId);
    double getAvgCadence() const;
    void setAvgCadence(double avgCadence);
    double getAvgHeartRate() const;
    void setAvgHeartRate(double avgHeartRate);
    double getAvgSpeed() const;
    void setAvgSpeed(double avgSpeed);
    int getCalories() const;
    void setCalories(int calories);
    const QString& getComments() const;
    void setComments(const QString& comments);
    double getDistance() const;
    void setDistance(double distance);
    double getDuration() const;
    void setDuration(double duration);
    double getElevGain() const;
    void setElevGain(double elevGain);
    double getElevLoss() const;
    void setElevLoss(double elevLoss);
    qint64 getId() const;
    void setId(qint64 id);
    double getMaxCadence() const;
    void setMaxCadence(double maxCadence);
    double getMaxHeartRate() const;
    void setMaxHeartRate(double maxHeartRate);
    double getMaxSpeed() const;
    void setMaxSpeed(double maxSpeed);
    const QImage& getPreview() const;
    void setPreview(const QImage& preview);
    qint64 getSportId() const;
    void setSportId(qint64 sportId);
    const QDateTime& getStartTime() const;
    void setStartTime(const QDateTime& startTime);
    double getStopped() const;
    void setStopped(double stopped);
    const QString& getTitle() const;
    void setTitle(const QString& title);
    const QVector<Lap>& getLaps() const;
    void setLaps(const QVector<Lap>& laps);

    const QString& getSource() const {
        return m_source;
    }

    void setSource(const QString& source) {
        m_source = source;
    }

private:
    qint64 m_id;
    QString m_title;
    qint64 m_sportId;
    qint64 m_athleteId;
    QString m_comments;
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
    QImage m_preview;

    QString m_source;
    QVector<Lap> m_laps;
};

#endif // ACTIVITY_H
