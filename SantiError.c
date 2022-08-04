//
// Created by 24216 on 2022/5/20.
//

#include "SantiError.h"
#include <stdlib.h>
#include <stdio.h>

static inline const char* get_info(char scError_id){
    switch(scError_id){
        case SC_ERROR_MATH:
            return "[ERROR] Invalid in math";
        case SC_ERROR_ARRAY_OUT_OF_RANGE:
            return "[ERROR] Out of bounds accessing array";
        case SC_ERROR_BAD_PARAMETER:
            return "[ERROR] Bad parameter";
        case SC_ERROR_UNSOLVABLE:
            return "[ERROR] Unsolvable";
        default:
            return "[ERROR] Unknown";
    }
}

void scError_handle(char scError_id, const char* where){
    const char* msg = get_info(scError_id);
    printf("%s (IN %s)\n", msg, where);
    // FIXME
    exit(0);
}