/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri 28. Feb 01:15:21 2014
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QGroupBox>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QStatusBar>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QTextBrowser>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOpen;
    QAction *actionSave_All;
    QAction *actionAbout;
    QAction *actionExit;
    QAction *actionCalculate;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout_2;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *calculateButton;
    QTableWidget *tableWidget;
    QLineEdit *fileNameEdit;
    QPushButton *buttonBrowse;
    QPushButton *buttonSaveAll;
    QWidget *tab_2;
    QTableWidget *tableWidgetResults;
    QWidget *tab_3;
    QGraphicsView *graphicsView;
    QGroupBox *groupBoxZoom;
    QPushButton *buttonZoomOut;
    QPushButton *buttonZoomOn;
    QWidget *tab_4;
    QLabel *label;
    QLabel *label_2;
    QGraphicsView *graphicsViewZDC;
    QGraphicsView *graphicsViewZUC;
    QLabel *label_3;
    QLabel *label_4;
    QTextBrowser *textBrowserSignificantZDC;
    QTextBrowser *textBrowserSignificantZUC;
    QLabel *label_5;
    QLabel *label_6;
    QTextBrowser *textBrowserSignificantZDCSign;
    QTextBrowser *textBrowserSignificantZUCSign;
    QLineEdit *lineZDC;
    QLineEdit *lineZDCSign;
    QLineEdit *lineZUC;
    QLineEdit *lineZUCSign;
    QGroupBox *groupBoxZoomHeightsZDC;
    QPushButton *buttonZoomOutHeightsZDC;
    QPushButton *buttonZoomOnHeightsZDC;
    QGroupBox *groupBoxZoomHeightsZUC;
    QPushButton *buttonZoomOutHeightsZUC;
    QPushButton *buttonZoomOnHeightsZUC;
    QWidget *tab_6;
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QGroupBox *groupBox;
    QGraphicsView *graphicsViewExceedingZDCLogTeorExper;
    QGraphicsView *graphicsViewExceedingZDCTeorExper;
    QGroupBox *groupBoxZoomProbZDCLog;
    QPushButton *buttonZoomOutZDCLog;
    QPushButton *buttonZoomOnZDCLog;
    QGroupBox *groupBoxZoomProbZDC;
    QPushButton *buttonZoomOutZDC;
    QPushButton *buttonZoomOnZDC;
    QLabel *label_13;
    QLineEdit *lineE;
    QLineEdit *lineT;
    QLabel *label_14;
    QLabel *label_17;
    QLineEdit *lineCr;
    QLabel *label_18;
    QLineEdit *lineTr;
    QWidget *tab_8;
    QGroupBox *groupBox_2;
    QGraphicsView *graphicsViewExceedingZUCTeorExper;
    QGraphicsView *graphicsViewExceedingZUCLogTeorExper;
    QGroupBox *groupBoxZoomProbZUC;
    QPushButton *buttonZoomOutZUC;
    QPushButton *buttonZoomOnZUC;
    QGroupBox *groupBoxZoomProbZUCLog;
    QPushButton *buttonZoomOutZUCLog;
    QPushButton *buttonZoomOnZUCLog;
    QLabel *label_15;
    QLineEdit *lineE_2;
    QLineEdit *lineT_2;
    QLabel *label_16;
    QLineEdit *lineTr_2;
    QLabel *label_19;
    QLabel *label_20;
    QLineEdit *lineCr_2;
    QWidget *tab_5;
    QGroupBox *groupBox_3;
    QGraphicsView *graphicsViewCloudsZDCA;
    QGraphicsView *graphicsViewCloudsZDCL;
    QLabel *label_9;
    QLabel *label_11;
    QGroupBox *groupBox_4;
    QGraphicsView *graphicsViewCloudsZUCA;
    QGraphicsView *graphicsViewCloudsZUCL;
    QLabel *label_10;
    QLabel *label_12;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuOptions;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1117, 714);
        MainWindow->setMinimumSize(QSize(924, 0));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
        actionSave_All = new QAction(MainWindow);
        actionSave_All->setObjectName(QString::fromUtf8("actionSave_All"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionCalculate = new QAction(MainWindow);
        actionCalculate->setObjectName(QString::fromUtf8("actionCalculate"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        horizontalLayout_2 = new QHBoxLayout(centralWidget);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        calculateButton = new QPushButton(tab);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setEnabled(false);
        calculateButton->setGeometry(QRect(260, 30, 75, 23));
        tableWidget = new QTableWidget(tab);
        if (tableWidget->columnCount() < 2)
            tableWidget->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter|Qt::AlignCenter);
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(10, 30, 241, 421));
        tableWidget->setMinimumSize(QSize(201, 0));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setColumnCount(2);
        fileNameEdit = new QLineEdit(tab);
        fileNameEdit->setObjectName(QString::fromUtf8("fileNameEdit"));
        fileNameEdit->setGeometry(QRect(0, 0, 911, 20));
        fileNameEdit->setMaximumSize(QSize(16777214, 16777215));
        fileNameEdit->setDragEnabled(true);
        fileNameEdit->setReadOnly(true);
        buttonBrowse = new QPushButton(tab);
        buttonBrowse->setObjectName(QString::fromUtf8("buttonBrowse"));
        buttonBrowse->setEnabled(true);
        buttonBrowse->setGeometry(QRect(260, 60, 75, 23));
        buttonSaveAll = new QPushButton(tab);
        buttonSaveAll->setObjectName(QString::fromUtf8("buttonSaveAll"));
        buttonSaveAll->setGeometry(QRect(260, 90, 75, 23));
        tabWidget->addTab(tab, QString());
        buttonBrowse->raise();
        buttonSaveAll->raise();
        calculateButton->raise();
        tableWidget->raise();
        fileNameEdit->raise();
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tableWidgetResults = new QTableWidget(tab_2);
        if (tableWidgetResults->columnCount() < 7)
            tableWidgetResults->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetResults->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetResults->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetResults->setHorizontalHeaderItem(2, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetResults->setHorizontalHeaderItem(3, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidgetResults->setHorizontalHeaderItem(4, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableWidgetResults->setHorizontalHeaderItem(5, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableWidgetResults->setHorizontalHeaderItem(6, __qtablewidgetitem8);
        tableWidgetResults->setObjectName(QString::fromUtf8("tableWidgetResults"));
        tableWidgetResults->setGeometry(QRect(10, 10, 881, 581));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(tableWidgetResults->sizePolicy().hasHeightForWidth());
        tableWidgetResults->setSizePolicy(sizePolicy);
        tableWidgetResults->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        graphicsView = new QGraphicsView(tab_3);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(9, 9, 981, 431));
        graphicsView->setFrameShape(QFrame::StyledPanel);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBoxZoom = new QGroupBox(tab_3);
        groupBoxZoom->setObjectName(QString::fromUtf8("groupBoxZoom"));
        groupBoxZoom->setGeometry(QRect(1000, 10, 81, 51));
        buttonZoomOut = new QPushButton(groupBoxZoom);
        buttonZoomOut->setObjectName(QString::fromUtf8("buttonZoomOut"));
        buttonZoomOut->setGeometry(QRect(40, 20, 31, 23));
        buttonZoomOn = new QPushButton(groupBoxZoom);
        buttonZoomOn->setObjectName(QString::fromUtf8("buttonZoomOn"));
        buttonZoomOn->setGeometry(QRect(10, 20, 31, 23));
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        label = new QLabel(tab_4);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 10, 171, 16));
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 230, 161, 16));
        graphicsViewZDC = new QGraphicsView(tab_4);
        graphicsViewZDC->setObjectName(QString::fromUtf8("graphicsViewZDC"));
        graphicsViewZDC->setGeometry(QRect(10, 30, 731, 192));
        graphicsViewZDC->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsViewZDC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsViewZUC = new QGraphicsView(tab_4);
        graphicsViewZUC->setObjectName(QString::fromUtf8("graphicsViewZUC"));
        graphicsViewZUC->setGeometry(QRect(10, 250, 731, 201));
        graphicsViewZUC->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        graphicsViewZUC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(750, 30, 91, 21));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(750, 250, 91, 21));
        textBrowserSignificantZDC = new QTextBrowser(tab_4);
        textBrowserSignificantZDC->setObjectName(QString::fromUtf8("textBrowserSignificantZDC"));
        textBrowserSignificantZDC->setGeometry(QRect(750, 50, 81, 21));
        textBrowserSignificantZDC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZDC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZUC = new QTextBrowser(tab_4);
        textBrowserSignificantZUC->setObjectName(QString::fromUtf8("textBrowserSignificantZUC"));
        textBrowserSignificantZUC->setGeometry(QRect(750, 270, 81, 21));
        textBrowserSignificantZUC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZUC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(750, 80, 91, 21));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(750, 300, 91, 21));
        textBrowserSignificantZDCSign = new QTextBrowser(tab_4);
        textBrowserSignificantZDCSign->setObjectName(QString::fromUtf8("textBrowserSignificantZDCSign"));
        textBrowserSignificantZDCSign->setGeometry(QRect(750, 100, 81, 21));
        textBrowserSignificantZDCSign->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZDCSign->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZUCSign = new QTextBrowser(tab_4);
        textBrowserSignificantZUCSign->setObjectName(QString::fromUtf8("textBrowserSignificantZUCSign"));
        textBrowserSignificantZUCSign->setGeometry(QRect(750, 320, 81, 21));
        textBrowserSignificantZUCSign->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZUCSign->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lineZDC = new QLineEdit(tab_4);
        lineZDC->setObjectName(QString::fromUtf8("lineZDC"));
        lineZDC->setGeometry(QRect(840, 60, 51, 2));
        lineZDC->setFrame(false);
        lineZDCSign = new QLineEdit(tab_4);
        lineZDCSign->setObjectName(QString::fromUtf8("lineZDCSign"));
        lineZDCSign->setGeometry(QRect(840, 110, 51, 2));
        lineZDCSign->setFrame(false);
        lineZUC = new QLineEdit(tab_4);
        lineZUC->setObjectName(QString::fromUtf8("lineZUC"));
        lineZUC->setGeometry(QRect(840, 280, 51, 2));
        lineZUC->setFrame(false);
        lineZUCSign = new QLineEdit(tab_4);
        lineZUCSign->setObjectName(QString::fromUtf8("lineZUCSign"));
        lineZUCSign->setGeometry(QRect(840, 330, 51, 2));
        lineZUCSign->setFrame(false);
        groupBoxZoomHeightsZDC = new QGroupBox(tab_4);
        groupBoxZoomHeightsZDC->setObjectName(QString::fromUtf8("groupBoxZoomHeightsZDC"));
        groupBoxZoomHeightsZDC->setGeometry(QRect(750, 130, 81, 51));
        buttonZoomOutHeightsZDC = new QPushButton(groupBoxZoomHeightsZDC);
        buttonZoomOutHeightsZDC->setObjectName(QString::fromUtf8("buttonZoomOutHeightsZDC"));
        buttonZoomOutHeightsZDC->setGeometry(QRect(40, 20, 31, 23));
        buttonZoomOnHeightsZDC = new QPushButton(groupBoxZoomHeightsZDC);
        buttonZoomOnHeightsZDC->setObjectName(QString::fromUtf8("buttonZoomOnHeightsZDC"));
        buttonZoomOnHeightsZDC->setGeometry(QRect(10, 20, 31, 23));
        groupBoxZoomHeightsZUC = new QGroupBox(tab_4);
        groupBoxZoomHeightsZUC->setObjectName(QString::fromUtf8("groupBoxZoomHeightsZUC"));
        groupBoxZoomHeightsZUC->setGeometry(QRect(750, 350, 81, 51));
        buttonZoomOutHeightsZUC = new QPushButton(groupBoxZoomHeightsZUC);
        buttonZoomOutHeightsZUC->setObjectName(QString::fromUtf8("buttonZoomOutHeightsZUC"));
        buttonZoomOutHeightsZUC->setGeometry(QRect(40, 20, 31, 23));
        buttonZoomOnHeightsZUC = new QPushButton(groupBoxZoomHeightsZUC);
        buttonZoomOnHeightsZUC->setObjectName(QString::fromUtf8("buttonZoomOnHeightsZUC"));
        buttonZoomOnHeightsZUC->setGeometry(QRect(10, 20, 31, 23));
        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        tabWidget_2 = new QTabWidget(tab_6);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 1081, 631));
        tab_7 = new QWidget();
        tab_7->setObjectName(QString::fromUtf8("tab_7"));
        groupBox = new QGroupBox(tab_7);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 861, 591));
        graphicsViewExceedingZDCLogTeorExper = new QGraphicsView(groupBox);
        graphicsViewExceedingZDCLogTeorExper->setObjectName(QString::fromUtf8("graphicsViewExceedingZDCLogTeorExper"));
        graphicsViewExceedingZDCLogTeorExper->setGeometry(QRect(10, 320, 751, 261));
        graphicsViewExceedingZDCLogTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsViewExceedingZDCTeorExper = new QGraphicsView(groupBox);
        graphicsViewExceedingZDCTeorExper->setObjectName(QString::fromUtf8("graphicsViewExceedingZDCTeorExper"));
        graphicsViewExceedingZDCTeorExper->setGeometry(QRect(10, 20, 751, 281));
        graphicsViewExceedingZDCTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBoxZoomProbZDCLog = new QGroupBox(groupBox);
        groupBoxZoomProbZDCLog->setObjectName(QString::fromUtf8("groupBoxZoomProbZDCLog"));
        groupBoxZoomProbZDCLog->setGeometry(QRect(770, 530, 81, 51));
        buttonZoomOutZDCLog = new QPushButton(groupBoxZoomProbZDCLog);
        buttonZoomOutZDCLog->setObjectName(QString::fromUtf8("buttonZoomOutZDCLog"));
        buttonZoomOutZDCLog->setGeometry(QRect(40, 20, 31, 23));
        buttonZoomOnZDCLog = new QPushButton(groupBoxZoomProbZDCLog);
        buttonZoomOnZDCLog->setObjectName(QString::fromUtf8("buttonZoomOnZDCLog"));
        buttonZoomOnZDCLog->setGeometry(QRect(10, 20, 31, 23));
        groupBoxZoomProbZDC = new QGroupBox(groupBox);
        groupBoxZoomProbZDC->setObjectName(QString::fromUtf8("groupBoxZoomProbZDC"));
        groupBoxZoomProbZDC->setGeometry(QRect(770, 250, 81, 51));
        buttonZoomOutZDC = new QPushButton(groupBoxZoomProbZDC);
        buttonZoomOutZDC->setObjectName(QString::fromUtf8("buttonZoomOutZDC"));
        buttonZoomOutZDC->setGeometry(QRect(40, 20, 31, 23));
        buttonZoomOnZDC = new QPushButton(groupBoxZoomProbZDC);
        buttonZoomOnZDC->setObjectName(QString::fromUtf8("buttonZoomOnZDC"));
        buttonZoomOnZDC->setGeometry(QRect(10, 20, 31, 23));
        label_13 = new QLabel(tab_7);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(890, 90, 161, 16));
        lineE = new QLineEdit(tab_7);
        lineE->setObjectName(QString::fromUtf8("lineE"));
        lineE->setGeometry(QRect(890, 120, 163, 2));
        lineE->setFrame(false);
        lineT = new QLineEdit(tab_7);
        lineT->setObjectName(QString::fromUtf8("lineT"));
        lineT->setGeometry(QRect(890, 50, 161, 2));
        lineT->setFrame(false);
        label_14 = new QLabel(tab_7);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(890, 20, 181, 16));
        label_17 = new QLabel(tab_7);
        label_17->setObjectName(QString::fromUtf8("label_17"));
        label_17->setGeometry(QRect(890, 140, 181, 21));
        lineCr = new QLineEdit(tab_7);
        lineCr->setObjectName(QString::fromUtf8("lineCr"));
        lineCr->setGeometry(QRect(890, 180, 161, 2));
        lineCr->setFrame(false);
        label_18 = new QLabel(tab_7);
        label_18->setObjectName(QString::fromUtf8("label_18"));
        label_18->setGeometry(QRect(890, 200, 181, 31));
        lineTr = new QLineEdit(tab_7);
        lineTr->setObjectName(QString::fromUtf8("lineTr"));
        lineTr->setGeometry(QRect(890, 250, 161, 2));
        lineTr->setFrame(false);
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        groupBox_2 = new QGroupBox(tab_8);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 861, 591));
        graphicsViewExceedingZUCTeorExper = new QGraphicsView(groupBox_2);
        graphicsViewExceedingZUCTeorExper->setObjectName(QString::fromUtf8("graphicsViewExceedingZUCTeorExper"));
        graphicsViewExceedingZUCTeorExper->setGeometry(QRect(10, 20, 751, 281));
        graphicsViewExceedingZUCTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsViewExceedingZUCLogTeorExper = new QGraphicsView(groupBox_2);
        graphicsViewExceedingZUCLogTeorExper->setObjectName(QString::fromUtf8("graphicsViewExceedingZUCLogTeorExper"));
        graphicsViewExceedingZUCLogTeorExper->setGeometry(QRect(10, 320, 751, 261));
        graphicsViewExceedingZUCLogTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBoxZoomProbZUC = new QGroupBox(groupBox_2);
        groupBoxZoomProbZUC->setObjectName(QString::fromUtf8("groupBoxZoomProbZUC"));
        groupBoxZoomProbZUC->setGeometry(QRect(770, 250, 81, 51));
        buttonZoomOutZUC = new QPushButton(groupBoxZoomProbZUC);
        buttonZoomOutZUC->setObjectName(QString::fromUtf8("buttonZoomOutZUC"));
        buttonZoomOutZUC->setGeometry(QRect(40, 20, 31, 23));
        buttonZoomOnZUC = new QPushButton(groupBoxZoomProbZUC);
        buttonZoomOnZUC->setObjectName(QString::fromUtf8("buttonZoomOnZUC"));
        buttonZoomOnZUC->setGeometry(QRect(10, 20, 31, 23));
        groupBoxZoomProbZUCLog = new QGroupBox(groupBox_2);
        groupBoxZoomProbZUCLog->setObjectName(QString::fromUtf8("groupBoxZoomProbZUCLog"));
        groupBoxZoomProbZUCLog->setGeometry(QRect(770, 530, 81, 51));
        buttonZoomOutZUCLog = new QPushButton(groupBoxZoomProbZUCLog);
        buttonZoomOutZUCLog->setObjectName(QString::fromUtf8("buttonZoomOutZUCLog"));
        buttonZoomOutZUCLog->setGeometry(QRect(40, 20, 31, 23));
        buttonZoomOnZUCLog = new QPushButton(groupBoxZoomProbZUCLog);
        buttonZoomOnZUCLog->setObjectName(QString::fromUtf8("buttonZoomOnZUCLog"));
        buttonZoomOnZUCLog->setGeometry(QRect(10, 20, 31, 23));
        label_15 = new QLabel(tab_8);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(890, 90, 171, 16));
        lineE_2 = new QLineEdit(tab_8);
        lineE_2->setObjectName(QString::fromUtf8("lineE_2"));
        lineE_2->setGeometry(QRect(890, 120, 163, 2));
        lineE_2->setFrame(false);
        lineT_2 = new QLineEdit(tab_8);
        lineT_2->setObjectName(QString::fromUtf8("lineT_2"));
        lineT_2->setGeometry(QRect(890, 50, 161, 2));
        lineT_2->setFrame(false);
        label_16 = new QLabel(tab_8);
        label_16->setObjectName(QString::fromUtf8("label_16"));
        label_16->setGeometry(QRect(890, 20, 181, 16));
        lineTr_2 = new QLineEdit(tab_8);
        lineTr_2->setObjectName(QString::fromUtf8("lineTr_2"));
        lineTr_2->setGeometry(QRect(890, 250, 161, 2));
        lineTr_2->setFrame(false);
        label_19 = new QLabel(tab_8);
        label_19->setObjectName(QString::fromUtf8("label_19"));
        label_19->setGeometry(QRect(890, 200, 181, 31));
        label_20 = new QLabel(tab_8);
        label_20->setObjectName(QString::fromUtf8("label_20"));
        label_20->setGeometry(QRect(890, 140, 181, 21));
        lineCr_2 = new QLineEdit(tab_8);
        lineCr_2->setObjectName(QString::fromUtf8("lineCr_2"));
        lineCr_2->setGeometry(QRect(890, 180, 161, 2));
        lineCr_2->setFrame(false);
        tabWidget_2->addTab(tab_8, QString());
        tabWidget->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        groupBox_3 = new QGroupBox(tab_5);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 431, 581));
        graphicsViewCloudsZDCA = new QGraphicsView(groupBox_3);
        graphicsViewCloudsZDCA->setObjectName(QString::fromUtf8("graphicsViewCloudsZDCA"));
        graphicsViewCloudsZDCA->setGeometry(QRect(10, 40, 401, 251));
        graphicsViewCloudsZDCL = new QGraphicsView(groupBox_3);
        graphicsViewCloudsZDCL->setObjectName(QString::fromUtf8("graphicsViewCloudsZDCL"));
        graphicsViewCloudsZDCL->setGeometry(QRect(10, 320, 401, 251));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 20, 181, 16));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 300, 181, 16));
        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        groupBox_4->setGeometry(QRect(450, 10, 431, 581));
        graphicsViewCloudsZUCA = new QGraphicsView(groupBox_4);
        graphicsViewCloudsZUCA->setObjectName(QString::fromUtf8("graphicsViewCloudsZUCA"));
        graphicsViewCloudsZUCA->setGeometry(QRect(10, 40, 401, 251));
        graphicsViewCloudsZUCL = new QGraphicsView(groupBox_4);
        graphicsViewCloudsZUCL->setObjectName(QString::fromUtf8("graphicsViewCloudsZUCL"));
        graphicsViewCloudsZUCL->setGeometry(QRect(10, 320, 401, 251));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(10, 20, 181, 16));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 300, 181, 16));
        tabWidget->addTab(tab_5, QString());

        horizontalLayout_2->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1117, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QString::fromUtf8("menuFile"));
        menuOptions = new QMenu(menuBar);
        menuOptions->setObjectName(QString::fromUtf8("menuOptions"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuOptions->menuAction());
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave_All);
        menuFile->addAction(actionAbout);
        menuFile->addAction(actionExit);
        menuOptions->addAction(actionCalculate);

        retranslateUi(MainWindow);
        QObject::connect(actionExit, SIGNAL(triggered()), MainWindow, SLOT(close()));
        QObject::connect(actionOpen, SIGNAL(triggered()), buttonBrowse, SLOT(click()));
        QObject::connect(actionSave_All, SIGNAL(triggered()), buttonSaveAll, SLOT(click()));
        QObject::connect(actionCalculate, SIGNAL(triggered()), calculateButton, SLOT(click()));

        tabWidget->setCurrentIndex(4);
        tabWidget_2->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Crossing Waves", 0, QApplication::UnicodeUTF8));
        actionOpen->setText(QApplication::translate("MainWindow", "Open", 0, QApplication::UnicodeUTF8));
        actionSave_All->setText(QApplication::translate("MainWindow", "Save All", 0, QApplication::UnicodeUTF8));
        actionAbout->setText(QApplication::translate("MainWindow", "About", 0, QApplication::UnicodeUTF8));
        actionExit->setText(QApplication::translate("MainWindow", "Exit", 0, QApplication::UnicodeUTF8));
        actionCalculate->setText(QApplication::translate("MainWindow", "Calculate", 0, QApplication::UnicodeUTF8));
        calculateButton->setText(QApplication::translate("MainWindow", "Calculate", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Sec", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Shift", 0, QApplication::UnicodeUTF8));
        buttonBrowse->setText(QApplication::translate("MainWindow", "Browse", 0, QApplication::UnicodeUTF8));
        buttonSaveAll->setText(QApplication::translate("MainWindow", "Save All", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Input Parametres", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetResults->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Type", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetResults->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "A+", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetResults->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "A-", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetResults->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "H", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetResults->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Position", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetResults->horizontalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Asymmetry(Vert)", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetResults->horizontalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Asymmetry(Hor)", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Result Parametres", 0, QApplication::UnicodeUTF8));
        groupBoxZoom->setTitle(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        buttonZoomOut->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        buttonZoomOn->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Waves", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "-down-zero-crossing wave heights", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "-up-zero-crossing wave heights", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "Height 1/3", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Height 1/3", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "Significant Height", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "Significant Height", 0, QApplication::UnicodeUTF8));
        groupBoxZoomHeightsZDC->setTitle(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        buttonZoomOutHeightsZDC->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        buttonZoomOnHeightsZDC->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        groupBoxZoomHeightsZUC->setTitle(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        buttonZoomOutHeightsZUC->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        buttonZoomOnHeightsZUC->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Heights' Diagram", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("MainWindow", "-down-zero-crossing waves", 0, QApplication::UnicodeUTF8));
        groupBoxZoomProbZDCLog->setTitle(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        buttonZoomOutZDCLog->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        buttonZoomOnZDCLog->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        groupBoxZoomProbZDC->setTitle(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        buttonZoomOutZDC->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        buttonZoomOnZDC->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("MainWindow", "teoretical exceedance probability", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("MainWindow", "experimental exceedance probability", 0, QApplication::UnicodeUTF8));
        label_17->setText(QApplication::translate("MainWindow", "exceedance probability of wave height\n"
"(crest)", 0, QApplication::UnicodeUTF8));
        label_18->setText(QApplication::translate("MainWindow", "exceedance probability of wave height\n"
"(trough)", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "-down-zero-crossing waves", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "-up-zero-crossing waves", 0, QApplication::UnicodeUTF8));
        groupBoxZoomProbZUC->setTitle(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        buttonZoomOutZUC->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        buttonZoomOnZUC->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        groupBoxZoomProbZUCLog->setTitle(QApplication::translate("MainWindow", "Zoom", 0, QApplication::UnicodeUTF8));
        buttonZoomOutZUCLog->setText(QApplication::translate("MainWindow", "-", 0, QApplication::UnicodeUTF8));
        buttonZoomOnZUCLog->setText(QApplication::translate("MainWindow", "+", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("MainWindow", "teoretical exceedance probability", 0, QApplication::UnicodeUTF8));
        label_16->setText(QApplication::translate("MainWindow", "experimental exceedance probability", 0, QApplication::UnicodeUTF8));
        label_19->setText(QApplication::translate("MainWindow", "exceedance probability of wave height\n"
"(trough)", 0, QApplication::UnicodeUTF8));
        label_20->setText(QApplication::translate("MainWindow", "exceedance probability of wave height\n"
"(crest)", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "-up-zero-crossing waves", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Heights' Probability", 0, QApplication::UnicodeUTF8));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "-down-zero-crossing waves", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("MainWindow", "Vertical Asymmetry", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("MainWindow", "Hoizontal Asymmetry", 0, QApplication::UnicodeUTF8));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "-up-zero-crossing waves", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("MainWindow", "Vertical Asymmetry", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("MainWindow", "Horizontal Asymmetry", 0, QApplication::UnicodeUTF8));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Clouds", 0, QApplication::UnicodeUTF8));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0, QApplication::UnicodeUTF8));
        menuOptions->setTitle(QApplication::translate("MainWindow", "Options", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
