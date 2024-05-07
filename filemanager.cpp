#include "filemanager.h"

FileManager& FileManager::Single(QObject* parent = nullptr, std::vector<FileT*> file, std::vector<ILog*> log)
{
    static FileManager manager(parent, file, log);
    return manager;
}

FileManager::FileManager(QObject* parent = nullptr, std::vector<FileT*> file, std::vector<ILog*> log): QObject(parent)
{
    files = file;
    logs = log;
}

void FileManager::check()
{
    std::vector<FileEvent*> events;
    QDateTime now = QDateTime::currentDateTime();
    for (auto file: files)
    {
        if (file->exists()) // файл существует
        {
            if (now - file->lastModified() < 100) //ВРЕМЕННАЯ МЕРА!!!
            {
                FileEvent* t = new FileEvent(file->GetPath(), changed, file->size());
                events.push_back(t);
                file->Update();
            }
        }
        else // файл не существует
        {
            FileEvent* t = new FileEvent(file->GetPath(), not_exists, file->size());
            events.push_back(t);
            file->Update();
        }
    }
    for (auto logger: logs)
    {
        for (auto event: events)
        {
            logger->MessageBuilder(event);
        }
    }
}

