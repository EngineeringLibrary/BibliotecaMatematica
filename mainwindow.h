#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <cstdlib>
#include <ctime>
#include <QMainWindow>
#include <QmessageBox>
#include "client.h"
#include "SistemasdeControle/headers/graphicLibs/plot.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "generalfunction.h"
#include "gauselimination.h"
#include "gaussjacobi.h"
#include "gaussseidel.h"
#include "lagrange.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_botaoConectar_clicked();

    void on_enviarDados_clicked();

    void on_botaoDesconectar_clicked();

    void RecebimentoDosDados();

    void SucessoNaConexao();

    void on_simularValores_clicked();

private:

    Ui::MainWindow *ui;
    Client *wifi;
    ModelHandler::Model<double> *model;
    PlotHandler::plot<double> *P;
    LinAlg::Matrix<double> U,Y;
    double Time;

};

#endif // MAINWINDOW_H
