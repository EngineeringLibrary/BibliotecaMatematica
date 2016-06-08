#ifndef GAUSSSEIDEL_H
#define GAUSSSEIDEL_H
#include <SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h>

namespace LinAlg
{
    template<typename Type>
    LinAlg::Matrix<Type> GaussSeidel(const LinAlg::Matrix<Type> &A, const LinAlg::Matrix<Type> &B,unsigned nIteracoes = 100, Type tolerance = 1e-10);
    template<typename Type>
    bool CritSassenfeld(const LinAlg::Matrix<Type> &A);
}
#include "gaussseidel.hpp"
#endif // GAUSSSEIDEL_H
