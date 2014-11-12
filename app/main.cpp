#include "qtquick2controlsapplicationviewer.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

#include <QApplication>
#include <QUrl>
#include "MainWindow.h"


int main(int argc, char *argv[])
{
//    Application app(argc, argv);

//    QtQuick2ControlsApplicationViewer viewer;
//    viewer.setMainQmlFile(":qml/app/main.qml");
//    viewer.show();

//    QGuiApplication app(argc, argv);
//    QQmlApplicationEngine engine(QUrl(QStringLiteral("qrc:///qml/app/main.qml")));
//    QObject *root = engine.rootObjects().at(0);
//    QQuickWindow *window = qobject_cast<QQuickWindow *>(root);
//    if (!window) {
//        qFatal("Error: No window found!");
//    }
//    window->show();

    QApplication app(argc,argv);
    app.setApplicationName("CyclingApp");
    app.setOrganizationName("Company Corp.");
//    app.setOrganizationDomain("company.net");

    MainWindow mainWindow;
    mainWindow.show();

    return app.exec();
}
