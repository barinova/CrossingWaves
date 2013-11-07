#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon.png"));
    wave = new CCrossingWave();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("DAT Files (*.dat)"));
    ui->fileNameEdit->setText(fileName);
}

void MainWindow::on_openButton_clicked()
{
    wave->calculatingWaves.clear();
    wave->parametres.clear();
    ui->tableWidget->clearContents();
   if(!ui->fileNameEdit->text().isNull())
   {
       if(wave->readingFile(ui->fileNameEdit->text().toStdString()))
       {
           for(int i(0); i < wave->parametres.size(); i++)
           {
                waveParametres param = wave->parametres.at(i);
                if(i > ui->tableWidget->rowCount() - 1)
                    ui->tableWidget->insertRow(i);
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(param.sec)));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(param.shift)));
           }
       }
       ui->calculateButton->setEnabled(true);
   }
}

void MainWindow::on_calculateButton_clicked()
{
    QString str;
    wave->calculateWaves();
    ui->tableWidgetResults->clearContents();
    for(int i(0); i < wave->calculatingWaves.size(); i++)
    {
        waveEntity param = wave->calculatingWaves.at(i);
        if(i > ui->tableWidgetResults->rowCount() - 1)
            ui->tableWidgetResults->insertRow(i);

        if(param.type == 0)
            str = "ZDC";
        else
            str = "ZUC";

        ui->tableWidgetResults->setItem(i,0,new QTableWidgetItem(str));
        ui->tableWidgetResults->setItem(i,1,new QTableWidgetItem(QString::number(param.amplMax)));
        ui->tableWidgetResults->setItem(i,2,new QTableWidgetItem(QString::number(param.amplMin)));
        ui->tableWidgetResults->setItem(i,3,new QTableWidgetItem(QString::number(param.totalHeight)));
        ui->tableWidgetResults->setItem(i,4,new QTableWidgetItem(QString::number(param.nullPoint[0]) + ";" + QString::number(param.nullPoint[2])));
        ui->tableWidgetResults->setItem(i,5,new QTableWidgetItem(QString::number(param.verticalAsummetry)));
        ui->tableWidgetResults->setItem(i,6,new QTableWidgetItem(QString::number(param.horizontalAsymmetry)));
    }
    ui->tabWidget->setCurrentIndex(1);
    ui->calculateButton->setDisabled(true);
    getGraph();
}

void MainWindow::getGraph()
{
    QGraphicsScene* scene = new QGraphicsScene(this);
    waveParametres first, second;
    QPen pen, axis;

    ui->graphicsView->setScene(scene);
    pen.setColor(Qt::red);
    pen.setWidth(2);
    axis.setColor(Qt::black);
    axis.setWidth(1);
    for(int i(0); i < wave->parametres.size() - 1; i++)
    {
        first = wave->parametres.at(i);
        second = wave->parametres.at(i+1);
        scene->addLine(first.sec * 40, - first.shift * 40, second.sec * 40, -second.shift * 40, pen);
        scene->addLine(first.sec * 40, -2, first.sec * 40, 2, axis);
    }
    scene->addLine( 0,- scene->height() , 0, scene->height(), axis);
    addLines(scene->height()/2, second.sec, axis, scene);

    renderingTroughsAndRidges(scene);
}

void MainWindow::addLines(float height, float width, QPen axis, QGraphicsScene* scene)
{
    for(int i(0); i < height; i+=10)
    {
        scene->addLine( 0, i * 40, width * 40, i * 40, axis);
        scene->addLine( 0, -i * 40, width * 40, -i * 40, axis);
    }
}

void MainWindow::addText(QGraphicsScene *scene, float x, float y)
{
    QGraphicsTextItem * text = new QGraphicsTextItem;
    text->setPos(x * 40 + 5 , - y * 40/1.5);
    text->adjustSize();
    text->setPlainText(QString::number(y));
    scene->addItem(text);
}

void MainWindow::renderingTroughsAndRidges(QGraphicsScene* scene)
{
    QPen line;
    waveEntity param;
    line.setColor(Qt::gray);
    line.setWidth(1);
    for(int i(0); i  < wave->calculatingWaves.size(); i++)
    {
        param =  wave->calculatingWaves.at(i);
        if(param.ridge > param.trough)
        {
            scene->addLine(param.ridge * 40, 0, param.ridge * 40 , - param.amplMax * 40, line);
            addText(scene, param.ridge, param.amplMax);
        }
        else
        {
            scene->addLine(param.trough * 40, 0, param.trough * 40, - param.amplMin * 40, line);
            addText(scene, param.trough, param.amplMin);
        }
    }
}
