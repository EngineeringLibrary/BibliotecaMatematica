#ifndef ELIMINACAOGAUSSJACOBI_H
#define ELIMINACAOGAUSSJACOBI_H
#include <SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h>
#include <SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h>


class EliminacaoGaussJacobi
{
    LinAlg::Matrix<double> X0;
    void PivotParcial(LingAlg::Matrix<double> &MatrizUni, int cols);
    double ads(double valor);

public:
    EliminacaoGaussJacobi();
    LinAlg::Matrix<double> GaussJacobi(LinAlg::Matrix<double> MatrizUni, unsigned MaxIterations);

    void LuFactorization(LinAlg::Matrix<double> Matriz, LinAlg::Matrix<double> &L, LinAlg::Matrix<double> &U);
    //Função para set dos Valores iniciais das sistema.
    void setX0(LinAlg::Matrix<double> InicialStep)
    {
        this->X0 = InicialStep;
    }
    //Criterios dos Metodos(Incompleto)
    void CritLinhas(LinAlg::Matrix<double> MatrizUni);
    void CritSassenfeld(LinAlg::Matrix<double> MatrizUni);
};

#endif // ELIMINACAOGAUSSJACOBI_H
