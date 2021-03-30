namespace qmath{

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

    double der4(double(*fun)(double), double* var, double point){
        *var = point;
        return (0.16666666666666667 * fun(*var - QMATHDELTA) - 1.3333333333333333 * fun(*var - 0.5 * QMATHDELTA) + 1.3333333333333333 * fun(*var + 0.5 * QMATHDELTA) - 0.16666666666666667 * fun(*var + QMATHDELTA)) / QMATHDELTA;
    }

    double der6(double(*fun)(double), double* var, double point){
        *var = point;
        return  (- 0.002190362405 * fun(*var - QMATHDELTA) + 0.04455918434 * fun(*var - 0.55 * QMATHDELTA) - 5.22317189 * fun(*var - 0.1 * QMATHDELTA) - 1.231642585e-14 * fun(*var) + 5.22317189 * fun(*var + 0.1 * QMATHDELTA) - 0.04455918434 * fun(*var + 0.55 * QMATHDELTA) + 0.002190362405 * fun(*var + QMATHDELTA)) / QMATHDELTA;
    }

}

namespace qmathf{

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

    float der4(float(*fun)(float), float* var, float point){
        *var = point;
        return (0.16666666f * fun(*var - QMATHDELTA) - 1.33333333f * fun(*var - 0.5f * QMATHDELTA) + 1.33333333f * fun(*var + 0.5f * QMATHDELTA) - 0.16666666f * fun(*var + QMATHDELTA)) / QMATHDELTA;
    }

    float der6(float(*fun)(float), float* var, float point){
        *var = point;
        return  (- 0.00219036f * fun(*var - QMATHDELTA) + 0.04455918f * fun(*var - 0.55f * QMATHDELTA) - 5.22317189f * fun(*var - 0.1f * QMATHDELTA) + 5.22317189f * fun(*var + 0.1f * QMATHDELTA) - 0.04455918f * fun(*var + 0.55f * QMATHDELTA) + 0.00219036f * fun(*var + QMATHDELTA)) / QMATHDELTA;
    }

}

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

////Attempted an even more upscaled version of Gaussian quadrature with disappointing results, I may come back to this one day.
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
