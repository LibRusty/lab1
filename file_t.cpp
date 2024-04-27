#include "file_t.h"

FileT::FileT(const QString &path)
{
    Path = path;
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

void FileT::SetSize()
{
    Size = this->size();
}

void FileT::SetExist()
{
    Exist = this->exists();
}
