//
// Created by 24216 on 2022/5/24.
//

#ifndef SANTICCORE_SANTIARRAY_H
#define SANTICCORE_SANTIARRAY_H

#include "SantiDefine.h"

#define TYPE scInt32
#define ADD_TYPE_NAME(X) X##_##Int32
#include "SantiArray_.h"
#undef TYPE
#undef ADD_TYPE_NAME

#define TYPE scFloat
#define ADD_TYPE_NAME(X) X##_##Float
#include "SantiArray_.h"
#undef TYPE
#undef ADD_TYPE_NAME


#endif //SANTICCORE_SANTIARRAY_H
