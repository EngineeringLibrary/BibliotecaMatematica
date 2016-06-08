#include "gaussseidel.h"

template<typename Type>
bool LinAlg::CritSassenfeld(const LinAlg::Matrix<Type> &A)
{
    LinAlg::Matrix<Type> beta(A.getNumberOfColumns(),1);
    Type BetaTemp = 0;
    for(unsigned i = 1; i <= A.getNumberOfColumns(); ++i )
    {
        for(unsigned j = 1; j <= i-1; ++j)
            beta(i,1) += Type (fabs(A(i,j)*beta(j,1)/(A(i,i))));

        for(unsigned j = i+1; j <= A.getNumberOfColumns(); ++j)
            beta(i,1) += Type (fabs(A(i,j)/(A(i,i))));

        if(BetaTemp < beta(i,1))
            BetaTemp = beta(i,1);
    }
    std::cout<< beta;
    if(BetaTemp >= 1)
    {
        return 0;
    }
    else
        return 1;
}

template<typename Type>
LinAlg::Matrix<Type> LinAlg::GaussSeidel(const LinAlg::Matrix<Type> &A, const LinAlg::Matrix<Type> &B,
                                         unsigned nIteracoes, Type tolerance)
{
    LinAlg::Matrix<Type> X = B, XA = B;

    for(unsigned i = 1; i <= nIteracoes; ++i)
    {
        Type MaxValue = 0;
        for(unsigned j = 1; j <= A.getNumberOfRows(); ++j)
        {
            X(j,1) = B(j,1)/A(j,j);

            for(unsigned k = 1; k <= A.getNumberOfColumns(); ++k)
                if(k != j)
                    X(j,1) -= A(j,k)*X(k,1)/A(j,j);

            if(fabs(Type(X(j,1)-XA(j,1))) > MaxValue)
                    MaxValue = fabs(Type(X(j,1)-XA(j,1)));
        }
        if(MaxValue < tolerance)
            break;
        XA = X;
    }
    return X;
}
