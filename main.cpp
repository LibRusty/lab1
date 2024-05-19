#include <QCoreApplication>
#include "filemanager.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::vector<FileT*> files{new FileT(&a, "1.txt"), new FileT(&a, "2.txt"), new FileT(&a, "3.txt"), new FileT(&a, "4.txt"), new FileT(&a, "5.txt")};
    std::set<FileEvent::State> f = {FileEvent::changed};
    ILog* log = new ConsoleLog(&a, f);

    FileManager& s = FileManager::Single(files, log);

    QTimer* timer = new QTimer(&s);
    FileManager::connect(timer, &QTimer::timeout, &s, &FileManager::check);
    timer->start(100);

    return a.exec();
}
