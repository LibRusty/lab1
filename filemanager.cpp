#include "filemanager.h"

std::vector<FileT*> nullfile{nullptr};

FileManager& FileManager::Single(std::vector<FileT*> file = nullfile, ILog* log = nullptr)
{
    static FileManager manager(file, log);
    return manager;
}

FileManager::FileManager(std::vector<FileT*> File, ILog* Log)
{
    files = File;
    log = Log;
}

void FileManager::check()
{
    std::vector<FileEvent*> events;
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->Turned())
        {
            if (files[i]->exists())
            {
                FileEvent* t = new FileEvent(files[i]->GetPath(), FileEvent::exists, files[i]->size());
                events.push_back(t);
                files[i]->Update();
            }
            else
            {
                FileEvent* t = new FileEvent(files[i]->GetPath(), FileEvent::not_exists, 0);
                events.push_back(t);
                files[i]->Update();
                files.erase(files.begin()+ i);
                i--;
            }
        }
        else
        {
            if (files[i]->exists()) // файл существует
            {
                if (files[i]->GetSize() != files[i]->size())
                {
                    FileEvent* t = new FileEvent(files[i]->GetPath(), FileEvent::changed, files[i]->size());
                    events.push_back(t);
                    files[i]->Update();
                }
            }
            else // файл удален
            {
                FileEvent* t = new FileEvent(files[i]->GetPath(), FileEvent::deleted, 0);
                events.push_back(t);
                files[i]->Update();
                files.erase(files.begin()+ i);
                i--;
            }
        }

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
