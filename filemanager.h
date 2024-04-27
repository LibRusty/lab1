#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <vector>
#include "file_t.h"
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
};

#endif // FILEMANAGER_H
