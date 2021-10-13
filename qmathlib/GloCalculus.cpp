namespace qmath{
// These functions are 3000x faster than the univariate variations.
// NEVER USE FOR CONVENIENCE!!! PlEASE SPEED TEST!!!

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

}

namespace qmathf{
//These functions are 3000x slower than the univariate variations.
// ONLY USE FOR CONVENIENCE!!! DO NOT SPEED TEST!!!

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

}
