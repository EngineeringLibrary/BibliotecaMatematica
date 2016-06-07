#include "elimincaodegaus.h"

LinAlg::Matrix<double> ElimincaodeGaus::Gauss(LinAlg::Matrix<double> MatrizUni)
{
    LinAlg::Matrix<double> MatrizGauss;

    for(unsigned i = 1; i < MatrizUni.getNumberOfColumns(); ++i)
    {
        for(unsigned j = i+1; j<= MatrizUni.getNumberOfColumns(); ++j)
        {
            double M = MatrizUni(j,i)/MatrizUni(i,i);

            for(unsigned z=i; z <= MatrizUni.getNumberOfColumns(); z++)
            {
                MatrizUni(j,z) = MatrizUni(j,z) - m*MatrizUni(i,z);
            }
        }
    }
    MatrizGauss = LinAlg::Zeros<double>(1, MatrizUni.getNumberOfRows());
    double R;
    for(unsigned i = 1; i <= MatrizUni.getNumberOfRows(); ++i)
    {
        unsigned k = MatrizUni.getNumberOfRows() - i + 1;
        R = 0;
        for(unsigned j = k + 1; j <= MatrizUni.getNumberOfColumns() - 1; ++j)
            R = R + MatrizUni(k, j)*MatrizGauss(1,j);
        MatrizGauss(1,k) = (MatrizUni(k,MatrizUni.getNumberOfColumns())-R)/MatrizUni(k,k);
    }
    return MatrizGauss;
}
