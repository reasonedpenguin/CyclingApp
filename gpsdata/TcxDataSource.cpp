#include "../gpsdata/TcxDataSource.h"

#include <QString>
#include <QFile>
#include <QDomDocument>
#include <QDomElement>
 #include <QDebug>




TcxDataSource::TcxDataSource()
{
}


Activity TcxDataSource::getActivityFromFile(const QString& filename)
{
    Activity activity;

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        qWarning() << tr("Cannot read file %1:\n%2.")
                             .arg(filename)
                             .arg(file.errorString());
        return activity;
    }

    //if (xbelTree->read(&file))
    //    statusBar()->showMessage(tr("File loaded"), 2000);

    QString errorStr;
    int errorLine;
    int errorColumn;
    QDomDocument domDocument;

    if (!domDocument.setContent(&file, true, &errorStr, &errorLine,
                                &errorColumn)) {
        qWarning() << tr("Parse error at line %1, column %2:\n%3")
                                 .arg(errorLine)
                                 .arg(errorColumn)
                                 .arg(errorStr);

        return activity;
    }


    QDomElement root = domDocument.documentElement();
    if (root.tagName() != "TrainingCenterDatabase") {
        qWarning() <<  tr("The file is not an TCX file.");

        return activity;
    }

    QDomElement child = root.firstChildElement("Activities");
    if(!child.isNull()) {
        // If there is more than one activity in a file, we look at the first one only.
        QDomElement activityChild = child.firstChildElement("Activity");
        if (!activityChild.isNull()) {
            activity = parseActivityElement(activityChild);
            //activityChild = activityChild.nextSiblingElement("Activity");
        }
    }


    return activity;
}

Activity TcxDataSource::parseActivityElement(QDomElement activityElement)
{
    QVector<Lap> laps;
    Activity activity;
    // TODO: figure out the sport id from the name
    QString sportName = activityElement.attribute("Sport","Unknown");
    activity.setSportId(-1);
    QDomElement element = activityElement.firstChildElement();
    while(!element.isNull()) {
        if(element.tagName() == QString("Id")) {
            activity.setTitle(element.text().trimmed());
        } else if(element.tagName() == QString("Creator")) {
            QString creator = element.firstChildElement("Name").text().trimmed();
            activity.setSource(creator);
        }
        else if(element.tagName() == QString("Lap")) {
            Lap lap = parseLapElement(element);
            if(!lap.isNull())
                laps.push_back(lap);
        }

        element = element.nextSiblingElement();
    }
    activity.setLaps(laps);
    return activity;
}


Lap TcxDataSource::parseLapElement(QDomElement lapElement)
{
    Lap lap;
    QDomElement element = lapElement.firstChildElement();
    while(!element.isNull()) {
        if(element.tagName() == QString("TotalTimeSeconds")) {
            lap.setDuration(element.text().trimmed().toDouble());
        } else if(element.tagName() == QString("DistanceMeters")) {
            lap.setDistance(element.text().trimmed().toDouble());
        } else if(element.tagName() == QString("MaximumSpeed")) {
            lap.setMaxSpeed(element.text().trimmed().toDouble());
        } else if(element.tagName() == QString("Calories")) {
            lap.setCalories(element.text().trimmed().toInt());
        } else if(element.tagName() == QString("AverageHeartRateBpm")) {
            lap.setAvgHeartRate(element.text().trimmed().toInt());
        } else if(element.tagName() == QString("MaximumHeartRateBpm")) {
            lap.setMaxHeartRate(element.text().trimmed().toInt());
        } else if(element.tagName() == QString("Cadence")) {
            lap.setAvgCadence(element.text().trimmed().toInt());
        }
        else if(element.tagName() == QString("Track")) {
            lap.setTrackpoints(parseTrackElement(element));
        }

        element = element.nextSiblingElement();
    }
    return lap;
}

QList<Trackpoint> TcxDataSource::parseTrackElement(QDomElement trackElement)
{
    QList<Trackpoint> tp_list;
    QDomElement element = trackElement.firstChildElement();
    while(!element.isNull()) {
        if(element.tagName() == QString("Trackpoint")) {
            Trackpoint tp;
            QDomElement trackValueElem = element.firstChildElement();
            while(!trackValueElem.isNull()) {
                if(trackValueElem.tagName() == QString("Time")) {
                    QDateTime time = QDateTime::fromString(trackValueElem.text().trimmed(),"yyyy-MM-ddTHH:mm:ss.zzzZ");
                    if(time.isNull())
                        time = QDateTime::fromString(trackValueElem.text().trimmed(),"yyyy-MM-ddTHH:mm:ssZ");
                    if(time.isNull())
                        qDebug() << "Could not parse time" << trackValueElem.text().trimmed();
                    tp.setTime(time);
                } else if(trackValueElem.tagName() == QString("Position")) {
                    QDomElement tmp = trackValueElem.firstChildElement("LatitudeDegrees");
                    if(!tmp.isNull())
                        tp.setLatitude(tmp.text().trimmed().toDouble());
                    tmp = trackValueElem.firstChildElement("LongitudeDegrees");
                    if(!tmp.isNull())
                        tp.setLatitude(tmp.text().trimmed().toDouble());
                } else if(trackValueElem.tagName() == QString("AltitudeMeters")) {
                    tp.setAltitude(trackValueElem.text().trimmed().toDouble());
                } else if(trackValueElem.tagName() == QString("DistanceMeters")) {
                    tp.setDistance(trackValueElem.text().trimmed().toDouble());
                } else if(trackValueElem.tagName() == QString("HeartRateBpm")) {
                    tp.setHeartRate(trackValueElem.text().trimmed().toInt());
                }
                // TODO: Add speed extension element.
//                else if(trackValueElem.tagName() == QString("Extensions")) {
//                    tp.setSpeed(trackValueElem.text().trimmed());
//                }
                trackValueElem = trackValueElem.nextSiblingElement();
            }
            tp_list.push_back(tp);
        }

        element = element.nextSiblingElement();
    }
    return tp_list;
}







