//
// Created by 24216 on 2022/5/19.
//

#include "SantiMath.h"

#define TYPE scInt32
#define ADD_TYPE_NAME(X) X##_##Int32
#include "SantiMath_.c"
#undef TYPE
#undef ADD_TYPE_NAME

#define TYPE scFloat
#define ADD_TYPE_NAME(X) X##_##Float
#include "SantiMath_.c"
#undef TYPE
#undef ADD_TYPE_NAME

bool scMath_equal_Float(scFloat x, scFloat to){
    if (scMath_abs_Float(x - to) < scEPS)
        return TRUE;
    return FALSE;
}

float scMath_arctan(float x){
    // http://nghiaho.com/?p=997
    return scPI / 4 * x - x * (scMath_abs_Float(x) - 1) * (0.2447 + 0.0663 * scMath_abs_Float(x));
}

// Absolute error <= 6.7e-5
float scMath_acos(float x){
    // https://developer.download.nvidia.com/cg/acos.html
    float negate = (float)(x < 0);
    x = scMath_abs_Float(x);
    float ret = -0.0187293f;
    ret = ret * x;
    ret = ret + 0.0742610f;
    ret = ret * x;
    ret = ret - 0.2121144f;
    ret = ret * x;
    ret = ret + 1.5707288f;
    ret = ret * scMath_sqrt(1.0f-x);
    ret = ret - 2 * negate * ret;
    return negate * scPI + ret;
}

float scMath_sqrt_inv_fast(float x){
    // <IEEE Standard 754 for Binary Floating-Point Arithmetic> <FAST INVERSE SQUARE ROOT>
    // http://www.matrix67.com/data/InvSqrt.pdf
    float xhalf = 0.5f*x;
    int i = *(int*)&x; // scMatrix_get bits for floating VALUE
    i = 0x5f375a86- (i>>1); // gives initial guess y0
    x = *(float*)&i; // convert bits BACK to float
    x = x*(1.5f-xhalf*x*x); // Newton step, repeating increases accuracy
    return x;
}

// faster but have a cost. e.g. sqrt(2) return 1.41386 (1.41421 in fact)
float scMath_sqrt_fast(const float x){
return x * scMath_sqrt_inv_fast(x);
}

float scMath_sqrt(const float x){
    // https://www.gamedev.net/forums/topic/704525-3-quick-ways-to-scMathulate-the-square-root-in-c/
    int i = 0x2035AD0C + (*(int*)&x >> 1);
    return x / *(float*)&i + *(float*)&i * 0.25f;
}



int scMath_pow(int base, int exp){
    int res = 1;
    while(1){
        if (exp & 1)
            res *= base;
        exp >>= 1;
        if (!exp)
            break;
        base *= base;
    }
    return res;
}

int clz32(scUInt32 x){
    if(x==0) return 32;
    static const char debruijn32[32] = {
            0, 31, 9, 30, 3, 8, 13, 29, 2, 5, 7, 21, 12, 24, 28, 19,
            1, 10, 4, 14, 6, 22, 25, 20, 11, 15, 23, 26, 16, 27, 17, 18
    };
    x |= x>>1;
    x |= x>>2;
    x |= x>>4;
    x |= x>>8;
    x |= x>>16;
    x++;
    return debruijn32[x*0x076be629>>27];
}