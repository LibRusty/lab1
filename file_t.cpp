#include "file_t.h"

FileT::FileT(QObject *parent, const QString &path): QObject(parent)
{
    this->Path = path;
    QFileInfo f(path);
    Size = f.size();
    Exist = false;
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

void FileT::Update()
{
    QFileInfo f(Path);
    Size = f.size();
    Exist = f.exists();
}
