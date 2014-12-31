PROJECT(src)

SET(src_SOURCES  Activity.cpp
    ActivityDB.cpp
    ActivityItem.cpp
    ActivityListModel.cpp
    GpsPosition.cpp
    IDataSource.cpp
    Lap.cpp
    TcxDataSource.cpp
    TcxWriter.cpp
    Trackpoint.cpp
    TreeItem.cpp
    qcustomplot.cpp)
    
SET(src_HEADERS Activity.h
    ActivityDB.h
    ActivityItem.h
    ActivityListModel.h
    src_global.h
    GpsPosition.h
    IDataSource.h
    Lap.h
    TcxDataSource.h
    TcxWriter.h
    Trackpoint.h
    qcustomplot.h)
    


QT4_WRAP_CPP(src_HEADERS_MOC ${src_HEADERS})
QT4_WRAP_UI(src_FORMS_HEADERS ${src_FORMS})
QT4_ADD_RESOURCES(src_RESOURCES_RCC ${src_RESOURCES})


ADD_LIBRARY(src ${src_SOURCES} 
    ${src_HEADERS_MOC}
    ${src_FORMS_HEADERS} 
    ${src_RESOURCES_RCC})
