#ifndef GAUSSJACOBI_H
#define GAUSSJACOBI_H
#include <SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h>


namespace LinAlg
{
    template<typename Type>
    LinAlg::Matrix<Type> GaussJacobi(const LinAlg::Matrix<Type> &A, LinAlg::Matrix<Type> &B, unsigned nIteracoes = 100, Type tolerance = 1e-10);
    template<typename Type>
    bool CriterioDeLinhas(const LinAlg::Matrix<Type> &A);
}

#include "gaussjacobi.hpp"

#endif // GAUSSJACOBI_H
