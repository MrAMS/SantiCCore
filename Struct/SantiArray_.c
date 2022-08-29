//
// Created by 24216 on 2022/7/30.
//

static scInt32 ADD_TYPE_NAME(get_i)(const ADD_TYPE_NAME(scStruct_array)* pl, const scInt32 i){
    if(i>=pl->len || i<-pl->len){
        SC_ERROR_REPORT(ARRAY_OUT_OF_RANGE);
        return 0;
    }
    if(i<0) return pl->len+i;
    else return i;
}

bool ADD_TYPE_NAME(scArray_add)(ADD_TYPE_NAME(scStruct_array)* array, const TYPE val){
    if(array->len == array->len_max)
        return FALSE;
    array->a[array->len++] = val;
    return TRUE;
}

TYPE ADD_TYPE_NAME(scArray_get)(const ADD_TYPE_NAME(scStruct_array)* array, const scInt32 i){
    return array->a[ADD_TYPE_NAME(get_i)(array, i)];
}
