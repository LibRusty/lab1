#include "filemanager.h"

std::vector<FileT*> nullfile{nullptr};

FileManager& FileManager::Single(std::vector<FileT*> file = nullfile, ILog* log = nullptr)
{
    static FileManager manager(file, log);
    return manager;
}

FileManager::FileManager(std::vector<FileT*> File, ILog* Log)
{
    std::set<QString> paths;
    for (int i = 0; i < File.size(); i++)
        if (paths.find(File[i]->GetPath()) == paths.end())
        {
            files.push_back(File[i]);
            paths.insert(File[i]->GetPath());
        }
    log = Log;
}

void FileManager::check()
{
    std::vector<FileEvent*> events;
    for (int i = 0; i < files.size(); i++)
    {
        if (files[i]->GetExist() != files[i]->exists(files[i]->GetPath())) // exist разный
        {
            if (files[i]->exists(files[i]->GetPath()))
            {
                QFileInfo f(files[i]->GetPath());
                FileEvent* t = new FileEvent(files[i]->GetPath(), FileEvent::exists, f.size());
                events.push_back(t);
                files[i]->Update();
            }
            else
            {
                FileEvent* t = new FileEvent(files[i]->GetPath(), FileEvent::not_exists, 0);
                events.push_back(t);
                files[i]->Update();
            }
        }
        else
        {
            if (files[i]->exists(files[i]->GetPath())) // файл существует, но изменен
            {
                QFileInfo f(files[i]->GetPath());
                if (files[i]->GetSize() != f.size())
                {
                    FileEvent* t = new FileEvent(files[i]->GetPath(), FileEvent::changed, f.size());
                    events.push_back(t);
                    files[i]->Update();
                }
            }
            else if (files[i]->exists(files[i]->GetPath()) != files[i]->GetExist()) // файл удален
            {
                FileEvent* t = new FileEvent(files[i]->GetPath(), FileEvent::deleted, 0);
                events.push_back(t);
                files[i]->Update();
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
