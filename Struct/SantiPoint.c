//
// Created by 24216 on 2022/5/20.
//

#include "SantiPoint.h"

#include "SantiMath.h"
#include "SantiError.h"


#define TYPE scInt32
#define ADD_TYPE_NAME(X) X##_##Int32
#include "SantiPoint_.c"
#undef TYPE
#undef ADD_TYPE_NAME

#define TYPE scFloat
#define ADD_TYPE_NAME(X) X##_##Float
#include "SantiPoint_.c"
#undef TYPE
#undef ADD_TYPE_NAME

#ifdef ENABLE_SANTICCORE_DEBUG
void scPoint_Float_print(const scStruct_point_Float * p){
    printf("Point(%f, %f)\n", p->x, p->y);
}
void scPointlist_Float_print(const scStruct_pointlist_Float * pl){
    printf("PointList[%d]{", pl->len);
    for(int i=0;i<pl->len;++i)
        scPoint_Float_print(&pl->p[i]);
    puts("}");
}
#endif


scFloat scStraight_val(const scStruct_straight* s, const scFloat val){
    return s->k * val + s->b;
}

scStruct_point_Float scStraight_get_crossover_point(const scStruct_straight* s1, const scStruct_straight* s2){
    scFloat x = (s1->k - s2->k) / (s1->b - s2->b);
    scStruct_point_Float res={x, scStraight_val(s1, x)};
    return res;
}