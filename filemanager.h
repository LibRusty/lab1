#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "file_t.h"
#include "ConsoleLog.h"
#include <QTimer>

class FileManager: public QObject
{
    Q_OBJECT
public:
    static FileManager& Single(std::vector<FileT*>);

private:
    FileManager(std::vector<FileT*>);
    ~FileManager(){}


protected:
    std::vector<FileT*> files;
    std::vector<ILog*> logs;
    QTimer* timer;

};

#endif // FILEMANAGER_H
