#ifndef GENERALFUNCTION_H
#define GENERALFUNCTION_H
#include "SistemasdeControle/headers/modelLibs/model.h"

static LinAlg::Matrix<double> logaritimo(
       LinAlg::Matrix<double> Input)
{
        double y = Input(1,1);

        double c = Input(2,1);

        double V = Input(3,1);

        double P = c/pow(V,3*y);
    return LinAlg::Matrix<double>(P);
}

static void sistemaLinear(
        LinAlg::Matrix<double>& V,
        LinAlg::Matrix<double>& P)
{
    LinAlg::Matrix<double> ATemp(
                V.getNumberOfRows(),2);
    LinAlg::Matrix<double> bTemp(
                P.getNumberOfRows(),1);

    for(unsigned i = 1; i<= V.getNumberOfRows(); ++i)
    {
        ATemp(i,1) = 1/log10(V(i,1));
        ATemp(i,2) = -3;
        bTemp(i,1) = log10(P(i,1))/log10(V(i,1));
    }
    V = ATemp;
    P = bTemp;
}

namespace ModelHandler {
    template <typename Type>
    class GeneralFunction : public Model<Type>
    {
    public:
        GeneralFunction(LinAlg::Matrix<Type>(*pointer2Function)(LinAlg::Matrix<Type>),
                        void(*LinearSystem)(LinAlg::Matrix<Type>&,LinAlg::Matrix<Type>&),
                        LinAlg::Matrix<Type>ModelCoef);

        Type         sim(Type x);
        Type         sim(Type x, Type y){return 0;}
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x){return LinAlg::Matrix<Type>(Type(0));}
        LinAlg::Matrix<Type> sim(Type lmin, Type lmax, Type step){return LinAlg::Matrix<Type>(Type(0));}
        LinAlg::Matrix<Type> sim(LinAlg::Matrix<Type> x, LinAlg::Matrix<Type> y){return LinAlg::Matrix<Type>(Type(0));}

        std::string print(){return "0";}
        unsigned getNumberOfVariables(){return 0;}
        unsigned getNumberOfInputs() const{return 0;}
        unsigned getNumberOfOutputs() const{return 0;}
        void setLinearVector(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output){}
        void setLinearModel(LinAlg::Matrix<Type> Input, LinAlg::Matrix<Type> Output);

    private:
        LinAlg::Matrix<Type>(*pointer2Function)
                        (LinAlg::Matrix<Type>);
                        void(*LinearSystem)
                        (LinAlg::Matrix<Type>&,
                         LinAlg::Matrix<Type>&);

    };
}
#include "generalfunction.hpp"
#endif // GENERALFUNCTION_H
