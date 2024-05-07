#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "file_t.h"
#include "ConsoleLog.h"
#include "fileevent.h"
#include <QDateTime>


class FileManager: public QObject
{
    Q_OBJECT
public:
    static FileManager& Single(std::vector<FileT*>, std::vector<ILog*>);

private:
    FileManager(std::vector<FileT*>, std::vector<ILog*>);
    ~FileManager(){}

    std::vector<FileT*> files;
    std::vector<ILog*> logs;

public slots:
    void check();
};

#endif // FILEMANAGER_H
