#include "generalfunction.h"
template<typename Type>
ModelHandler::GeneralFunction<Type>::GeneralFunction
(
                LinAlg::Matrix<Type>(*pointer2Function)(LinAlg::Matrix<Type>),
                void(*LinearSystem)(LinAlg::Matrix<Type>&,LinAlg::Matrix<Type>&),
                LinAlg::Matrix<Type>ModelCoef
)
{
    this->pointer2Function = pointer2Function;
    this->LinearSystem = LinearSystem;
    this->ModelCoef = ModelCoef;
}
template<typename Type>
Type ModelHandler::GeneralFunction<Type>::sim(Type x)
{
    LinAlg::Matrix<double> input =
            this->ModelCoef||
            LinAlg::Matrix<Type>(x);
    return((*pointer2Function)(input))(1,1);
}
template<typename Type>
void ModelHandler::GeneralFunction<Type>::setLinearModel(LinAlg::Matrix<Type>input,LinAlg::Matrix<Type>Output)
{
    ((*LinearSystem)(input,Output));
    this->LinearMatrixA = input;
    this->LinearEqualityB = Output;
}
