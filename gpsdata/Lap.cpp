#include "../gpsdata/Lap.h"

Lap::Lap()
{
}

bool Lap::isNull() const
{
    return m_duration <= 0 && m_distance <= 0;
}

double Lap::getAvgCadence() const {
    return m_avgCadence;
}

void Lap::setAvgCadence(double avgCadence) {
    m_avgCadence = avgCadence;
}

double Lap::getAvgHeartRate() const {
    return m_avgHeartRate;
}

void Lap::setAvgHeartRate(double avgHeartRate) {
    m_avgHeartRate = avgHeartRate;
}

double Lap::getAvgSpeed() const {
    return m_avgSpeed;
}

void Lap::setAvgSpeed(double avgSpeed) {
    m_avgSpeed = avgSpeed;
}

int Lap::getCalories() const {
    return m_calories;
}

void Lap::setCalories(int calories) {
    m_calories = calories;
}

double Lap::getDistance() const {
    return m_distance;
}

void Lap::setDistance(double distance) {
    m_distance = distance;
}

double Lap::getDuration() const {
    return m_duration;
}

void Lap::setDuration(double duration) {
    m_duration = duration;
}

double Lap::getElevGain() const {
    return m_elevGain;
}

void Lap::setElevGain(double elevGain) {
    m_elevGain = elevGain;
}

double Lap::getElevLoss() const {
    return m_elevLoss;
}

void Lap::setElevLoss(double elevLoss) {
    m_elevLoss = elevLoss;
}

int Lap::getLapNumber() const {
    return m_lapNumber;
}

void Lap::setLapNumber(int lapNumber) {
    m_lapNumber = lapNumber;
}

double Lap::getMaxCadence() const {
    return m_maxCadence;
}

void Lap::setMaxCadence(double maxCadence) {
    m_maxCadence = maxCadence;
}

double Lap::getMaxHeartRate() const {
    return m_maxHeartRate;
}

void Lap::setMaxHeartRate(double maxHeartRate) {
    m_maxHeartRate = maxHeartRate;
}

double Lap::getMaxSpeed() const {
    return m_maxSpeed;
}

void Lap::setMaxSpeed(double maxSpeed) {
    m_maxSpeed = maxSpeed;
}

const QDateTime& Lap::getStartTime() const {
    return m_startTime;
}

void Lap::setStartTime(const QDateTime& startTime) {
    m_startTime = startTime;
}

double Lap::getStopped() const {
    return m_stopped;
}

void Lap::setStopped(double stopped) {
    m_stopped = stopped;
}

const QList<Trackpoint>& Lap::getTrackpoints() const {
    return m_trackpoints;
}

void Lap::setTrackpoints(const QList<Trackpoint>& trackpoints) {
    m_trackpoints = trackpoints;
}

int Lap::getId() const {
    return m_id;
}

void Lap::setId(int id) {
    m_id = id;
}
