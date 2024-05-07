#include "file_t.h"

FileT::FileT(QObject *parent, const QString &path): QObject(parent)
{
    this->Path = path;
    QFileInfo f(path);
    Size = static_cast<long long>(f.size()); // size() возвращает qint_64
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

void FileT::Update()
{
    Size = static_cast<long long>(this->size());
    Exist = this->exists();
}
