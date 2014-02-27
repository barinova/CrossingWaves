#include "csavefile.h"

CSaveFile::CSaveFile()
{
    printer = new QPrinter();
    p = new QPainter();
    printer->setResolution(QPrinter::HighResolution);
    printer->setPageSize(QPrinter::A4);
    printer->setOrientation(QPrinter::Portrait);
    printer->setOutputFormat(QPrinter::PdfFormat);
    printer->setOutputFileName("CrossingWaves.pdf");
    p->begin(printer);
}

bool CSaveFile::AddFile(QGraphicsScene *scene, QString txt)
{
    p->scale(0.1, 0.1);
    p->drawText(3, 3, txt);
    p->save();
    p->scale(10, 10);
    if(scene != NULL) scene->render(p);
    printer->newPage();
 }

bool CSaveFile::SaveAll()
{
     p->end();
}
