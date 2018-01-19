#include "signalhandler.h"
#include "parser.h"
#include <QString>
#include <QVariant>
#include "display.h"
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
        std::vector<StatementLambda*>* disj;
        try {
            disj = p.parse();
        }
        catch (ParserAnalysisException e) {
            return;
        }

        if (p.getErrorState()) return;

        Parser p2(targetStatemens.toStdString());
        std::vector<StatementLambda*>* target;
        try {
             target = p2.parse();
        }
        catch (ParserAnalysisException e) {
            return;
        }

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

//        out += "Результирующие подстановки: \n";
//        output->setProperty("textEditorText", out);

        std::vector<Lambda*>* res = reconciliation(root);

        Display::getInstance()->printLine(QString(""));
        Display::getInstance()->printLine(QString("Результирующие подстановки:"));

        for (Lambda* l : *res) {
            Display::getInstance()->printLine(l->toString(), 0);
        }

}
