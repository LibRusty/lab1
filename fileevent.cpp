#include "fileevent.h"

FileEvent::FileEvent(const QString& p, State stat, int s)
{
    path = p;
    state = stat;
    size = s;
}

State FileEvent::GetState()
{
    return state;
}

QString FileEvent::GetPath()
{
    return path;
}

int FileEvent::GetSize()
{
    return size;
}
