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
#include "ui_mainwindow.h"
#include <math.h>

enum typeDelta{ X, Y};

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
    void on_browseButton_clicked();

    void on_openButton_clicked();

    void on_calculateButton_clicked();

private:
    Ui::MainWindow *ui;
    void getGraph();
    void addLines(float height, float width, QGraphicsScene *scene);
    void renderingTroughsAndRidges(QGraphicsScene *scene);
    void addText(QGraphicsScene *scene, float x, float y, QString label, Qt::GlobalColor color, double size);
    void diagramHeights();
    void setTableWidgetResults();
    void renderingProbability();
    void renderingProbabilityList(QList<probability> list, QGraphicsView *graphTeor, QGraphicsView *graphTeorLog, QGraphicsView *graphExper, QGraphicsView *graphExperLog, int type);
    void getProbNormalGraph(QGraphicsScene* scene,QList<float> &prev, float p, probability param);
    void getProbLogGraph(QGraphicsScene* scene,QList<float> &prev, float p, probability param);
    void addGraphicsAxis(QGraphicsScene* scene, QString strX, QString strY, int y);
    void renderCloudsAsimetry();
    void addGraphicsLittleLines(QGraphicsScene* scene);
    void addGraphicsOrtLine(QGraphicsScene *scene, int point, typeDelta delta, Qt::GlobalColor color, QString label, int width);
    template <typename T> int sign(T val);
};


#endif // MAINWINDOW_H
