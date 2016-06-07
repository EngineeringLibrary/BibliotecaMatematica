#include "gauselimination.h"

template<typename Type>
LinAlg::Matrix<Type> LinAlg::Elimination(LinAlg::Matrix<Type> A, LinAlg::Matrix<Type> B)
{
    LinAlg::Matrix<Type> AB = (A|B);

    for(unsigned i = 1; i < A.getNumberOfColumns(); ++i)
        for(unsigned j = i+1; j <= A.getNumberOfColumns(); ++j)
        {
            Type M = A(j,i)/A(i,i);// pegando valores (ex A12/A11)
            for(unsigned k = 1; k <= AB.getNumberOfColumns(); ++k)
                AB(2,k) -= M*AB(1,k);
        }

    LinAlg::Matrix<Type> X(B.getNumberOfRows(), B.getNumberOfColumns());
    for(unsigned i = A.getNumberOfColumns(); i >= 1; --i)
    {
        for(unsigned j = i+1; j <= A.getNumberOfColumns(); ++j)
            X(i,1) -= AB(i,j)*X(j,1);   // fazendo apenas a parte do somatorio

        X(i,1) += AB(i, A.getNumberOfColumns()+1);
        X(i,1) /= AB(i,i);
    }
    return X;
}
