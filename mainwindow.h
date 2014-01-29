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
    void addHorizontalLines(float height, float width, QGraphicsScene *scene);
    void renderingTroughsAndRidges(QGraphicsScene *scene);
    void addText(QGraphicsScene *scene, float x, float y, QString label, Qt::GlobalColor color, double size);
    void diagramHeights();
    void setTableWidgetResults();
    void renderingProbability();
    void renderingProbabilityList(QList<probability> list,QGraphicsView* graphTeorExper, QGraphicsView* graphTeorExperLog,int type);
    void getProbNormalGraph(QGraphicsScene* scene,QList<float> &prev, float p, probability param, QPen pen);
    void getProbLogGraph(QGraphicsScene* scene,QList<float> &prev, float p, probability param, QPen pen);
    void addGraphicsAxis(QGraphicsScene* scene, QString strX, QString strY, int y);
    void renderCloudsAsimetry();
    void addGraphicsLittleLines(QGraphicsScene* scene, int delta, double scaleX, double scaleY);
    void addGraphicsOrtLine(QGraphicsScene *scene, int point, typeDelta delta, Qt::GlobalColor color, QString label, int width);
    void addVerticalLines(QGraphicsScene* scene, QString label, int x, int y);
    template <typename T> int sign(T val);
};


template <typename T> int MainWindow::sign(T val) {
    return (T(0) < val) - (val < T(0));
}
#endif // MAINWINDOW_H
