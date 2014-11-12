#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T16:28:05
#
#-------------------------------------------------
include(../common.pri)

QT       += testlib

QT       -= gui

TARGET = tst_importtest
CONFIG   += console
CONFIG   -= app_bundle

LIBS += -L../src -lcyclingapp

TEMPLATE = app


SOURCES += tst_importtest.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    tests.qrc
