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
       if(wave->ReadingFile(ui->fileNameEdit->text().toStdString()))
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
    wave->CalculatingWaves();
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
        scene->addLine(first.sec * 10, - first.shift * 10, second.sec * 10, -second.shift * 10, pen);
        scene->addLine(first.sec * 10, -2, first.sec * 10, 2, axis);
    }
    scene->addLine( 0,- scene->height() , 0, scene->height(), axis);
    addLines(scene->height()/2, second.sec, axis, scene);

}

void MainWindow::addLines(int height, int width, QPen axis, QGraphicsScene* scene)
{
    for(int i(0); i < height; i+=10)
    {
        scene->addLine( 0, i, width * 10, i, axis);
        scene->addLine( 0, -i, width * 10, -i, axis);
    }
}
