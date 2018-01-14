#include "signalhandler.h"
#include "parser.h"
#include <QString>
#include <QVariant>
#include "ip.h"

SignalHandler::SignalHandler(QObject *parent) : QObject(parent)
{

}

void SignalHandler::onRunButtonClick() {

//    Получение исходных данных
    QObject* input = parent()->findChild<QObject*>("knowledgeBase");
    QObject* input2 = parent()->findChild<QObject*>("targetStatements");
    QObject* output = parent()->findChild<QObject*>("outputTextEditor");

    QObject* list = parent()->findChild<QObject*>("errorModel");
//    QVariant ret;
    QMetaObject::invokeMethod(list, "clear");

    QString text = input->property("textEditorText").toString();
    QString targetStatemens = input2->property("textEditorText").toString();

    Parser p(text.toStdString());
    std::vector<StatementLambda*>* disj = p.parse();

    if (p.getErrorState()) return;

    Parser p2(targetStatemens.toStdString());
    std::vector<StatementLambda*>* target = p2.parse();

    if (p2.getErrorState()) return;

    QString out = "";


    for (StatementLambda* stat : *disj) {
        out += QString::fromStdString(stat->b->toString()) + '\n';
    }

    out += "----------------------------\n";

    for (StatementLambda* stat : *target) {
        out += QString::fromStdString(stat->b->toString()) + '\n' + '\n';
    }

    output->setProperty("textEditorText", out);

//    part_divide((*disj)[0], (*target)[0]);

//    divide(disj, (*target)[0]);
//    inference(disj, (*target)[0]);
    Step* root = conclusion(*disj, new Divisor((*target)[0]->b), 2, NULL);

}
