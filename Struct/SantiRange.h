//
// Created by 24216 on 2022/7/30.
//

#ifndef SANTICCORE_SANTIRANGE_H
#define SANTICCORE_SANTIRANGE_H

#include "SantiDefine.h"
#include "SantiError.h"

/*
 * Range [left, right]
 */

#define TYPE scInt32
#define ADD_TYPE_NAME(X) X##_##Int32
#include "SantiRange_.h"
#undef TYPE
#undef ADD_TYPE_NAME

#define TYPE scFloat
#define ADD_TYPE_NAME(X) X##_##Float
#include "SantiRange_.h"
#undef TYPE
#undef ADD_TYPE_NAME


#endif //SANTICCORE_SANTIRANGE_H
