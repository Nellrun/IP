#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "filereader.h"
#include "signalhandler.h"
#include "display.h"
#include "treemodel.h"
#include <QQmlDebuggingEnabler>

int main(int argc, char *argv[])
{
    qmlRegisterType<FileReader, 1>("FileReader", 1, 0, "FileReader");
//    qmlRegisterType<TreeModel, 1>("TreeModel", 1, 0, "TreeModel");

    QQmlDebuggingEnabler enabler;

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

//    TreeModel treemodel("Text");
//    engine.rootContext()->setContextProperty("myTreeModel",treemodel);

    engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    QObject* root = engine.rootObjects()[0];

    Display::setParent(root);

    SignalHandler* sh = new SignalHandler(root);
    QObject* leftMenu = root->findChild<QObject*>("leftMenu");

    QObject::connect(leftMenu, SIGNAL(runButtonClick()), sh, SLOT(onRunButtonClick()));

    return app.exec();
}
