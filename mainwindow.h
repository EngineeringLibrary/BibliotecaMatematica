#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QmessageBox>
#include "client.h"
#include <SistemasdeControle/headers/graphicLibs/plot.h>
#include <SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h>

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
    LinAlg::Matrix<double> A;
};

#endif // MAINWINDOW_H
