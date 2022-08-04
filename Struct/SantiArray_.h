//
// Created by 24216 on 2022/7/30.
//

/*
 * Array with length
 */

typedef struct ADD_TYPE_NAME(Struct_SantiArray){
    TYPE* a;
    scInt32 len, len_max;
} ADD_TYPE_NAME(scStruct_array);

// append value to list
// return false if fail due to max len
bool ADD_TYPE_NAME(scArray_add)(ADD_TYPE_NAME(scStruct_array)* array, TYPE val);

// get i-th value, support -n index
TYPE ADD_TYPE_NAME(scArray_get)(const ADD_TYPE_NAME(scStruct_array)* array, scInt32 i);
