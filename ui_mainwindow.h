/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QAction>
#include <QApplication>
#include <QButtonGroup>
#include <QGraphicsView>
#include <QGroupBox>
#include <QHeaderView>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QStatusBar>
#include <QTabWidget>
#include <QTableWidget>
#include <QTextBrowser>
#include <QWidget>

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
    QPushButton *browseButton;
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
    QTabWidget *tabWidget_2;
    QWidget *tab_7;
    QGroupBox *groupBox;
    QGraphicsView *graphicsViewExceedingZDCLogTeorExper;
    QGraphicsView *graphicsViewExceedingZDCTeorExper;
    QLabel *label_13;
    QLineEdit *lineE;
    QLineEdit *lineT;
    QLabel *label_14;
    QWidget *tab_8;
    QGroupBox *groupBox_2;
    QGraphicsView *graphicsViewExceedingZUCTeorExper;
    QGraphicsView *graphicsViewExceedingZUCLogTeorExper;
    QLabel *label_15;
    QLineEdit *lineE_2;
    QLineEdit *lineT_2;
    QLabel *label_16;
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

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(("MainWindow"));
        MainWindow->resize(924, 714);
        MainWindow->setMinimumSize(QSize(924, 0));
        MainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(("tabWidget"));
        tabWidget->setGeometry(QRect(0, 0, 901, 671));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Rounded);
        tabWidget->setElideMode(Qt::ElideNone);
        tab = new QWidget();
        tab->setObjectName(("tab"));
        calculateButton = new QPushButton(tab);
        calculateButton->setObjectName(("calculateButton"));
        calculateButton->setEnabled(false);
        calculateButton->setGeometry(QRect(600, 10, 75, 23));
        openButton = new QPushButton(tab);
        openButton->setObjectName(("openButton"));
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
        tableWidget->setObjectName(("tableWidget"));
        tableWidget->setGeometry(QRect(340, 10, 241, 421));
        tableWidget->setMinimumSize(QSize(201, 0));
        tableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tableWidget->setColumnCount(2);
        browseButton = new QPushButton(tab);
        browseButton->setObjectName(("browseButton"));
        browseButton->setGeometry(QRect(250, 10, 75, 23));
        fileNameEdit = new QLineEdit(tab);
        fileNameEdit->setObjectName(("fileNameEdit"));
        fileNameEdit->setGeometry(QRect(10, 10, 231, 20));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(("tab_2"));
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
        tableWidgetResults->setObjectName(("tableWidgetResults"));
        tableWidgetResults->setGeometry(QRect(10, 10, 881, 581));
        tableWidgetResults->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(("tab_3"));
        graphicsView = new QGraphicsView(tab_3);
        graphicsView->setObjectName(("graphicsView"));
        graphicsView->setGeometry(QRect(10, 20, 881, 341));
        graphicsView->setFrameShape(QFrame::StyledPanel);
        graphicsView->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        tabWidget->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(("tab_4"));
        label = new QLabel(tab_4);
        label->setObjectName(("label"));
        label->setGeometry(QRect(10, 10, 171, 16));
        label_2 = new QLabel(tab_4);
        label_2->setObjectName(("label_2"));
        label_2->setGeometry(QRect(10, 230, 161, 16));
        graphicsViewZDC = new QGraphicsView(tab_4);
        graphicsViewZDC->setObjectName(("graphicsViewZDC"));
        graphicsViewZDC->setGeometry(QRect(10, 30, 731, 192));
        graphicsViewZDC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsViewZDC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsViewZUC = new QGraphicsView(tab_4);
        graphicsViewZUC->setObjectName(("graphicsViewZUC"));
        graphicsViewZUC->setGeometry(QRect(10, 250, 731, 201));
        graphicsViewZUC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsViewZUC->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_3 = new QLabel(tab_4);
        label_3->setObjectName(("label_3"));
        label_3->setGeometry(QRect(750, 30, 91, 21));
        label_4 = new QLabel(tab_4);
        label_4->setObjectName(("label_4"));
        label_4->setGeometry(QRect(750, 250, 91, 21));
        textBrowserSignificantZDC = new QTextBrowser(tab_4);
        textBrowserSignificantZDC->setObjectName(("textBrowserSignificantZDC"));
        textBrowserSignificantZDC->setGeometry(QRect(750, 50, 81, 21));
        textBrowserSignificantZDC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZDC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZUC = new QTextBrowser(tab_4);
        textBrowserSignificantZUC->setObjectName(("textBrowserSignificantZUC"));
        textBrowserSignificantZUC->setGeometry(QRect(750, 270, 81, 21));
        textBrowserSignificantZUC->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZUC->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        label_5 = new QLabel(tab_4);
        label_5->setObjectName(("label_5"));
        label_5->setGeometry(QRect(750, 80, 91, 21));
        label_6 = new QLabel(tab_4);
        label_6->setObjectName(("label_6"));
        label_6->setGeometry(QRect(750, 300, 91, 21));
        textBrowserSignificantZDCSign = new QTextBrowser(tab_4);
        textBrowserSignificantZDCSign->setObjectName(("textBrowserSignificantZDCSign"));
        textBrowserSignificantZDCSign->setGeometry(QRect(750, 100, 81, 21));
        textBrowserSignificantZDCSign->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZDCSign->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZUCSign = new QTextBrowser(tab_4);
        textBrowserSignificantZUCSign->setObjectName(("textBrowserSignificantZUCSign"));
        textBrowserSignificantZUCSign->setGeometry(QRect(750, 320, 81, 21));
        textBrowserSignificantZUCSign->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        textBrowserSignificantZUCSign->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        lineZDC = new QLineEdit(tab_4);
        lineZDC->setObjectName(("lineZDC"));
        lineZDC->setGeometry(QRect(840, 60, 51, 2));
        lineZDC->setFrame(false);
        lineZDCSign = new QLineEdit(tab_4);
        lineZDCSign->setObjectName(("lineZDCSign"));
        lineZDCSign->setGeometry(QRect(840, 110, 51, 2));
        lineZDCSign->setFrame(false);
        lineZUC = new QLineEdit(tab_4);
        lineZUC->setObjectName(("lineZUC"));
        lineZUC->setGeometry(QRect(840, 280, 51, 2));
        lineZUC->setFrame(false);
        lineZUCSign = new QLineEdit(tab_4);
        lineZUCSign->setObjectName(("lineZUCSign"));
        lineZUCSign->setGeometry(QRect(840, 330, 51, 2));
        lineZUCSign->setFrame(false);
        tabWidget->addTab(tab_4, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(("tab_6"));
        tabWidget_2 = new QTabWidget(tab_6);
        tabWidget_2->setObjectName(("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(0, 0, 881, 631));
        tab_7 = new QWidget();
        tab_7->setObjectName(("tab_7"));
        groupBox = new QGroupBox(tab_7);
        groupBox->setObjectName(("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 671, 591));
        graphicsViewExceedingZDCLogTeorExper = new QGraphicsView(groupBox);
        graphicsViewExceedingZDCLogTeorExper->setObjectName(("graphicsViewExceedingZDCLogTeorExper"));
        graphicsViewExceedingZDCLogTeorExper->setGeometry(QRect(10, 320, 641, 261));
        graphicsViewExceedingZDCLogTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsViewExceedingZDCTeorExper = new QGraphicsView(groupBox);
        graphicsViewExceedingZDCTeorExper->setObjectName(("graphicsViewExceedingZDCTeorExper"));
        graphicsViewExceedingZDCTeorExper->setGeometry(QRect(10, 20, 641, 281));
        graphicsViewExceedingZDCTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_13 = new QLabel(tab_7);
        label_13->setObjectName(("label_13"));
        label_13->setGeometry(QRect(680, 90, 281, 16));
        lineE = new QLineEdit(tab_7);
        lineE->setObjectName(("lineE"));
        lineE->setGeometry(QRect(680, 120, 163, 2));
        lineE->setFrame(false);
        lineT = new QLineEdit(tab_7);
        lineT->setObjectName(("lineT"));
        lineT->setGeometry(QRect(680, 50, 161, 2));
        lineT->setFrame(false);
        label_14 = new QLabel(tab_7);
        label_14->setObjectName(("label_14"));
        label_14->setGeometry(QRect(680, 20, 281, 16));
        tabWidget_2->addTab(tab_7, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(("tab_8"));
        groupBox_2 = new QGroupBox(tab_8);
        groupBox_2->setObjectName(("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 671, 591));
        graphicsViewExceedingZUCTeorExper = new QGraphicsView(groupBox_2);
        graphicsViewExceedingZUCTeorExper->setObjectName(("graphicsViewExceedingZUCTeorExper"));
        graphicsViewExceedingZUCTeorExper->setGeometry(QRect(10, 20, 641, 281));
        graphicsViewExceedingZUCTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        graphicsViewExceedingZUCLogTeorExper = new QGraphicsView(groupBox_2);
        graphicsViewExceedingZUCLogTeorExper->setObjectName(("graphicsViewExceedingZUCLogTeorExper"));
        graphicsViewExceedingZUCLogTeorExper->setGeometry(QRect(10, 320, 641, 261));
        graphicsViewExceedingZUCLogTeorExper->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignVCenter);
        label_15 = new QLabel(tab_8);
        label_15->setObjectName(("label_15"));
        label_15->setGeometry(QRect(680, 90, 281, 16));
        lineE_2 = new QLineEdit(tab_8);
        lineE_2->setObjectName(("lineE_2"));
        lineE_2->setGeometry(QRect(680, 120, 163, 2));
        lineE_2->setFrame(false);
        lineT_2 = new QLineEdit(tab_8);
        lineT_2->setObjectName(("lineT_2"));
        lineT_2->setGeometry(QRect(680, 50, 161, 2));
        lineT_2->setFrame(false);
        label_16 = new QLabel(tab_8);
        label_16->setObjectName(("label_16"));
        label_16->setGeometry(QRect(680, 20, 281, 16));
        tabWidget_2->addTab(tab_8, QString());
        tabWidget->addTab(tab_6, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(("tab_5"));
        groupBox_3 = new QGroupBox(tab_5);
        groupBox_3->setObjectName(("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 10, 431, 581));
        graphicsViewCloudsZDCA = new QGraphicsView(groupBox_3);
        graphicsViewCloudsZDCA->setObjectName(("graphicsViewCloudsZDCA"));
        graphicsViewCloudsZDCA->setGeometry(QRect(10, 40, 401, 251));
        graphicsViewCloudsZDCL = new QGraphicsView(groupBox_3);
        graphicsViewCloudsZDCL->setObjectName(("graphicsViewCloudsZDCL"));
        graphicsViewCloudsZDCL->setGeometry(QRect(10, 320, 401, 251));
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName(("label_9"));
        label_9->setGeometry(QRect(10, 20, 181, 16));
        label_11 = new QLabel(groupBox_3);
        label_11->setObjectName(("label_11"));
        label_11->setGeometry(QRect(10, 300, 181, 16));
        groupBox_4 = new QGroupBox(tab_5);
        groupBox_4->setObjectName(("groupBox_4"));
        groupBox_4->setGeometry(QRect(450, 10, 431, 581));
        graphicsViewCloudsZUCA = new QGraphicsView(groupBox_4);
        graphicsViewCloudsZUCA->setObjectName(("graphicsViewCloudsZUCA"));
        graphicsViewCloudsZUCA->setGeometry(QRect(10, 40, 401, 251));
        graphicsViewCloudsZUCL = new QGraphicsView(groupBox_4);
        graphicsViewCloudsZUCL->setObjectName(("graphicsViewCloudsZUCL"));
        graphicsViewCloudsZUCL->setGeometry(QRect(10, 320, 401, 251));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName(("label_10"));
        label_10->setGeometry(QRect(10, 20, 181, 16));
        label_12 = new QLabel(groupBox_4);
        label_12->setObjectName(("label_12"));
        label_12->setGeometry(QRect(10, 300, 181, 16));
        tabWidget->addTab(tab_5, QString());
        MainWindow->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(4);
        tabWidget_2->setCurrentIndex(1);


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
        browseButton->setText(QApplication::translate("MainWindow", "Browse", 0));
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
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Waves", 0));
        label->setText(QApplication::translate("MainWindow", "-down-zero-crossing wave heights", 0));
        label_2->setText(QApplication::translate("MainWindow", "-up-zero-crossing wave heights", 0));
        label_3->setText(QApplication::translate("MainWindow", "Height 1/3", 0));
        label_4->setText(QApplication::translate("MainWindow", "Height 1/3", 0));
        label_5->setText(QApplication::translate("MainWindow", "Significant Height", 0));
        label_6->setText(QApplication::translate("MainWindow", "Significant Height", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Heights' Diagram", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "-down-zero-crossing waves", 0));
        label_13->setText(QApplication::translate("MainWindow", "teoretical exceedance probability", 0));
        label_14->setText(QApplication::translate("MainWindow", "experimental exceedance probability", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_7), QApplication::translate("MainWindow", "-down-zero-crossing waves", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "-up-zero-crossing waves", 0));
        label_15->setText(QApplication::translate("MainWindow", "teoretical exceedance probability", 0));
        label_16->setText(QApplication::translate("MainWindow", "experimental exceedance probability", 0));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_8), QApplication::translate("MainWindow", "-down-zero-crossing waves", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_6), QApplication::translate("MainWindow", "Heights' Probability", 0));
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
