#ifndef CONSOLELOG_H
#define CONSOLELOG_H

#include "ILog.h"
#include <set>
#include <QTextStream>


class ConsoleLog: public ILog
{
    std::set<FileEvent::State> included;
public:
    ConsoleLog(QObject* parent, std::set<FileEvent::State>);
    ConsoleLog(QObject* parent);
    virtual void MessageBuilder(FileEvent*) override;
    virtual void Logging(QString&) override;
};

#endif // CONSOLELOG_H
