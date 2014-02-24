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
    bool AddFile(QGraphicsScene *graphic);
    bool AddFile(QString txt);
};

#endif // CSAVEFILE_H
