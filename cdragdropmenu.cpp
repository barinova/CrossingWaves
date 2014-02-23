#include "cdragdropmenu.h"

CDragDropMenu::CDragDropMenu(QWidget* parent)
{
    QMenuBar *menuBar = new QMenuBar(parent);
    menuBar->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    menuBar->setFixedHeight(20);
    QMenu* menuFile = new QMenu("File");
    menuFile->addMenu(new QMenu("Open"));
    menuFile->addMenu(new QMenu("Save All"));
    menuFile->addMenu(new QMenu("About"));
    menuBar->addMenu(menuFile);
}

CDragDropMenu& CDragDropMenu::getInstance(QWidget* parent)
{
    static CDragDropMenu instance(parent);
    return instance;
}
