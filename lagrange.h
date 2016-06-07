#ifndef LAGRANGE_H
#define LAGRANGE_H
#include "SistemasdeControle/headers/modelLibs/model.h"
namespace ModelHandler
{
template <typename Type>
    class lagrange
    {
        Model<Type> F;
    public:
        lagrange(Model<Type> F);
        Type encontrarFuncao(Type X, Type Y);
    };
}
#include "lagrange.hpp"
#endif // LAGRANGE_H
