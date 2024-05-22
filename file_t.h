#ifndef FILE_T_H
#define FILE_T_H
#include <QFileInfo>
#include <QFile>


class FileT: public QObject, public QFileInfo
{
    Q_OBJECT
protected:
    QString Path;
    long long Size;
    bool Exist;
public:
    explicit FileT(QObject* parent, const QString&); // для предотвращения неявных преобразований
    int GetSize();
    bool GetExist();
    QString GetPath();

    void Update();
};
#endif // FILE_T_H
