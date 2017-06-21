#include "filereader.h"
#include <QFile>
#include <QTextStream>
#include <QUrl>

FileReader::FileReader(QObject *parent) : QObject(parent)
{

}


QString FileReader::read() {
    if (fSource.isEmpty()) {
        emit error("Source is empty");
        return QString();
    }

    QFile f(fSource.path());

    if (f.open(QIODevice::ReadOnly)) {
        QTextStream ts(&f);
        QString out = ts.readAll();
        f.close();
        return out;
    }
    else {
        emit error("Could't open a file");
        return QString();
    }
}
