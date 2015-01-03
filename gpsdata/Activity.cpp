#include "../gpsdata/Activity.h"

#include <math.h>


Activity::Activity() :
    m_id(-1)
{
}

bool Activity::isNull() const
{
    return m_title.isNull();
}

//QVector<Lap> & Activity::laps()
//{
//    return m_laps;
//}
//

// TODO: the summing here might just be a TCX file thing.
void Activity::setLaps(const QVector<Lap> &laps)
{
    m_laps = laps;
    m_distance = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_distance += m_laps[i].getDistance();
    }

    m_duration = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_duration += m_laps[i].getDuration();
    }

    m_maxSpeed = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_maxSpeed = fmax(m_laps[i].getMaxSpeed(),m_maxSpeed);
    }

    m_calories = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_calories += m_laps[i].getCalories();
    }

    m_avgHeartRate = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_avgHeartRate += m_laps[i].getDuration()/m_duration * m_laps[i].getAvgHeartRate();
    }

    m_maxHeartRate = 0;
    for(int i=0;i<m_laps.size();++i) {
        m_maxHeartRate = fmax(m_laps[i].getMaxHeartRate(),m_maxHeartRate);
    }
}


qint64 Activity::getAthleteId() const {
    return m_athleteId;
}

void Activity::setAthleteId(qint64 athleteId) {
    m_athleteId = athleteId;
}

double Activity::getAvgCadence() const {
    return m_avgCadence;
}

void Activity::setAvgCadence(double avgCadence) {
    m_avgCadence = avgCadence;
}

double Activity::getAvgHeartRate() const {
    return m_avgHeartRate;
}

void Activity::setAvgHeartRate(double avgHeartRate) {
    m_avgHeartRate = avgHeartRate;
}

double Activity::getAvgSpeed() const {
    return m_avgSpeed;
}

void Activity::setAvgSpeed(double avgSpeed) {
    m_avgSpeed = avgSpeed;
}

int Activity::getCalories() const {
    return m_calories;
}

void Activity::setCalories(int calories) {
    m_calories = calories;
}

const QString& Activity::getComments() const {
    return m_comments;
}

void Activity::setComments(const QString& comments) {
    m_comments = comments;
}

double Activity::getDistance() const {
    return m_distance;
}

void Activity::setDistance(double distance) {
    m_distance = distance;
}

double Activity::getDuration() const {
    return m_duration;
}

void Activity::setDuration(double duration) {
    m_duration = duration;
}

double Activity::getElevGain() const {
    return m_elevGain;
}

void Activity::setElevGain(double elevGain) {
    m_elevGain = elevGain;
}

double Activity::getElevLoss() const {
    return m_elevLoss;
}

void Activity::setElevLoss(double elevLoss) {
    m_elevLoss = elevLoss;
}

qint64 Activity::getId() const {
    return m_id;
}

void Activity::setId(qint64 id) {
    m_id = id;
}

double Activity::getMaxCadence() const {
    return m_maxCadence;
}

void Activity::setMaxCadence(double maxCadence) {
    m_maxCadence = maxCadence;
}

double Activity::getMaxHeartRate() const {
    return m_maxHeartRate;
}

void Activity::setMaxHeartRate(double maxHeartRate) {
    m_maxHeartRate = maxHeartRate;
}

double Activity::getMaxSpeed() const {
    return m_maxSpeed;
}

void Activity::setMaxSpeed(double maxSpeed) {
    m_maxSpeed = maxSpeed;
}

const QImage& Activity::getPreview() const {
    return m_preview;
}

void Activity::setPreview(const QImage& preview) {
    m_preview = preview;
}

qint64 Activity::getSportId() const {
    return m_sportId;
}

void Activity::setSportId(qint64 sportId) {
    m_sportId = sportId;
}

const QDateTime& Activity::getStartTime() const {
    return m_startTime;
}

void Activity::setStartTime(const QDateTime& startTime) {
    m_startTime = startTime;
}

double Activity::getStopped() const {
    return m_stopped;
}

void Activity::setStopped(double stopped) {
    m_stopped = stopped;
}

const QString& Activity::getTitle() const {
    return m_title;
}

void Activity::setTitle(const QString& title) {
    m_title = title;
}

const QVector<Lap>& Activity::getLaps() const {
    return m_laps;
}

//void Activity::setLaps(const QVector<Lap>& laps) {
//    m_laps = laps;
//}
