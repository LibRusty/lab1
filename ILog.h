#ifndef ILOG_H
#define ILOG_H

#include <QString>
#include <QObject>
#include "fileevent.h"

class ILog: public QObject
{
public:
    ILog(QObject* parent = nullptr): QObject(parent){}

    virtual void Logging(QString&) = 0;
    virtual void MessageBuilder(FileEvent*) = 0;
};

#endif // ILOG_H
