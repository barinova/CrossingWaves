#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon.png"));
    ui->lineZDCSign->setStyleSheet("QLineEdit{background: darkGray;}");
    ui->lineZDC->setStyleSheet("QLineEdit{background: lightGray;}");
    ui->lineZUCSign->setStyleSheet("QLineEdit{background: darkGray;}");
    ui->lineZUC->setStyleSheet("QLineEdit{background: lightGray;}");
    wave = new CCrossingWave();

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInputParametres()
{
    wave->clearAll();
    ui->tableWidget->clearContents();
    if(wave->readingFile(ui->fileNameEdit->text().toStdString()))
    {
        //table
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

        ui->tabWidget->setCurrentIndex(1);
        ui->calculateButton->setDisabled(true);

        param.type == 0 ? str = "ZDC" : str = "ZUC";
        //    str = "ZDC";
        //else
        //    str = "ZUC";

        ui->tableWidgetResults->setItem(i,0,new QTableWidgetItem(str));
        ui->tableWidgetResults->setItem(i,1,new QTableWidgetItem(QString::number(param.amplMax)));
        ui->tableWidgetResults->setItem(i,2,new QTableWidgetItem(QString::number(param.amplMin)));
        ui->tableWidgetResults->setItem(i,3,new QTableWidgetItem(QString::number(param.totalHeight)));
        ui->tableWidgetResults->setItem(i,4,new QTableWidgetItem(QString::number(param.nullPoint[0]) + ";" + QString::number(param.nullPoint[2])));
        ui->tableWidgetResults->setItem(i,5,new QTableWidgetItem(QString::number(param.verticalAsummetry)));
        ui->tableWidgetResults->setItem(i,6,new QTableWidgetItem(QString::number(param.horizontalAsymmetry)));
    }

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

        scene->addLine(first.sec * 7, - first.shift * 40, second.sec * 7, -second.shift * 40, pen);
        scene->addLine(first.sec * 7, -2, first.sec * 7, 2, axis);
    }
    //horizontal lines
    addHorizontalLines(scene->height()/2, second.sec, scene);
    addGraphicsAxis(scene,"x","h",- scene->height(), scene->height());
    renderingTroughsAndRidges(scene);
}

// already exists similar function - small lines
void MainWindow::addHorizontalLines(float height, float width, QGraphicsScene* scene)
{
    QPen pen;
    pen.setColor(Qt::lightGray);
    pen.setWidth(1);
    for(int i(0); i < height; i+=15)
    {
        scene->addLine( 0, i , width * 15 , i , pen);
        scene->addLine( 0, -i , width* 15 , -i , pen);
    }
}


void MainWindow::addGraphicsLittleLines(QGraphicsScene *scene, int delta, float scaleX, float scaleY,
                                        int yMin, int yMax)
{
    int width = scene->width() - 5;
    float tmp;

    //y
    for(float i(0); i < yMin; i+=delta)
    {
         QGraphicsTextItem* text = new QGraphicsTextItem;
         text->setScale(0.8);
         text->setDefaultTextColor(Qt::darkGray);
         text->setPos(0, - i);
         tmp = i/scaleY;
         text->setPlainText(QString::number(tmp));
         scene->addLine(0, - i , 2, - i);
         scene->addItem(text);
    }

    for(float i(0); i > yMax; i-=delta)
    {
         QGraphicsTextItem* text = new QGraphicsTextItem;
         text->setScale(0.8);
         text->setDefaultTextColor(Qt::darkGray);
         text->setPos(0, - i);
         tmp = i/scaleY;
         text->setPlainText(QString::number(tmp));
         scene->addLine(0, - i , 2, - i);
         scene->addItem(text);
    }

    //x
    for(int i(0); i < width; i+=delta)
    {
       QGraphicsTextItem* text = new QGraphicsTextItem;
        text->setScale(0.8);
        text->setDefaultTextColor(Qt::darkGray);
        text->setPos(i, 2);
        tmp = (float)i/scaleX;
        text->setPlainText(QString::number(tmp));
        scene->addLine(i, -1 , i, 1);
        scene->addItem(text);
    }
}


void MainWindow::addVerticalLines(QGraphicsScene *scene, QString label, int x, int y)
{
    QPen line;
    line.setColor(Qt::cyan);
    line.setWidth(0.8);
    scene->addLine(x, 0, x, - y, line);
    addText(scene, x, y, label, Qt::blue, 0.9);
}

void MainWindow::renderingTroughsAndRidges(QGraphicsScene* scene)
{
    waveEntity param;
    float ampl;
    for(int i(0); i < wave->calculatingWaves.size(); i++)
    {
        param =  wave->calculatingWaves.at(i);

        if(param.ridge < param.trough)
        {
            addVerticalLines(scene, QString::number(param.amplMax), param.ridge * 7, param.amplMax * 40);
        }
        else
        {
            addVerticalLines(scene, QString::number(param.amplMin), param.trough * 7,  param.amplMin * 40);
        }

        //remake
        if(i ==  wave->calculatingWaves.size() - 1)
        {
            param.ridge > param.trough ? ampl =  param.amplMax : ampl = param.amplMin;
            addVerticalLines(scene, QString::number(ampl), param.trough * 7,  ampl * 40);
        }
    }
}

void MainWindow::diagramHeights()
{
    waveEntity param;
    QGraphicsScene* scene;
    QPen pen;
    QGraphicsScene* sceneZDC = new QGraphicsScene(this);
    QGraphicsScene* sceneZUC = new QGraphicsScene(this);

    ui->graphicsViewZDC->setScene(sceneZDC);
    ui->graphicsViewZUC->setScene(sceneZUC);
    pen.setColor(Qt::red);
    pen.setWidth(2);

    for(int i(0); i < wave->calculatingWaves.size(); i++)
    {
        QGraphicsTextItem* text = new QGraphicsTextItem;
        param =  wave->calculatingWaves.at(i);

        param.type == ZDC ? scene = sceneZDC : scene = sceneZUC;

        addText(scene, i * 7 - 5, param.totalHeight * 20 + 15, QString::number(param.totalHeight), Qt::blue, 0.7);
        scene->addLine( i * 7, 0 , i * 7, - param.totalHeight * 20, pen);
        scene->addItem(text);
    }

    //0 - zdc
    ui->graphicsViewZDC->setSceneRect(0, 0, sceneZDC->width(), - sceneZDC->height()/2 - 10);
    ui->graphicsViewZUC->setSceneRect(0, 0, sceneZUC->width(), - sceneZUC->height()/2 - 10);


    addGraphicsAxis(sceneZDC, "H", "N", - ui->graphicsViewZDC->height(), ui->graphicsViewZDC->height());
    addGraphicsAxis(sceneZUC, "H", "N", - ui->graphicsViewZDC->height(), ui->graphicsViewZDC->height());

    addGraphicsOrtLine(sceneZDC,  wave->h.at(0).significantHeight * 20, X,Qt::darkGray, "significant height", 1);
    addGraphicsOrtLine(sceneZDC,  wave->h.at(0).heightOneThird * 20, X,Qt::lightGray, "height one third", 1);
    addGraphicsOrtLine(sceneZUC,  wave->h.at(1).significantHeight * 20, X,Qt::darkGray, "significant height", 1);
    addGraphicsOrtLine(sceneZUC,  wave->h.at(1).heightOneThird * 20, X,Qt::lightGray, "height one third", 1);
}


void MainWindow::renderingProbability()
{
    wave->setProbabilities();
    // 0 - ZDC, 1 - ZDC
    renderingProbabilityList(wave->listProbabilitiesZDC,ui->graphicsViewExceedingZDCTeorExper,
                             ui->graphicsViewExceedingZDCLogTeorExper,0);
    renderingProbabilityList(wave->listProbabilitiesZUC, ui->graphicsViewExceedingZUCTeorExper,
                             ui->graphicsViewExceedingZUCLogTeorExper, 1);
    ui->lineT->setStyleSheet("QLineEdit{background-color:#FF9F00;}");
    ui->lineE->setStyleSheet("QLineEdit{background-color:#66CCFF}");
    ui->lineT_2->setStyleSheet("QLineEdit{background-color:#FF9F00;}");
    ui->lineE_2->setStyleSheet("QLineEdit{background-color:#66CCFF}");
    //ui->graphicsViewExceedingZDCTeorExper->setSceneRect(0, 0, ui->graphicsViewExceedingZDCTeorExper->width(), - ui->graphicsViewExceedingZDCTeorExper->height()/2 - 10);
    //ui->graphicsViewExceedingZUCTeorExper->setSceneRect(0, 0, ui->graphicsViewExceedingZUCTeorExper->width(), - ui->graphicsViewExceedingZUCTeorExper->height()/2 - 10);
    //ui->graphicsViewExceedingZDCLogTeorExper->setSceneRect(0, 0, ui->graphicsViewExceedingZDCLogTeorExper->width(), ui->graphicsViewExceedingZDCLogTeorExper->height()/2 - 50);
    //ui->graphicsViewExceedingZUCLogTeorExper->setSceneRect(0, 0, ui->graphicsViewExceedingZUCLogTeorExper->width(), ui->graphicsViewExceedingZUCLogTeorExper->height()/2 - 50);
}

void MainWindow::renderingProbabilityList(QList<probability> list, QGraphicsView* graphTeorExper,
                                          QGraphicsView* graphTeorExperLog, int type)
{
    QGraphicsScene* sceneTeorExper = new QGraphicsScene(this);
    QGraphicsScene* sceneTeorExperLog = new QGraphicsScene(this);
    QPen penE, penT, penCr, penTr;
    float pExper, pTeor, signH, pCrest, pThrough;
    probability param;
    QList<float> prevTeor, prevTeorLog, prevExper, prevExperLog,
    prevCrest, prevCrestLog, prevThrough, prevThroughLog;

    //bind scenes
    graphTeorExper->setScene(sceneTeorExper);
    graphTeorExperLog->setScene(sceneTeorExperLog);
    qDebug("H   ExperP   TeorP\n");

    penE.setColor(QColor(0xFF, 0x9F, 0x00));
    penE.setWidth(2);
    penT.setColor(QColor(0x66, 0xCC, 0xFF));
    penT.setWidth(2);
    penCr.setColor(QColor(0x00, 0xFF, 0xCC));
    penCr.setWidth(2);
    penTr.setColor(QColor(0xFF, 0xCC, 0x00));
    penTr.setWidth(2);

    //addBigLables(sceneTeorExper, "Probability", 10, - 100, 2);
    //addBigLables(sceneTeorExperLog, "Probability",  10,  20, 2);
    //rendering graphics
    for(int i(0); i < list.size(); i++)
    {
        //if(i != list.size())
        //{
            signH = pow(wave->h.at(type).significantHeight, 2);
            param = list.at(i);
            pTeor = param.teorP;
            pExper = param.experP;
            pCrest = param.crestP;
            pThrough = param.troughP;
            qreal tmp, tmp2, tmp3;
            if(type == 0)
            {
                qDebug("%f %f %f\n", param.H, pExper, pTeor);
                tmp = param.H * 100;
                tmp2 = pExper * 100;
                tmp3 = pTeor * 100;
                qDebug("%f %f %f\n", tmp/100, tmp2/100, tmp3/100);
            }

        //}
        //else
        //{
        //    pTeor = 0;
        //    pExper = 0;
        //}
        getProbNormalGraph(sceneTeorExper, prevTeor, pTeor, param, penT);
        getProbLogGraph(sceneTeorExperLog, prevTeorLog, pTeor, param, penT);
        getProbNormalGraph(sceneTeorExper, prevExper, pExper, param, penE);
        getProbLogGraph(sceneTeorExperLog, prevExperLog, pExper, param, penE);
        getProbNormalGraph(sceneTeorExper, prevCrest, pCrest, param, penCr);
        getProbLogGraph(sceneTeorExperLog, prevCrestLog, pCrest, param, penCr);
        getProbNormalGraph(sceneTeorExper, prevThrough, pThrough, param, penTr);
        getProbLogGraph(sceneTeorExperLog, prevThroughLog, pThrough, param, penTr);

    }

    //sign axis
    addGraphicsAxis(sceneTeorExperLog, "H", "lg(P)", 0, sceneTeorExperLog->height());
    addGraphicsAxis(sceneTeorExper, "H", "P", - sceneTeorExper->height(), 0);

    addGraphicsLittleLines(sceneTeorExperLog, 25, 100, 100, 0, - sceneTeorExperLog->height());
    addGraphicsLittleLines(sceneTeorExper, 25, 100, 100, sceneTeorExper->height(),0);

    addBigLables(sceneTeorExper, "H", sceneTeorExper->width() - 5, 10, 1);
    addBigLables(sceneTeorExperLog, "H",sceneTeorExperLog->width() - 5, 10, 1);
    addBigLables(sceneTeorExper, "P", 10, - sceneTeorExper->height() + 5, 1);
    addBigLables(sceneTeorExperLog, "lg(p)", 10, sceneTeorExperLog->height() - 5, 1);
}

void MainWindow::addGraphicsAxis(QGraphicsScene *scene, QString strX, QString strY, int yMax, int yMin)
{
    //QGraphicsTextItem* textX = new QGraphicsTextItem;
    //QGraphicsTextItem* textY = new QGraphicsTextItem;

    scene->addLine(0, yMax, 0 , yMin);
    scene->addLine(0, 0, scene->width(), 0);

    //textY->setPos(2, - y - 5);
   // textY->setPlainText(strY);
    //scene->addItem(textY);

    //textX->setPos(scene->width() - 2, 0);
    //textX->setPlainText(strX);
    //scene->addItem(textX);
}

void MainWindow::getProbNormalGraph(QGraphicsScene* scene, QList<float> &prev, float p, probability param, QPen pen)
{
    if(prev.count() != 0)
    {
        scene->addLine(prev.at(0)* 100, - prev.at(1)* 100, param.H * 100, - p * 100, pen);
        scene->addEllipse(prev.at(0)* 100, -prev.at(1)* 100, 2, 2, QPen(),QBrush(Qt::SolidPattern));
    }
    else
    {
        scene->addLine(0, - p * 100, param.H * 100, - p * 100, pen);
        scene->addEllipse(0, 0, 2, 2, QPen(),QBrush(Qt::SolidPattern));
    }
    //scene->addEllipse(param.H * 100, - p * 100, 2, 2, QPen(),QBrush(Qt::SolidPattern));

    prev.clear();
    prev.append(param.H);
    prev.append(p);
}

void MainWindow::getProbLogGraph(QGraphicsScene* scene,QList<float> &prev, float p, probability param, QPen pen)
{
    if(prev.count()!=0)
    {
        scene->addLine(prev.at(0)* 100, - prev.at(1)* 100, param.H * 100, - log10((double)p) * 100, pen);
        scene->addEllipse(prev.at(0)* 100, - prev.at(1)* 100, 2, 2, QPen(),QBrush(Qt::SolidPattern));
    }
    else
    {
        scene->addLine(0, - log10((double)p) * 100, param.H * 100, - log10((double)p) * 100, pen);
        scene->addEllipse(0, 0, 2, 2, QPen(),QBrush(Qt::SolidPattern));
    }
    //scene->addEllipse(param.H * 100,  - log10((double)p) * 100, 2, 2, QPen(),QBrush(Qt::SolidPattern));
    prev.clear();
    prev.append(param.H);
    prev.append(log10((double)p));
}


void MainWindow::renderCloudsAsimetry()
{
    waveEntity param;
    float x, y;
    int delta(30);
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
            x = wave->h.at(0).heightOneThird;
            //sign(Xcr/Xtr-1)*(Xcr/Xtr)^(sign(Xcr/Xtr-1))
            y = sign(param.verticalAsummetry - 1) * pow(param.verticalAsummetry, sign(param.verticalAsummetry));
            sceneZDCVert->addEllipse(param.totalHeight/x * 400, - y * 10, 2.0, 2.0,
                                     QPen(), QBrush(Qt::SolidPattern));
            y = sign(param.horizontalAsymmetry - 1) * pow(param.horizontalAsymmetry, sign(param.horizontalAsymmetry));
            sceneZDCHor->addEllipse(param.totalHeight/x * 400, - y * 10, 2.0, 2.0,
                                            QPen(), QBrush(Qt::SolidPattern));
        }
        else
        {
            x = wave->h.at(1).heightOneThird;
            y = sign(param.verticalAsummetry - 1) * pow(param.verticalAsummetry, sign(param.verticalAsummetry));
            sceneZUCVert->addEllipse(param.totalHeight/x * 400, - y * 10, 2.0, 2.0,
                                            QPen(), QBrush(Qt::SolidPattern));
            y = sign(param.horizontalAsymmetry - 1) * pow(param.horizontalAsymmetry, sign(param.horizontalAsymmetry));
            sceneZUCHor->addEllipse(param.totalHeight/x * 400, - y * 10, 2.0, 2.0,
                                            QPen(), QBrush(Qt::SolidPattern));
        }
    }
    //переделать
    addGraphicsAxis(sceneZDCHor, "H/H(1/3)", "Lcr/Ltr - 1", - sceneZDCHor->height(), sceneZDCHor->height());
    addGraphicsAxis(sceneZUCHor, "H/H(1/3)", "Lcr/Ltr - 1", - sceneZUCHor->height(), sceneZUCHor->height());
    addGraphicsAxis(sceneZDCVert, "H/H(1/3)", "Acr/Atr - 1", - sceneZDCVert->height(), sceneZDCVert->height());
    addGraphicsAxis(sceneZUCVert, "H/H(1/3)", "Acr/Atr - 1", sceneZUCVert->height(), sceneZUCVert->height());

    addGraphicsLittleLines(sceneZDCHor, delta, 400, 10, - sceneZDCHor->height()/2, sceneZDCHor->height()/2);
    addGraphicsLittleLines(sceneZUCHor, delta, 400, 10, - sceneZUCHor->height()/2, sceneZUCHor->height()/2);
    addGraphicsLittleLines(sceneZDCVert, delta, 400, 10, - sceneZDCVert->height()/2, sceneZDCVert->height()/2);
    addGraphicsLittleLines(sceneZUCVert, delta, 400, 10, -sceneZUCVert->height()/2, sceneZUCVert->height()/2);
}

void MainWindow::addGraphicsOrtLine(QGraphicsScene *scene, int point, typeDelta delta, Qt::GlobalColor color, QString label, int width)
{
    //delta 0 - x, delta 1 - y
    QPen pen;
    pen.setColor(color);
    pen.setWidth(width);

    switch(delta)
    {
    case X:
        scene->addLine(0, - point, scene->width(), - point, pen);
        addText(scene, scene->width(), point, label, color, 0.9);
        break;
    case Y:
        scene->addLine( point, scene->height()/2, point, - scene->height()/2, pen);
        addText(scene, point, scene->height(), label, color, 0.9);
        break;
    }
 }

void MainWindow::addText(QGraphicsScene *scene, float x, float y, QString label, Qt::GlobalColor color, double size)
{
    QGraphicsTextItem* text = new QGraphicsTextItem;
    y > 0 ? text->setPos(x  + 1 , - y - 15) : text->setPos(x + 1 , - y + 5);
    text->setScale(size);
    text->setDefaultTextColor(color);
    text->setPlainText(label);
    scene->addItem(text);
}

void MainWindow::addBigLables(QGraphicsScene *scene, QString label, float x, float y, int size)
{
    QGraphicsTextItem* text = new QGraphicsTextItem;
    text->setScale(size);
    //text->setDefaultTextColor(color);
    text->setPlainText(label);
    text->setPos(x , y - 2);
    scene->addItem(text);
}

void MainWindow::on_buttonBrowse_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),"/path/to/file/",tr("DAT Files (*.dat)"));
    ui->fileNameEdit->setText(fileName);

    if(!ui->fileNameEdit->text().isNull())
    {
        setInputParametres();
    }
}
