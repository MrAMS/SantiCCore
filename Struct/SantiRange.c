//
// Created by 24216 on 2022/7/30.
//

#include "SantiRange.h"

#define TYPE scInt32
#define ADD_TYPE_NAME(X) X##_##Int32
#include "SantiRange_.c"
#undef TYPE
#undef ADD_TYPE_NAME

#define TYPE scFloat
#define ADD_TYPE_NAME(X) X##_##Float
#include "SantiRange_.c"
#undef TYPE
#undef ADD_TYPE_NAME