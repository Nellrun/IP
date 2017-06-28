#ifndef SIGNALHANDLER_H
#define SIGNALHANDLER_H

#include <QObject>

class SignalHandler : public QObject
{
    Q_OBJECT
public:
    explicit SignalHandler(QObject *parent = 0);

signals:

public slots:
    void onRunButtonClick();
};

#endif // SIGNALHANDLER_H
