#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "playermodel.h"

#include <QtConcurrent/QtConcurrent>
#include <QFuture>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    PlayerModel playerModel;
    engine.rootContext()->setContextProperty("playerModel", &playerModel);
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    //QFuture<void> result = QtConcurrent::run ( RunPosServer );
    //result.waitForFinished();

    return app.exec();
}
