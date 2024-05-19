#include "ConsoleLog.h"

ConsoleLog::ConsoleLog(QObject *parent, std::set<State> incl): ILog(parent)
{
    included = incl;
}

void ConsoleLog::MessageBuilder(FileEvent* event)
{
    QString str;
    if (included.find(event->GetState()) != included.end())
    {
        if (event->GetState() != deleted || event->GetState() != not_exists)
            str = 'File along path ' + event->GetPath() + ' with size ' + event->GetSize() + event->GetState();
        else
            str = 'File along path ' + event->GetPath() + event->GetState();
        Logging(str);
    }
}

void ConsoleLog::Logging(QString& str)
{
    QTextStream txt_out(stdout);
    txt_out << str;
}
