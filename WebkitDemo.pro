#-------------------------------------------------
#
# Project created by QtCreator 2017-04-04T00:38:55
#
#-------------------------------------------------

QT       += core gui
 QT+= webkitwidgets
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebkitDemo
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sourceview.cpp

HEADERS  += mainwindow.h \
    sourceview.h

FORMS    += mainwindow.ui \
    sourceview.ui
