#include "filemanager.h"

FileManager& FileManager::Single(std::vector<FileT*> file = nullfile, ILog* log = nullptr)
{
    static FileManager manager(file, log);
    return manager;
}

FileManager::FileManager(std::vector<FileT*> File, ILog* Log)
{
    files = File;
    log = Log;
    check();
}

void FileManager::check()
{
    std::vector<FileEvent*> events;
    for (auto file: files)
    {
        if (file->Turned())
        {
            if (file->exists())
            {
                FileEvent* t = new FileEvent(file->GetPath(), exists, file->size());
                events.push_back(t);
            }
            else
            {
                FileEvent* t = new FileEvent(file->GetPath(), not_exists, 0);
                events.push_back(t);
            }
        }
        else
        {
            if (file->exists()) // файл существует
            {
                if (file->GetSize() != file->size())
                {
                    FileEvent* t = new FileEvent(file->GetPath(), changed, file->size());
                    events.push_back(t);
                }
            }
            else // файл удален
            {
                FileEvent* t = new FileEvent(file->GetPath(), deleted, 0);
                events.push_back(t);
            }
        }
        file->Update();
    }
    if (log)
    {
        for (auto event: events)
        {
            log->MessageBuilder(event);
        }
    }
}

FileManager::~FileManager()
{
    delete log;
    for (auto file: files)
    {
        delete file;
    }
}
