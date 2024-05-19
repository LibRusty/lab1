#ifndef FILEEVENT_H
#define FILEEVENT_H

#include <QString>

class FileEvent
{
public:
    enum State
    {
        exists,
        changed,
        not_exists,
        deleted
    };

    FileEvent(const QString&, State, int);

    State GetState();
    QString GetPath();
    int GetSize();

private:
    State state;
    QString path;
    int size;
};

#endif // FILEEVENT_H
