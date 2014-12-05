#-------------------------------------------------
#
# Project created by QtCreator 2014-10-19T16:28:05
#
#-------------------------------------------------
include(../common.pri)

QT       += testlib

QT       -= gui

TARGET = cyclingapp_unittests
CONFIG   += console
CONFIG   -= app_bundle

LIBS += -L../src -lcyclingapp

TEMPLATE = app

HEADERS += \
    tst_importtest.h \
    tst_exporttest.h \
    #
    
SOURCES += \
    tst_importtest.cpp \
    tst_exporttest.cpp \
    main.cpp \
    #

DEFINES += SRCDIR=\\\"$$PWD/\\\"

RESOURCES += \
    tests.qrc
