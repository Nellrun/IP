#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QUrl>

class FileReader : public QObject
{
    Q_OBJECT
public:
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)

    explicit FileReader(QObject *parent = nullptr);

    Q_INVOKABLE QString read();

    QUrl source() { return fSource; }

signals:
    void sourceChanged(const QUrl &source);
    void error(const QString &msg);

public slots:
    void setSource(const QUrl &source) {fSource = source; }

private:
    QUrl fSource;
};

#endif // FILEREADER_H
