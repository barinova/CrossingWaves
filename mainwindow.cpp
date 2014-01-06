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
                {
                    ui->tableWidget->insertRow(i);
                }
                ui->tableWidget->setItem(i,0,new QTableWidgetItem(QString::number(param.sec)));
                ui->tableWidget->setItem(i,1,new QTableWidgetItem(QString::number(param.shift)));
           }
       }
       ui->calculateButton->setEnabled(true);
   }
}

void MainWindow::on_calculateButton_clicked()
{

    wave->calculateWaves();
    setTableWidgetResults();
    getGraph();
    diagramHeights();
    renderingProbability();
    renderCloudsAsimetry();
}

void MainWindow::setTableWidgetResults()
{
    QString str;
    heights zdcH, zucH;
    waveEntity param;

    ui->tableWidgetResults->clearContents();
    for(int i(0); i < wave->calculatingWaves.size(); i++)
    {
       param = wave->calculatingWaves.at(i);
        if(i > ui->tableWidgetResults->rowCount() - 1)
        {
            ui->tableWidgetResults->insertRow(i);
        }

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
    if(wave->h.count() != 0)
    {
        zdcH = wave->h.at(0);
        zucH = wave->h.at(1);
        ui->textBrowserSignificantZDC->setText(QString::number(zdcH.heightOneThird));
        ui->textBrowserSignificantZUC->setText(QString::number(zucH.heightOneThird));
        ui->textBrowserSignificantZDCSign->setText(QString::number(zdcH.significantHeight));
        ui->textBrowserSignificantZUCSign->setText(QString::number(zucH.significantHeight));
    }
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
        scene->addLine(first.sec * 15, - first.shift * 40, second.sec * 15, -second.shift * 40, pen);
        scene->addLine(first.sec * 15, -2, first.sec * 15, 2, axis);
    }
    scene->addLine( 0,- scene->height() , 0, scene->height(), axis);
    addLines(scene->height()/2, second.sec, scene);

    renderingTroughsAndRidges(scene);
}

void MainWindow::addLines(float height, float width, QGraphicsScene* scene)
{
    QPen pen;
    pen.setColor(Qt::gray);
    pen.setWidth(1);
    for(int i(0); i < height; i+=20)
    {
        scene->addLine( 0, i , width * 15 , i , pen);
        scene->addLine( 0, -i , width* 15 , -i , pen);
    }
}

void MainWindow::addText(QGraphicsScene *scene, float x, float y)
{
    QGraphicsTextItem* text = new QGraphicsTextItem;
    if(y > 0)
        text->setPos(x * 15 + 1 , - y * 40 - 15);
    else
        text->setPos(x * 15 + 1 , - y * 40 + 5);
    text->scale(0.9, 0.9);
    text->setDefaultTextColor(Qt::blue);
    text->setPlainText(QString::number(y));
    scene->addItem(text);
}

void MainWindow::renderingTroughsAndRidges(QGraphicsScene* scene)
{
    QPen line;
    waveEntity param;
    line.setColor(Qt::yellow);
    line.setWidth(1);
    for(int i(0); i  < wave->calculatingWaves.size(); i++)
    {
        param =  wave->calculatingWaves.at(i);
        if(param.ridge < param.trough)
        {
            scene->addLine(param.ridge * 15, 0, param.ridge * 15 , - param.amplMax * 40, line);
            addText(scene, param.ridge, param.amplMax);
        }
        else
        {
            scene->addLine(param.trough * 15, 0, param.trough * 15, - param.amplMin * 40, line);
            addText(scene, param.trough, param.amplMin);
        }
        if(i ==  wave->calculatingWaves.size() - 1)
        {
            float ampl;
            if(param.ridge > param.trough ? ampl =  param.amplMax : ampl = param.amplMin);
            scene->addLine(param.trough * 15, 0, param.trough * 15, - ampl * 40, line);
            addText(scene, param.trough, ampl);
        }
    }
}

void MainWindow::diagramHeights()
{
    waveEntity param;
    QGraphicsScene* scene;
    QPen pen, axis;
    QGraphicsScene* sceneZDC = new QGraphicsScene(this);
    QGraphicsScene* sceneZUC = new QGraphicsScene(this);

    ui->graphicsViewZDC->setScene(sceneZDC);
    ui->graphicsViewZUC->setScene(sceneZUC);
    pen.setColor(Qt::red);
    pen.setWidth(2);
    axis.setColor(Qt::black);
    axis.setWidth(1);

    for(int i(0); i < wave->calculatingWaves.size(); i++)
    {

        QGraphicsTextItem* text = new QGraphicsTextItem;
        param =  wave->calculatingWaves.at(i);

        if(param.type == ZDC ? scene = sceneZDC : scene = sceneZUC);
        text->setPos( i * 7 - 5, - param.totalHeight * 20 - 15);
        text->scale( 0.7, 0.7);
        text->setDefaultTextColor(Qt::blue);
        text->setPlainText(QString::number(param.totalHeight));

        scene->addLine( i * 7, 0 , i * 7, - param.totalHeight * 20, pen);
        scene->addItem(text);
    }
    sceneZDC->addLine( 0 ,0 , sceneZDC->width(), 0, axis);
    sceneZUC->addLine( 0 ,0 , sceneZUC->width(), 0, axis);
}
void MainWindow::renderingProbability()
{
    wave->setProbabilities();
    // 0 - ZDC, 1 - ZDC
    renderingProbabilityList(wave->listProbabilitiesZDC,ui->graphicsViewExceedingZDCTeor, ui->graphicsViewExceedingZDCLogTeor,
                             ui->graphicsViewExceedingZDCExper, ui->graphicsViewExceedingZDCLogExper,0);
    renderingProbabilityList(wave->listProbabilitiesZUC, ui->graphicsViewExceedingZUCTeor, ui->graphicsViewExceedingZUCLogTeor,
                             ui->graphicsViewExceedingZUCExper, ui->graphicsViewExceedingZUCLogExper, 1);
}

void MainWindow::renderingProbabilityList(QList<probability> list,QGraphicsView* graphTeor, QGraphicsView* graphTeorLog,
                                          QGraphicsView* graphExper, QGraphicsView* graphExperLog, int type)
{
    QGraphicsScene* sceneTeor = new QGraphicsScene(this);
    QGraphicsScene* sceneLogTeor = new QGraphicsScene(this);
    QGraphicsScene* sceneExper = new QGraphicsScene(this);
    QGraphicsScene* sceneLogExper = new QGraphicsScene(this);

    QPen axis;
    float pExper, pTeor;
    probability param;
    QList<float> prevTeor, prevTeorLog, prevExper, prevExperLog;

    //bind scenes
    graphTeorLog->setScene(sceneLogTeor);
    graphTeor->setScene(sceneTeor);
    graphExperLog->setScene(sceneLogExper);
    graphExper->setScene(sceneExper);

    //rendering graphics
    for(int i(0); i < list.size(); i++)
    {
        param = list.at(i);
        pTeor = exp(-param.H * param.H/(8*wave->h.at(type).significantHeight));
        pExper = param.P;
        getProbNormalGraph(sceneTeor, prevTeor, pTeor, param);
        getProbLogGraph(sceneLogTeor, prevTeorLog, pTeor, param);
        getProbNormalGraph(sceneExper, prevExper, pExper, param);
        getProbLogGraph(sceneLogExper, prevExperLog, pExper, param);
    }

    //adding axis and text
    //sceneLogTeor->addLine(0, 0, sceneLogTeor->width(), 0, axis);
    //sceneTeor->addLine(0, 0, sceneTeor->width(), 0, axis);
    //sceneLogExper->addLine(0, 0, sceneLogExper->width(), 0, axis);
    //sceneExper->addLine(0, 0, sceneExper->width(), 0, axis);

   // sceneLogTeor->addLine(0, - 30, 0, 70, axis);
   // sceneTeor->addLine(0, - 70, 0, 30, axis);
   // sceneLogExper->addLine(0, - 30, 0, 70, axis);
   // sceneExper->addLine(0, - 70, 0, 30, axis);

    //sign axis
    addGraphicsAxis(sceneLogTeor, "H", "lg(P)", sceneLogTeor->height()/2 - 20);
    addGraphicsAxis(sceneTeor, "H", "P", sceneLogTeor->height()/2);
    addGraphicsAxis(sceneLogExper, "H", "lg(P)", sceneLogTeor->height()/2 - 20);
    addGraphicsAxis(sceneExper, "H", "P", sceneLogTeor->height()/2);

}

void MainWindow::addGraphicsAxis(QGraphicsScene *scene, QString strX, QString strY, int y)
{
    QGraphicsTextItem* textX = new QGraphicsTextItem;
    QGraphicsTextItem* textY = new QGraphicsTextItem;

    scene->addLine(0, - scene->height()/2, 0 , scene->height()/2);
    scene->addLine(0, 0, scene->width(), 0);

    textY->setPos(2, - y - 5);
    textY->setPlainText(strY);
    scene->addItem(textY);

    textX->setPos(scene->width() - 2, 0);
    textX->setPlainText(strX);
    scene->addItem(textX);
}

void MainWindow::getProbNormalGraph(QGraphicsScene* scene, QList<float> &prev, float p, probability param)
{
    QPen pen;
//    QGraphicsTextItem* text = new QGraphicsTextItem;
    if(prev.count()!=0)
    {
        scene->addLine(prev.at(0)* 50, - prev.at(1)* 50, param.H * 50, - p * 50, pen);
    }
    else
    {
        scene->addLine(0, - p * 50, param.H * 50, - p * 50, pen);
    }
    prev.clear();
    prev.append(param.H);
    prev.append(p);
}

void MainWindow::getProbLogGraph(QGraphicsScene* scene,QList<float> &prev, float p, probability param)
{
    QPen pen;
    if(prev.count()!=0)
    {
        scene->addLine(prev.at(0)* 50, - prev.at(1)* 50, param.H * 50, - log10((double)p) * 50, pen);
    }
    else
    {
        scene->addLine(0, - log10((double)p) * 50, param.H * 50, - log10((double)p) * 50, pen);
    }
    prev.clear();
    prev.append(param.H);
    prev.append(log10((double)p));
}


void MainWindow::renderCloudsAsimetry()
{
    waveEntity param;
    QGraphicsScene* sceneZDCVert = new QGraphicsScene(this);
    QGraphicsScene* sceneZDCHor = new QGraphicsScene(this);
    QGraphicsScene* sceneZUCVert = new QGraphicsScene(this);
    QGraphicsScene* sceneZUCHor = new QGraphicsScene(this);
    ui->graphicsViewCloudsZDCA->setScene(sceneZDCVert);
    ui->graphicsViewCloudsZDCL->setScene(sceneZDCHor);
    ui->graphicsViewCloudsZUCA->setScene(sceneZUCVert);
    ui->graphicsViewCloudsZUCL->setScene(sceneZUCHor);

    for(int i(0); i < wave->calculatingWaves.size(); i++)
    {
        param = wave->calculatingWaves.at(i);
        if(param.type == ZDC)
        {
            sceneZDCVert->addEllipse(param.totalHeight/(wave->h.at(0).heightOneThird) * 400, - (param.verticalAsummetry - 1) * 60, 2.0, 2.0,
                                            QPen(), QBrush(Qt::SolidPattern));
            sceneZDCHor->addEllipse(param.totalHeight/wave->h.at(0).heightOneThird * 400, - (param.horizontalAsymmetry - 1) * 60, 2.0, 2.0,
                                            QPen(), QBrush(Qt::SolidPattern));
        }
        else
        {
            sceneZUCVert->addEllipse(param.totalHeight/wave->h.at(0).heightOneThird * 400, - (param.verticalAsummetry - 1) * 60, 2.0, 2.0,
                                            QPen(), QBrush(Qt::SolidPattern));
            sceneZUCHor->addEllipse(param.totalHeight/wave->h.at(0).heightOneThird * 400, - (param.horizontalAsymmetry - 1) * 60, 2.0, 2.0,
                                            QPen(), QBrush(Qt::SolidPattern));
        }
    }

    addGraphicsAxis(sceneZDCHor, "H/H(1/3)", "Lcr/Ltr - 1", sceneZDCHor->height()/4);
    addGraphicsAxis(sceneZUCHor, "H/H(1/3)", "Lcr/Ltr - 1", sceneZUCHor->height()/4);
    addGraphicsAxis(sceneZDCVert, "H/H(1/3)", "Acr/Atr - 1", sceneZDCVert->height()/4);
    addGraphicsAxis(sceneZUCVert, "H/H(1/3)", "Acr/Atr - 1", sceneZUCVert->height()/4);

    addGraphicsLittleLines(sceneZDCHor);
    addGraphicsLittleLines(sceneZUCHor);
    addGraphicsLittleLines(sceneZDCVert);
    //addGraphicsLittleLines(sceneZUCVert);
}

void MainWindow::addGraphicsLittleLines(QGraphicsScene *scene)
{
    for(int i(0); i < scene->height()/4; i++)
    {
        if((int)scene->height()%10 == 0)
        {
            QGraphicsTextItem* text = new QGraphicsTextItem;
            text->scale(0.9, 0.9);
            text->setDefaultTextColor(Qt::gray);
            text->setPos(2, - i);
            text->setPlainText(QString::number(i/400));
            scene->addLine(0, i , 2, i);
            scene->addItem(text);
        }
    }

    for(int i(0); i < scene->width(); i++)
    {
        if((int)scene->height()%10 == 0)
        {
            QGraphicsTextItem* text = new QGraphicsTextItem;
            text->scale(0.9, 0.9);
            text->setDefaultTextColor(Qt::gray);
            text->setPos(i, 2);
            text->setPlainText(QString::number(i/70));
            scene->addLine(i, -1 , i, 1);
            scene->addItem(text);
        }
    }
}
