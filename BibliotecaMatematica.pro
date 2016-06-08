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
    qcustomplot.h \
    SistemasdeControle/src/modelLibs/model.hpp \
    SistemasdeControle/headers/modelLibs/model.h \
    SistemasdeControle/headers/modelLibs/arx.h \
    SistemasdeControle/src/modelLibs/arx.hpp \
    SistemasdeControle/headers/modelLibs/statespace.h \
    SistemasdeControle/src/modelLibs/statespace.hpp \
    generalfunction.h \
    generalfunction.hpp \
    lagrange.h \
    lagrange.hpp \
    SistemasdeControle/headers/primitiveLibs/polynom.h \
    SistemasdeControle/src/primitiveLibs/polynom.hpp \
    elimincaodegaus.h \
    elimincaodegaus.hpp \
    SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h \
    SistemasdeControle/src/primitiveLibs/LinAlg/linalg.hpp \
    gauselimination.h \
    gauselimination.hpp \
    gaussjacobi.h \
    gaussjacobi.hpp \
    gaussseidel.h \
    gaussseidel.hpp

FORMS    += mainwindow.ui
