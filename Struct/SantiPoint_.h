//
// Created by 24216 on 2022/7/30.
//

/*
 * 2D Point
 * (x,y)
 */

typedef struct ADD_TYPE_NAME(Struct_SantiPoint){
    TYPE x,y;
} ADD_TYPE_NAME(scStruct_point);

// check if two points are the same
bool ADD_TYPE_NAME(scPoint_is_eq)(const ADD_TYPE_NAME(scStruct_point) *p1, const ADD_TYPE_NAME(scStruct_point) *p2);

// calc k of the straight formed by 2 points, note to check whether x1==x2
scFloat ADD_TYPE_NAME(scPoint_calc_k)(const ADD_TYPE_NAME(scStruct_point)* a, const ADD_TYPE_NAME(scStruct_point)* b);

// return the distance between 2 points
scFloat ADD_TYPE_NAME(scPoint_get_distance)(const ADD_TYPE_NAME(scStruct_point)* a, const ADD_TYPE_NAME(scStruct_point)* b);

// calc the angle a-b-c
scFloat ADD_TYPE_NAME(scPoint_calc_angle)(const ADD_TYPE_NAME(scStruct_point)* p_a, const ADD_TYPE_NAME(scStruct_point)* p_b, const ADD_TYPE_NAME(scStruct_point)* p_c);

// return false if it is perpendicular to the X axis
bool ADD_TYPE_NAME(scPoint_get_straight_func)(const ADD_TYPE_NAME(scStruct_point)* a, const ADD_TYPE_NAME(scStruct_point)* b, scStruct_straight* straight);

// return true if k of the straight formed by 2 points is less than threshold_k
bool ADD_TYPE_NAME(scPoint_is_k_less_than)(ADD_TYPE_NAME(scStruct_point) a, ADD_TYPE_NAME(scStruct_point) b, scFloat threshold_k);

// return curvature of a circle formed by 3 points
scFloat ADD_TYPE_NAME(scPoint_get_curvature)(const ADD_TYPE_NAME(scStruct_point)* a, const ADD_TYPE_NAME(scStruct_point)* b, const ADD_TYPE_NAME(scStruct_point)* c);


/*
 * Point List
 */

typedef struct ADD_TYPE_NAME(Struct_SantiPointList){
    ADD_TYPE_NAME(scStruct_point)* p;
    scInt32 len, len_max;
} ADD_TYPE_NAME(scStruct_pointlist);

// append a point to list
// return false if fail due to max len
bool ADD_TYPE_NAME(scPointlist_add)(ADD_TYPE_NAME(scStruct_pointlist)* pl, ADD_TYPE_NAME(scStruct_point) p);

// get point in list, support -1 index
ADD_TYPE_NAME(scStruct_point) ADD_TYPE_NAME(scPointlist_get)(const ADD_TYPE_NAME(scStruct_pointlist)* pl, scInt32 i);

// select [a, b] elements and return a shallow copy, support -1 index
ADD_TYPE_NAME(scStruct_pointlist) ADD_TYPE_NAME(scPointlist_select)(const ADD_TYPE_NAME(scStruct_pointlist)* pl, scInt32 a, scInt32 b);

// check if the points form a road_type_straight by three points according to threshold_curvature
// support -1 index
bool ADD_TYPE_NAME(scPointlist_is_line_straight)(const ADD_TYPE_NAME(scStruct_pointlist)* pl, scInt32 i_begin, scInt32 i_end, scFloat threshold_curvature);