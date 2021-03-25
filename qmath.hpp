
namespace qmath {

    ////SPECIAL MATH FUNCTIONS////

    int sign(double in);

    int sign(float in);

    int sign(int in);

    double abs(double in);

    float abs(float in);

    int abs(int in);

    long long abs(long int in);

    double frexp(double in1, int *in2);

    double frexp(double in1, short *in2);

    float frexp(float in1, int *in2);

    float frexp(float in1, short *in2);

    ////TRIGONOMETRIC MATH FUNCTIONS////

    double sin(double in);

    float sin(float in);

    double qsin(double in);

    float qsin(float in);

    double cos(double in);

    float cos(float in);

    double qcos(double in);

    float qcos(float in);

    double tan(double in);

    float tan(float in);

    double qtan(double in);

    double cot(double in);

    float cot(float in);

    double qcot(double in);

    ////EXPONENTIALLY BASED FUNCTIONS////

    double log(double in);

    double qlog(double in);

    double sqrt(double in);

    double qsqrt(double in);

    double exp(double in);

    float exp(float in);

    double cosh(double in);

    float cosh(float in);

    double sech(double in);

    float sech(float in);

    double sinh(double in);

    float sinh(float in);

    double csch(double in);

    float csch(float in);

    double tanh(double in);

    double coth(double in);

    ////UNIVARIATE CALCULUS FUNCTIONS////

    double nint(double(*fun)(double), double* var, double low, double up);

    float nint(float(*fun)(float), float* var, float low, float up);

    double der4(double(*fun)(double), double* var, double point);

    float der4(float(*fun)(float), float* var, float point);

    double der6(double(*fun)(double), double* var, double point);

    float der6(float(*fun)(float), float* var, float point);

    ////GLOBAL VARIABLE CALCULUS FUNCTIONS////

    double gnint(double(*fun)(), double* var, double low, double up);

    float gnint(float(*fun)(), float* var, float low, float up);

    double gder4(double(*fun)(), double* var, double point);

    float gder4(float(*fun)(), float* var, float point);

    double gder6(double(*fun)(), double* var, double point);

    float gder6(float(*fun)(), float* var, float point);

}
