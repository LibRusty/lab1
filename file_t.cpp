#include "file_t.h"

FileT::FileT(QObject *parent, const QString &path): QObject(parent)
{
    this->Path = path;
    QFileInfo f(path);
    Size = f.size();
    Exist = f.exists();
}

int FileT::GetSize()
{
    return Size;
}

bool FileT::GetExist()
{
    return Exist;
}

QString FileT::GetPath()
{
    return Path;
}

bool FileT::Turned()
{
    return turn;
}

void FileT::Update()
{
    Size = this->size();
    Exist = this->exists();
    turn = false;
}
