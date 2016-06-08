#include "gaussjacobi.h"

template<typename Type>
bool LinAlg::CriterioDeLinhas(const LinAlg::Matrix<Type> &A)
{
    Type Alfa = 0;
    for(unsigned i = 1; i< A.getNumberOfColumns(); ++i )
    {
        Type AlfaTemp = 0;
        for(unsigned j = 1; j <= A.getNumberOfColumns(); ++j)
            if(i != j)
            {
                AlfaTemp += Type (fabs(A(i,j))/(A(i,i)));
            }
        if(AlfaTemp > Alfa)
            Alfa = AlfaTemp;
    }
    if(Alfa >= 1)
    {
        return 0;
    }
    else
        return 1;
}


template<typename Type>
LinAlg::Matrix<Type> LinAlg::GaussJacobi(const LinAlg::Matrix<Type> &A, LinAlg::Matrix<Type> &B, unsigned nIteracoes, Type tolerance)
{
    LinAlg::Matrix<Type> X = B, XA = B;
    LinAlg::Matrix<Type> C = A;
    LinAlg::Matrix<Type> G = B;

    for(unsigned i = 1; i <= A.getNumberOfRows(); ++i )
    {
        for(unsigned j = 1; j <= A.getNumberOfColumns(); ++j)
            if(j != i)
                C(i,j) = -A(i,j)/A(i,i);
            else
                C(i,j) = 0;
        G(i,1) = B(i,1)/A(i,i);
     }

    for(unsigned i = 1; i <= nIteracoes; ++i )
    {
        X = C*X+G;
        Type MaxValue = 0;
        for(unsigned j = 1; j <= X.getNumberOfRows(); ++j)
            if(fabs(Type(X(j,1)-XA(j,1))) > MaxValue)
                    MaxValue = fabs(Type(X(j,1)-XA(j,1)));
        if(MaxValue < tolerance)
            break;
        XA = X;
    }
    return X;
}
