//
// Created by 24216 on 2022/5/20.
//

#ifndef SANTICCORE_SANTIDEFINE_H
#define SANTICCORE_SANTIDEFINE_H

/*
 * Option define
 */
// DEBUG
#define ENABLE_SANTICCORE_DEBUG

/*
 * Type define
 */
#include <stdint.h>

typedef float scFloat;
typedef signed char scChar;

typedef int8_t scInt8;
typedef uint8_t scUInt8;
typedef int16_t scInt16;
typedef uint16_t scUInt16;
typedef uint32_t scUInt32;
typedef int32_t scInt32;


#ifndef bool
    typedef char bool;
#endif

#ifndef TRUE
    #define TRUE 1
    #define FALSE 0
#endif

#endif //SANTICCORE_SANTIDEFINE_H
