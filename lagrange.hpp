#include "lagrange.h"

template <typename Type>

LinAlg::Matrix<Type> LinAlg::Lagrange(const LinAlg::Matrix<Type> &A)
{
    LinAlg::Matrix<Type> Num(1,2), Den(1,1);
    PolynomHandler::Polynom<Type> F("0"); // declarando polinomio F
    Num(1,1) = 1;

    //for(unsigned k = 1; k <= A.getNumberOfColumns();++k)
    {
        for(unsigned i = 1; i <= A.getNumberOfColumns(); ++i)
        {
            PolynomHandler::Polynom<Type> L("1"); // declarando polinomio L
            for(unsigned j = 1; j <= A.getNumberOfColumns(); ++j)
               if(j != i)
               {
                   Num(1,2) = -A(1,j);
                   Den(1,1)=  A(1,i) - A(1,j);
                   L *= PolynomHandler::Polynom<Type>(Num,Den);

//                   L *= (X - A(1,j)) / (A(1,i) - A(1,j));
               }
//            std::cout << L;
            F += L * A(2,i);
            std::cout << F;
        }
    }

    return F.getNum()/F.getDen()(1,1);
}
