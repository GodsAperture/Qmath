
namespace qmath {

    int sign(double in) {
        return (in > 0) - (in < 1);
    }//Returns the sign of the given double.

    int sign(int in) {
        return (in > 0) - (in < 0);
    }//Returns the sign of the given int.

    double abs(const double in){
        return in * (in > 0) - in * (in < 0);
    }

    int abs(const int in) {
        return in * (in > 0) - in * (in < 0);
    }//Returns the absolute value of the given int.

    long long abs(const long int in) {
        return in * (in > 0) - in * (in < 0);
    }//Returns the absolute value of the given long int.

    double frexp(const double in1, int *in2) {
        *in2 = ((0x7ff0000000000000 & (*(long long *) &in1)) >> 52) - 1023;
        return 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in1)) + 1;
    }//Returns the mantissa and exponent of the given double.

    double frexp(const double in1, short *in2) {
        *in2 = ((0x7ff0000000000000 & (*(long long *) &in1)) >> 52) - 1023;
        return 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in1)) + 1;
    }//Returns the mantissa and exponent of the given double.

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

    float frexp(const float in1, int *in2) {
        *in2 = ((0x7F800000 & (*(long *) &in1)) >> 23) - 127;
        return 1.192092896e-7f * (0x000fffff & (*(long *) &in1)) + 1;
    }//Returns the mantissa and the exponent of the given float.

    float frexp(const float in1, short *in2) {
        *in2 = ((0x7F800000 & (*(long *) &in1)) >> 23) - 127;
        return 1.192092896e-7f * (0x000fffff & (*(long *) &in1)) + 1;
    }//Returns the mantissa and the exponent of the given float.

}
