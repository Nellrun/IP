#include "signalhandler.h"
#include "parser.h"
#include <QString>
#include <QVariant>

SignalHandler::SignalHandler(QObject *parent) : QObject(parent)
{

}

void SignalHandler::onRunButtonClick() {
    QObject* input = parent()->findChild<QObject*>("knowledgeBase");
    QObject* output = parent()->findChild<QObject*>("outputTextEditor");

    QString text = input->property("textEditorText").toString();

    Parser p(text.toStdString());
    std::vector<Statement*>* disj = p.parse();

    QString out = "";


    for (Statement* stat : *disj) {
        out += QString::fromStdString(stat->toString()) + '\n';
//        stat->toString();
    }

    output->setProperty("textEditorText", out);
}
