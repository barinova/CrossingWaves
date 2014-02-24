#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ccrossingwave.h"
#include <QFileDialog>
#include <QPainter>
#include <QPointF>
#include <QSystemTrayIcon>
#include <QGraphicsTextItem>
#include <QDebug>
#include <QMenu>
#include <QMenuBar>
#include "ui_mainwindow.h"
#include <math.h>

enum typeDelta{ X, Y};

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
    void on_buttonBrowse_clicked();

    void on_calculateButton_clicked();

//    void on_saveButton_clicked(int tabsIndex);


private:
    Ui::MainWindow *ui;
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
    template <typename T> int sign(T val);
};


template <typename T> int MainWindow::sign(T val) {
    return (T(0) < val) - (val < T(0));
}
#endif // MAINWINDOW_H
