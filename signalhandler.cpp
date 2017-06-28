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

    QString text = input->property("textEditorText").toString();
    QString targetStatemens = input2->property("textEditorText").toString();

    Parser p(text.toStdString());
    std::vector<Statement*>* disj = p.parse();

    Parser p2(targetStatemens.toStdString());
    std::vector<Statement*>* target = p2.parse();

    QString out = "";


    for (Statement* stat : *disj) {
        out += QString::fromStdString(stat->toString()) + '\n';
    }

    out += "----------------------------\n";

    for (Statement* stat : *target) {
        out += QString::fromStdString(stat->toString()) + '\n';
    }

    out += "\nUnification:\n";

    for (Statement* tgt: *target) {
        for (Predicate* oP : *tgt->getPredicates())
            for (Statement* stat: *disj) {
                for (Predicate* p : *stat->getPredicates()) {
                    out += "\t" + QString::fromStdString(p->toString()) + " <-> " +
                            QString::fromStdString(oP->toString()) + " = " +
                            QString::fromStdString(unification(p, oP)->toString()) + "\n";
                }
            }
    }


    output->setProperty("textEditorText", out);
}
