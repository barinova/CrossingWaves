/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Thu 30. Jan 00:54:40 2014
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *calculateButton;
    QPushButton *openButton;
    QTableWidget *tableWidget;
    QPushButton *buttonBrowse;
    //QPushButton * buttonSave;
    QLineEdit *fileNameEdit;
    QWidget *tab_2;
    QTableWidget *tableWidgetResults;
    QWidget *tab_3;
    QGraphicsView *graphicsView;
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
    QWidget *tab_6;
    QGroupBox *groupBox;
    QGraphicsView *graphicsViewExceedingZDCLogTeorExper;
    QGraphicsView *graphicsViewExceedingZDCTeorExper;
    QGroupBox *groupBox_2;
    QGraphicsView *graphicsViewExceedingZUCTeorExper;
    QGraphicsView *graphicsViewExceedingZUCLogTeorExper;
    QLabel *label_13;
    QLabel *label_14;
    QLineEdit *lineT;
    QLineEdit *lineE;
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
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(924, 669);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(10, 0, 901, 621));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        calculateButton = new QPushButton(tab);
        calculateButton->setObjectName(QString::fromUtf8("calculateButton"));
        calculateButton->setEnabled(false);
        calculateButton->setGeometry(QRect(600, 10, 75, 23));
        openButton = new QPushButton(tab);
        openButton->setObjectName(QString::fromUtf8("openButton"));
        openButton->setGeometry(QRect(250, 40, 75, 23));
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
        tableWidget->setGeometry(QRect(340, 10, 241, 421));
        tableWidget->setMinimumSize(QSize(201, 0));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setColumnCount(2);
        buttonBrowse = new QPushButton(tab);
        buttonBrowse->setObjectName(QString::fromUtf8("browseButton"));
        buttonBrowse->setGeometry(QRect(250, 10, 75, 23));
        fileNameEdit = new QLineEdit(tab);
        fileNameEdit->setObjectName(QString::fromUtf8("fileNameEdit"));
        fileNameEdit->setGeometry(QRect(10, 10, 231, 20));
        tabWidget->addTab(tab, QString());
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
        tableWidgetResults->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        graphicsView = new QGraphicsView(tab_3);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 881, 341));
        graphicsView->setFrameShape(QFrame::StyledPanel);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tabWidget->addTab(tab_3, QString());
        //buttonSave = new QPushButton(tab_3);
        //buttonSave->setObjectName(QString::fromUtf8("buttonSave"));
        //buttonSave->setGeometry(QRect(10, 550, 75, 23));
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
        graphicsViewZDC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsViewZDC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsViewZUC = new QGraphicsView(tab_4);
        graphicsViewZUC->setObjectName(QString::fromUtf8("graphicsViewZUC"));
        graphicsViewZUC->setGeometry(QRect(10, 250, 731, 192));
        graphicsViewZUC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
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
        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        groupBox = new QGroupBox(tab_6);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(0, 0, 671, 301));
        graphicsViewExceedingZDCLogTeorExper = new QGraphicsView(groupBox);
        graphicsViewExceedingZDCLogTeorExper->setObjectName(QString::fromUtf8("graphicsViewExceedingZDCLogTeorExper"));
        graphicsViewExceedingZDCLogTeorExper->setGeometry(QRect(10, 160, 641, 131));
        graphicsViewExceedingZDCLogTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsViewExceedingZDCTeorExper = new QGraphicsView(groupBox);
        graphicsViewExceedingZDCTeorExper->setObjectName(QString::fromUtf8("graphicsViewExceedingZDCTeorExper"));
        graphicsViewExceedingZDCTeorExper->setGeometry(QRect(10, 20, 641, 131));
        graphicsViewExceedingZDCTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        groupBox_2 = new QGroupBox(tab_6);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 300, 671, 311));
        graphicsViewExceedingZUCTeorExper = new QGraphicsView(groupBox_2);
        graphicsViewExceedingZUCTeorExper->setObjectName(QString::fromUtf8("graphicsViewExceedingZUCTeorExper"));
        graphicsViewExceedingZUCTeorExper->setGeometry(QRect(10, 20, 641, 131));
        graphicsViewExceedingZUCTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsViewExceedingZUCLogTeorExper = new QGraphicsView(groupBox_2);
        graphicsViewExceedingZUCLogTeorExper->setObjectName(QString::fromUtf8("graphicsViewExceedingZUCLogTeorExper"));
        graphicsViewExceedingZUCLogTeorExper->setGeometry(QRect(10, 160, 641, 131));
        graphicsViewExceedingZUCLogTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_13 = new QLabel(tab_6);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(680, 10, 281, 16));
        label_14 = new QLabel(tab_6);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(680, 80, 281, 16));
        lineT = new QLineEdit(tab_6);
        lineT->setObjectName(QString::fromUtf8("lineT"));
        lineT->setGeometry(QRect(680, 40, 161, 2));
        lineT->setFrame(false);
        lineE = new QLineEdit(tab_6);
        lineE->setObjectName(QString::fromUtf8("lineE"));
        lineE->setGeometry(QRect(680, 110, 163, 2));
        lineE->setFrame(false);
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
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 924, 21));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Crossing Waves", 0));
        calculateButton->setText(QApplication::translate("MainWindow", "Calculate", 0));
        openButton->setText(QApplication::translate("MainWindow", "Open", 0));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Sec", 0));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Shift", 0));
        buttonBrowse->setText(QApplication::translate("MainWindow", "Browse", 0));
        //buttonSave->setText(QApplication::translate("MainWindow", "Save", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Input Parametres", 0));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetResults->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Type", 0));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetResults->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "A+", 0));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetResults->horizontalHeaderItem(2);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "A-", 0));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetResults->horizontalHeaderItem(3);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "H", 0));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidgetResults->horizontalHeaderItem(4);
        ___qtablewidgetitem6->setText(QApplication::translate("MainWindow", "Position", 0));
        QTableWidgetItem *___qtablewidgetitem7 = tableWidgetResults->horizontalHeaderItem(5);
        ___qtablewidgetitem7->setText(QApplication::translate("MainWindow", "Asymmetry(Vert)", 0));
        QTableWidgetItem *___qtablewidgetitem8 = tableWidgetResults->horizontalHeaderItem(6);
        ___qtablewidgetitem8->setText(QApplication::translate("MainWindow", "Asymmetry(Hor)", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Result Parametres", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Graph of Results", 0));
        label->setText(QApplication::translate("MainWindow", "-down-zero-crossing wave heights", 0));
        label_2->setText(QApplication::translate("MainWindow", "-up-zero-crossing wave heights", 0));
        label_3->setText(QApplication::translate("MainWindow", "Height 1/3", 0));
        label_4->setText(QApplication::translate("MainWindow", "Height 1/3", 0));
        label_5->setText(QApplication::translate("MainWindow", "Significant Height", 0));
        label_6->setText(QApplication::translate("MainWindow", "Significant Height", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Diagram", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "-down-zero-crossing waves", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "-up-zero-crossing waves", 0));
        label_13->setText(QApplication::translate("MainWindow", "teoretical exceedance probability", 0));
        label_14->setText(QApplication::translate("MainWindow", "experimental exceedance probability", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Probability distribution exceeding", 0));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "-down-zero-crossing waves", 0));
        label_9->setText(QApplication::translate("MainWindow", "Vertical Asymmetry", 0));
        label_11->setText(QApplication::translate("MainWindow", "Hoizontal Asymmetry", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "-up-zero-crossing waves", 0));
        label_10->setText(QApplication::translate("MainWindow", "Vertical Asymmetry", 0));
        label_12->setText(QApplication::translate("MainWindow", "Horizontal Asymmetry", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("MainWindow", "Clouds", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
