#ifndef CONSOLELOG_H
#define CONSOLELOG_H

#include "ILog.h"
#include <QObject>

class ConsoleLog: public QObject, ILog
{
public:
    void MessageBuilder(QString);
    virtual void Logging(QString) override;
};

#endif // CONSOLELOG_H
