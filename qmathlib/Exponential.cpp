namespace qmath{

    //~30% faster than std::log with the MSVC compiler
    double log(const double in) {
        const int exp = ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 1023;
        const double base = 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in)) + 1;

        const double base1 = (base - 1) / (base + 1);

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;
        const double base8 = base4 * base4;

        return exp * 0.69314718055994531 + 2 * base1 * (1 + 0.33333333333333333 * base2 + 0.2 * base4 + 0.14285714285714286 * base4 * base2 + 0.11111111111111111 * base8 + 0.090909090909090909 * base8 * base2 + 0.076923076923076923 * base8 * base4 + 0.066666666666666667 * base8 * base4 * base2 + 0.058823529411764706 * base8 * base8);
    }//Returns the natural logarithm of the given double whose accuracy depends entirely on the mantissa of the double.

    //~30% faster than std::log with the MSVC compiler
    double qlog(const double in) {
        const int exp = ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 1023;
        const double base = 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in)) + 1;

        const double base1 = (base - 1) / (base + 1);

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;
        const double base8 = base4 * base4;

        return exp * 0.69314718055994531 + 2 * base1 * (1 + 0.33333333333333333 * base2 + 0.2 * base4 + 0.14285714285714286 * base4 * base2 + 0.11111111111111111 * base8 + 0.090909090909090909 * base8 * base2 + 0.076923076923076923 * base8 * base4 + 0.066666666666666667 * base8 * base4 * base2 + 0.058823529411764706 * base8 * base8);
    }//Quickly returns the natural logarithm of the given double whose accuracy depends entirely on the mantissa of the double.

    //~60% faster than std::sqrt with the MSVC compiler
    double sqrt(const double in){
        const double exp = (0.5 * ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 511.5);
        const double base1 = 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in)) - 0.5;

        union DouToInt{
            double asDou;
            long long int asInt;
        };

        DouToInt exp1;
        exp1.asInt = (((long long) exp) + 1023) << 52;

        exp1.asDou *= (1.2247448713915890 + 0.40824829046386302 * base1) * (1 + 0.69314718055994531 * (exp - (int) exp));

        const double exp2 = exp1.asDou * exp1.asDou;
        const double exp4 = exp2 * exp2;
        const double in2 = in * in;

        return (in2 * in2 + 28 * in2 * in * exp2 + 70 * in2 * exp4 + 28 * in * exp4 * exp2 + exp4 * exp4) / (8 * in * in2 * exp1.asDou + 56 * in2 * exp2 * exp1.asDou + 56 * in * exp4 * exp1.asDou + 8 * exp4 * exp2 * exp1.asDou);

    }//Return the square root of the given double.

    //~40% faster than std::exp with the MSVC compiler
    double exp(const double in){
        const long int val = (long int) (1.4426950408889634 * in);
        const double dec1 = 1.4426950408889634 * in - val;
        const double dec2 = dec1 * dec1;
        const double dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = (long long int) (val + 1023);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        double base2 = 1 + 0.086643397569993164 * dec1 + 0.0037535391712359486 * dec2 + 0.00010840646223597965 * dec2 * dec1 + 2.3481760516671087e-6 * dec4 + 4.0690790241786021e-8 * dec4 * dec1 + 5.8759805272604408e-10 * dec4 * dec2 + 7.2730702419566347e-12 * dec4 * dec2 * dec1;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        return base2 * derp.asDou;

    }//Returns Euler's number raised to the double power, accurate to a around of 8 decimal places.

    //~88% faster than std::cosh with the MSVC compiler
    double cosh(const double in){
        const long int val = (long int) (1.4426950408889634 * in);
        const double dec1 = 1.4426950408889634 * in - val;
        const double dec2 = dec1 * dec1;
        const double dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = (long long int) (val + 1023);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        double base2 = 1 + 0.086643397569993164 * dec1 + 0.0037535391712359486 * dec2 + 0.00010840646223597965 * dec2 * dec1 + 2.3481760516671087e-6 * dec4 + 4.0690790241786021e-8 * dec4 * dec1 + 5.8759805272604408e-10 * dec4 * dec2 + 7.2730702419566347e-12 * dec4 * dec2 * dec1;// + 7.8770439566041884e-14 * dec4 * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const double final = base2 * derp.asDou;

        return 0.5 * final + 0.5 / final;
    }//Returns the hyperbolic Cosine of the given double, accurate to around 8 decimal places.

    //~88% faster than std::sinh with the MSVC compiler
    double sech(const double in){
        const long int val = (long int) (1.4426950408889634 * in);
        const double dec1 = 1.4426950408889634 * in - val;
        const double dec2 = dec1 * dec1;
        const double dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = (long long int) (val + 1023);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        double base2 = 1 + 0.086643397569993164 * dec1 + 0.0037535391712359486 * dec2 + 0.00010840646223597965 * dec2 * dec1 + 2.3481760516671087e-6 * dec4 + 4.0690790241786021e-8 * dec4 * dec1 + 5.8759805272604408e-10 * dec4 * dec2 + 7.2730702419566347e-12 * dec4 * dec2 * dec1;// + 7.8770439566041884e-14 * dec4 * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const double final = base2 * derp.asDou;

        return 2 * final / (final * final + 1);
    }//Returns the hyperbolic Secant of the given double, accurate to around 8 decimal places.

    //~88% faster than std::sinh with the MSVC compiler
    double sinh(const double in){
        const long int val = (long int) (1.4426950408889634 * in);
        const double dec1 = 1.4426950408889634 * in - val;
        const double dec2 = dec1 * dec1;
        const double dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = (long long int) (val + 1023);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        double base2 = 1 + 0.086643397569993164 * dec1 + 0.0037535391712359486 * dec2 + 0.00010840646223597965 * dec2 * dec1 + 2.3481760516671087e-6 * dec4 + 4.0690790241786021e-8 * dec4 * dec1 + 5.8759805272604408e-10 * dec4 * dec2 + 7.2730702419566347e-12 * dec4 * dec2 * dec1;// + 7.8770439566041884e-14 * dec4 * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const double final = base2 * derp.asDou;

        return 0.5 * final - 0.5 / final;
    }//Returns the hyperbolic Sine of the given double, accurate to around 8 decimal places.

    //~88% faster than std::sinh with the MSVC compiler
    double csch(const double in){
        const long int val = (long int) (1.4426950408889634 * in);
        const double dec1 = 1.4426950408889634 * in - val;
        const double dec2 = dec1 * dec1;
        const double dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = (long long int) (val + 1023);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        double base2 = 1 + 0.086643397569993164 * dec1 + 0.0037535391712359486 * dec2 + 0.00010840646223597965 * dec2 * dec1 + 2.3481760516671087e-6 * dec4 + 4.0690790241786021e-8 * dec4 * dec1 + 5.8759805272604408e-10 * dec4 * dec2 + 7.2730702419566347e-12 * dec4 * dec2 * dec1;// + 7.8770439566041884e-14 * dec4 * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const double final = base2 * derp.asDou;

        return 2 * final / (final * final - 1);
    }//Returns the hyperbolic Cosecant of the given double, accurate to around 8 decimal places.

    //~5-10% faster than std::tanh with the MSVC compiler
    double tanh(const double in){
        const long int val = (long int) (1.4426950408889634 * in);
        const double dec1 = 1.4426950408889634 * in - val;
        const double dec2 = dec1 * dec1;
        const double dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = (long long int) (val + 1023);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        double base2 = 1 + 0.086643397569993164 * dec1 + 0.0037535391712359486 * dec2 + 0.00010840646223597965 * dec2 * dec1 + 2.3481760516671087e-6 * dec4 + 4.0690790241786021e-8 * dec4 * dec1 + 5.8759805272604408e-10 * dec4 * dec2 + 7.2730702419566347e-12 * dec4 * dec2 * dec1;// + 7.8770439566041884e-14 * dec4 * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const double final = base2 * derp.asDou;

        return (final * final - 1) / (final * final + 1);
    }

    //~5-10% faster than std::tanh with the MSVC compiler
    double coth(const double in) {
        const long int val = (long int) in;
        const double base1 = (in - val);
        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        union doutoint {
            long long asInt;
            double asDou;
        };

        const long long int whoexp = ((int) (1.4426950408889634 * val) + 1023);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        const double decexp1 = 1.4426950408889634 * val - (int) (1.4426950408889634 * val);
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        const double val1 = 1 + 0.5 * base1 + 0.125 * base2 + 0.020833333333333333 * base2 * base1 + 0.0026041666666666667 * base4 + 0.00026041666666666667 * base4 * base1 + 0.000021701388888888889 * base4 * base2 + 1.5500992063492063e-6 * base4 * base2 * base1 + 9.6881200396825397e-8 * base4 * base4;
        const double val2 = 1 + 0.34657359027997265 * decexp1 + 0.060056626739775178 * decexp2 + 0.0069380135831026975 * decexp2 * decexp1 + 0.00060113306922677982 * decexp4 + 0.000041667369207588886 * decexp4 * decexp1 + 2.4068016239658766e-6 * decexp4 * decexp2 + 1.1916198284421750e-7 * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9 * decexp4 * decexp4;

        const double final = val1 * val1 * val2 * val2 * derp.asDou;

        return (final * final + 1) / (final * final + 1);
    }

}

namespace qmathf{
    //~30% faster than std::log with the MSVC compiler
    float log(const double in) {
        const int exp = ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 1023;
        const double base = 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in)) + 1;

        const double base1 = (base - 1) / (1 + base);

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;
        const double base8 = base4 * base4;

        return exp * 0.69314718055994531 + 2 * base1 * (1 + 0.33333333333333333 * base2 + 0.2 * base4 + 0.14285714285714286 * base4 * base2 + 0.11111111111111111 * base8 + 0.090909090909090909 * base8 * base2);
    }//Returns the natural logarithm of the given double whose accuracy depends entirely on the mantissa of the double.

    //~30% faster than std::log with the MSVC compiler
    float qlog(const double in) {
        const int exp = ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 1023;
        const double base = 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in)) + 1;

        const double base1 = (base - 1) / (1 + base);

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;
        const double base8 = base4 * base4;

        return exp * 0.69314718055994531 + 2 * base1 * (1 + 0.33333333333333333 * base2 + 0.2 * base4);
    }//Quickly returns the natural logarithm of the given double whose accuracy depends entirely on the mantissa of the double.

    //~60% faster than std::sqrt with the MSVC compiler
    float sqrt(const float in){
        const float exp = (0.5f * ((0x7F800000 & (*(int *) &in)) >> 23) - 63.5);
        const float base1 = 1.192092896e-7f * (0x000fffff & (*(int *) &in)) - 0.5f;

        union DouToInt{
            float asFlo;
            long long int asInt;
        };

        DouToInt exp1;
        exp1.asInt = (((int) exp) + 127) << 23;

        exp1.asFlo *= (1.22474487f + 0.40824829f * base1) * (1 + 0.6931471f * (exp - (int) exp));

        const float exp2 = exp1.asFlo * exp1.asFlo;
        const float exp4 = exp2 * exp2;
        const float in2 = in * in;

        return (in2 * in2 + 28 * in2 * in * exp2 + 70 * in2 * exp4 + 28 * in * exp4 * exp2 + exp4 * exp4) / (8 * in * in2 * exp1.asFlo + 56 * in2 * exp2 * exp1.asFlo + 56 * in * exp4 * exp1.asFlo + 8 * exp4 * exp2 * exp1.asFlo);

    }//Return the square root of the given float.

    //~40% faster than std::exp with the MSVC compiler
    float exp(const float in){
        const long int val = (long int) (1.44269504f * in);
        const float dec1 = 1.44269504f * in - val;
        const float dec2 = dec1 * dec1;
        const float dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long int whoexp = (long int) (val + 127);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        float base2 = 1 + 0.08664339f * dec1 + 0.00375353f * dec2 + 0.00010840f * dec2 * dec1 + 2.34817605e-6f * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        return base2 * derp.asFlo;

    }//Returns Euler's number raised to the float power, accurate to around 6 decimal places.

    //~88% faster than std::cosh with the MSVC compiler
    float cosh(const float in){
        const long int val = (long int) (1.44269504f * in);
        const float dec1 = 1.44269504f * in - val;
        const float dec2 = dec1 * dec1;
        const float dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long int whoexp = (long int) (val + 127);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        float base2 = 1 + 0.08664339f * dec1 + 0.00375353f * dec2 + 0.00010840f * dec2 * dec1 + 2.34817605e-6f * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const float final = base2 * derp.asFlo;

        return 0.5f * final + 0.5f / final;
    }//Returns the hyperbolic Cosine of the given float, accurate to around 6 decimal places.

    //~88% faster than std::sinh with the MSVC compiler
    float sech(const float in){
        const long int val = (long int) (1.44269504f * in);
        const float dec1 = 1.44269504f * in - val;
        const float dec2 = dec1 * dec1;
        const float dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long int whoexp = (long int) (val + 127);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        float base2 = 1 + 0.08664339f * dec1 + 0.00375353f * dec2 + 0.00010840f * dec2 * dec1 + 2.34817605e-6f * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const float final = base2 * derp.asFlo;

        return 1.f / (0.5f * final + 0.5f / final);
    }//Returns the hyperbolic Secant of the given float, accurate to around 6 decimal places.

    //~88% faster than std::sinh with the MSVC compiler
    float sinh(const float in){
        const long int val = (long int) (1.44269504f * in);
        const float dec1 = 1.44269504f * in - val;
        const float dec2 = dec1 * dec1;
        const float dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long int whoexp = (long int) (val + 127);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        float base2 = 1 + 0.08664339f * dec1 + 0.00375353f * dec2 + 0.00010840f * dec2 * dec1 + 2.34817605e-6f * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const float final = base2 * derp.asFlo;

        return 0.5f * final - 0.5f / final;
    }//Returns the hyperbolic Sine of the given float, accurate to around 6 decimal places.

    //~88% faster than std::sinh with the MSVC compiler
    float csch(const float in){
        const long int val = (long int) (1.44269504f * in);
        const float dec1 = 1.44269504f * in - val;
        const float dec2 = dec1 * dec1;
        const float dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long int whoexp = (long int) (val + 127);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        float base2 = 1 + 0.08664339f * dec1 + 0.00375353f * dec2 + 0.00010840f * dec2 * dec1 + 2.34817605e-6f * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const float final = base2 * derp.asFlo;

        return 1 / (0.5f * final - 0.5f / final);
    }//Returns the hyperbolic Cosecant of the given float, accurate to around 6 decimal places.

    //~5-10% faster than std::tanh with the MSVC compiler
    float tanh(const float in){
        const long int val = (long int) (1.44269504f * in);
        const float dec1 = 1.44269504f * in - val;
        const float dec2 = dec1 * dec1;
        const float dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long int whoexp = (long int) (val + 127);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        float base2 = 1 + 0.08664339f * dec1 + 0.00375353f * dec2 + 0.00010840f * dec2 * dec1 + 2.34817605e-6f * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const float final = base2 * derp.asFlo;

        return (final * final - 1) / (final * final + 1);
    }

    float coth(const float in) {
        const long int val = (long int) (1.44269504f * in);
        const float dec1 = 1.44269504f * in - val;
        const float dec2 = dec1 * dec1;
        const float dec4 = dec2 * dec2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long int whoexp = (long int) (val + 127);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        float base2 = 1 + 0.08664339f * dec1 + 0.00375353f * dec2 + 0.00010840f * dec2 * dec1 + 2.34817605e-6f * dec4;

        base2 *= base2;
        base2 *= base2;
        base2 *= base2;

        const float final = base2 * derp.asFlo;

        return (final * final + 1) / (final * final - 1);
    }
};
