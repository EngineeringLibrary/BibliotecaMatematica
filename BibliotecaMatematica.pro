#-------------------------------------------------
#
# Project created by QtCreator 2016-05-26T21:17:04
#
#-------------------------------------------------

QT       += core gui\
            network \

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = BibliotecaMatematica
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    client.cpp \
    qcustomplot.cpp

HEADERS  += mainwindow.h \
    client.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/matrix.hpp \
    SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h \
    SistemasdeControle/src/graphicLibs/plot.hpp \
    SistemasdeControle/headers/graphicLibs/plot.h \
    qcustomplot.h

FORMS    += mainwindow.ui
