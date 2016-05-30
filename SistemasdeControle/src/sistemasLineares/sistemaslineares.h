#ifndef SISTEMASLINEARES_H
#define SISTEMASLINEARES_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/linalg.h"
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"

using namespace std;

class SistemasLineares
{
    LinAlg::Matrix<float> X0;
    //Criterio do Metodo(incompleto)
    void PivotParcial(LinAlg::Matrix<float> &MatrizUni, int cols);
    //Modulo de um valor
    float abs(float Valor);

public:
    SistemasLineares();
    ~SistemasLineares();
    //Metodos para montar os Sistemas Lineares Gauss, Jacobi, Seidel
    LinAlg::Matrix<float> Gauss(LinAlg::Matrix<float> MatrizUni);
    LinAlg::Matrix<float> GaussJacobi(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations);
    LinAlg::Matrix<float> GaussSeidel(LinAlg::Matrix<float> MatrizUni, unsigned MaxIterations);
    //Fatoração LU
    void LU_Factorization(LinAlg::Matrix<float> Matriz, LinAlg::Matrix<float> &L, LinAlg::Matrix<float> &U);
    //Função para set dos Valores iniciais das sistema.
    void setX0(LinAlg::Matrix<float> InicialStep){this->X0 = InicialStep;}
    //Criterios dos Metodos(Incompleto)
    void CritLinhas(LinAlg::Matrix<float> MatrizUni);
    void CritSassenfeld(LinAlg::Matrix<float> MatrizUni);

};
#endif // SISTEMASLINEARES_H
