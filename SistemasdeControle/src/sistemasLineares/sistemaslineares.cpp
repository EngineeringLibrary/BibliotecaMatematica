#include "sistemaslineares.h"

SistemasLineares::SistemasLineares()
{
}
SistemasLineares::~SistemasLineares()
{
}

void SistemasLineares::PivotParcial(LinAlg::Matrix<float> &MatrizUni, int cols)
{
    SistemasLineares A;
    LinAlg::Matrix<float> AUX;

        for(unsigned i = cols + 1; i <= MatrizUni.getNumberOfRows(); i++){
            if(abs(MatrizUni(cols,cols)) < abs(MatrizUni(i,cols)))
            {
//                AUX = LinAlg::Matrix<float>::GetRow(cols);
//                LinAlg::Matrix<float>::SwapRows(cols,i);
//                LinAlg::Matrix<float>::SwapRows(i,AUX);
            }
      }
}

LinAlg::Matrix<float> SistemasLineares::Gauss(LinAlg::Matrix<float> MatrizUni)
{
    LinAlg::Matrix<float> MatrizGauss;
    //Laço para contagem das colunas de MatrizUni.
    for(unsigned i = 1; i < MatrizUni.getNumberOfColumns(); i++)
    {   //Laço para contagem das linhas de MatrizUni.
        for(unsigned j = i + 1; j <= MatrizUni.getNumberOfRows();  j++)
        {
            float m = MatrizUni(j,i)/MatrizUni(i,i);
            //Laço para contagem das colunas da equação.
            for(unsigned z = i ; z <= MatrizUni.getNumberOfColumns(); z++)
                MatrizUni(j,z) = MatrizUni(j,z) - m*MatrizUni(i,z);
        }
    }

    MatrizGauss = LinAlg::Zeros<float>(1, MatrizUni.getNumberOfRows());
    float R;
    for(unsigned i = 1; i <= MatrizUni.getNumberOfRows(); ++i)
    {
        unsigned k = MatrizUni.getNumberOfRows() - i + 1;
        R = 0;
        for(unsigned j = k + 1; j <= MatrizUni.getNumberOfColumns() - 1; ++j)
                R = R + MatrizUni(k, j) * MatrizGauss(1, j);

        MatrizGauss(1, k) = (MatrizUni(k, MatrizUni.getNumberOfColumns()) - R) / MatrizUni(k, k);
    }
    return MatrizGauss;
}

LinAlg::Matrix<float> SistemasLineares::GaussJacobi(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations)
{
    //Matriz Resposta
    LinAlg::Matrix<float> MatrizRes(MaxIterations, MatrizUni.getNumberOfColumns());
    LinAlg::Matrix<float> C (MatrizUni.getNumberOfRows(), MatrizUni.getNumberOfColumns() - 1);
    LinAlg::Matrix<float> g (MatrizUni.getNumberOfRows(), 1);
    LinAlg::Matrix<float> x0(C.getNumberOfColumns(), 1);

    //    //Deixa o vetor de chute inicial padronizado como vetor linha
    if(this->X0.getNumberOfColumns() < this->X0.getNumberOfRows())
        ~this->X0;

    //    //Insere o chute inicial na Matriz resposta
    for(unsigned i = 1; i < MatrizRes.getNumberOfColumns() - 1; ++i)
        x0(1,i) = this->X0(1,i);

        //Laço para contar as linhas da MatrizUni e Matriz C.
        for(unsigned i = 1; i <= MatrizUni.getNumberOfRows(); ++i)
        {   //Laço para contar as colunas da MAtrizUni e Matriz C.
            for(unsigned j = 1; j < MatrizUni.getNumberOfColumns(); ++j)
            {
                if(i != j)
                    C(i,j) = - MatrizUni(i,j)/MatrizUni(i,i);//Matriz com a diagonal zerada.
            }
            g(i,1) = MatrizUni(i,MatrizUni.getNumberOfColumns()) / MatrizUni(i,i);//Matriz dos termos independentes.
        }

        MatrizRes = ~x0;
        for(unsigned k = 1; k < MaxIterations; ++k)
        {
            x0 =  (C * x0) + g;
            MatrizRes = MatrizRes || ~x0;
        }
    return MatrizRes;
}

LinAlg::Matrix<float> SistemasLineares::GaussSeidel(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations)
{
    LinAlg::Matrix<float> MatrizRes(MaxIterations, MatrizUni.getNumberOfColumns());

   //Deixa o vetor de chute inicial padronizado como vetor linha
   if(this->X0.getNumberOfColumns() < this->X0.getNumberOfRows())
   {
       ~this->X0;
   }
   //Insere o chute inicial na Matriz resposta
   for(unsigned i = 1; i < MatrizRes.getNumberOfColumns(); i++){
       MatrizRes(1,i) = this->X0(1,i);
   }

   //Laço para contar as linhas da Matriz Resposta
   for(unsigned k = 2; k <= MaxIterations; k++)
   {
       //Laço para contar as colunas da MatrizRes e linhas da MatrizUni.
       for(unsigned i = 1; i < MatrizUni.getNumberOfColumns(); i++)
       {
           float aux = 0;

           //Verificação das variáveis atualizadas (mesma linha)
           for(unsigned j = 1; j < i; j++)
           {
               aux += (MatrizUni(i,j)*MatrizRes(k, j));
           }

           //Verificação das variaveis não atualizadas (linha anterior)
           for(unsigned j = i+1; j < MatrizUni.getNumberOfColumns(); j++)
           {
               aux += (MatrizUni(i,j)*MatrizRes(k-1, j));
           }

           //Aplicação da formula geral (Bi-x1-x2)/Aii
           MatrizRes(k,i) = (MatrizUni(i, MatrizUni.getNumberOfColumns()) - aux)/MatrizUni(i,i);

           //Verifica se o valor de erro d(k) é o maior encontrado
           if(abs(MatrizRes(k,i) - MatrizRes(k-1,i)) > MatrizRes(k-1, MatrizRes.getNumberOfColumns()))
               MatrizRes(k-1, MatrizRes.getNumberOfColumns()) = abs(MatrizRes(k,i) - MatrizRes(k-1,i));
       }
   }
   return MatrizRes;
}

void SistemasLineares::CritLinhas(LinAlg::Matrix<float> MatrizUni)
{
    LinAlg::Matrix<float> MatrizRes(1,MatrizUni.getNumberOfRows());
    for(unsigned i = 1; i <= MatrizUni.getNumberOfRows(); i++)
    {
        for(unsigned j =1; j <= MatrizUni.getNumberOfColumns(); j++)
        {
            if(i != j)
            {
                MatrizRes(1, i) += MatrizUni(i,j)/MatrizUni(i,i);
            }
        }
        if(MatrizRes(1, i) > 1)
        {
            cout<<"O sistema não possui solução para qualquer valor inicial de X0";
            break;
        }
    }
}

void SistemasLineares::CritSassenfeld(LinAlg::Matrix<float> MatrizUni)
{

}

void SistemasLineares::LU_Factorization(LinAlg::Matrix<float> Matriz, LinAlg::Matrix<float> &L, LinAlg::Matrix<float> &U)//Para Matriz Quadrada.
{
    L = LinAlg::Eye<float>(Matriz.getNumberOfRows());

    for(unsigned i = 1; i < Matriz.getNumberOfColumns(); ++i)
    {   //Laço para contagem das linhas de MatrizUni.
        for(unsigned j = i + 1; j <= Matriz.getNumberOfRows();  ++j)
        {
            L(j, i) = Matriz(j, i)/Matriz(i, i);
            //Laço para contagem das colunas da equação.
            for(unsigned z = i ; z <= Matriz.getNumberOfColumns(); ++z)
                Matriz(j, z) = Matriz(j, z) - L(j, i)*Matriz(i, z);
        }
    }
    U = Matriz;
}

float SistemasLineares::abs(float Valor)
{
    if(Valor < 0)
           Valor = -Valor;

    return Valor;
}
