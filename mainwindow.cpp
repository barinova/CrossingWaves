#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon.png"));
    CDragDropMenu *dnd;
    dnd->getInstance(this);
    ui->lineZDCSign->setStyleSheet("QLineEdit{background: darkGray;}");
    ui->lineZDC->setStyleSheet("QLineEdit{background: lightGray;}");
    ui->lineZUCSign->setStyleSheet("QLineEdit{background: darkGray;}");
    ui->lineZUC->setStyleSheet("QLineEdit{background: lightGray;}");
    wave = new CCrossingWave();

    //connect(ui->buttonSave, SIGNAL(clicked()), this,
    //        SLOT(on_saveButton_clicked());

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
    addGraphicsAxis(scene,"x","h",scene->height());
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


void MainWindow::addGraphicsLittleLines(QGraphicsScene *scene, int delta, double scaleX, double scaleY)
{
    int height = scene->height()/2;
    int width = scene->width();
    float tmp;

    //y
    for(int i(- height); i < height; i+=delta)
    {
         QGraphicsTextItem* text = new QGraphicsTextItem;
         text->setScale(0.6);
         text->setDefaultTextColor(Qt::darkGray);
         text->setPos(2, - i);
         tmp = (float)i/scaleY;
         text->setPlainText(QString::number(floor(tmp*10)/10.0));
         scene->addLine(0, i , 2, i);
         scene->addItem(text);
    }

    //x
    for(int i(0); i < width; i+=delta)
    {
       QGraphicsTextItem* text = new QGraphicsTextItem;
        text->setScale(0.6);
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


    addGraphicsAxis(sceneZDC, "H", "N", ui->graphicsViewZDC->height());
    addGraphicsAxis(sceneZUC, "H", "N", ui->graphicsViewZDC->height());

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

    ui->graphicsViewExceedingZDCTeorExper->setSceneRect(0, 0, ui->graphicsViewExceedingZDCTeorExper->width(), - ui->graphicsViewExceedingZDCTeorExper->height()/2 - 10);
    ui->graphicsViewExceedingZUCTeorExper->setSceneRect(0, 0, ui->graphicsViewExceedingZUCTeorExper->width(), - ui->graphicsViewExceedingZUCTeorExper->height()/2 - 10);
    //ui->graphicsViewExceedingZDCLogTeorExper->setSceneRect(0, 0, ui->graphicsViewExceedingZDCLogTeorExper->width(), ui->graphicsViewExceedingZDCLogTeorExper->height()/2 - 50);
    //ui->graphicsViewExceedingZUCLogTeorExper->setSceneRect(0, 0, ui->graphicsViewExceedingZUCLogTeorExper->width(), ui->graphicsViewExceedingZUCLogTeorExper->height()/2 - 50);
}

void MainWindow::renderingProbabilityList(QList<probability> list, QGraphicsView* graphTeorExper,
                                          QGraphicsView* graphTeorExperLog, int type)
{
    QGraphicsScene* sceneTeorExper = new QGraphicsScene(this);
    QGraphicsScene* sceneTeorExperLog = new QGraphicsScene(this);
    QPen penE, penT;
    float pExper, pTeor, signH;
    probability param;
    QList<float> prevTeor, prevTeorLog, prevExper, prevExperLog;

    //bind scenes
    graphTeorExper->setScene(sceneTeorExper);
    graphTeorExperLog->setScene(sceneTeorExperLog);
    qDebug("H   ExperP   TeorP\n");

    penE.setColor(QColor(0xFF, 0x9F, 0x00));
    penT.setColor(QColor(0x66, 0xCC, 0xFF));
    //rendering graphics
    for(int i(0); i < list.size(); i++)
    {
        signH = pow(wave->h.at(type).significantHeight, 2);
        param = list.at(i);
        pTeor = param.teorP;
        pExper = param.P;
        if(type == 0) qDebug("%f %f %f\n", param.H, pExper, pTeor);

        getProbNormalGraph(sceneTeorExper, prevTeor, pTeor, param, penT);
        getProbLogGraph(sceneTeorExperLog, prevTeorLog, pTeor, param, penT);
        getProbNormalGraph(sceneTeorExper, prevExper, pExper, param, penE);
        getProbLogGraph(sceneTeorExperLog, prevExperLog, pExper, param, penE);
    }

    //sign axis
    addGraphicsAxis(sceneTeorExperLog, "H", "lg(P)", sceneTeorExperLog->height() + 20);
    addGraphicsAxis(sceneTeorExper, "H", "P", sceneTeorExper->height() + 20);

    addGraphicsLittleLines(sceneTeorExper, 10, 100, 50);
    addGraphicsLittleLines(sceneTeorExperLog, 10, 100, 50);
}

void MainWindow::addGraphicsAxis(QGraphicsScene *scene, QString strX, QString strY, int y)
{
    QGraphicsTextItem* textX = new QGraphicsTextItem;
    QGraphicsTextItem* textY = new QGraphicsTextItem;

    scene->addLine(0, - y, 0 , y);
    scene->addLine(0, 0, scene->width(), 0);

    textY->setPos(2, - y - 5);
    textY->setPlainText(strY);
    scene->addItem(textY);

    textX->setPos(scene->width() - 2, 0);
    textX->setPlainText(strX);
    scene->addItem(textX);
}

void MainWindow::getProbNormalGraph(QGraphicsScene* scene, QList<float> &prev, float p, probability param, QPen pen)
{
    if(prev.count() != 0)
    {
        scene->addLine(prev.at(0)* 100, - prev.at(1)* 50, param.H * 100, - p * 50, pen);
    }
    else
    {
        scene->addLine(0, - p * 50, param.H * 100, - p * 50, pen);
    }
    prev.clear();
    prev.append(param.H);
    prev.append(p);
}

void MainWindow::getProbLogGraph(QGraphicsScene* scene,QList<float> &prev, float p, probability param, QPen pen)
{
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

    addGraphicsAxis(sceneZDCHor, "H/H(1/3)", "Lcr/Ltr - 1", sceneZDCHor->height());
    addGraphicsAxis(sceneZUCHor, "H/H(1/3)", "Lcr/Ltr - 1", sceneZUCHor->height());
    addGraphicsAxis(sceneZDCVert, "H/H(1/3)", "Acr/Atr - 1", sceneZDCVert->height());
    addGraphicsAxis(sceneZUCVert, "H/H(1/3)", "Acr/Atr - 1", sceneZUCVert->height());

    addGraphicsLittleLines(sceneZDCHor, delta, 400, 10);
    addGraphicsLittleLines(sceneZUCHor, delta, 400, 10);
    addGraphicsLittleLines(sceneZDCVert, delta, 400, 10);
    addGraphicsLittleLines(sceneZUCVert, delta, 400, 10);
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

//void MainWindow::on_saveButton_clicked(int tabsIndex)
//{
//   QString tabName = tabName.at(i);
//   CSaveImg *img = new CSaveImg();
//   img->Save(i, ui->tab);
//}
