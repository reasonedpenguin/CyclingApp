#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T16:31:34
#
#-------------------------------------------------
include(../common.pri)

QT += core gui
greaterThan(QT_MAJOR_VERSION,4): QT += widgets printsupport

CONFIG += static
TARGET = cyclingapp
TEMPLATE = lib

DEFINES += SRC_LIBRARY

SOURCES += \
    IDataSource.cpp \
    TcxDataSource.cpp \
    Activity.cpp \
    Lap.cpp \
    Trackpoint.cpp \
    GpsPosition.cpp \
    qcustomplot.cpp \
    ActivityListModel.cpp \
    TreeItem.cpp

HEADERS +=\
        src_global.h \
    IDataSource.h \
    TcxDataSource.h \
    Activity.h \
    Lap.h \
    Trackpoint.h \
    GpsPosition.h \
    qcustomplot.h \
    ActivityListModel.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
