#ifndef ELIMINCAODEGAUS_H
#define ELIMINCAODEGAUS_H
#include <SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h>
#include <SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h>

class ElimincaodeGaus
{
    LinAlg::Matrix<double> X0;
    void PivotParcial(LingAlg::Matrix<double> &MatrizUni, int cols);
    double ads(double valor);

public:

    //Metodos para montar os sistema Linear de Gauss:
    ElimincaodeGaus();
    LinAlg::Matrix<double> Gauss(LinAlg::Matrix<double> MatrizUni);

    //Fatoração LU:
    Void LuFatorization(LinAlg::Matrix<double> Matriz, LinAlg::Matrix<double> &L, LinAlg::Matrix<double> &U);

    //Função Valores Iniciais do sistema:
    void setX0(LinAlg::Matrix<double> InicialStep)
    {
        this-> X0 = InicialStep;
    }

    //Criterio dos Metodos
    void CritLinhas(LinAlg::Matrix<double> MatrizUni);
    void CritSassenfeld(LinAlg::Matrix<double> MatrizUni);

};
#include "elimincaodegaus.hpp"
#endif // ELIMINCAODEGAUS_H
