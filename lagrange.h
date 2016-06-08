#ifndef LAGRANGE_H
#define LAGRANGE_H
#include "SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h"
#include "SistemasdeControle/headers/primitiveLibs/polynom.h"

namespace LinAlg
{
    template<typename Type>
    LinAlg::Matrix<Type> Lagrange(const LinAlg::Matrix<Type> &Y);
}

#include "lagrange.hpp"
#endif // LAGRANGE_H
