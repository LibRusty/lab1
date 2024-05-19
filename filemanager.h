#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "file_t.h"
#include "ConsoleLog.h"
#include "fileevent.h"
#include <QDateTime>

std::vector<FileT*> nullfile{nullptr};

class FileManager: public QObject
{
    Q_OBJECT
public:
    static FileManager& Single(std::vector<FileT*>, ILog*);

    FileManager(const FileManager&) = delete;
    FileManager operator=(const FileManager&) = delete;

private:
    FileManager(std::vector<FileT*>, ILog*);
    ~FileManager();

    std::vector<FileT*> files;
    ILog* log;

public slots:
    void check();
};

#endif // FILEMANAGER_H
