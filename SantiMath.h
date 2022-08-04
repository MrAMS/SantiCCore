//
// Created by 24216 on 2022/5/19.
//

#ifndef SANTICCORE_SANTIMATH_H
#define SANTICCORE_SANTIMATH_H

#include "SantiDefine.h"

#define PI 3.1415
#define EPS 1e-4

#define TYPE scInt32
#define ADD_TYPE_NAME(X) X##_##Int32
#include "SantiMath_.h"
#undef TYPE
#undef ADD_TYPE_NAME

#define TYPE scFloat
#define ADD_TYPE_NAME(X) X##_##Float
#include "SantiMath_.h"
#undef TYPE
#undef ADD_TYPE_NAME



bool scMath_equal_Float(scFloat x, scFloat to);

float scMath_sqrt_inv_fast(float x);

float scMath_sqrt_fast(float x);

float scMath_sqrt(float x);

float scMath_arctan(float x);

int scMath_pow(int base, int exp);

// count leading zeros
int clz32(scUInt32 x);

#endif //SANTICCORE_SANTIMATH_H
