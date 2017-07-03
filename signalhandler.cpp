#include "signalhandler.h"
#include "parser.h"
#include <QString>
#include <QVariant>
#include "ip.h"

SignalHandler::SignalHandler(QObject *parent) : QObject(parent)
{

}

void SignalHandler::onRunButtonClick() {
    QObject* input = parent()->findChild<QObject*>("knowledgeBase");
    QObject* input2 = parent()->findChild<QObject*>("targetStatements");
    QObject* output = parent()->findChild<QObject*>("outputTextEditor");

    QObject* list = parent()->findChild<QObject*>("errorModel");
//    QVariant ret;
    QMetaObject::invokeMethod(list, "clear");

    QString text = input->property("textEditorText").toString();
    QString targetStatemens = input2->property("textEditorText").toString();

    Parser p(text.toStdString());
    std::vector<Statement*>* disj = p.parse();

    if (p.getErrorState()) return;

    Parser p2(targetStatemens.toStdString());
    std::vector<Statement*>* target = p2.parse();

    if (p2.getErrorState()) return;

    QString out = "";


    for (Statement* stat : *disj) {
        out += QString::fromStdString(stat->toString()) + '\n';
    }

    out += "----------------------------\n";

    for (Statement* stat : *target) {
        out += QString::fromStdString(stat->toString()) + '\n' + '\n';
    }

    output->setProperty("textEditorText", out);

//    part_divide((*disj)[0], (*target)[0]);

//    divide(disj, (*target)[0]);
    inference(disj, (*target)[0]);
}
