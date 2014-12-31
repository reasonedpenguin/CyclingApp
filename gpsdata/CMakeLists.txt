PROJECT(gpsdata)

SET(gpsdata_SOURCES  Activity.cpp
    ActivityDB.cpp
    ActivityItem.cpp
    ActivityListModel.cpp
    GpsPosition.cpp
    IDataSource.cpp
    Lap.cpp
    TcxDataSource.cpp
    TcxWriter.cpp
    Trackpoint.cpp
    TreeItem.cpp)
    
SET(gpsdata_HEADERS Activity.h
    ActivityDB.h
    ActivityItem.h
    ActivityListModel.h
    GpsPosition.h
    IDataSource.h
    Lap.h
    TcxDataSource.h
    TcxWriter.h
    Trackpoint.h)
    


QT4_WRAP_CPP(gpsdata_HEADERS_MOC ${gpsdata_HEADERS})
QT4_WRAP_UI(gpsdata_FORMS_HEADERS ${gpsdata_FORMS})
QT4_ADD_RESOURCES(gpsdata_RESOURCES_RCC ${gpsdata_RESOURCES})


ADD_LIBRARY(gpsdata ${gpsdata_SOURCES} 
    ${gpsdata_HEADERS_MOC}
    ${gpsdata_FORMS_HEADERS} 
    ${gpsdata_RESOURCES_RCC})
