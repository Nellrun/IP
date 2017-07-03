#include "display.h"
#include <QString>
#include <QVariant>

QObject* Display::parent = NULL;
Display* Display::instance = NULL;

Display::Display()
{

}

Display::Display(QObject *parent) {
    this->parent = parent;
}

void Display::printError(QString msg) {
    QObject* list = parent->findChild<QObject*>("errorModel");
    QVariant ret;
    QMetaObject::invokeMethod(list, "addNew", Q_RETURN_ARG(QVariant, ret), Q_ARG(QVariant, msg));
}

void Display::printError(std::string msg) {
    Display::printError(QString::fromStdString(msg));
}

void Display::printLine(QString line, int depth) {
    for (int i = 0; i < depth; i++) line = "\t" + line;

    QObject* textEdit = parent->findChild<QObject*>("outputTextEditor");

    QString text = textEdit->property("textEditorText").toString();
    text = text + line + "\n";
    textEdit->setProperty("textEditorText", text);
}

void Display::printLine(std::string line, int depth) {
    printLine(QString::fromStdString(line), depth);
}
