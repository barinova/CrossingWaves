#include "cmatlabproc.h"
#include <iostream>

CMatLabProc::CMatLabProc(QString pathToMat, QString pathToFile, QFileInfoList listFiles)
{
    state = IDLE;
    pathToMat.replace(QChar('\\'), QChar('/'));
   // this->listFiles= listFiles;
    this->pathToMat = pathToMat;
    this->pathToFile = pathToFile;
    path = listFiles.at(0).filePath();
    qDebug() << this->pathToFile;
    qDebug() << this->pathToMat;
    openSlots();
    if(!start())
    {
        QMessageBox::critical(0, "Crossing Waves",
                                      QString("Sorry. An internal error occurred.\nCan't open file."));
    }
}

bool CMatLabProc::start()
{
    QDir dir;

    QString str = "\"" + pathToMat + "\"" + " -nodisplay -nosplash -nodesktop  -noconsole -r \"GetDataFromMat('"
            + dir.currentPath() + "\',\'" + path + "')\"";
    qDebug() << str;
    proc.start(str);

    if(proc.waitForStarted())
    {
        //proc.closeWriteChannel();
        return true;
    }
    return false;
}

bool CMatLabProc::stop()
{
    proc.terminate();
}

void CMatLabProc::openSlots()
{
    QObject::connect(&proc, SIGNAL(readyReadStandardOutput()), (QObject*)this, SLOT(stream()));
    QObject::connect(&proc, SIGNAL(readyReadStandardError()), (QObject*)this, SLOT(err()));
}

void CMatLabProc::stream()
{
    if (proc.canReadLine())
    {
         QByteArray data = proc.readAllStandardOutput();
         //read numbers from data
         if (data.end())
         {
             qDebug() << data;
             //proc.closeReadChannel(QProcess::StandardOutput);
             //proc.disconnect();
             //emit fin(data);
         }
    }


    //CReadingFile* file = new CReadingFile(newPathToFile);


    stop();
}

void CMatLabProc::err()
{
    if (proc.canReadLine())
    {
        QByteArray data = proc.readAllStandardError();
        proc.closeReadChannel(QProcess::StandardError);
        proc.disconnect();
        state = ERROR;
    }
}
