#-------------------------------------------------
#
# Project created by QtCreator 2018-09-16T18:57:07
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = dashboard
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    treeitem.cpp \
    treemodel.cpp \
    icontext.cpp \
    settings.cpp

HEADERS  += mainwindow.h \
    treeitem.h \
    treemodel.h \
    icontext.h \
    settings.h

FORMS    += mainwindow.ui \
    icontext.ui \
    settings.ui

RESOURCES += \
    treecontent.qrc \
    fontawesome.qrc

OTHER_FILES +=

