#include "csavefile.h"

CSaveFile::CSaveFile(bool typePDF)
{
	if (typePDF)
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
	else
	{

	}
}

bool CSaveFile::AddPDFFile(QGraphicsScene *scene, QString txt)
{
    p->scale(0.1, 0.1);
    p->drawText(3, 3, txt);
    p->save();
    p->scale(10, 10);
    if(scene != NULL) scene->render(p);
    printer->newPage();
    return true;
 }

bool CSaveFile::AddPNGFile(QGraphicsScene *scene, QString txt)
{
	QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
	QPainter painter(&image);
	scene->render(&painter);
	image.save("result" + txt + ".png");
    return true;
 }

bool CSaveFile::SaveAll()
{
     p->end();
     return true;
}
