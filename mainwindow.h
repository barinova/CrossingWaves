#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ccrossingwave.h"
#include <QFileDialog>
#include <QPainter>
#include <QPointF>
#include <QSystemTrayIcon>
#include <QGraphicsTextItem>
#include "ui_mainwindow.h"

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
    void addLines(float height, float width, QPen axis, QGraphicsScene *scene);
    void renderingTroughsAndRidges(QGraphicsScene *scene);
    void addText(QGraphicsScene *scene, float x, float y);
};

#endif // MAINWINDOW_H
