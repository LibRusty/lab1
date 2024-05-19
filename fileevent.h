#ifndef FILEEVENT_H
#define FILEEVENT_H

#include <QString>

enum State
{
    exists,
    changed,
    not_exists,
    deleted
};

class FileEvent
{
    State state;
    QString path;
    int size;
public:
    FileEvent(const QString&, State, int);

    State GetState();
    QString GetPath();
    int GetSize();
};

#endif // FILEEVENT_H
