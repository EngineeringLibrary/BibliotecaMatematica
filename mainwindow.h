#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QmessageBox>
#include "client.h"
#include <SistemasdeControle/headers/graphicLibs/plot.h>

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

private:
    Ui::MainWindow *ui;
    Client *wifi;
//    PlotHandler::plot<double> *plotDados [10];
//    long long unsigned int Amostras;
};

#endif // MAINWINDOW_H
