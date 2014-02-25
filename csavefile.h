#ifndef CSAVEFILE_H
#define CSAVEFILE_H
#include <QGraphicsScene>
#include <QPrinter>
#include <QPainter>

class CSaveFile
{
public:
    CSaveFile();
    bool SaveAll();
    bool AddFile(QGraphicsScene *graphic, QString txt);
private:
    QPainter p;
    QPrinter printer;
};

#endif // CSAVEFILE_H
