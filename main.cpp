#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "filereader.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<FileReader, 1>("FileReader", 1, 0, "FileReader");

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QLatin1String("qrc:/main.qml")));

    return app.exec();
}
