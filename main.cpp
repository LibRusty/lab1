#include <QCoreApplication>
#include "filemanager.h"
#include <QTimer>
#include <iostream>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<FileT*> files{new FileT(&a, "C:/lab1/1.txt"), new FileT(&a, "C:/lab1/2.txt"), new FileT(&a, "C:/lab1/3.txt"), new FileT(&a, "C:/lab1/4.txt"), new FileT(&a, "C:/lab1/5.txt")};
    std::set<FileEvent::State> f = {FileEvent::changed};
    ILog* log = new ConsoleLog(&a);

    FileManager::Single(files, log).check();

    QTimer* timer = new QTimer(&FileManager::Single(files, log));

    FileManager::connect(timer, &QTimer::timeout, &FileManager::Single(files, log), &FileManager::check);
    timer->start(100);

    return a.exec();
}
