#include "csavefile.h"

CSaveFile::CSaveFile()
{
}

bool CSaveFile::AddFile(QGraphicsScene *scene)
{
    QPrinter printer(QPrinter::HighResolution);
           printer.setPageSize(QPrinter::A4);
           printer.setOrientation(QPrinter::Portrait);
           printer.setOutputFormat(QPrinter::PdfFormat);
           printer.setOutputFileName("test.pdf"); // file will be created in your build directory (where debug/release directories are)

           QPainter p;

           if(!p.begin(&printer))
           {
               return false;
           }
           scene->render(&p);
           p.end();}

bool CSaveFile::AddFile(QString txt)
{}

bool CSaveFile::SaveAll()
{}
