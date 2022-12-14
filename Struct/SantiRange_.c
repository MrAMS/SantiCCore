//
// Created by 24216 on 2022/7/30.
//

bool ADD_TYPE_NAME(scRange_is_in_range)(const ADD_TYPE_NAME(scStruct_range)* range, TYPE x){
    if(range->l>range->r)
        SC_ERROR_REPORT(BAD_PARAMETER);
    if(x<range->l) return FALSE;
    if(x>range->r) return FALSE;
    return TRUE;
}

TYPE ADD_TYPE_NAME(scRange_safe_range)(const ADD_TYPE_NAME(scStruct_range)* range, TYPE x){
    if(range->l>range->r)
        SC_ERROR_REPORT(BAD_PARAMETER);
    if(x<range->l) return range->l;
    if(x>range->r) return range->r;
    return x;
}