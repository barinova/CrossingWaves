#-------------------------------------------------
#
# Project created by QtCreator 2013-10-22T01:20:25
#
#-------------------------------------------------

QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
TARGET = CrossingWave
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ccrossingwave.cpp \
    csaveimg.cpp \
    cdragdropmenu.cpp

HEADERS  += mainwindow.h \
    ccrossingwave.h \
    csaveimg.h \
    cdragdropmenu.h

FORMS    += mainwindow.ui

RC_FILE += icon.rc

OTHER_FILES += \
    icon.rc
