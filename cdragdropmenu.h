#ifndef CDRAGDROPMENU_H
#define CDRAGDROPMENU_H

#include <qmenubar.h>
#include <QToolButton>

class CDragDropMenu
{

public:
    CDragDropMenu& getInstance(QWidget* parent);
    //static CDragDropMenu instance;

private:
     CDragDropMenu(QWidget *parent);
};

#endif // CDRAGDROPMENU_H
