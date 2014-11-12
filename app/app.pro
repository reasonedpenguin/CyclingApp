# Add more folders to ship with the application, here
folder_01.source = qml/app
folder_01.target = qml
DEPLOYMENTFOLDERS = folder_01

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

include(../common.pri)
TEMPLATE = app


# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp
SOURCES += MainWindow.cpp
SOURCES += PlotWindow.cpp

HEADERS += MainWindow.h
HEADERS += PlotWindow.h

FORMS += forms/MainWindowBase.ui
FORMS += forms/PlotWindowBase.ui

LIBS += -L../src -lcyclingapp
# Installation path
# target.path =

# Please do not modify the following two lines. Required for deployment.
include(qtquick2controlsapplicationviewer/qtquick2controlsapplicationviewer.pri)
qtcAddDeployment()

RESOURCES += \
    app.qrc
