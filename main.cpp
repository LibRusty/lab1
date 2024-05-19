#include <QCoreApplication>
#include "filemanager.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<FileT*> files{new FileT(&a, "1.txt"), new FileT(&a, "2.txt"), new FileT(&a, "3.txt"), new FileT(&a, "4.txt"), new FileT(&a, "5.txt")};
    ILog* log = new ConsoleLog(&a, full);

    FileManager::Single(files, log);

    QTimer* timer = new QTimer(&FileManager::Single(files, log));
    FileManager::connect(timer, &QTimer::timeout, &FileManager::Single(files, log), &FileManager::check);
    timer->start(100);

    return a.exec();
}
