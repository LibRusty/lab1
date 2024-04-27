#ifndef FILE_T_H
#define FILE_T_H
#include <QFileInfo>
#include <QFile>
#include <QString>

class FileT: public QObject, QFileInfo
{
    Q_OBJECT
protected:
    const QString Path;
    long long Size;
    bool Exist;
public:
    explicit FileT(const QString&); // для предотвращения неявных преобразований
    int GetSize();
    bool GetExist();

    void SetSize();
    void SetExist();

};
#endif // FILE_T_H
