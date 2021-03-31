
namespace qmath {

    int sign(double in) {
        return (in > 0) - (in < 1);
    }//Returns the sign of the given double.

    int sign(int in) {
        return (in > 0) - (in < 0);
    }//Returns the sign of the given int.

    double abs(const double in){
        return in * (in > 0) - in * (in < 0);
    }//Returns the absolute value of the given double.

    int abs(const int in) {
        return in * (in > 0) - in * (in < 0);
    }//Returns the absolute value of the given int.

    long long abs(const long int in) {
        return in * (in > 0) - in * (in < 0);
    }//Returns the absolute value of the given long int.

    double frexp(const double in1, int *in2) {
        *in2 = ((0x7ff0000000000000 & (*(long long *) &in1)) >> 52) - 1022;
        return 1.1102230246251565e-16 * (0x000fffffffffffff & (*(long long *) &in1)) + 0.5;
    }//Returns the mantissa and exponent of the given double.

    double frexp(const double in1, short *in2) {
        *in2 = ((0x7ff0000000000000 & (*(long long *) &in1)) >> 52) - 1022;
        return 1.1102230246251565e-16 * (0x000fffffffffffff & (*(long long *) &in1)) + 0.5;
    }//Returns the mantissa and exponent of the given double.

    double ldexp(const double in1, const long long in2){
        return in1 * ((in2 + 1023) << 52);
    }//Returns the double constructed from the given mantissa and exponent.

    int floor(const double in){
        int sign = (in > 0) - (in < 0);
        int val = (int) (in * sign);
        return (val + 0.5 + 0.5 * (in < 0) * sign + 1.5 * (in < 0) * (val * sign != in)) * sign;
    }//Returns the current double rounded down.

    int ceil(const double in){
        int sign = (in > 0) - (in < 0);
        double val = (int) (in * sign);
        return (val + (sign + (in < 0)) * (in * sign != val)) * sign;
    }//Returns the current double rounded up.

    bool iseven(int in){
        return 2 * ((int) (0.5 * in)) == in;
    }//Returns True bool value when the input is even.

    bool isodd(int in){
        return 2 * ((int) (0.5 * in)) != in;
    }//Returns True bool value when the input is odd.

}

namespace qmathf{

    int sign(float in) {
        return (in > 0) - (in < 1);
    }//Returns the sign of the given float.

    int sign(int in) {
        return (in > 0) - (in < 1);
    }//Returns the sign of the given int.

    float abs(const float in) {
        return in * (in > 0) - in * (in < 0);
    }//Returns the absolute value of the given float.

    int abs(const int in) {
        return in * (in > 0) - in * (in < 0);
    }//Returns the absolute value of the given int.

    long long abs(const long int in) {
        return in * (in > 0) - in * (in < 0);
    }//Returns the absolute value of the given long int.

    double frexp(const double in1, int *in2) {
        *in2 = ((0x7ff0000000000000 & (*(long long *) &in1)) >> 52) - 1022;
        return 1.1102230246251565e-16 * (0x000fffffffffffff & (*(long long *) &in1)) + 0.5;
    }//Returns the mantissa and exponent of the given double.

    double frexp(const double in1, short *in2) {
        *in2 = ((0x7ff0000000000000 & (*(long long *) &in1)) >> 52) - 1022;
        return 1.1102230246251565e-16 * (0x000fffffffffffff & (*(long long *) &in1)) + 0.5;
    }//Returns the mantissa and exponent of the given double.

    float ldexp(const float in1, const long in2){
        return in1 * ((in2 + 127) << 23);
    }//Returns the float constructed from the given mantissa and exponent.

    int floor(const float in){
        int sign = (in > 0) - (in < 0);
        int val = (int) (in * sign);
        return (val + 0.5 + 0.5 * (in < 0) * sign + 1.5 * (in < 0) * (val * sign != in)) * sign;
    }//Returns the current double rounded down.

    int ceil(const float in){
        int sign = (in > 0) - (in < 0);
        int val = (int) (in * sign);
        return (val + (sign + (in < 0)) * (in * sign != val)) * sign;
    }//Returns the current double rounded up.

    bool iseven(int in){
        return 2 * ((int) (0.5 * in)) == in;
    }//Returns True bool value when the input is even.

    bool isodd(int in){
        return 2 * ((int) (0.5 * in)) != in;
    }//Returns True bool value when the input is odd.


}
