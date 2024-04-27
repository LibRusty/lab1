#include "filemanager.h"

FileManager& FileManager::Single(std::vector<FileT*> file)
{
    static FileManager manager(file);
    return manager;
}

FileManager::FileManager(std::vector<FileT*> file)
{
    std::vector<FileT*> files;
    files.assign(file.begin(), file.end());
}

