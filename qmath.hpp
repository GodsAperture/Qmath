
#include "qmathlib/Constants.hpp"

namespace qmath {

    ////SPECIAL MATH FUNCTIONS////

    int sign(double in);

    int sign(int in);

    double abs(double in);

    int abs(int in);

    long long abs(long int in);

    double frexp(double in1, int *in2);

    double frexp(double in1, short *in2);

    double ldexp(double in1, long long in2);

    int floor(double in);

    int ceil(double in);

    bool iseven(int in);

    bool isodd(int in);

    ////TRIGONOMETRIC MATH FUNCTIONS////

    double sin(double in);

    double qsin(double in);

    double cos(double in);

    double qcos(double in);

    double tan(double in);

    double qtan(double in);

    double cot(double in);

    double qcot(double in);

    ////EXPONENTIALLY BASED FUNCTIONS////

    double log(double in);

    double log10(double in);

    double qlog(double in);

    double qlog10(double in);

    double sqrt(double in);

    double exp(double in);

    double cosh(double in);

    double sech(double in);

    double sinh(double in);

    double csch(double in);

    double tanh(double in);

    double coth(double in);

    double pow(double base, double expo);

    ////UNIVARIATE CALCULUS FUNCTIONS////

    double nint(double(*fun)(double), double* var, double low, double up);

    double der4(double(*fun)(double), double* var, double point);

    double der6(double(*fun)(double), double* var, double point);

    ////GLOBAL VARIABLE CALCULUS FUNCTIONS////

    double gnint(double(*fun)(), double* var, double low, double up);

    double gder4(double(*fun)(), double* var, double point);

    double gder6(double(*fun)(), double* var, double point);

}

namespace qmathf{

    ////SPECIAL MATH FUNCTIONS////

    int sign(float in);

    int sign(int in);

    float abs(float in);

    int abs(int in);

    long long abs(long int in);

    float frexp(double in1, int *in2);

    float frexp(double in1, short *in2);

    float ldexp(float in1, long int);

    int floor(float in);

    int ceil(float in);

    bool iseven(int in);

    bool isodd(int in);


    ////TRIGONOMETRIC MATH FUNCTIONS////

    float sin(float in);

    float qsin(float in);

    float cos(float in);

    float qcos(float in);

    float tan(float in);

    float qtan(float in);

    float cot(float in);

    float qcot(float in);

    ////EXPONENTIALLY BASED FUNCTIONS////

    float log(double in);

    float log10(double in);

    float qlog(double in);

    float qlog10(double in);

    float sqrt(float in);

    float exp(float in);

    float cosh(float in);

    float sech(float in);

    float sinh(float in);

    float csch(float in);

    float tanh(float in);

    float coth(float in);

    float pow(double base, float expo);

    ////UNIVARIATE CALCULUS FUNCTIONS////

    float nint(float(*fun)(float), float* var, float low, float up);

    float der4(float(*fun)(float), float* var, float point);

    float der6(float(*fun)(float), float* var, float point);

    ////GLOBAL VARIABLE CALCULUS FUNCTIONS////

    float gnint(float(*fun)(), float* var, float low, float up);

    float gder4(float(*fun)(), float* var, float point);

    float gder6(float(*fun)(), float* var, float point);

}
