#ifndef MATLABPROC_H
#define MATLABPROC_H
#include <QProcess>
#include <QMainWindow>
#include <QTimer>
#include <QDir>
#include <QMessageBox>
#include <QDebug>

class CMatLabProc: public QMainWindow
{
    Q_OBJECT
private:
    QProcess proc;
    enum State {IDLE, ERROR, CALC};
    State state;
    QFileInfoList listFiles;
    QString pathToMat, pathToFile, path, newPathToFileX, newPathToFileT, newPathToFileS;

public:
    CMatLabProc(QString pathToMat, QString pathToFile, QFileInfoList listFiles);
    bool start();
    bool stop();
    bool readFromMatlab();

private slots:
    void stream();
    void err();
    void openSlots();
};

#endif // MATLABPROC_H
