#-------------------------------------------------
#
# Project created by QtCreator 2013-10-22T01:20:25
#
#-------------------------------------------------

QT       += core gui sql
TARGET = CrossingWave
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    ccrossingwave.cpp \
    cloadfile.cpp \
    csavefile.cpp \
    cmatlabproc.cpp

HEADERS  += mainwindow.h \
    ccrossingwave.h \
    cloadfile.h \
    csavefile.h \
    cmatlabproc.h

FORMS    += mainwindow.ui

RC_FILE += icon.rc

OTHER_FILES += \
    icon.rc
