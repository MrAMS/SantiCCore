//
// Created by 24216 on 2022/7/30.
//

TYPE ADD_TYPE_NAME(scMath_sqr)(TYPE n) {
    return n * n;
}

TYPE ADD_TYPE_NAME(scMath_abs)(TYPE n) {
    if (n < 0) return -n;
    return n;
}

TYPE ADD_TYPE_NAME(scMath_max)(TYPE a, TYPE b) {
    if (a > b) return a;
    return b;
}

TYPE ADD_TYPE_NAME(scMath_min)(TYPE a, TYPE b) {
    if (a < b) return a;
    return b;
}

void ADD_TYPE_NAME(scMath_swap)(TYPE* a, TYPE* b) {
    TYPE t = *a;
    *a = *b;
    *b = t;
}