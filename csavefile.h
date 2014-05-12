#ifndef CSAVEFILE_H
#define CSAVEFILE_H
#include <QtWidgets/QGraphicsScene>
#include <QtPrintSupport/QPrinter>
#include <QPainter>

class CSaveFile
{
public:
    CSaveFile(bool typePDF);
    bool SaveAll();
    bool AddPDFFile(QGraphicsScene *graphic, QString txt);
	bool AddPNGFile(QGraphicsScene *graphic, QString txt);
private:
    QPainter *p;
    QPrinter *printer;
};

#endif // CSAVEFILE_H
