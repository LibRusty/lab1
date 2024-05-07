#ifndef CONSOLELOG_H
#define CONSOLELOG_H

#include "ILog.h"
#include <QObject>
#include <set>
#include <QTextStream>

std::set<State> full = {exists, not_exists, changed};

class ConsoleLog: public ILog
{
    std::set<State> included;
public:
    ConsoleLog(QObject* parent = nullptr, std::set<State> = full);

    virtual void MessageBuilder(FileEvent*) override;
    virtual void Logging(QString&) override;
};

#endif // CONSOLELOG_H
