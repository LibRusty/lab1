#include "ConsoleLog.h"

std::set<FileEvent::State> full = {FileEvent::exists, FileEvent::not_exists, FileEvent::changed, FileEvent::deleted};

ConsoleLog::ConsoleLog(QObject *parent = nullptr, std::set<FileEvent::State> incl = full): ILog(parent)
{
    included = incl;
}
ConsoleLog::ConsoleLog(QObject *parent = nullptr): ILog(parent)
{
    included = full;
}
void ConsoleLog::MessageBuilder(FileEvent* event)
{
    QString str;
    if (included.find(event->GetState()) != included.end())
    {
        switch(event->GetState())
        {
        case FileEvent::deleted:
            str = "File along path " + event->GetPath() + " deleted";
            break;
        case FileEvent::not_exists:
            str = "File along path " + event->GetPath() + " exists";
            break;
        case FileEvent::exists:
            str = "File along path " + event->GetPath() + " with size " + QString::number(event->GetSize()) + "exists";
            break;
        case FileEvent::changed:
            str = "File along path " + event->GetPath() + " with size " + QString::number(event->GetSize()) + "changed";
            break;
        }
        Logging(str);
    }
}

void ConsoleLog::Logging(QString& str)
{
    QTextStream txt_out(stdout);
    txt_out << str << "\n";
}
