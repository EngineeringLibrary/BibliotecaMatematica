#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    PlotHandler::plot<double> T("1,2,3,4,5","1,2,3,4,5",ui-> grafico2);
    //P[0] = new PlotHandler::plot<double>(ui-> grafico2);
    P = new PlotHandler::plot<double>(ui->grafico1);
    //Time = 0;

//    srand(time(NULL));
//        LinAlg::Random<double> X(1,1) %20 - 5;
//        std::string str;
//        str << X;

    srand(time(NULL));




//    LinAlg::Matrix<double> A = "0,1;-1,-2";
//    LinAlg::Matrix<double> B = "0;1";
//    LinAlg::Matrix<double> C = "1,0";
//    LinAlg::Matrix<double> D = "0";

//    ModelHandler::Model<double> *x = new ModelHandler::StateSpace<double>(A,B,C,D);
//    std::string str;
//    str << x;

//    ui->textdadosRecebidos->append(str.c_str());

//    std::string str0;
//    std::string str1;
//    std::string str2;
//    std::string str3;
//    std::string str4;
//    str0 << A;
//    str1 << B;
//    str2 << C;
//    str3 << D;
//    str4 << x;

//    ui->textdadosRecebidos->setText(str0.c_str());
//    ui->textdadosRecebidos->append(str1.c_str());
//    ui->textdadosRecebidos->append(str2.c_str());
//    ui->textdadosRecebidos->append(str3.c_str());
//    ui->textdadosRecebidos->append(str4.c_str());

//    this-> A = ("1,2;3,5");
//    std::string str;
//    str << A;
//    ui->textdadosRecebidos->setText(str.c_str());

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
    LinAlg::Matrix<double> Coef = ui->lineEnviarDados->text().toStdString().c_str();
    model = new ModelHandler::GeneralFunction<double>(logaritimo,sistemaLinear,Coef);
}

void MainWindow::on_botaoDesconectar_clicked()
{
    U = LinAlg::Random<double>(5,1)*10-5;
    std::string str;
    str << U;
    wifi->writeData(str.c_str());
}

void MainWindow::SucessoNaConexao()
{
    QMessageBox msgBox;
    msgBox.setText("Conexão Realizada com sucesso");
    msgBox.exec();
}

void MainWindow::RecebimentoDosDados()
{
    Y = wifi->dataReceived().toStdString().c_str();
    std::string dadosRecebidos;
    dadosRecebidos << Y;
    ui->textdadosRecebidos->append(dadosRecebidos.c_str());
}

void MainWindow::on_simularValores_clicked()
{

    LinAlg::Matrix<double> U = ui->lineSimular->text().toStdString().c_str();
    LinAlg::Matrix<double> Y = U;

    for(unsigned i = 1; i <= U.getNumberOfRows(); ++i)
    {
        Y(i,1) = model->sim(U(i,1));
        P->realTimeDataUpdate(U(i,1),Y(i,1));
    }
    model->setLinearModel(U,Y);
    LinAlg::Matrix<double> A = (~model->getLinearMatrixA())*model->getLinearMatrixA();
    LinAlg::Matrix<double> b = (~model->getLinearMatrixA())*model->getLinearEqualityB();
    LinAlg::Matrix<double> x = LinAlg::Elimination(A,b);
    std::string str;
    str << x;
    ui->textdadosRecebidos->append(str.c_str());
}
