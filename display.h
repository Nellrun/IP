#ifndef DISPLAY_H
#define DISPLAY_H

#include <QString>
#include <QObject>

class Display
{
public:
    Display();
    Display(QObject* parent);

    static Display* getInstance() {
        return instance;
    }

    static void setParent(QObject* p) {
        parent = p;
    }

    void printLine(std::string line, int depth = 0);
    void printLine(QString line, int depth = 0);

private:
    static Display* instance;
    static QObject* parent;
};

#endif // DISPLAY_H
