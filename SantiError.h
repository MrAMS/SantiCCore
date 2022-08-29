//
// Created by 24216 on 2022/5/20.
//

#ifndef SANTICCORE_SANTIERROR_H
#define SANTICCORE_SANTIERROR_H

#include <stdlib.h>
#include <stdio.h>

#define ARRAY_OUT_OF_RANGE 1
#define MATH_INVALID 2
#define BAD_PARAMETER 3
#define UNSOLVABLE 4

#define SC_ERROR_REPORT(ERROR_INFO) \
    do{ \
    printf("\n[SC ERROR] %s:%d IN %s: %s\n", __FILE__, __LINE__, __FUNCTION__, #ERROR_INFO); \
    exit(0); \
    }while(0)


#endif //SANTICCORE_SANTIERROR_H
