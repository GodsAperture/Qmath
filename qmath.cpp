//Math algorithms: Joshua Champion.
//Computer science algorithms: Andrew Rubenstein.
//Contact on Discord: GodsAperture#8507
//Discord Computer Science server: https://discord.gg/Uv5eErc

namespace qmath {

//~30% faster
    double frexp(const double in1, int* in2) {
        *in2 = ((0x7ff0000000000000 & (*(long long *) &in1)) >> 52) - 1023;
        return 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in1)) + 1;
    }//Returns the mantissa and exponent of the given double.

    float frexp(const float in1, int* in2) {
        *in2 = ((0x7ff00000 & (*(long *) &in1)) >> 52) - 1023;
        return 1.192092896e-7f * (0x000fffff & (*(long *) &in1)) + 1;
        }//Returns the mantissa and the exponent of the given float.

//~25% faster
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

//~45% faster
    double qsin(const double in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const double ang = 0.125 * in - 0.78539816339744831 * ((int) (0.15915494309189534 * in + 0.39269908169872415)) - 0.19634954084936208;
        const double ang2 = ang * ang; //ang^2

        const double cosang = 1 - 0.5 * ang2 + 0.041666666666666667 * ang2 * ang2; //Approximates the Cosine of the angle.
        const double cosang2 = cosang * cosang;
        const double cosang4 = cosang2 * cosang2;

        return 1 - 32 * cosang2 + 160 * cosang4 - 256 * cosang4 * cosang2 + 128 * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Sine of a given double, accurate to around 5 decimal places.

//~40% faster
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

    float fqsin(const float in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const float ang = 0.125f * in - 0.78539816339744831f * ((int) (0.15915494309189534f * in + 0.39269908169872415f)) - 0.19634954084936208f;
        const float ang2 = ang * ang; //ang^2

        const float cosang = 1.f - 0.5f * ang2 + 0.041666666666666667f * ang2 * ang2; //Approximates the Cosine of the angle.
        const float cosang2 = cosang * cosang;
        const float cosang4 = cosang2 * cosang2;

        return 1.f - 32.f * cosang2 + 160.f * cosang4 - 256.f * cosang4 * cosang2 + 128.f * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Sine of a given double, accurate to around 3 decimal places.

//~25% faster
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

    float cos(const float in){
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
    }

//~45% faster
    double qcos(const double in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const double ang = 0.125 * in - 0.78539816339744831 * ((int) (0.15915494309189534 * in + 0.39269908169872415));
        const double ang2 = ang * ang; //ang^2

        const double cosang = 1 - 0.5 * ang2 + 0.041666666666666667 * ang2 * ang2; //Approximates the Cosine of the angle.
        const double cosang2 = cosang * cosang;
        const double cosang4 = cosang2 * cosang2;

        return 1 - 32 * cosang2 + 160 * cosang4 - 256 * cosang4 * cosang2 + 128 * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Cosine of a given double, accurate to around 5 decimal places.

//~25% faster
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
               (tanang3 * tanang2 * tanang1 - 35 * tanang3 * tanang2 + 273 * tanang3 * tanang1 - 715 * tanang3 +
                715 * tanang2 * tanang1 - 273 * tanang2 + 35 * tanang1 - 1) /
               (tanang3 * tanang3 - 120 * tanang3 * tanang2 * tanang1 + 1820 * tanang3 * tanang2 -
                8008 * tanang3 * tanang1 + 12870 * tanang3 - 8008 * tanang2 * tanang1 + 1820 * tanang2 - 120 * tanang1 +
                1);
    }//Returns the Tangent of the given double, accurate to around 10 decimal places.

//~45% faster
    double qtan(const double in) {
        const double ang =
                -0.125 * in + 0.39269908169872415 * ((int) (0.31830988618379067 * (in + 1.5707963267948966)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;

        const double tanang = ang * (1 + 0.33333333333333333 * ang1 + 0.13333333333333333 * ang2 +
                                     0.053968253968253968 * ang2 * ang1);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;

        return 8 * tanang * (tanang2 * tanang1 - 7 * tanang2 + 7 * tanang1 - 1) /
               (tanang2 * tanang2 - 28 * tanang2 * tanang1 + 70 * tanang2 - 28 * tanang1 + 1);
    }//Quickly returns the Tangent of the given double, accurate to around ?? decimal places.

//~25% faster
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

//~45% faster
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
    }//Quickly returns the Cotangent of the given double.

//~20% faster
    double log(const double in) {
        const int exp = ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 1023;
        double base1 = 0.5 - 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in));

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;
        const double base8 = base4 * base4;

        return exp * 0.69314718055994531 + 0.40546510810816438 - 0.66666666666666667 * base1 - 0.22222222222222222 * base2 - 0.098765432098765432 * base2 * base1 - 0.049382716049382716 * base4 - 0.026337448559670782 * base4 * base1 - 0.014631915866483768 * base4 * base2 - 0.0083610947808478673 * base4 * base2 * base1 - 0.0048773052888279226 * base8 - 0.0028902549859721023 * base8 * base1 - 0.0017341529915832614 * base8 * base2 - 0.0010510018130807645 * base8 * base2 * base1 - 0.00064227888577157828 * base8 * base4 - 0.00039524854509020202 * base8 * base4 * base1 - 0.00024467767077012506 * base8 * base4 * base2;
    }//Returns the logarithm of the given double whose accuracy depends entirely on the mantissa of the double.

//~30% faster
    double qlog(const double in) {
        const int exp = ((0x7ff0000000000000 & (*(long long *) &in)) >> 52) - 1023;
        double base1 = 0.5 - 2.2204460492503131e-16 * (0x000fffffffffffff & (*(long long *) &in));

        const double base2 = base1 * base1;
        const double base4 = base2 * base2;

        return exp * 0.69314718055994531 + 0.40546510810816438 - 0.66666666666666667 * base1 - 0.22222222222222222 * base2 - 0.098765432098765432 * base2 * base1 - 0.049382716049382716 * base4 - 0.026337448559670782 * base4 * base1 - 0.014631915866483768 * base4 * base2 - 0.0083610947808478673 * base4 * base2 * base1;
        }//Quickly returns the logarithm of the given double whose accuracy depends entirely on the mantissa of the double.

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

//~65% faster
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
    }

//~90% faster
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
    }

//The standard library doesn't contain the hyperbolic secant function
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
    }

//~90% faster
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
    }

//The standard library doesn't contain the hyperbolic cosecant function
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
    }

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
    double coth(const double in){
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

        return (final * final + 1) / (final * final + 1);
    }
};
