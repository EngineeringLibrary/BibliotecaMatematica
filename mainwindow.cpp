#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PlotHandler::plot<double> P("1,2,3,4,5","1,2,3,4,5",ui-> grafico1);
    PlotHandler::plot<double> C("1,2,3,4,5","1,2,3,4,5",ui-> grafico2);

    this-> A = ("1,2;3,5");
    std::string str;
    str << A;
    ui->textdadosRecebidos->setText(str.c_str());

}

MainWindow::~MainWindow()
{
    delete ui;
    delete this-> wifi;
}

void MainWindow::on_botaoConectar_clicked()
{
    this->wifi = new Client(ui->lineIP->text(), ui->linePorta->text().toInt());
    connect(wifi, SIGNAL(connectionSuccessful()), this, SLOT(SucessoNaConexao()));
    connect(wifi, SIGNAL(hasReadData()), this, SLOT(RecebimentoDosDados()));
}

void MainWindow::on_enviarDados_clicked()
{
    //this->wifi->writeData(ui->lineEnviarDados->text());
}

void MainWindow::on_botaoDesconectar_clicked()
{

}

void MainWindow::SucessoNaConexao()
{
    QMessageBox msgBox;
    msgBox.setText("Conexão Realizada com sucesso");
    msgBox.exec();
}

void MainWindow::RecebimentoDosDados()
{

}
