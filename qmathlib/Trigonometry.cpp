namespace qmath{

    //~20% faster than std::sin with the MSVC compiler
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

    //~20% faster than std::cos with the MSVC compiler
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

    //Equal to std::tan with the MSVC compiler
    double tan(const double in) {
        const double ang = -0.0625 * in + 0.19634954084936208 * ((int) (0.31830988618379067 * (in + 1.5707963267948966)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;
        const double ang3 = ang2 * ang2;

        const double tanang = ang * (1 + 0.33333333333333333 * ang1 + 0.13333333333333333 * ang2 + 0.053968253968253968 * ang2 * ang1 + 0.021869488536155203 * ang3 + 0.0088632355299021966 * ang3 * ang1 + 0.0035921280365724810 * ang3 * ang2 + 0.0014558343870513183 * ang3 * ang2 * ang1 + 0.00059002744094558598 * ang3 * ang3);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;
        const double tanang3 = tanang2 * tanang2;

        return 16 * tanang * (tanang3 * tanang2 * tanang1 - 35 * tanang3 * tanang2 + 273 * tanang3 * tanang1 - 715 * tanang3 + 715 * tanang2 * tanang1 - 273 * tanang2 + 35 * tanang1 - 1) / (tanang3 * tanang3 - 120 * tanang3 * tanang2 * tanang1 + 1820 * tanang3 * tanang2 - 8008 * tanang3 * tanang1 + 12870 * tanang3 - 8008 * tanang2 * tanang1 + 1820 * tanang2 - 120 * tanang1 +1);
    }//Returns the Tangent of the given double, accurate to around 10 decimal places.

    //Equal to std::tan with the MSVC compiler
    double cot(const double in) {
        const double ang =
                -0.0625 * in + 0.19634954084936208 * ((int) (0.31830988618379067 * (in + 1.5707963267948966)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;
        const double ang3 = ang2 * ang2;

        const double tanang = ang * (1 + 0.33333333333333333 * ang1 + 0.13333333333333333 * ang2 + 0.053968253968253968 * ang2 * ang1 + 0.021869488536155203 * ang3 + 0.0088632355299021966 * ang3 * ang1 + 0.0035921280365724810 * ang3 * ang2 + 0.0014558343870513183 * ang3 * ang2 * ang1 + 0.00059002744094558598 * ang3 * ang3);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;
        const double tanang3 = tanang2 * tanang2;

        return (tanang3 * tanang3 - 120 * tanang3 * tanang2 * tanang1 + 1820 * tanang3 * tanang2 - 8008 * tanang3 * tanang1 + 12870 * tanang3 - 8008 * tanang2 * tanang1 + 1820 * tanang2 - 120 * tanang1 + 1) / (16 * tanang * (tanang3 * tanang2 * tanang1 - 35 * tanang3 * tanang2 + 273 * tanang3 * tanang1 - 715 * tanang3 + 715 * tanang2 * tanang1 - 273 * tanang2 + 35 * tanang1 - 1));
    }//Returns the Cotangent of the given double, accurate to around 10 decimal places.

    ///qfunctions

    //~40% faster than std::sin with the MSVC compiler
    double qsin(const double in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const double ang = 0.125 * in - 0.78539816339744831 * ((int) (0.15915494309189534 * in + 0.39269908169872415)) - 0.19634954084936208;
        const double ang2 = ang * ang; //ang^2

        const double cosang = 1 - 0.5 * ang2 + 0.041666666666666667 * ang2 * ang2; //Approximates the Cosine of the angle.
        const double cosang2 = cosang * cosang;
        const double cosang4 = cosang2 * cosang2;

        return 1 - 32 * cosang2 + 160 * cosang4 - 256 * cosang4 * cosang2 + 128 * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Sine of a given double, accurate to around 5 decimal places.

    //~40% faster than std::cos with the MSVC compiler
    double qcos(const double in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const double ang = 0.125 * in - 0.78539816339744831 * ((int) (0.15915494309189534 * in + 0.39269908169872415));
        const double ang2 = ang * ang; //ang^2

        const double cosang = 1 - 0.5 * ang2 + 0.041666666666666667 * ang2 * ang2; //Approximates the Cosine of the angle.
        const double cosang2 = cosang * cosang;
        const double cosang4 = cosang2 * cosang2;

        return 1 - 32 * cosang2 + 160 * cosang4 - 256 * cosang4 * cosang2 + 128 * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Cosine of a given double, accurate to around 5 decimal places.

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
    }//Quickly returns the Tangent of the given double, accuracy depends on how near a pole the double is.

    //~45% faster than std::cot
    double qcot(const double in) {
        const double ang =
                -0.125 * in + 0.39269908169872415 * ((int) (0.31830988618379067 * (in + 1.5707963267948966)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;

        const double tanang = ang * (1 + 0.33333333333333333 * ang1 + 0.13333333333333333 * ang2 + 0.053968253968253968 * ang2 * ang1);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;

        return 0.125 * (tanang2 * tanang2 - 28 * tanang2 * tanang1 + 70 * tanang2 - 28 * tanang1 + 1) / (tanang * (tanang2 * tanang1 - 7 * tanang2 + 7 * tanang1 - 1));
    }//Quickly returns the Cotangent of the given double, accurate to a minimum of 7 decimal places.

}

namespace qmathf{

    //~40% faster than std::sin with the MSVC compiler
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

    //~45% faster than std::cos with the MSVC compiler
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

    //Equal to std::tan with the MSVC compiler
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

    //Equal to std::tan with the MSVC compiler
    float cot(const float in){
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

    ////qfunctions

    //~50% faster than std::sin with the MSVC compiler
    float qsin(const float in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const float ang = 0.125f * in - 0.78539816339744831f * ((int) (0.15915494309189534f * in + 0.39269908169872415f)) - 0.19634954084936208f;
        const float ang2 = ang * ang; //ang^2

        const float cosang = 1.f - 0.5f * ang2 + 0.041666666666666667f * ang2 * ang2; //Approximates the Cosine of the angle.
        const float cosang2 = cosang * cosang;
        const float cosang4 = cosang2 * cosang2;

        return 1.f - 32.f * cosang2 + 160.f * cosang4 - 256.f * cosang4 * cosang2 + 128.f * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Sine of a given double, accurate to around 3 decimal places.

    //~50% faster than std::cos with the MSVC compiler
    float qcos(const float in) {
        //Forces the given angle to be between -Pi and Pi and then divides it by 8
        const float ang = 0.125f * in - 0.78539816339744831f * ((int) (0.15915494309189534f * in + 0.39269908169872415f));
        const float ang2 = ang * ang; //ang^2

        const float cosang = 1.f - 0.5f * ang2 + 0.041666666666666667f * ang2 * ang2; //Approximates the Cosine of the angle.
        const float cosang2 = cosang * cosang;
        const float cosang4 = cosang2 * cosang2;

        return 1.f - 32.f * cosang2 + 160.f * cosang4 - 256.f * cosang4 * cosang2 + 128.f * cosang4 * cosang4; //8th angle formula for Cosine.
    }//Quickly returns the Cosine of the given float, accurate to around 3 decimal places.

    float qtan(const float in) {
        const float ang = -0.125f * in + 0.39269908f * ((int) (0.31830988f * (in + 1.57079626f)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;

        const double tanang = ang * (1 + 0.333333333f * ang1 + 0.13333333f * ang2 + 0.05396825f * ang2 * ang1);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;

        return 8 * tanang * (tanang2 * tanang1 - 7 * tanang2 + 7 * tanang1 - 1) / (tanang2 * tanang2 - 28 * tanang2 * tanang1 + 70 * tanang2 - 28 * tanang1 + 1);
    }//Quickly returns the Tangent of the given float, accuracy depends on how near a pole the float is.

    float qcot(const float in) {
        const float ang = -0.125f * in + 0.39269908f * ((int) (0.31830988f * (in + 1.57079626f)));
        const double ang1 = ang * ang;
        const double ang2 = ang1 * ang1;

        const double tanang = ang * (1 + 0.333333333f * ang1 + 0.13333333f * ang2 + 0.05396825f * ang2 * ang1);
        const double tanang1 = tanang * tanang;
        const double tanang2 = tanang1 * tanang1;

        return  (tanang2 * tanang2 - 28 * tanang2 * tanang1 + 70 * tanang2 - 28 * tanang1 + 1) / (8 * tanang * (tanang2 * tanang1 - 7 * tanang2 + 7 * tanang1 - 1));
    }//Quickly returns the Tangent of the given float, accuracy depends on how near a pole the float is.

}
