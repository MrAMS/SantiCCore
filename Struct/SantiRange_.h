//
// Created by 24216 on 2022/7/30.
//

typedef struct ADD_TYPE_NAME(Struct_SantiRange){
    TYPE l, r;
} ADD_TYPE_NAME(scStruct_range);

// check if x is in the range
bool ADD_TYPE_NAME(scRange_is_in_range)(const ADD_TYPE_NAME(scStruct_range)* range, TYPE x);

// if x out of range return the nearest valid value
TYPE ADD_TYPE_NAME(scRange_safe_range)(const ADD_TYPE_NAME(scStruct_range)* range, TYPE x);
