#include <QCoreApplication>
#include "filemanager.h"
#include <QTimer>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    std::set<State> b {changed};

    std::vector<FileT*> files{new FileT(&a, "1.txt"), new FileT(&a, "2.txt"), new FileT(&a, "3.txt"), new FileT(&a, "4.txt"), new FileT(&a, "5.txt")};
    std::vector<ILog*> logs{new ConsoleLog(&a), new ConsoleLog(&a, b)};

    FileManager& instance = FileManager::Single(files, logs);

    QTimer* timer = new QTimer(&a);
    timer->start(100);
    connect(timer, &QTimer::timeout, instance, &FileManager::check);


    return a.exec();
}
