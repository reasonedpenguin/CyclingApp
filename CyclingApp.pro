TEMPLATE = subdirs
CONFIG += ordered
SUBDIRS = \
    src \
    app \
    tests

app.depends = src
tests.depends = src

# Please do not modify the following two lines. Required for deployment.
include(qtquick2controlsapplicationviewer/qtquick2controlsapplicationviewer.pri)
qtcAddDeployment()
