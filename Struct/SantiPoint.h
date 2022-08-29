//
// Created by 24216 on 2022/5/20.
//

#ifndef SANTICCORE_SANTIPOINT_H
#define SANTICCORE_SANTIPOINT_H

#include "SantiDefine.h"

/*
 * 2D Straight
 * y=kx+b
 */

typedef struct Struct_SantiStraight{
    scFloat k,b;
} scStruct_straight;


#ifdef ENABLE_SANTICCORE_DEBUG
#include "SantiError.h"
#endif

#define TYPE scInt32
#define ADD_TYPE_NAME(X) X##_##Int32
#include "SantiPoint_.h"
#undef TYPE
#undef ADD_TYPE_NAME

#define TYPE scFloat
#define ADD_TYPE_NAME(X) X##_##Float
#include "SantiPoint_.h"
#undef TYPE
#undef ADD_TYPE_NAME




#ifdef ENABLE_SANTICCORE_DEBUG
void scPoint_Float_print(const scStruct_point_Float * p);
void scPointlist_Float_print(const scStruct_pointlist_Float * pl);
void scPoint_In32_print(const scStruct_point_Int32 * p);
void scPointlist_Int32_print(const scStruct_pointlist_Int32 * pl);
#endif


scFloat scStraight_val(const scStruct_straight* s, scFloat val);

scStruct_point_Float scStraight_get_crossover_point(const scStruct_straight* s1, const scStruct_straight* s2);

#endif //SANTICCORE_SANTIPOINT_H
