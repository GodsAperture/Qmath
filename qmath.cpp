//Mathematics algorithms: Joshua Champion.
//Computer science algorithms: Andrew Rubenstein.
//Contact on Discord: GodsAperture#8507
//Discord Computer Science server: https://discord.gg/Uv5eErc

namespace qmath {
    double QMATHDELTA;
    static const double Pi = 3.1415926535897932;
    static const double E  = 2.7182818284590452;

    ////SPECIAL MATH FUNCTIONS////

//    int sign(auto in){
//        return in < 0 ? -1 : 1;
//    }

    double abs(const double in){
        union doutoint{
            double asDou;
            long long asInt;
        };
        doutoint val = {in};
        val.asInt &= 0x7fffffffffffffff;
        return val.asDou;
    }//Returns the absolute value of the given double.

    float abs(const float in){
        union flotoint{
            float asFlo;
            long asInt;
        };
        flotoint val = {in};
        val.asInt &= 0x7fffffff;
        return val.asFlo;
    }

    int abs(const int in) {
        union flotoint {
            float asFlo;
            int asInt;
        };
        flotoint val = {(float) in};
        val.asInt &= 0x7fffffff;
        return val.asFlo;
    }

    long long abs(const long int in){
        union doutoint {
            double asDou;
            long long asInt;
        };
        doutoint val = {(double) in};
        val.asInt &= 0x7fffffffffffffff;
        return val.asDou;
    }

    double frexp(const double in1, int* in2) {
        *in2 = ((0x7ff0000000000000 & (*(long long *) &in1)) >> 52) - 1023;
        return 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in1)) + 1;
    }//Returns the mantissa and exponent of the given double.

    double frexp(const double in1, short* in2) {
        *in2 = ((0x7ff0000000000000 & (*(long long *) &in1)) >> 52) - 1023;
        return 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in1)) + 1;
    }//Returns the mantissa and exponent of the given double.

    float frexp(const float in1, int* in2) {
        *in2 = ((0x7F800000 & (*(long *) &in1)) >> 23) - 127;
        return 1.192092896e-7f * (0x000fffff & (*(long *) &in1)) + 1;
        }//Returns the mantissa and the exponent of the given float.

    float frexp(const float in1, short* in2) {
        *in2 = ((0x7F800000 & (*(long *) &in1)) >> 23) - 127;
        return 1.192092896e-7f * (0x000fffff & (*(long *) &in1)) + 1;
    }//Returns the mantissa and the exponent of the given float.

    ////TRIGONOMETRIC MATH FUNCTIONS////

//~25% faster than std::sin
    double sin(const double in) {
        //Forces `in` to be between -Pi and Pi and then divides it by 8.
        const double ang = 0.125 * in - 0.78539816339744831 * ((int) (0.15915494309189534 * in + 0.39269908169872415)) - 0.19634954084936208;

        const double ang2 = ang * ang; //ang^2
        const double ang4 = ang2 * ang2; //ang^4
        const double ang8 = ang4 * ang4; //ang^8

        //Accurately approximates the Cosine of the given angle.
        const double cosang = 1 - 0.5 * ang2 + 0.041666666666666667 * ang4 - 0.0013888888888888889 * ang4 * ang2 + 0.000024801587301587302 * ang8 - 2.7557319223985891e-7 * ang8 * ang2 + 2.0876756987868099e-9 * ang8 * ang4;
        const double cosang2 = cosang * cosang;
        const double cosang4 = cosang2 * cosang2;

        //8th angle formula for Cosine.
        return 1 - 32 * cosang2 + 160 * cosang4 - 256 * cosang4 * cosang2 + 128 * cosang4 * cosang4;
    }//Returns the Sine of the given double, accurate to around 12 decimal places.

//~40% faster than std::sin
    float sin(const float in) {
        //Forces `in` to be between -Pi and Pi and then divides it by 8.
        const float ang = 0.125f * in - 0.78539816339744831f * ((int) (0.15915494309189534f * in + 0.39269908169872415f)) - 0.19634954084936208f;

        const float ang2 = ang * ang; //ang^2
        const float ang4 = ang2 * ang2; //ang^4
        const float ang8 = ang4 * ang4; //ang^8

        //Accurately approximates the Cosine of the given angle.
        const float cosang = 1 - 0.5f * ang2 + 0.041666666666666667f * ang4 - 0.0013888888888888889f * ang4 * ang2 + 0.000024801587301587302f * ang8 - 2.7557319223985891e-7f * ang8 * ang2 + 2.0876756987868099e-9f * ang8 * ang4;
        const float cosang2 = cosang * cosang;
        const float cosang4 = cosang2 * cosang2;

        //8th angle formula for Cosine.
        return 1.f - 32.f * cosang2 + 160.f * cosang4 - 256.f * cosang4 * cosang2 + 128.f * cosang4 * cosang4;
    }//Returns the Sine of the given double, accurate to around 12 decimal places.

//~45% faster than std::sin
    double qsin(const double in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const double ang = 0.125 * in - 0.78539816339744831 * ((int) (0.15915494309189534 * in + 0.39269908169872415)) - 0.19634954084936208;
        const double ang2 = ang * ang; //ang^2

        const double cosang = 1 - 0.5 * ang2 + 0.041666666666666667 * ang2 * ang2; //Approximates the Cosine of the angle.
        const double cosang2 = cosang * cosang;
        const double cosang4 = cosang2 * cosang2;

        return 1 - 32 * cosang2 + 160 * cosang4 - 256 * cosang4 * cosang2 + 128 * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Sine of a given double, accurate to around 5 decimal places.

//~50% faster than std::sin
    float qsin(const float in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const float ang = 0.125f * in - 0.78539816339744831f * ((int) (0.15915494309189534f * in + 0.39269908169872415f)) - 0.19634954084936208f;
        const float ang2 = ang * ang; //ang^2

        const float cosang = 1.f - 0.5f * ang2 + 0.041666666666666667f * ang2 * ang2; //Approximates the Cosine of the angle.
        const float cosang2 = cosang * cosang;
        const float cosang4 = cosang2 * cosang2;

        return 1.f - 32.f * cosang2 + 160.f * cosang4 - 256.f * cosang4 * cosang2 + 128.f * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Sine of a given double, accurate to around 3 decimal places.

//~25% faster than std::cos
    double cos(const double in) {
        const double ang = 0.125 * in - 0.78539816339744831 * ((int) (0.15915494309189534 * in + 0.39269908169872415));

        const double ang2 = ang * ang; //ang^2
        const double ang4 = ang2 * ang2; //ang^4
        const double ang8 = ang4 * ang4; //ang^8

        //Accurately approximates the Cosine of the given angle.
        const double cosang = 1 - 0.5 * ang2 + 0.041666666666666667 * ang4 - 0.0013888888888888889 * ang4 * ang2 + 0.000024801587301587302 * ang8 - 2.7557319223985891e-7 * ang8 * ang2 + 2.0876756987868099e-9 * ang8 * ang4;
        const double cosang2 = cosang * cosang;
        const double cosang4 = cosang2 * cosang2;

        //8th angle formula for Cosine.
        return 1 - 32 * cosang2+ 160 * cosang4 - 256 * cosang4 * cosang2 + 128 * cosang4 * cosang4;
    }//Returns the Cosine of the given double, accurate to around 12 decimal places.

//~45% faster than std::cos
    float cos(const float in) {
        const float ang = 0.125f * in - 0.78539816339744831f * ((int) (0.15915494309189534f * in + 0.39269908169872415f));

        const float ang2 = ang * ang; //ang^2
        const float ang4 = ang2 * ang2; //ang^4
        const float ang8 = ang4 * ang4; //ang^8

        //Accurately approximates the Cosine of the given angle.
        const float cosang = 1.f - 0.5f * ang2 + 0.041666666666666667f * ang4 - 0.0013888888888888889f * ang4 * ang2 + 0.000024801587301587302f * ang8 - 2.7557319223985891e-7f * ang8 * ang2 + 2.0876756987868099e-9f * ang8 * ang4;
        const float cosang2 = cosang * cosang;
        const float cosang4 = cosang2 * cosang2;

        //8th angle formula for Cosine.
        return 1.f - 32.f * cosang2 + 160.f * cosang4 - 256.f * cosang4 * cosang2 + 128.f * cosang4 * cosang4;
    }//Returns the Cosine of the given float, accurate to around 12 decimal places.

//~45% faster than std::cos
    double qcos(const double in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const double ang = 0.125 * in - 0.78539816339744831 * ((int) (0.15915494309189534 * in + 0.39269908169872415));
        const double ang2 = ang * ang; //ang^2

        const double cosang = 1 - 0.5 * ang2 + 0.041666666666666667 * ang2 * ang2; //Approximates the Cosine of the angle.
        const double cosang2 = cosang * cosang;
        const double cosang4 = cosang2 * cosang2;

        return 1 - 32 * cosang2 + 160 * cosang4 - 256 * cosang4 * cosang2 + 128 * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Cosine of a given double, accurate to around 5 decimal places.

//~50% faster than std::cos
    float qcos(const float in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const float ang = 0.125f * in - 0.78539816339744831f * ((int) (0.15915494309189534f * in + 0.39269908169872415f));
        const float ang2 = ang * ang; //ang^2

        const float cosang = 1.f - 0.5f * ang2 + 0.041666666666666667f * ang2 * ang2; //Approximates the Cosine of the angle.
        const float cosang2 = cosang * cosang;
        const float cosang4 = cosang2 * cosang2;

        return 1.f - 32.f * cosang2 + 160.f * cosang4 - 256.f * cosang4 * cosang2 + 128.f * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Cosine of the given float, accurate to around 3 decimal places.

//~25% faster than std::tan
    double tan(const double in) {
        const double ang =
                -0.0625 * in + 0.19634954084936208 * ((int) (0.31830988618379067 * (in + 1.5707963267948966)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;
        const double ang3 = ang2 * ang2;

        const double tanang = ang * (1 + 0.33333333333333333 * ang1 + 0.13333333333333333 * ang2 + 0.053968253968253968 * ang2 * ang1 + 0.021869488536155203 * ang3 + 0.0088632355299021966 * ang3 * ang1 + 0.0035921280365724810 * ang3 * ang2 + 0.0014558343870513183 * ang3 * ang2 * ang1 + 0.00059002744094558598 * ang3 * ang3);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;
        const double tanang3 = tanang2 * tanang2;

        return 16 * tanang *
               (tanang3 * tanang2 * tanang1 - 35 * tanang3 * tanang2 + 273 * tanang3 * tanang1 - 715 * tanang3 + 715 * tanang2 * tanang1 - 273 * tanang2 + 35 * tanang1 - 1) / (tanang3 * tanang3 - 120 * tanang3 * tanang2 * tanang1 + 1820 * tanang3 * tanang2 - 8008 * tanang3 * tanang1 + 12870 * tanang3 - 8008 * tanang2 * tanang1 + 1820 * tanang2 - 120 * tanang1 +1);
    }//Returns the Tangent of the given double, accurate to around 10 decimal places.

//~35% faster than std::tan
    float tan(const float in){
        const float ang = -0.0625f * in + 0.19634954084936208f * ((int) (0.31830988618379067f * (in + 1.5707963267948966f)));
        const float ang1 = ang * ang;
        const float ang2 = ang1 * ang1;
        const float ang3 = ang2 * ang2;

        const float tanang = ang * (1.f + 0.33333333333333333f * ang1 + 0.13333333333333333f * ang2 + 0.053968253968253968f * ang2 * ang1 + 0.021869488536155203f * ang3 + 0.0088632355299021966f * ang3 * ang1 + 0.0035921280365724810f * ang3 * ang2 + 0.0014558343870513183f * ang3 * ang2 * ang1 + 0.00059002744094558598f * ang3 * ang3);
        const float tanang1 = tanang * tanang;
        const float tanang2 = tanang1 * tanang1;
        const float tanang3 = tanang2 * tanang2;

        return 16.f * tanang * (tanang3 * tanang2 * tanang1 - 35.f * tanang3 * tanang2 + 273.f * tanang3 * tanang1 - 715.f * tanang3 + 715.f * tanang2 * tanang1 - 273.f * tanang2 + 35.f * tanang1 - 1.f) / (tanang3 * tanang3 - 120.f * tanang3 * tanang2 * tanang1 + 1820.f * tanang3 * tanang2 - 8008.f * tanang3 * tanang1 + 12870.f * tanang3 - 8008.f * tanang2 * tanang1 + 1820.f * tanang2 - 120.f * tanang1 +1.f);
    }//Returns the Tangent of the given float, accuracy depends on how near a pole the float is.

//~45% faster than std::tan
    double qtan(const double in) {
        const double ang =
                -0.125 * in + 0.39269908169872415 * ((int) (0.31830988618379067 * (in + 1.5707963267948966)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;

        const double tanang = ang * (1 + 0.33333333333333333 * ang1 + 0.13333333333333333 * ang2 + 0.053968253968253968 * ang2 * ang1);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;

        return 8 * tanang * (tanang2 * tanang1 - 7 * tanang2 + 7 * tanang1 - 1) / (tanang2 * tanang2 - 28 * tanang2 * tanang1 + 70 * tanang2 - 28 * tanang1 + 1);
    }//Quickly returns the Tangent of the given double, accuracy depends on how near a pole the float is.

//~25% faster than std::tan
    double cot(const double in) {
        const double ang =
                -0.0625 * in + 0.19634954084936208 * ((int) (0.31830988618379067 * (in + 1.5707963267948966)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;
        const double ang3 = ang2 * ang2;

        const double tanang = ang * (1 + 0.33333333333333333 * ang1 + 0.13333333333333333 * ang2 +
                                     0.053968253968253968 * ang2 * ang1 + 0.021869488536155203 * ang3 +
                                     0.0088632355299021966 * ang3 * ang1 + 0.0035921280365724810 * ang3 * ang2 +
                                     0.0014558343870513183 * ang3 * ang2 * ang1 + 0.00059002744094558598 * ang3 * ang3);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;
        const double tanang3 = tanang2 * tanang2;

        return (tanang3 * tanang3 - 120 * tanang3 * tanang2 * tanang1 + 1820 * tanang3 * tanang2 -
                8008 * tanang3 * tanang1 + 12870 * tanang3 - 8008 * tanang2 * tanang1 + 1820 * tanang2 - 120 * tanang1 +
                1) / (16 * tanang *
                      (tanang3 * tanang2 * tanang1 - 35 * tanang3 * tanang2 + 273 * tanang3 * tanang1 - 715 * tanang3 +
                       715 * tanang2 * tanang1 - 273 * tanang2 + 35 * tanang1 - 1));
    }//Returns the Cotangent of the given double, accurate to around 10 decimal places.

//~35% faster than std::tan
    float fcot(const float in){
        const float ang = -0.0625f * in + 0.19634954084936208f * ((int) (0.31830988618379067f * (in + 1.5707963267948966f)));
        const float ang1 = ang * ang;
        const float ang2 = ang1 * ang1;
        const float ang3 = ang2 * ang2;

        const float tanang = ang * (1.f + 0.33333333333333333f * ang1 + 0.13333333333333333f * ang2 + 0.053968253968253968f * ang2 * ang1 + 0.021869488536155203f * ang3 + 0.0088632355299021966f * ang3 * ang1 + 0.0035921280365724810f * ang3 * ang2 + 0.0014558343870513183f * ang3 * ang2 * ang1 + 0.00059002744094558598f * ang3 * ang3);
        const float tanang1 = tanang * tanang;
        const float tanang2 = tanang1 * tanang1;
        const float tanang3 = tanang2 * tanang2;

        return 0.0625f * (tanang3 * tanang3 - 120.f * tanang3 * tanang2 * tanang1 + 1820.f * tanang3 * tanang2 - 8008.f * tanang3 * tanang1 + 12870.f * tanang3 - 8008.f * tanang2 * tanang1 + 1820.f * tanang2 - 120.f * tanang1 +1.f) / (tanang * (tanang3 * tanang2 * tanang1 - 35.f * tanang3 * tanang2 + 273.f * tanang3 * tanang1 - 715.f * tanang3 + 715.f * tanang2 * tanang1 - 273.f * tanang2 + 35.f * tanang1 - 1.f));
    }//Returns the Cotangent of the given float, accuracy depends on how near a pole the float is.

//~45% faster than std::cot
    double qcot(const double in) {
        const double ang =
                -0.125 * in + 0.39269908169872415 * ((int) (0.31830988618379067 * (in + 1.5707963267948966)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;

        const double tanang = ang * (1 + 0.33333333333333333 * ang1 + 0.13333333333333333 * ang2 +
                                     0.053968253968253968 * ang2 * ang1);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;

        return 0.125 * (tanang2 * tanang2 - 28 * tanang2 * tanang1 + 70 * tanang2 - 28 * tanang1 + 1) /
               (tanang * (tanang2 * tanang1 - 7 * tanang2 + 7 * tanang1 - 1));
    }//Quickly returns the Cotangent of the given double, accurate to a minimum of 7 decimal places.

    ////EXPONENTIALLY BASED FUNCTIONS////

//~20% faster than std::log
    double log(const double in) {
        const int exp = ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 1023;
        const double base1 = 0.5 - 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in));

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;
        const double base8 = base4 * base4;

        return exp * 0.69314718055994531 + 0.40546510810816438 - 0.66666666666666667 * base1 - 0.22222222222222222 * base2 - 0.098765432098765432 * base2 * base1 - 0.049382716049382716 * base4 - 0.026337448559670782 * base4 * base1 - 0.014631915866483768 * base4 * base2 - 0.0083610947808478673 * base4 * base2 * base1 - 0.0048773052888279226 * base8 - 0.0028902549859721023 * base8 * base1 - 0.0017341529915832614 * base8 * base2 - 0.0010510018130807645 * base8 * base2 * base1 - 0.00064227888577157828 * base8 * base4 - 0.00039524854509020202 * base8 * base4 * base1 - 0.00024467767077012506 * base8 * base4 * base2;
    }//Returns the natural logarithm of the given double whose accuracy depends entirely on the mantissa of the double.

////With the current logarithm definition, there will not be a float log.

//~30% faster than std::log
    double qlog(const double in) {
        const int exp = ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 1023;
        const double base1 = 0.5 - 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long*) &in));

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        return exp * 0.69314718055994531 + 0.40546510810816438 - 0.66666666666666667 * base1 - 0.22222222222222222 * base2 - 0.098765432098765432 * base2 * base1 - 0.049382716049382716 * base4 - 0.026337448559670782 * base4 * base1 - 0.014631915866483768 * base4 * base2 - 0.0083610947808478673 * base4 * base2 * base1;
        }//Quickly returns the natural logarithm of the given double whose accuracy depends entirely on the mantissa of the double.

////With the current logarithm definition, there will not be a float qlog.

////Slower, rework
    double sqrt(const double in){
        const double exp = 0.5 * ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 511.5;
        const double base1 = 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in)) - 0.5;

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        union DouToInt{
            double asDou;
            long long int asInt;
        };

        DouToInt newexp1;
        newexp1.asInt = (((long long int) exp) + 1023) << 52;
        const double decexp1 = exp - (int) exp;
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        return (1 + 0.69314718055994531 * decexp1 + 0.24022650695910071 * decexp2 + 0.055504108664821580 * decexp2 * decexp1 + 0.0096181291076284772 * decexp4 + 0.0013333558146428443 * decexp4 * decexp1 + 0.00015403530393381610 * decexp4 * decexp2 + 0.000015252733804059840 * decexp4 * decexp2 * decexp1 + 1.3215486790144309e-6 * decexp4 * decexp4) * newexp1.asDou * (1.2247448713915890 + 0.40824829046386302 * base1 - 0.068041381743977169 * base2 + 0.022680460581325723 * base2 * base1 - 0.0094501919088857180 * base4 + 0.0044100895574800017 * base4 * base1 - 0.0022050447787400009 * base4 * base2 + 0.0011550234555304766 * base4 * base2 * base1);
    }//Return the square root of the given input.

////Also slower
    double qsqrt(const double in){
        const double exp = 0.5 * ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 511.5;
        const double base1 = 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in)) - 0.5;

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        union DouToInt{
            double asDou;
            long long int asInt;
        };

        DouToInt newexp1;
        newexp1.asInt = (((long long int) exp) + 1023) >> 52;
        const double decexp1 = exp - (int) exp;
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        return (1 + 0.69314718055994531 * decexp1 + 0.24022650695910071 * decexp2 + 0.055504108664821580 * decexp2 * decexp1 + 0.0096181291076284772 * decexp4 + 0.0013333558146428443 * decexp4 * decexp1 + 0.00015403530393381610 * decexp4 * decexp2) * newexp1.asDou * (1.2247448713915890 + 0.40824829046386302 * base1 - 0.068041381743977169 * base2 + 0.022680460581325723 * base2 * base1 - 0.0094501919088857180 * base4 + 0.0044100895574800017 * base4 * base1 - 0.0022050447787400009 * base4 * base2);// + 0.0011550234555304766 * base4 * base2 * base1);
    }//Quickly returns the square root of the given input.

//~65% faster than std::exp
    double exp(const double in){
        const double base1 = (in - (int) in);
        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = ((int) (1.4426950408889634 * ((int) in)) + 1023) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        const double decexp1 = 1.4426950408889634 * ((int) in) - (int) (1.4426950408889634 * ((int) in));
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        const double val1 = 1 + 0.5 * base1 + 0.125 * base2 + 0.020833333333333333 * base2 * base1 + 0.0026041666666666667 * base4 + 0.00026041666666666667 * base4 * base1 + 0.000021701388888888889 * base4 * base2 + 1.5500992063492063e-6 * base4 * base2 * base1 + 9.6881200396825397e-8 * base4 * base4;
        const double val2 = 1 + 0.34657359027997265 * decexp1 + 0.060056626739775178 * decexp2 + 0.0069380135831026975 * decexp2 * decexp1 + 0.00060113306922677982 * decexp4 + 0.000041667369207588886 * decexp4 * decexp1 + 2.4068016239658766e-6 * decexp4 * decexp2 + 1.1916198284421750e-7 * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9 * decexp4 * decexp4;

        return val1 * val1 * val2 * val2 * derp.asDou;
    }//Returns Euler's number raised to the double power, accurate to a around of 8 decimal places.

//~65% faster than std::exp
    float exp(const float in){
        const float base1 = (in - (int) in);
        const float base2 = base1 * base1;
        const float base4 = base2 * base2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long long int whoexp = ((int) (1.4426950408889634f * ((int) in)) + 127) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        const float decexp1 = 1.4426950408889634f * ((int) in) - (int) (1.4426950408889634f * ((int) in));
        const float decexp2 = decexp1 * decexp1;
        const float decexp4 = decexp2 * decexp2;

        const float val1 = 1.f + 0.5f * base1 + 0.125f * base2 + 0.020833333333333333f * base2 * base1 + 0.0026041666666666667f * base4 + 0.00026041666666666667f * base4 * base1 + 0.000021701388888888889f * base4 * base2 + 1.5500992063492063e-6f * base4 * base2 * base1 + 9.6881200396825397e-8f * base4 * base4;
        const float val2 = 1.f + 0.34657359027997265f * decexp1 + 0.060056626739775178f * decexp2 + 0.0069380135831026975f * decexp2 * decexp1 + 0.00060113306922677982f * decexp4 + 0.000041667369207588886f * decexp4 * decexp1 + 2.4068016239658766e-6f * decexp4 * decexp2 + 1.1916198284421750e-7f * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9f * decexp4 * decexp4;

        return val1 * val1 * val2 * val2 * derp.asFlo;

    }//Returns Euler's number raised to the float power, accurate to around 6 decimal places.

//~90% faster than std::cosh
    double cosh(const double in){
        const double base1 = (in - (int) in);
        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = ((int) (1.4426950408889634 * ((int) in)) + 1023) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        const double decexp1 = 1.4426950408889634 * ((int) in) - (int) (1.4426950408889634 * ((int) in));
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        const double val1 = 1 + 0.5 * base1 + 0.125 * base2 + 0.020833333333333333 * base2 * base1 + 0.0026041666666666667 * base4 + 0.00026041666666666667 * base4 * base1 + 0.000021701388888888889 * base4 * base2 + 1.5500992063492063e-6 * base4 * base2 * base1 + 9.6881200396825397e-8 * base4 * base4;
        const double val2 = 1 + 0.34657359027997265 * decexp1 + 0.060056626739775178 * decexp2 + 0.0069380135831026975 * decexp2 * decexp1 + 0.00060113306922677982 * decexp4 + 0.000041667369207588886 * decexp4 * decexp1 + 2.4068016239658766e-6 * decexp4 * decexp2 + 1.1916198284421750e-7 * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9 * decexp4 * decexp4;

        const double final = val1 * val1 * val2 * val2 * derp.asDou;

        return 0.5 * final + 0.5 / final;
    }//Returns the hyperbolic Cosine of the given double, accurate to around 8 decimal places.

//~90% faster than std::cosh
    float cosh(const float in){
        const float base1 = (in - (int) in);
        const float base2 = base1 * base1;
        const float base4 = base2 * base2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long long int whoexp = ((int) (1.4426950408889634f * ((int) in)) + 127) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        const float decexp1 = 1.4426950408889634f * ((int) in) - (int) (1.4426950408889634f * ((int) in));
        const float decexp2 = decexp1 * decexp1;
        const float decexp4 = decexp2 * decexp2;

        const float val1 = 1.f + 0.5f * base1 + 0.125f * base2 + 0.020833333333333333f * base2 * base1 + 0.0026041666666666667f * base4 + 0.00026041666666666667f * base4 * base1 + 0.000021701388888888889f * base4 * base2 + 1.5500992063492063e-6f * base4 * base2 * base1 + 9.6881200396825397e-8f * base4 * base4;
        const float val2 = 1.f + 0.34657359027997265f * decexp1 + 0.060056626739775178f * decexp2 + 0.0069380135831026975f * decexp2 * decexp1 + 0.00060113306922677982f * decexp4 + 0.000041667369207588886f * decexp4 * decexp1 + 2.4068016239658766e-6f * decexp4 * decexp2 + 1.1916198284421750e-7f * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9f * decexp4 * decexp4;

        const float final = val1 * val1 * val2 * val2 * derp.asFlo;

        return 0.5f * final + 0.5f / final;
    }//Returns the hyperbolic Cosine of the given float, accurate to around 6 decimal places.

//~90% faster than std::sinh
    double sech(const double in){
        const double base1 = (in - (int) in);
        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = ((int) (1.4426950408889634 * ((int) in)) + 1023) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        const double decexp1 = 1.4426950408889634 * ((int) in) - (int) (1.4426950408889634 * ((int) in));
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        const double val1 = 1 + 0.5 * base1 + 0.125 * base2 + 0.020833333333333333 * base2 * base1 + 0.0026041666666666667 * base4 + 0.00026041666666666667 * base4 * base1 + 0.000021701388888888889 * base4 * base2 + 1.5500992063492063e-6 * base4 * base2 * base1 + 9.6881200396825397e-8 * base4 * base4;
        const double val2 = 1 + 0.34657359027997265 * decexp1 + 0.060056626739775178 * decexp2 + 0.0069380135831026975 * decexp2 * decexp1 + 0.00060113306922677982 * decexp4 + 0.000041667369207588886 * decexp4 * decexp1 + 2.4068016239658766e-6 * decexp4 * decexp2 + 1.1916198284421750e-7 * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9 * decexp4 * decexp4;

        const double final = val1 * val1 * val2 * val2 * derp.asDou;

        return 2 * final / (final * final + 1);
    }//Returns the hyperbolic Secant of the given double, accurate to around 8 decimal places.

//~90% faster than std::sinh
    float sech(const float in){
        const float base1 = (in - (int) in);
        const float base2 = base1 * base1;
        const float base4 = base2 * base2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long long int whoexp = ((int) (1.4426950408889634f * ((int) in)) + 127) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        const float decexp1 = 1.4426950408889634f * ((int) in) - (int) (1.4426950408889634f * ((int) in));
        const float decexp2 = decexp1 * decexp1;
        const float decexp4 = decexp2 * decexp2;

        const float val1 = 1.f + 0.5f * base1 + 0.125f * base2 + 0.020833333333333333f * base2 * base1 + 0.0026041666666666667f * base4 + 0.00026041666666666667f * base4 * base1 + 0.000021701388888888889f * base4 * base2 + 1.5500992063492063e-6f * base4 * base2 * base1 + 9.6881200396825397e-8f * base4 * base4;
        const float val2 = 1.f + 0.34657359027997265f * decexp1 + 0.060056626739775178f * decexp2 + 0.0069380135831026975f * decexp2 * decexp1 + 0.00060113306922677982f * decexp4 + 0.000041667369207588886f * decexp4 * decexp1 + 2.4068016239658766e-6f * decexp4 * decexp2 + 1.1916198284421750e-7f * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9f * decexp4 * decexp4;

        const float final = val1 * val1 * val2 * val2 * derp.asFlo;

        return 1.f / (0.5f * final + 0.5f / final);
    }//Returns the hyperbolic Secant of the given float, accurate to around 6 decimal places.

//~90% faster than std::sinh
    double sinh(const double in){
        const double base1 = (in - (int) in);
        const double base2 = base1 * base1;
        const double base4 = base2 * base2;



        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = ((int) (1.4426950408889634 * ((int) in)) + 1023) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        const double decexp1 = 1.4426950408889634 * ((int) in) - (int) (1.4426950408889634 * ((int) in));
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        const double val1 = 1 + 0.5 * base1 + 0.125 * base2 + 0.020833333333333333 * base2 * base1 + 0.0026041666666666667 * base4 + 0.00026041666666666667 * base4 * base1 + 0.000021701388888888889 * base4 * base2 + 1.5500992063492063e-6 * base4 * base2 * base1 + 9.6881200396825397e-8 * base4 * base4;
        const double val2 = 1 + 0.34657359027997265 * decexp1 + 0.060056626739775178 * decexp2 + 0.0069380135831026975 * decexp2 * decexp1 + 0.00060113306922677982 * decexp4 + 0.000041667369207588886 * decexp4 * decexp1 + 2.4068016239658766e-6 * decexp4 * decexp2 + 1.1916198284421750e-7 * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9 * decexp4 * decexp4;

        const double final = val1 * val1 * val2 * val2 * derp.asDou;

        return 0.5 * final - 0.5 / final;
    }//Returns the hyperbolic Sine of the given double, accurate to around 8 decimal places.

//~90% faster than std::sinh
    float sinh(const float in){
        const float base1 = (in - (int) in);
        const float base2 = base1 * base1;
        const float base4 = base2 * base2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long long int whoexp = ((int) (1.4426950408889634f * ((int) in)) + 127) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        const float decexp1 = 1.4426950408889634f * ((int) in) - (int) (1.4426950408889634f * ((int) in));
        const float decexp2 = decexp1 * decexp1;
        const float decexp4 = decexp2 * decexp2;

        const float val1 = 1.f + 0.5f * base1 + 0.125f * base2 + 0.020833333333333333f * base2 * base1 + 0.0026041666666666667f * base4 + 0.00026041666666666667f * base4 * base1 + 0.000021701388888888889f * base4 * base2;
        const float val2 = 1.f + 0.34657359027997265f * decexp1 + 0.060056626739775178f * decexp2 + 0.0069380135831026975f * decexp2 * decexp1 + 0.00060113306922677982f * decexp4 + 0.000041667369207588886f * decexp4 * decexp1;

        const float final = val1 * val1 * val2 * val2 * derp.asFlo;

        return 0.5f * final - 0.5f / final;
    }//Returns the hyperbolic Sine of the given float, accurate to around 6 decimal places.

//~90% faster than std::sinh
    double csch(const double in){
        const double base1 = (in - (int) in);
        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = ((int) (1.4426950408889634 * ((int) in)) + 1023) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        const double decexp1 = 1.4426950408889634 * ((int) in) - (int) (1.4426950408889634 * ((int) in));
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        const double val1 = 1 + 0.5 * base1 + 0.125 * base2 + 0.020833333333333333 * base2 * base1 + 0.0026041666666666667 * base4 + 0.00026041666666666667 * base4 * base1 + 0.000021701388888888889 * base4 * base2 + 1.5500992063492063e-6 * base4 * base2 * base1 + 9.6881200396825397e-8 * base4 * base4;
        const double val2 = 1 + 0.34657359027997265 * decexp1 + 0.060056626739775178 * decexp2 + 0.0069380135831026975 * decexp2 * decexp1 + 0.00060113306922677982 * decexp4 + 0.000041667369207588886 * decexp4 * decexp1 + 2.4068016239658766e-6 * decexp4 * decexp2 + 1.1916198284421750e-7 * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9 * decexp4 * decexp4;

        const double final = val1 * val1 * val2 * val2 * derp.asDou;

        return 2 * final / (final * final - 1);
    }//Returns the hyperbolic Cosecant of the given double, accurate to around 8 decimal places.

//~90% faster than std::sinh
    float csch(const float in){
        const float base1 = (in - (int) in);
        const float base2 = base1 * base1;
        const float base4 = base2 * base2;

        union doutoint{
            long long asInt;
            float asFlo;
        };

        const long long int whoexp = ((int) (1.4426950408889634f * ((int) in)) + 127) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 23;

        const float decexp1 = 1.4426950408889634f * ((int) in) - (int) (1.4426950408889634f * ((int) in));
        const float decexp2 = decexp1 * decexp1;
        const float decexp4 = decexp2 * decexp2;

        const float val1 = 1.f + 0.5f * base1 + 0.125f * base2 + 0.020833333333333333f * base2 * base1 + 0.0026041666666666667f * base4 + 0.00026041666666666667f * base4 * base1 + 0.000021701388888888889f * base4 * base2 + 1.5500992063492063e-6f * base4 * base2 * base1 + 9.6881200396825397e-8f * base4 * base4;
        const float val2 = 1.f + 0.34657359027997265f * decexp1 + 0.060056626739775178f * decexp2 + 0.0069380135831026975f * decexp2 * decexp1 + 0.00060113306922677982f * decexp4 + 0.000041667369207588886f * decexp4 * decexp1 + 2.4068016239658766e-6f * decexp4 * decexp2 + 1.1916198284421750e-7f * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9f * decexp4 * decexp4;

        const float final = val1 * val1 * val2 * val2 * derp.asFlo;

        return 1 / (0.5f * final - 0.5f / final);
    }//Returns the hyperbolic Cosecant of the given float, accurate to around 6 decimal places.

////~10% slower, rework
    double tanh(const double in){
        const double base1 = (in - (int) in);
        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        union doutoint{
            long long asInt;
            double asDou;
        };

        const long long int whoexp = ((int) (1.4426950408889634 * ((int) in)) + 1023) ;
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        const double decexp1 = 1.4426950408889634 * ((int) in) - (int) (1.4426950408889634 * ((int) in));
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        const double val1 = 1 + 0.5 * base1 + 0.125 * base2 + 0.020833333333333333 * base2 * base1 + 0.0026041666666666667 * base4 + 0.00026041666666666667 * base4 * base1 + 0.000021701388888888889 * base4 * base2 + 1.5500992063492063e-6 * base4 * base2 * base1 + 9.6881200396825397e-8 * base4 * base4;
        const double val2 = 1 + 0.34657359027997265 * decexp1 + 0.060056626739775178 * decexp2 + 0.0069380135831026975 * decexp2 * decexp1 + 0.00060113306922677982 * decexp4 + 0.000041667369207588886 * decexp4 * decexp1 + 2.4068016239658766e-6 * decexp4 * decexp2 + 1.1916198284421750e-7 * decexp4 * decexp2 * decexp1 + 5.1622995274001209e-9 * decexp4 * decexp4;

        const double final = val1 * val1 * val2 * val2 * derp.asDou;

        return (final * final - 1) / (final * final + 1);
    }

////~10% slower, rework
    double coth(const double in) {
        const double base1 = (in - (int) in);
        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        union doutoint {
            long long asInt;
            double asDou;
        };

        const long long int whoexp = ((int) (1.4426950408889634 * ((int) in)) + 1023);
        doutoint derp = {whoexp};
        derp.asInt = whoexp << 52;

        const double decexp1 = 1.4426950408889634 * ((int) in) - (int) (1.4426950408889634 * ((int) in));
        const double decexp2 = decexp1 * decexp1;
        const double decexp4 = decexp2 * decexp2;

        const double val1 =
                1 + 0.5 * base1 + 0.125 * base2 + 0.020833333333333333 * base2 * base1 + 0.0026041666666666667 * base4 +
                0.00026041666666666667 * base4 * base1 + 0.000021701388888888889 * base4 * base2 +
                1.5500992063492063e-6 * base4 * base2 * base1 + 9.6881200396825397e-8 * base4 * base4;
        const double val2 = 1 + 0.34657359027997265 * decexp1 + 0.060056626739775178 * decexp2 +
                            0.0069380135831026975 * decexp2 * decexp1 + 0.00060113306922677982 * decexp4 +
                            0.000041667369207588886 * decexp4 * decexp1 + 2.4068016239658766e-6 * decexp4 * decexp2 +
                            1.1916198284421750e-7 * decexp4 * decexp2 * decexp1 +
                            5.1622995274001209e-9 * decexp4 * decexp4;

        const double final = val1 * val1 * val2 * val2 * derp.asDou;

        return (final * final + 1) / (final * final + 1);
    }

    ////UNIVARIATE CALCULUS FUNCTIONS////

////Attempted implementation of Gaussian Quadrature, however it doesn't seem to converge faster than nint in various cases.
//    double Nnint(double(*fun)(double), double* var, double low, double up){
//        double sum = 0;
//        const int length =  (up - low) / QMATHDELTA - 1;
//        const double diff = up - low - (length + 1) * QMATHDELTA;
//
//        *var = low;
//
//        for(int i = 1; i < length; i+= 1){
//            sum += 0.34785484513745386 / 2 * fun(*var + (i - 0.86113631159405258 / 2) * QMATHDELTA);
//            sum += 0.65214515486254614 / 2 * fun(*var + (i - 0.33998104358485626 / 2) * QMATHDELTA);
//            sum += 0.65214515486254614 / 2 * fun(*var + (i + 0.33998104358485626 / 2) * QMATHDELTA);
//            sum += 0.34785484513745386 / 2 * fun(*var + (i + 0.86113631159405258 / 2) * QMATHDELTA);
//        }
//
//        *var = up;
//
//        return QMATHDELTA * sum + diff * (0.125 * fun(*var - diff) + 0.375 * fun(*var - 0.6666666666666667 * diff) + 0.375 * fun(*var - 0.3333333333333333 * diff) + 0.125 * fun(*var));
//    }

////Attempted an even more upscaled version of Gaussian quadrature with disappointing results, I'll come back to this one day.
//    double Nnint(double(*fun)(double), double* var, double low, double up){
//        double sum = 0;
//        const int length =  (up - low) / QMATHDELTA - 1;
//        const double diff = up - low - (length + 1) * QMATHDELTA;
//
//        *var = low;
//
//        for(int i = 1; i < length; i+= 1){
//            sum += 0.066671344308688 / 2 * fun(*var + (i - 0.973906528517171 / 2) * QMATHDELTA);
//            sum += 0.149451349150580 / 2 * fun(*var + (i - 0.865063366688984 / 2) * QMATHDELTA);
//            sum += 0.219086362515982 / 2 * fun(*var + (i - 0.679409568299024 / 2) * QMATHDELTA);
//            sum += 0.269266719309996 / 2 * fun(*var + (i - 0.433395394129247 / 2) * QMATHDELTA);
//            sum += 0.295524224714752 / 2 * fun(*var + (i - 0.148874338981631 / 2) * QMATHDELTA);
//            sum += 0.295524224714752 / 2 * fun(*var + (i + 0.148874338981631 / 2) * QMATHDELTA);
//            sum += 0.269266719309996 / 2 * fun(*var + (i + 0.433395394129247 / 2) * QMATHDELTA);
//            sum += 0.219086362515982 / 2 * fun(*var + (i + 0.679409568299024 / 2) * QMATHDELTA);
//            sum += 0.149451349150580 / 2 * fun(*var + (i + 0.865063366688984 / 2) * QMATHDELTA);
//            sum += 0.066671344308688 / 2 * fun(*var + (i + 0.973906528517171 / 2) * QMATHDELTA);
//        }
//
//        *var = up;
//
//        return QMATHDELTA * sum + diff * (0.125 * fun(*var - diff) + 0.375 * fun(*var - 0.6666666666666667 * diff) + 0.375 * fun(*var - 0.3333333333333333 * diff) + 0.125 * fun(*var));
//    }

    double nint(double(*fun)(double), double* var, double low, double up){
        double sum = 0;
        const int length = (up - low) / QMATHDELTA;
        const double diff = up - low - length * QMATHDELTA;

        *var = low;

        double old1 = 0.125 * fun(*var);

        for(int i = 0; i < length; i+= 1){
            sum += old1;
            sum += 0.375 * fun(*var + (i + 0.3333333333333333) * QMATHDELTA);
            sum += 0.375 * fun(*var + (i + 0.6666666666666667) * QMATHDELTA);

            old1 = 0.125 * fun(*var + (i + 1) * QMATHDELTA);

            sum += old1;
        }

        *var = up;

        return QMATHDELTA * sum + diff * (0.125 * fun(*var - diff) + 0.375 * fun(*var - 0.6666666666666667 * diff) + 0.375 * fun(*var - 0.3333333333333333 * diff) + 0.125 * fun(*var));
    }

    float nint(float(*fun)(float), float* var, float low, float up){
        float sum = 0;
        int i;
        int length = (up - low) / QMATHDELTA;
        float diff = up - low - length * QMATHDELTA;

        *var = low;

        for(i = 0; i < length; i+= 4){
            sum += 0.31111111f * fun(*var + i * QMATHDELTA);
            sum += 1.42222222f * fun(*var + (i + 1) * QMATHDELTA);
            sum += 0.53333333f * fun(*var + (i + 2) * QMATHDELTA);
            sum += 1.42222222f * fun(*var + (i + 3) * QMATHDELTA);
            sum += 0.31111111f * fun(*var + (i + 4) * QMATHDELTA);
        }
        return QMATHDELTA * sum + diff * (0.31111111f * fun(*var - 4.0f * diff) + 1.42222222f * fun(*var - 3.0f * diff) + 0.53333333f * fun(*var - 2.0f * diff) + 1.42222222f * fun(*var - diff) + 0.31111111f * fun(*var));
    }

    double der4(double(*fun)(double), double* var, double point){
        *var = point;
        return (0.16666666666666667 * fun(*var - QMATHDELTA) - 1.3333333333333333 * fun(*var - 0.5 * QMATHDELTA) + 1.3333333333333333 * fun(*var + 0.5 * QMATHDELTA) - 0.16666666666666667 * fun(*var + QMATHDELTA)) / QMATHDELTA;
    }

    float der4(float(*fun)(float), float* var, float point){
        *var = point;
        return (0.16666666f * fun(*var - QMATHDELTA) - 1.33333333f * fun(*var - 0.5f * QMATHDELTA) + 1.33333333f * fun(*var + 0.5f * QMATHDELTA) - 0.16666666f * fun(*var + QMATHDELTA)) / QMATHDELTA;
    }

    double der6(double(*fun)(double), double* var, double point){
        *var = point;
        return  (- 0.002190362405 * fun(*var - QMATHDELTA) + 0.04455918434 * fun(*var - 0.55 * QMATHDELTA) - 5.22317189 * fun(*var - 0.1 * QMATHDELTA) - 1.231642585e-14 * fun(*var) + 5.22317189 * fun(*var + 0.1 * QMATHDELTA) - 0.04455918434 * fun(*var + 0.55 * QMATHDELTA) + 0.002190362405 * fun(*var + QMATHDELTA)) / QMATHDELTA;
    }

    float der6(float(*fun)(float), float* var, float point){
        *var = point;
        return  (- 0.00219036f * fun(*var - QMATHDELTA) + 0.04455918f * fun(*var - 0.55f * QMATHDELTA) - 5.22317189f * fun(*var - 0.1f * QMATHDELTA) + 5.22317189f * fun(*var + 0.1f * QMATHDELTA) - 0.04455918f * fun(*var + 0.55f * QMATHDELTA) + 0.00219036f * fun(*var + QMATHDELTA)) / QMATHDELTA;
    }

    ////GLOBAL VARIABLE CALCULUS FUNCTIONS////

    double gnint(double(*fun)(), double* var, double low, double up){
        double sum = 0;
        const int length = (up - low) / QMATHDELTA;
        const double diff = up - low - length * QMATHDELTA;

        *var = low;

        double old1 = 0.125 * fun();

        for(int i = 0; i < length; i+= 1){
            sum += old1;

            *var = low + (i + 0.3333333333333333) * QMATHDELTA;
            sum += 0.375 * fun();

            *var = low + (i + 0.6666666666666667) * QMATHDELTA;
            sum += 0.375 * fun();

            *var = low + (i + 1) * QMATHDELTA;
            old1 = 0.125 * fun();

            sum += old1;
        }

        sum *= QMATHDELTA;

        *var = up - diff;
        sum += diff * 0.125 * fun();

        *var = up - 0.6666666666666667 * diff;
        sum += diff * 0.375 * fun();

        *var = up - 0.3333333333333333 * diff;
        sum += diff * 0.375 * fun();

        *var = up;
        sum += diff * 0.125 * fun();

        return sum;
    }

    float gnint(float(*fun)(), float* var, float low, float up){
        float sum = 0;
        const int length = (up - low) / QMATHDELTA;
        const float diff = up - low - length * QMATHDELTA;

        *var = low;

        float old1 = 0.125f * fun();

        for(int i = 0; i < length; i+= 1){
            sum += old1;

            *var = low + (i + 0.33333333f) * QMATHDELTA;
            sum += 0.375f * fun();

            *var = low + (i + 0.66666666f) * QMATHDELTA;
            sum += 0.375f * fun();

            *var = low + (i + 1) * QMATHDELTA;
            old1 = 0.125f * fun();

            sum += old1;
        }

        sum *= QMATHDELTA;

        *var = up - diff;
        sum += diff * 0.125f * fun();

        *var = up - 0.66666666f * diff;
        sum += diff * 0.375f * fun();

        *var = up - 0.33333333f * diff;
        sum += diff * 0.375f * fun();

        *var = up;
        sum += diff * 0.125f * fun();

        return sum;
    }

    double gder4(double(*fun)(), double* var, double point){
        double diff = 0;
        *var = point - QMATHDELTA;
        diff += 0.16666666666666667 * fun();

        *var = point - 0.5 * QMATHDELTA;
        diff -= 1.33333333333333333 * fun();

        *var = point + 0.5 * QMATHDELTA;
        diff += 1.33333333333333333 * fun();

        *var = point + QMATHDELTA;
        diff -= 0.16666666666666667 * fun();

        return diff / QMATHDELTA;
    }

    float gder4(float(*fun)(), float* var, float point){
        float diff = 0;
        *var = point - QMATHDELTA;
        diff += 0.16666666f * fun();

        *var = point - 0.5f * QMATHDELTA;
        diff -= 1.33333333f * fun();

        *var = point + 0.5f * QMATHDELTA;
        diff += 1.33333333f * fun();

        *var = point + QMATHDELTA;
        diff -= 0.16666666f * fun();

        return diff / QMATHDELTA;
    }

    double gder6(double(*fun)(), double* var, double point){
        double diff = 0;
        *var = point - QMATHDELTA;
        diff -= 0.002190362405 * fun();

        *var = point - 0.55 * QMATHDELTA;
        diff += 0.04455918434 * fun();

        *var = point - 0.1 * QMATHDELTA;
        diff -= 5.22317189 * fun();

        *var = point + 0.1 * QMATHDELTA;
        diff += 5.22317189 * fun();

        *var = point + 0.55 * QMATHDELTA;
        diff -= 0.04455918434 * fun();

        *var = point + QMATHDELTA;
        diff += 0.002190362405 * fun();

        return diff / QMATHDELTA;
    }

    float gder6(float(*fun)(), float* var, float point){
        float diff = 0;
        *var = point - QMATHDELTA;
        diff -= 0.00219036f * fun();

        *var = point - 0.55f * QMATHDELTA;
        diff += 0.04455918f * fun();

        *var = point - 0.1 * QMATHDELTA;
        diff -= 5.22317189f * fun();

        *var = point + 0.1f * QMATHDELTA;
        diff += 5.22317189f * fun();

        *var = point + 0.55f * QMATHDELTA;
        diff -= 0.04455918f * fun();

        *var = point + QMATHDELTA;
        diff += 0.002190362f * fun();

        return diff / QMATHDELTA;
    }

    ////STATISTICS FUNCTIONS////

//    int sum(int in[]){
//        int total = 0;
//        for(int i = 0; i < sizeof in; i ++){
//            total += in[i];
//        }
//        return total;
//    }//Returns the sum of the given array of ints.
//
//    float sum(float in){
//        float total = 0;
//        int length = sizeof in;
//        return length;
////        for(int i = 0; i < length; i++){
////            total += in[i];
////        }
////        return total;
//    }//Returns the sum of the given array of floats.
//
//    double sum(double in[]){
//        double total = 0;
//        for(int i = 0; i < sizeof in; i++){
//            total += in[i];
//        }
//        return total;
//    }
};
