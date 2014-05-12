#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/QGraphicsView>
#include "ccrossingwave.h"
#include <QtWidgets/QFileDialog>
#include <QPainter>
#include <QPointF>
#include <QtWidgets/QSystemTrayIcon>
#include <QtWidgets/QGraphicsTextItem>
#include <QDebug>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include "ui_mainwindow.h"
#include <math.h>
#include "csavefile.h"
#include "cmatlabproc.h"
#include <QtWidgets/QMessageBox>
//#include <QMouseEvent>
//#include <QWheelEvent>

enum typeDelta{ X, Y};

enum zoom { ZoomOut, ZoomOn};

enum tabName
{
    InputParametres = 0,
    ResultParametres,
    ResultsGraph,
    HeightsDiagram,
    HeightsProbability,
    Clouds
};


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    CCrossingWave *wave;
    ~MainWindow();

private slots:

    void on_buttonBrowse_M_clicked();
    void on_calculateButton_clicked();
    void on_buttonSaveAll_clicked(); 
    void on_buttonBrowse_clicked();

    void on_buttonZoomOutHeightsZUC_clicked();
    void on_buttonZoomOnHeightsZUC_clicked();
    void on_buttonZoomOutZDCLog_clicked();
    void on_buttonZoomOnZDCLog_clicked();
    void on_buttonZoomOutZDC_clicked();
    void on_buttonZoomOnZDC_clicked();
    void on_buttonZoomOutZUCLog_clicked();
    void on_buttonZoomOnZUCLog_clicked();
    void on_buttonZoomOutZUC_clicked();
    void on_buttonZoomOnZUC_clicked();
    void on_buttonZoomOutHeightsZDC_clicked();
    void on_buttonZoomOnHeightsZDC_clicked();
    void on_buttonZoomOut_clicked();
    void on_buttonZoomOn_clicked();


private:
    Ui::MainWindow *ui;
    void zoomEvent(QGraphicsView *graphic, zoom typeZoom);
    void getGraph();
    void setInputParametres();
    void addHorizontalLines(float height, float width, QGraphicsScene *scene);
    void renderingTroughsAndRidges(QGraphicsScene *scene);
    void addText(QGraphicsScene *scene, float x, float y, QString label, Qt::GlobalColor color, double size);
    void diagramHeights();
    void setTableWidgetResults();
    void renderingProbability();
    void renderingProbabilityList(QList<probability> list,QGraphicsView* graphTeorExper, QGraphicsView* graphTeorExperLog,int type);
    void getProbNormalGraph(QGraphicsScene* scene,QList<float> &prev, float p, probability param, QPen pen);
    void getProbLogGraph(QGraphicsScene* scene,QList<float> &prev, float p, probability param, QPen pen);
    void addGraphicsAxis(QGraphicsScene* scene, QString strX, QString strY, int yMax, int yMin);
    void renderCloudsAsimetry();
    void addGraphicsLittleLines(QGraphicsScene *scene, int delta, float scaleX, float scaleY, int yMax, int yMin);
    //void addGraphicsLittleLines(QGraphicsScene* scene, int delta, double scaleX, double scaleY);
    void addGraphicsOrtLine(QGraphicsScene *scene, int point, typeDelta delta, Qt::GlobalColor color, QString label, int width);
    void addVerticalLines(QGraphicsScene* scene, QString label, int x, int y);
    void addBigLables(QGraphicsScene *scene, QString label, float x, float y, int size);
     QFileInfoList contentList(QString fileName);
    template <typename T> int sign(T val);
};


template <typename T> int MainWindow::sign(T val) {
    return (T(0) < val) - (val < T(0));
}
#endif // MAINWINDOW_H
