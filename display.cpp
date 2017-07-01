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
