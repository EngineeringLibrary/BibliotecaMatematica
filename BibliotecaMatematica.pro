#-------------------------------------------------
#
# Project created by QtCreator 2016-05-26T21:17:04
#
#-------------------------------------------------

QT       += core gui\
            network \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BibliotecaMatematica
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp

HEADERS  += mainwindow.h \
    client.h

FORMS    += mainwindow.ui
