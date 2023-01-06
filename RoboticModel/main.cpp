#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlComponent>

#include "WorkheadSolver.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType< WorkheadSolver >("Workhead", 1, 0, "WorkheadSolver" );

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
