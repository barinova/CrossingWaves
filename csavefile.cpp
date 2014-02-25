#include "csavefile.h"

CSaveFile::CSaveFile()
{
    printer.setResolution(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOrientation(QPrinter::Portrait);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName("CrossingWaves.pdf");
    p.begin(&printer);
}

bool CSaveFile::AddFile(QGraphicsScene *scene, QString txt)
{
    QFont font;// = p.font() ;
    font.setPointSize(0.1);
    p.setFont(font);
    p.drawText(1, 1, txt);
     //if(!p.begin(&printer))
     //{
     //    return false;
     //}
     if(scene != NULL)

     scene->render(&p);

     printer.newPage();
 }

bool CSaveFile::SaveAll()
{
         p.end();
}
