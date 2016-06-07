#ifndef GAUSELIMINATION_H
#define GAUSELIMINATION_H
#include <SistemasdeControle/headers/primitiveLibs/LinAlg/matrix.h>

namespace LinAlg
{
    template<typename Type>
    LinAlg::Matrix<Type> Elimination(LinAlg::Matrix<Type> A, LinAlg::Matrix<Type> B);
}

#include "gauselimination.hpp"

#endif // GAUSELIMINATION_H
