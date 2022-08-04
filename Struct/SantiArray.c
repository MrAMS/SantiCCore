//
// Created by 24216 on 2022/5/24.
//

#include "SantiArray.h"
#include "SantiError.h"

#define TYPE scInt32
#define ADD_TYPE_NAME(X) X##_##Int32
#include "SantiArray_.c"
#undef TYPE
#undef ADD_TYPE_NAME

#define TYPE scFloat
#define ADD_TYPE_NAME(X) X##_##Float
#include "SantiArray_.c"
#undef TYPE
#undef ADD_TYPE_NAME

