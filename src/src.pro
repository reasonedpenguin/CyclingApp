#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T16:31:34
#
#-------------------------------------------------
include(../common.pri)

QT += core gui
greaterThan(QT_MAJOR_VERSION,4): QT += widgets printsupport

#CONFIG += static
TARGET = cyclingapp
TEMPLATE = lib

DEFINES += SRC_LIBRARY

SOURCES += \
    Activity.cpp \
    ActivityDB.cpp \
    ActivityItem.cpp \
    ActivityListModel.cpp \
    GpsPosition.cpp \
    IDataSource.cpp \
    Lap.cpp \
    TcxDataSource.cpp \
    TcxWriter.cpp \
    Trackpoint.cpp \
    TreeItem.cpp \
    qcustomplot.cpp \
    #

HEADERS +=\
    Activity.h \
    ActivityDB.h \
    ActivityItem.h \
    ActivityListModel.h \
    src_global.h \
    GpsPosition.h \
    IDataSource.h \
    Lap.h \
    TcxDataSource.h \
    TcxWriter.h \
    Trackpoint.h \
    qcustomplot.h \
    #
    
unix {
    target.path = /usr/lib
    INSTALLS += target
}
