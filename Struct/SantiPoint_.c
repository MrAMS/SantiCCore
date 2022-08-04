//
// Created by 24216 on 2022/7/30.
//


bool ADD_TYPE_NAME(scPoint_is_eq)(const ADD_TYPE_NAME(scStruct_point) *p1, const ADD_TYPE_NAME(scStruct_point) *p2){
    if(p1->x==p2->x&&p1->y==p2->y) return TRUE;
    return scMath_equal_Float(p1->x, p2->x) && scMath_equal_Float(p1->y, p2->y);
}

scFloat ADD_TYPE_NAME(scPoint_calc_k)(const ADD_TYPE_NAME(scStruct_point)* a, const ADD_TYPE_NAME(scStruct_point)* b){
    if(scMath_equal_Float(a->x, b->x))
        scError_handle(SC_ERROR_MATH, "scPoint_calc_k");
    return (scFloat)(a->y - b->y) / (scFloat)(a->x - b->x);
}

scFloat ADD_TYPE_NAME(scPoint_get_distance)(const ADD_TYPE_NAME(scStruct_point)* a, const ADD_TYPE_NAME(scStruct_point)* b){
    return scMath_sqrt(scMath_sqr_Float(a->x - b->x) + scMath_sqr_Float(a->y - b->y));
}

bool ADD_TYPE_NAME(scPoint_get_straight_func)(const ADD_TYPE_NAME(scStruct_point)* a, const ADD_TYPE_NAME(scStruct_point)* b, scStruct_straight* straight){
    if (scMath_equal_Float(a->x, b->x))
        return FALSE;
    scFloat k = ADD_TYPE_NAME(scPoint_calc_k)(a, b);
    straight->k = k;
    straight->b = a->y - a->x * k;
    return TRUE;
}

bool ADD_TYPE_NAME(scPoint_is_k_less_than)(ADD_TYPE_NAME(scStruct_point) a, ADD_TYPE_NAME(scStruct_point) b, scFloat threshold_k){
    scStruct_straight straight;
    if (!ADD_TYPE_NAME(scPoint_get_straight_func)(&a, &b, &straight))
        return FALSE;
    return (scMath_abs_Float(straight.k) < threshold_k ? TRUE : FALSE);
}

scFloat ADD_TYPE_NAME(scPoint_get_curvature)(const ADD_TYPE_NAME(scStruct_point)* a, const ADD_TYPE_NAME(scStruct_point)* b, const ADD_TYPE_NAME(scStruct_point)* c){
    scFloat s_abc =
            scMath_abs_Float((b->x - a->x) * (c->y - a->y) - (b->y - a->y) * (c->x - a->x)) / 2;
    scFloat ab2 = scMath_sqr_Float(a->x - b->x) + scMath_sqr_Float(a->y - b->y);
    scFloat bc2 = scMath_sqr_Float(b->x - c->x) + scMath_sqr_Float(b->y - c->y);
    scFloat ac2 = scMath_sqr_Float(a->x - c->x) + scMath_sqr_Float(a->y - c->y);
    if (scMath_equal_Float(ab2, 0) || scMath_equal_Float(bc2, 0) || scMath_equal_Float(ac2, 0)) return 0;
    return 4 * s_abc / (scMath_sqrt(ab2) * scMath_sqrt(bc2) * scMath_sqrt(ac2));
}


bool ADD_TYPE_NAME(scPointlist_add)(ADD_TYPE_NAME(scStruct_pointlist)* pl, const ADD_TYPE_NAME(scStruct_point) p){
    if(pl->len == pl->len_max)
        return FALSE;
    pl->p[pl->len++] = p;
    return TRUE;
}

static bool ADD_TYPE_NAME(check_i)(const ADD_TYPE_NAME(scStruct_pointlist)* pl, const scInt32 i){
    if(i>=pl->len || i<-pl->len){
        scError_handle(SC_ERROR_ARRAY_OUT_OF_RANGE, "scPointlist:check_i");
        return FALSE;
    }
    return TRUE;
}

ADD_TYPE_NAME(scStruct_point) ADD_TYPE_NAME(scPointlist_get)(const ADD_TYPE_NAME(scStruct_pointlist)* pl, scInt32 i){
    ADD_TYPE_NAME(check_i)(pl, i);
    if(i>=0)
        return pl->p[i];
    else
        return pl->p[i+pl->len];
}

ADD_TYPE_NAME(scStruct_pointlist) ADD_TYPE_NAME(scPointlist_select)(const ADD_TYPE_NAME(scStruct_pointlist)* pl, scInt32 a, scInt32 b){
    ADD_TYPE_NAME(check_i)(pl, a);
    ADD_TYPE_NAME(check_i)(pl, b);
    if(a<0) a+=pl->len;
    if(b<0) b+=pl->len;
    if(a>b)
        scError_handle(SC_ERROR_ARRAY_OUT_OF_RANGE, "scPointlist_select");
    ADD_TYPE_NAME(scStruct_pointlist) res = {pl->p+a, b-a+1, pl->len_max-a};
    return res;
}

bool ADD_TYPE_NAME(scPointlist_is_line_straight)(const ADD_TYPE_NAME(scStruct_pointlist)* pl, scInt32 i_begin, scInt32 i_end, scFloat threshold_curvature){
    ADD_TYPE_NAME(check_i)(pl, i_begin);
    ADD_TYPE_NAME(check_i)(pl, i_end);
    if(i_begin<0) i_begin+=pl->len;
    if(i_end<0) i_end+=pl->len;
    if(i_begin>i_end)
        scError_handle(SC_ERROR_ARRAY_OUT_OF_RANGE, "scPointlist_is_line_straight");
    return ADD_TYPE_NAME(scPoint_get_curvature)(&pl->p[i_begin], &pl->p[(scInt32)(i_begin + i_end) / 2], &pl->p[i_end]) < threshold_curvature;
}
